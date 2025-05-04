/********************************************************************************
** Form generated from reading UI file 'trackdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKDIALOG_H
#define UI_TRACKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_TrackDialog
{
public:
    QComboBox *comboBoxBoxes;
    QLabel *labelDistance;
    QLabel *labelStatus;

    void setupUi(QDialog *TrackDialog)
    {
        if (TrackDialog->objectName().isEmpty())
            TrackDialog->setObjectName("TrackDialog");
        TrackDialog->resize(612, 458);
        comboBoxBoxes = new QComboBox(TrackDialog);
        comboBoxBoxes->setObjectName("comboBoxBoxes");
        comboBoxBoxes->setGeometry(QRect(160, 50, 261, 24));
        labelDistance = new QLabel(TrackDialog);
        labelDistance->setObjectName("labelDistance");
        labelDistance->setGeometry(QRect(130, 280, 111, 16));
        labelStatus = new QLabel(TrackDialog);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(380, 280, 111, 16));

        retranslateUi(TrackDialog);

        QMetaObject::connectSlotsByName(TrackDialog);
    } // setupUi

    void retranslateUi(QDialog *TrackDialog)
    {
        TrackDialog->setWindowTitle(QCoreApplication::translate("TrackDialog", "Dialog", nullptr));
        labelDistance->setText(QString());
        labelStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrackDialog: public Ui_TrackDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKDIALOG_H
