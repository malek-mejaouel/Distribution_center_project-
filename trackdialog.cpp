/************************************************************
 * trackdialog.cpp – “Live tracking” window
 ************************************************************/
#include "trackdialog.h"
#include "ui_trackdialog.h"

#include "Arduino1.h"          // <-- make sure header is visible
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSerialPortInfo>
#include <cmath>
#include <QDebug>

// ──────────────────────────────────────────────────────────
// ctor / dtor
// ──────────────────────────────────────────────────────────
TrackDialog::TrackDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrackDialog)
    , arduino(new Arduino1(this))   // member we added in the header
    , currentBoxId(-1)
    , targetDistance(0.0f)
    , matchedAlerted(false)
    , surpassedAlerted(false)
{
    ui->setupUi(this);

    /* 1) Populate the combobox with the existing boxes
     *    (format:  “12 – Institut Alpha”)                        */
    QSqlQuery q(R"(
        SELECT b.ID_BOX, i.NOM_INST
          FROM KINZA.BOXS b
          JOIN KINZA.INSTITUTS i ON b.ID_INST = i.ID_INST
      ORDER BY b.ID_BOX
    )");

    ui->comboBoxBoxes->addItem("– Select box –", QVariant());     // placeholder
    while (q.next()) {
        int     idBox   = q.value(0).toInt();
        QString institut= q.value(1).toString();
        ui->comboBoxBoxes->addItem(QString("%1 – %2").arg(idBox).arg(institut),
                                   idBox);
    }
    // disable the first (placeholder) entry
    if (auto *model = qobject_cast<QStandardItemModel*>(ui->comboBoxBoxes->model()))
        if (auto *item = model->item(0))
            item->setEnabled(false);
    ui->comboBoxBoxes->setCurrentIndex(0);

    /* 2) Connect to Arduino on a fixed port (change if necessary) */
    if (!arduino->connectArduino1("COM6")) {                      // <- corrected call
        QMessageBox::warning(this, "Serial error",
                             "Cannot open COM6 – close any other app using that port.");
    }

    /* 3) Signal/slot wiring */
    connect(ui->comboBoxBoxes, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TrackDialog::on_comboBoxBoxes_currentIndexChanged);

    connect(arduino, &Arduino1::distanceUpdated,                  // <- corrected pointer
            this,    &TrackDialog::updateDistance);
}

TrackDialog::~TrackDialog()
{
    delete ui;
}

// ──────────────────────────────────────────────────────────
// When the user picks a box to track
// ──────────────────────────────────────────────────────────
void TrackDialog::on_comboBoxBoxes_currentIndexChanged(int idx)
{
    matchedAlerted   = false;
    surpassedAlerted = false;
    currentBoxId     = -1;
    targetDistance   = 0.0f;
    ui->labelStatus  ->setText("Status:");
    ui->labelDistance->setText("Distance:");

    if (idx < 1) return;                      // placeholder selected

    /* Fetch the reference distance (DISTANCE_INST) and current ETAT */
    int boxId = ui->comboBoxBoxes->currentData().toInt();
    QSqlQuery qq;
    qq.prepare(R"(
        SELECT i.DISTANCE_INST, b.ETAT
          FROM KINZA.BOXS b
          JOIN KINZA.INSTITUTS i ON b.ID_INST = i.ID_INST
         WHERE b.ID_BOX = :id
    )");
    qq.bindValue(":id", boxId);

    if (!qq.exec() || !qq.next()) {
        qDebug() << "Could not load box info:" << qq.lastError().text();
        return;
    }

    currentBoxId   = boxId;
    targetDistance = qq.value(0).toFloat();
    QString etat   = qq.value(1).toString();

    ui->labelStatus  ->setText(QString("Status: %1").arg(etat));
    ui->labelDistance->setText(QString("Distance: %1 cm").arg(targetDistance,0,'f',1));

    /* Optionally tell the Arduino the threshold so it can beep itself */
    QByteArray cmd = "D" + QByteArray::number(targetDistance, 'f', 1) + "\n";
    arduino->writeData(cmd);
}

// ──────────────────────────────────────────────────────────
// Re-evaluated whenever Arduino sends a new distance
// ──────────────────────────────────────────────────────────
void TrackDialog::updateDistance(float cm)
{
    if (currentBoxId < 0) return;                     // nothing selected

    float diff = cm - targetDistance;

    /* 1) First time within ±1 cm  → mark delivered */
    if (!matchedAlerted && std::fabs(diff) <= 1.0f) {
        matchedAlerted = true;
        arduino->writeData("matched\n");              // single short beep

        QSqlQuery upd;
        upd.prepare("UPDATE KINZA.BOXS SET ETAT = 'livree' WHERE ID_BOX = :id");
        upd.bindValue(":id", currentBoxId);
        if (!upd.exec())
            qDebug() << "DB update failed:" << upd.lastError().text();
        else {
            ui->labelStatus->setText("Status: livree");
            emit deliveryDone();                      // let MainWindow refresh
        }
        QMessageBox::information(this, "Info", "Box delivered!");
        return;
    }

    /* 2) First time *past* the target again → “surpassed” alert */
    if (matchedAlerted && !surpassedAlerted && diff > 1.0f) {
        surpassedAlerted = true;
        arduino->writeData("surpassed\n");            // long beep
        QMessageBox::information(this, "Alert", "Box surpassed the drop point!");
    }
}
