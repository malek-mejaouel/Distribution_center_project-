// trackdialog.cpp

#include "trackdialog.h"
#include "ui_trackdialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>
#include <QStandardItemModel>
#include <cmath>
#include <QDebug>

TrackDialog::TrackDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::TrackDialog),
    arduino(new Arduino(this)),
    currentBoxId(-1),
    targetDistance(0.0f),
    matchedAlerted(false),
    surpassedAlerted(false)
{
    ui->setupUi(this);

    // 1) Populate comboBox with ID_BOX – NOM_INST
    QSqlQuery q(
        "SELECT b.ID_BOX, i.NOM_INST "
        "  FROM KINZA.BOXS b "
        "  JOIN KINZA.INSTITUTS i ON b.ID_INST = i.ID_INST "
        " ORDER BY b.ID_BOX"
        );
    ui->comboBoxBoxes->addItem("– Select box –", QVariant());
    while (q.next()) {
        int    id        = q.value(0).toInt();
        QString institut = q.value(1).toString();
        ui->comboBoxBoxes->addItem(
            QString("%1 – %2").arg(id).arg(institut),
            id
            );
    }
    // Disable the placeholder entry
    if (auto model = qobject_cast<QStandardItemModel*>(ui->comboBoxBoxes->model())) {
        if (auto item = model->item(0))
            item->setEnabled(false);
    }
    ui->comboBoxBoxes->setCurrentIndex(0);

    // 2) Connect to Arduino (explicit port or auto‐scan)
    if (!arduino->connectArduino("COM6")) {
        QMessageBox::warning(this, "Serial Error",
                             "Cannot open COM6.\nPlease close any other apps using that port."
                             );
    }

    // 3) Hook up signals
    connect(ui->comboBoxBoxes,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &TrackDialog::on_comboBoxBoxes_currentIndexChanged);

    connect(arduino,
            &Arduino::distanceUpdated,
            this,
            &TrackDialog::updateDistance);
}

TrackDialog::~TrackDialog() {
    delete ui;
}

void TrackDialog::on_comboBoxBoxes_currentIndexChanged(int idx) {
    // Reset all state
    matchedAlerted   = false;
    surpassedAlerted = false;
    currentBoxId     = -1;
    targetDistance   = 0.0f;
    ui->labelStatus->setText("Status:");
    ui->labelDistance->setText("Distance:");

    if (idx < 1) return;  // placeholder still selected

    // 4) Fetch targetDistance from INSTITUTS and ETAT from BOXS
    int boxId = ui->comboBoxBoxes->currentData().toInt();
    QSqlQuery qq;
    qq.prepare(R"(
      SELECT i.DISTANCE_INST, b.ETAT
        FROM KINZA.BOXS b
        JOIN KINZA.INSTITUTS i
          ON b.ID_INST = i.ID_INST
       WHERE b.ID_BOX = :id
    )");
    qq.bindValue(":id", boxId);
    if (!qq.exec() || !qq.next()) {
        qDebug() << "Failed to load box info:" << qq.lastError().text();
        return;
    }

    currentBoxId    = boxId;
    targetDistance  = qq.value(0).toFloat();
    QString etat    = qq.value(1).toString();

    // Update the static labels
    ui->labelStatus->setText(QString("Status: %1").arg(etat));
    ui->labelDistance->setText(
        QString("Distance: %1 cm").arg(targetDistance, 0, 'f', 1)
        );

    // Inform Arduino of the target (optional)
    QByteArray cmd = "D" + QByteArray::number(targetDistance, 'f', 1) + "\n";
    arduino->writeData(cmd);
}

void TrackDialog::updateDistance(float cm) {
    if (currentBoxId < 0)
        return;  // ignore until a box is selected

    float diff = cm - targetDistance;

    // 1) Matched: first time within ±1 cm
    if (!matchedAlerted && std::fabs(diff) <= 1.0f) {
        matchedAlerted = true;

        // Trigger single beep
        arduino->writeData("matched\n");

        // Update database ETAT to 'livree'
        QSqlQuery upd;
        upd.prepare("UPDATE KINZA.BOXS SET ETAT='livree' WHERE ID_BOX = :id");
        upd.bindValue(":id", currentBoxId);
        if (!upd.exec()) {
            qDebug() << "Failed to update ETAT:" << upd.lastError().text();
        } else {
            ui->labelStatus->setText("Status: livree");
            // Notify MainWindow to refresh the table
            emit deliveryDone();        }

        QMessageBox::information(this, "Alert", "Box delivered!");
        return;
    }

    // 2) Surpassed: first time beyond +1 cm
    if (matchedAlerted && !surpassedAlerted && diff > 1.0f) {
        surpassedAlerted = true;
        arduino->writeData("surpassed\n");
        QMessageBox::information(this, "Alert", "Box surpassed!");
    }
}
