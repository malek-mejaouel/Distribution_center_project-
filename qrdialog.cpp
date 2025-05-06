#include "qrdialog.h"
#include "ui_qrdialog.h"  // Must come first
#include <QZXing.h>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QComboBox>  //  include
#include <QPushButton>  //  include

QRDialog::QRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRDialog)
{
    ui->setupUi(this);
    loadBoxes();

    setMinimumSize(400, 500);

    connect(ui->boxComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &QRDialog::on_boxComboBox_currentIndexChanged);
    connect(ui->downloadButton, &QPushButton::clicked,
            this, &QRDialog::on_downloadButton_clicked);
}

QRDialog::~QRDialog()
{
    delete ui;
}

void QRDialog::loadBoxes()
{
    ui->boxComboBox->clear();
    QSqlQuery query("SELECT ID_BOX, DESTINATION FROM BOXS ORDER BY ID_BOX");
    while (query.next()) {
        int boxId = query.value(0).toInt();
        QString destination = query.value(1).toString();
        ui->boxComboBox->addItem(QString("%1 - %2").arg(boxId).arg(destination), boxId);
    }
}

QString QRDialog::getBoxInfo(int boxId)
{
    QSqlQuery query;
    query.prepare("SELECT ID_BOX, DESTINATION, DATE_CREATION, STATUS, ETAT "
                  "FROM BOXS WHERE ID_BOX = :boxId");
    query.bindValue(":boxId", boxId);

    if (!query.exec() || !query.next()) {
        return "Error: Box not found";
    }

    return QString(
               "Box ID: %1\n"
               "Destination: %2\n"
               "Created: %3\n"
               "Status: %4\n"
               "State: %5"
               ).arg(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString()
            );
}

void QRDialog::generateQRCode(const QString &data)
{
    QImage qrImage = QZXing::encodeData(data,
                                        QZXing::EncoderFormat_QR_CODE,
                                        QSize(300, 300),
                                        QZXing::EncodeErrorCorrectionLevel_L,
                                        true);

    if (qrImage.isNull()) {
        ui->qrCodeLabel->setText("Failed to generate QR code");
        return;
    }

    ui->qrCodeLabel->setPixmap(QPixmap::fromImage(qrImage));
    ui->qrCodeLabel->setScaledContents(true);
}

void QRDialog::on_boxComboBox_currentIndexChanged(int index)
{
    if (index < 0) return;

    int boxId = ui->boxComboBox->currentData().toInt();
    QString boxInfo = getBoxInfo(boxId);
    generateQRCode(boxInfo);
}

void QRDialog::on_downloadButton_clicked()
{
    // Get the pixmap from the label
    QPixmap qrPixmap = ui->qrCodeLabel->pixmap();

    // Check if we have a valid pixmap
    if (qrPixmap.isNull()) {
        QMessageBox::warning(this, "Error", "No QR code to save");
        return;
    }

    // Get save file name
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Save QR Code",
        QString("Box_%1_QR.png").arg(ui->boxComboBox->currentData().toInt()),
        "PNG Images (*.png);;JPEG Images (*.jpg *.jpeg)"
        );

    // Save the pixmap
    if (!fileName.isEmpty() && !qrPixmap.save(fileName)) {
        QMessageBox::critical(this, "Error", "Failed to save QR code");
    }
}
