/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGroupBox *horizontalGroupBox_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *nomInst_input;
    QLineEdit *adresseInst_input;
    QLineEdit *emailInst_input;
    QLineEdit *telephoneInst_input;
    QLineEdit *responsableInst_input;
    QLineEdit *capaciteInst_input;
    QLabel *label_18;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b5;
    QWidget *tab_6;
    QWidget *horizontalWidget;
    QLineEdit *lineEdit_8;
    QLabel *label_8;
    QTableWidget *tab1;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_5;
    QPushButton *b4;
    QPushButton *b3;
    QWidget *verticalWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_17;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(200, 0, 601, 291));
        tabWidget->setMaximumSize(QSize(16777215, 291));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Style the entire TabWidget */\n"
"QTabWidget::pane {\n"
"    background: white; /* Background of the tab widget */\n"
"    border: 2px solid #A9A8FF;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* Style for the Tab Bar (tab headers) */\n"
"QTabBar::tab {\n"
"    background: #8685F5; /* Default tab background */\n"
"    color: white; /* Text color */\n"
"    padding: 8px 16px;\n"
"    border-radius: 8px;\n"
"    margin: 2px;\n"
"    border: 1px solid #6563FF;\n"
"}\n"
"\n"
"/* Selected Tab */\n"
"QTabBar::tab:selected {\n"
"    background: #6563FF; /* Active tab color */\n"
"    font-weight: bold;\n"
"    border-bottom: 3px solid white;\n"
"}\n"
"\n"
"/* Hover effect on tabs */\n"
"QTabBar::tab:hover {\n"
"    background: #7A79FF;\n"
"}\n"
"\n"
"/* Disabled tabs */\n"
"QTabBar::tab:disabled {\n"
"    background: #D3D3D3;\n"
"    color: gray;\n"
"}\n"
""));
        widget = new QWidget();
        widget->setObjectName("widget");
        horizontalGroupBox_2 = new QGroupBox(widget);
        horizontalGroupBox_2->setObjectName("horizontalGroupBox_2");
        horizontalGroupBox_2->setGeometry(QRect(-10, -30, 621, 281));
        horizontalGroupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        label_12 = new QLabel(horizontalGroupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(120, 90, 81, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_13 = new QLabel(horizontalGroupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(120, 120, 81, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_14 = new QLabel(horizontalGroupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(120, 150, 81, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_15 = new QLabel(horizontalGroupBox_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(120, 180, 81, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_16 = new QLabel(horizontalGroupBox_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(120, 210, 81, 31));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_17 = new QLabel(horizontalGroupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(120, 240, 141, 31));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        nomInst_input = new QLineEdit(horizontalGroupBox_2);
        nomInst_input->setObjectName("nomInst_input");
        nomInst_input->setGeometry(QRect(250, 100, 141, 16));
        nomInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        adresseInst_input = new QLineEdit(horizontalGroupBox_2);
        adresseInst_input->setObjectName("adresseInst_input");
        adresseInst_input->setGeometry(QRect(250, 130, 141, 16));
        adresseInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        emailInst_input = new QLineEdit(horizontalGroupBox_2);
        emailInst_input->setObjectName("emailInst_input");
        emailInst_input->setGeometry(QRect(250, 160, 141, 16));
        emailInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        telephoneInst_input = new QLineEdit(horizontalGroupBox_2);
        telephoneInst_input->setObjectName("telephoneInst_input");
        telephoneInst_input->setGeometry(QRect(250, 190, 141, 16));
        telephoneInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        responsableInst_input = new QLineEdit(horizontalGroupBox_2);
        responsableInst_input->setObjectName("responsableInst_input");
        responsableInst_input->setGeometry(QRect(250, 220, 141, 16));
        responsableInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        capaciteInst_input = new QLineEdit(horizontalGroupBox_2);
        capaciteInst_input->setObjectName("capaciteInst_input");
        capaciteInst_input->setGeometry(QRect(250, 250, 141, 16));
        capaciteInst_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_18 = new QLabel(horizontalGroupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(30, 50, 161, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font.setBold(true);
        font.setItalic(false);
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_18 = new QPushButton(horizontalGroupBox_2);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(90, 290, 80, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        font1.setItalic(false);
        pushButton_18->setFont(font1);
        pushButton_18->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_19 = new QPushButton(horizontalGroupBox_2);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(400, 290, 80, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font2.setBold(true);
        pushButton_19->setFont(font2);
        pushButton_19->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        b1 = new QPushButton(horizontalGroupBox_2);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(450, 230, 71, 31));
        b1->setFont(font2);
        b1->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        b2 = new QPushButton(horizontalGroupBox_2);
        b2->setObjectName("b2");
        b2->setGeometry(QRect(530, 230, 71, 31));
        b2->setFont(font2);
        b2->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        b5 = new QPushButton(horizontalGroupBox_2);
        b5->setObjectName("b5");
        b5->setGeometry(QRect(440, 40, 151, 31));
        b5->setFont(font2);
        b5->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        label_12->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        adresseInst_input->raise();
        emailInst_input->raise();
        telephoneInst_input->raise();
        responsableInst_input->raise();
        capaciteInst_input->raise();
        label_18->raise();
        pushButton_18->raise();
        pushButton_19->raise();
        nomInst_input->raise();
        b1->raise();
        b2->raise();
        b5->raise();
        tabWidget->addTab(widget, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setGeometry(QRect(200, 290, 971, 491));
        horizontalWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_8 = new QLineEdit(horizontalWidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(10, 40, 281, 16));
        label_8 = new QLabel(horizontalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 261, 21));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        tab1 = new QTableWidget(horizontalWidget);
        if (tab1->columnCount() < 7)
            tab1->setColumnCount(7);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        __qtablewidgetitem->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(10, 21, 91));
        tab1->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tab1->setObjectName("tab1");
        tab1->setGeometry(QRect(10, 60, 581, 211));
        tab1->setAutoFillBackground(false);
        tab1->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);\n"
"background-color: rgb(14, 0, 214);\n"
"background-color: rgb(179, 179, 179);"));
        label_11 = new QLabel(horizontalWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(390, 30, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(470, 30, 91, 24));
        pushButton_14 = new QPushButton(horizontalWidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(40, 310, 81, 31));
        pushButton_14->setFont(font2);
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_15 = new QPushButton(horizontalWidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(410, 310, 81, 31));
        pushButton_15->setFont(font2);
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_16 = new QPushButton(horizontalWidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(520, 310, 81, 31));
        pushButton_16->setFont(font2);
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_5 = new QPushButton(horizontalWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(300, 30, 51, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/search-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon);
        b4 = new QPushButton(horizontalWidget);
        b4->setObjectName("b4");
        b4->setGeometry(QRect(490, 220, 91, 31));
        b4->setFont(font2);
        b4->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        b3 = new QPushButton(horizontalWidget);
        b3->setObjectName("b3");
        b3->setGeometry(QRect(390, 220, 91, 31));
        b3->setFont(font2);
        b3->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(-10, -40, 211, 671));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(10, 21, 91)"));
        label = new QLabel(verticalWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 161, 71));
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    font-family: \"Montserrat\";\n"
"    letter-spacing: 2px;\n"
"    text-transform: uppercase;"));
        pushButton = new QPushButton(verticalWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 130, 121, 51));
        QFont font4;
        font4.setBold(true);
        pushButton->setFont(font4);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"color: #1E2350;\n"
"border-radius: 10px;\n"
"font-size: 14px;\n"
"padding: 8px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon1);
        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 190, 121, 51));
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon2);
        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 250, 121, 51));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon3);
        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 310, 121, 51));
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;\n"
"background-color: rgb(175, 175, 175);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon4);
        pushButton_9 = new QPushButton(verticalWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 370, 121, 51));
        pushButton_9->setFont(font4);
        pushButton_9->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon5);
        pushButton_10 = new QPushButton(verticalWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 430, 121, 51));
        pushButton_10->setFont(font4);
        pushButton_10->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ressources/box-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon6);
        pushButton_13 = new QPushButton(verticalWidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(40, 490, 121, 51));
        pushButton_13->setFont(font4);
        pushButton_13->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon7);
        pushButton_17 = new QPushButton(verticalWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 550, 121, 41));
        pushButton_17->setFont(font4);
        pushButton_17->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_17->setIcon(icon8);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Telephone:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Responsable", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "capacite", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Ajouter une institut", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Verifier", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        b1->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        b2->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        b5->setText(QCoreApplication::translate("MainWindow", "afficher les instituts", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Ajouter une Institut", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionalit\303\251s", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Recherche d'une Institut avec son id :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID Institut", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab1->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Capacite", nullptr));
#if QT_CONFIG(tooltip)
        tab1->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>background-color:rgb(10, 21, 91)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tab1->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_11->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "capacite", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_5->setText(QString());
        b4->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        b3->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "FullMark", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Equipement", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Examen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Institut", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Livreur", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Parammetre", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
