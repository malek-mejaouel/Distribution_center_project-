/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *leftMenu;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QLabel *label_45;
    QPushButton *pushButton_24;
    QLabel *label_13;
    QPushButton *pushButton_10;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *page_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1170, 658);
        Form->setStyleSheet(QString::fromUtf8("*{\n"
"font-family:century gothic ;\n"
"font-size:24px;\n"
"border:none;\n"
"}\n"
"#payment_pdf QPushButton{\n"
"color:white;\n"
"background:#EBEBEB;\n"
"border-radius:15px ;\n"
"}\n"
"#payment_pdf QPushButton:hover{\n"
"color:white;\n"
"background:white;\n"
"border-radius:15px ;\n"
"}\n"
"\n"
"QDialog{\n"
"background:white;\n"
"border-radius:15px ;\n"
"\n"
"}\n"
"QComboBox{color:white;\n"
"background:#8685F5;\n"
"border-radius:15px ;}\n"
"QComboBox:hover{\n"
"color:white;\n"
"background:#6563FF;\n"
"border-radius:15px ;\n"
"}\n"
"QTableView{\n"
"background:#EDEDED;\n"
"}\n"
"\n"
"QFrame{\n"
"background:white;\n"
"}\n"
"QStackedWidget{\n"
"background:#A9A8FF;\n"
"border-radius:15px ;\n"
"}\n"
"QTabWidget{\n"
"\n"
"background:#A9A8FF;\n"
"\n"
"}\n"
"#tab{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"#tab_2{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"#leftMenu{\n"
"background:#A9A8FF;\n"
"}\n"
"#leftMenu:hover{\n"
"ba"
                        "ckground:#A9A8FF;\n"
"\n"
"}\n"
"QToolButton{\n"
"background:#A9A8FF;\n"
"border-radius:60px;\n"
"}\n"
"QLabel{\n"
"color:#6563FF;\n"
"}\n"
"#leftMenu QLabel{\n"
"color:white;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"background:#8685F5;\n"
"border-radius:15px ;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:white;\n"
"background:#6563FF;\n"
"border-radius:15px ;\n"
"}\n"
"#leftMenu QPushButton{\n"
"color:white;\n"
"background:#EBEBEB;\n"
"border-radius:15px ;\n"
"}\n"
"#leftMenu QPushButton:hover\n"
"{\n"
"color:white;\n"
"background:white;\n"
"border-radius:15px ;\n"
"}\n"
"QLineEdit{\n"
"background:transparent;\n"
"border-radius:14px;\n"
"border:none;\n"
"color:#717072;\n"
"border-bottom:1px solid #717072;\n"
"\n"
"}\n"
"QLineEdit:hover{\n"
"color:black;\n"
"border-bottom:1px solid #6563FF;\n"
"}\n"
"#client1{\n"
"background:white;\n"
"}\n"
"#client2{\n"
"background:white;\n"
"}\n"
"#client1:hover{\n"
"}\n"
"#client2:hover{\n"
"}\n"
"#client_statistic1{\n"
"background:white;\n"
"}\n"
"#client_statistic2{\n"
""
                        "background:white;\n"
"}\n"
"#client_statistic1:hover{\n"
"}\n"
"#client_statistic2:hover{\n"
"}\n"
"\n"
"/*payment page */\n"
"#payment1{\n"
"background:white;\n"
"}\n"
"#payment2{\n"
"background:white;\n"
"}\n"
"#payment1:hover{\n"
"}\n"
"#payment2:hover{\n"
"}\n"
"#payment_statistic1{\n"
"background:white;\n"
"}\n"
"#payment_statistic2{\n"
"background:white;\n"
"}\n"
"#payment_statistic1:hover{\n"
"}\n"
"#payment_statistic2:hover{\n"
"}\n"
"#payment_tab1{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"#payment_tab2{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"/*-------------------------------------*/\n"
"\n"
"/*reservation page */\n"
"#reservation1{\n"
"background:white;\n"
"}\n"
"#reservation2{\n"
"background:white;\n"
"}\n"
"#reservation1:hover{\n"
"}\n"
"#reservation:hover{\n"
"}\n"
"#reservation_statistic1{\n"
"background:white;\n"
"}\n"
"#reservation_statistic2{\n"
"background:white;\n"
"}\n"
"#reservation_stati"
                        "stic1:hover{\n"
"}\n"
"#reservation_statistic2:hover{\n"
"}\n"
"#reservation_tab1{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"#reservation_tab2{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"/*-------------------------------------*/\n"
"\n"
"/*employee page */\n"
"#employee1{\n"
"background:white;\n"
"}\n"
"#employee2{\n"
"background:white;\n"
"}\n"
"#employee1:hover{\n"
"}\n"
"#employee2:hover{\n"
"}\n"
"#employee_statistic1{\n"
"background:white;\n"
"}\n"
"#employee_statistic2{\n"
"background:white;\n"
"}\n"
"#employee_statistic1:hover{\n"
"}\n"
"#employee_statistic2:hover{\n"
"}\n"
"#employee_tab1{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"#employee_tab2{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"/*-------------------------------------*/\n"
"\n"
"\n"
"/*accommodation page */\n"
"#accommodation1{\n"
"background:white"
                        ";\n"
"}\n"
"#accommodation2{\n"
"background:white;\n"
"}\n"
"#accommodation1:hover{\n"
"}\n"
"#accommodation2:hover{\n"
"}\n"
"#accommodation_statistic1{\n"
"background:white;\n"
"}\n"
"#accommodation_statistic2{\n"
"background:white;\n"
"}\n"
"#accommodation_statistic1:hover{\n"
"}\n"
"#accommodation_statistic2:hover{\n"
"}\n"
"#accommodation_tab1{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF ;\n"
"border-radius:0px;\n"
"\n"
"\n"
"}\n"
"#accommodation_tab2{\n"
"background:transparent;\n"
"border:10px solid #A9A8FF;\n"
"border-radius:0px;\n"
"}\n"
"\n"
"/*-------------------------------------*/\n"
"\n"
"\n"
"QListWidget{\n"
"background:#EDEDED;\n"
"}\n"
"#label_6:hover{\n"
"text-decoration: underline;\n"
"}\n"
"#label_7:hover{\n"
"text-decoration: underline;\n"
"}"));
        leftMenu = new QWidget(Form);
        leftMenu->setObjectName("leftMenu");
        leftMenu->setGeometry(QRect(10, -10, 291, 731));
        leftMenu->setStyleSheet(QString::fromUtf8("border-radius:15px;"));
        pushButton_4 = new QPushButton(leftMenu);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(190, 310, 75, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/feather (3)/users.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(28, 28));
        label_5 = new QLabel(leftMenu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 291, 51));
        label_5->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"border-bottom:2px solid white;\n"
"font-size:30px;\n"
"font-weight:700;"));
        label_6 = new QLabel(leftMenu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 50, 231, 51));
        label_6->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
""));
        label_7 = new QLabel(leftMenu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 400, 291, 51));
        label_7->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
"\n"
""));
        pushButton_8 = new QPushButton(leftMenu);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(190, 60, 75, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/feather (3)/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(28, 28));
        pushButton_9 = new QPushButton(leftMenu);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(190, 410, 75, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ressources/settings.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon2);
        pushButton_9->setIconSize(QSize(24, 24));
        label_8 = new QLabel(leftMenu);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 150, 231, 51));
        label_8->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
""));
        pushButton = new QPushButton(leftMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 160, 75, 31));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(28, 28));
        label_9 = new QLabel(leftMenu);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 200, 231, 51));
        label_9->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
""));
        pushButton_2 = new QPushButton(leftMenu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 210, 75, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/feather (3)/shopping-cart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(28, 28));
        label_10 = new QLabel(leftMenu);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 250, 231, 51));
        label_10->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
""));
        pushButton_3 = new QPushButton(leftMenu);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 260, 75, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/feather (3)/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(28, 28));
        label_11 = new QLabel(leftMenu);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 300, 171, 51));
        label_11->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
""));
        label_12 = new QLabel(leftMenu);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 350, 291, 51));
        label_12->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"border-bottom:1px solid white;\n"
"\n"
"\n"
""));
        pushButton_5 = new QPushButton(leftMenu);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(190, 360, 75, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/feather (3)/home.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setIconSize(QSize(28, 28));
        label_45 = new QLabel(leftMenu);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(0, 450, 291, 51));
        label_45->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"\n"
"\n"
"\n"
""));
        pushButton_24 = new QPushButton(leftMenu);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(190, 460, 75, 31));
        pushButton_24->setIconSize(QSize(28, 28));
        label_13 = new QLabel(leftMenu);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 100, 291, 51));
        label_13->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-radius:0px;\n"
"font-size:20px;\n"
"font-weight:700;\n"
"border-bottom:1px solid white;\n"
"\n"
"\n"
""));
        pushButton_10 = new QPushButton(leftMenu);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(190, 110, 75, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/feather (3)/map.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon6);
        pushButton_10->setIconSize(QSize(28, 28));
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(300, 10, 1071, 651));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_4->setText(QString());
        label_5->setText(QCoreApplication::translate("Form", "FullMark", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "  Mon profile", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "  Settings", nullptr));
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        label_8->setText(QCoreApplication::translate("Form", " Equipement", nullptr));
        pushButton->setText(QString());
        label_9->setText(QCoreApplication::translate("Form", " Examen", nullptr));
        pushButton_2->setText(QString());
        label_10->setText(QCoreApplication::translate("Form", " Institut", nullptr));
        pushButton_3->setText(QString());
        label_11->setText(QCoreApplication::translate("Form", " Livreur", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "Box", nullptr));
        pushButton_5->setText(QString());
        label_45->setText(QCoreApplication::translate("Form", "  Log out", nullptr));
        pushButton_24->setText(QString());
        label_13->setText(QCoreApplication::translate("Form", " Map", nullptr));
        pushButton_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
