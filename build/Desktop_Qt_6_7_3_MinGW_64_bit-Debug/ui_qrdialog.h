/********************************************************************************
** Form generated from reading UI file 'qrdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRDIALOG_H
#define UI_QRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QRDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *boxComboBox;
    QLabel *qrCodeLabel;
    QPushButton *downloadButton;

    void setupUi(QDialog *QRDialog)
    {
        if (QRDialog->objectName().isEmpty())
            QRDialog->setObjectName("QRDialog");
        QRDialog->resize(400, 500);
        verticalLayout = new QVBoxLayout(QRDialog);
        verticalLayout->setObjectName("verticalLayout");
        boxComboBox = new QComboBox(QRDialog);
        boxComboBox->setObjectName("boxComboBox");

        verticalLayout->addWidget(boxComboBox);

        qrCodeLabel = new QLabel(QRDialog);
        qrCodeLabel->setObjectName("qrCodeLabel");
        qrCodeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(qrCodeLabel);

        downloadButton = new QPushButton(QRDialog);
        downloadButton->setObjectName("downloadButton");

        verticalLayout->addWidget(downloadButton);


        retranslateUi(QRDialog);

        QMetaObject::connectSlotsByName(QRDialog);
    } // setupUi

    void retranslateUi(QDialog *QRDialog)
    {
        QRDialog->setWindowTitle(QCoreApplication::translate("QRDialog", "QR Code Generator", nullptr));
        downloadButton->setText(QCoreApplication::translate("QRDialog", "Download QR Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRDialog: public Ui_QRDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRDIALOG_H
