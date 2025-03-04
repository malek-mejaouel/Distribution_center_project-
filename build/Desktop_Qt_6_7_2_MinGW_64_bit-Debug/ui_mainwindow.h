/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
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
    QWidget *horizontalWidget;
    QLineEdit *search_input;
    QLabel *label_8;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *searchbutt;
    QTableView *tableView;
    QPushButton *deletebutt;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGroupBox *horizontalGroupBox;
    QLabel *label_3;
    QLineEdit *nom_input;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *prenom_input;
    QLineEdit *modpass_input;
    QLineEdit *email_input;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_9;
    QLineEdit *telephone_input;
    QLabel *label_12;
    QDateEdit *dateEdit;
    QLabel *label_10;
    QLineEdit *cin_input;
    QLabel *label_5;
    QRadioButton *r1;
    QRadioButton *r2;
    QRadioButton *r3;
    QRadioButton *r4;
    QRadioButton *r5;
    QRadioButton *r6;
    QPushButton *pushButton_18;
    QWidget *tab_6;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(-10, -20, 211, 671));
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
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"background-color: rgb(175, 175, 175);\n"
"color: #1E2350;\n"
"border-radius: 10px;\n"
"font-size: 14px;\n"
"padding: 8px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 190, 121, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 250, 121, 51));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon2);
        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 310, 121, 51));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon3);
        pushButton_9 = new QPushButton(verticalWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 370, 121, 51));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon4);
        pushButton_10 = new QPushButton(verticalWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 430, 121, 51));
        pushButton_10->setFont(font);
        pushButton_10->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ressources/box-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon5);
        pushButton_13 = new QPushButton(verticalWidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(40, 490, 121, 51));
        pushButton_13->setFont(font);
        pushButton_13->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon6);
        pushButton_17 = new QPushButton(verticalWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 550, 121, 41));
        pushButton_17->setFont(font);
        pushButton_17->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_17->setIcon(icon7);
        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setGeometry(QRect(200, 290, 971, 491));
        horizontalWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        search_input = new QLineEdit(horizontalWidget);
        search_input->setObjectName("search_input");
        search_input->setGeometry(QRect(10, 40, 281, 16));
        label_8 = new QLabel(horizontalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 261, 21));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_11 = new QLabel(horizontalWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(440, 30, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(510, 30, 71, 21));
        pushButton_14 = new QPushButton(horizontalWidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(40, 310, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font1.setBold(true);
        pushButton_14->setFont(font1);
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_15 = new QPushButton(horizontalWidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(410, 310, 81, 31));
        pushButton_15->setFont(font1);
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_16 = new QPushButton(horizontalWidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(520, 310, 81, 31));
        pushButton_16->setFont(font1);
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        searchbutt = new QPushButton(horizontalWidget);
        searchbutt->setObjectName("searchbutt");
        searchbutt->setGeometry(QRect(300, 30, 51, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ressources/search-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchbutt->setIcon(icon8);
        tableView = new QTableView(horizontalWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 70, 581, 201));
        tableView->setStyleSheet(QString::fromUtf8("background:#EDEDED;\n"
"color:#6563FF;\n"
"font-size:16px;"));
        deletebutt = new QPushButton(horizontalWidget);
        deletebutt->setObjectName("deletebutt");
        deletebutt->setGeometry(QRect(360, 30, 61, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font2.setBold(true);
        font2.setItalic(true);
        deletebutt->setFont(font2);
        deletebutt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 0, 601, 291));
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
        horizontalGroupBox = new QGroupBox(widget);
        horizontalGroupBox->setObjectName("horizontalGroupBox");
        horizontalGroupBox->setGeometry(QRect(-10, -20, 621, 271));
        horizontalGroupBox->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        horizontalGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        label_3 = new QLabel(horizontalGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 40, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        nom_input = new QLineEdit(horizontalGroupBox);
        nom_input->setObjectName("nom_input");
        nom_input->setGeometry(QRect(160, 40, 141, 16));
        nom_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(horizontalGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 60, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_6 = new QLabel(horizontalGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 90, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_7 = new QLabel(horizontalGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 130, 81, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        prenom_input = new QLineEdit(horizontalGroupBox);
        prenom_input->setObjectName("prenom_input");
        prenom_input->setGeometry(QRect(160, 70, 141, 16));
        prenom_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        modpass_input = new QLineEdit(horizontalGroupBox);
        modpass_input->setObjectName("modpass_input");
        modpass_input->setGeometry(QRect(160, 100, 141, 16));
        modpass_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        email_input = new QLineEdit(horizontalGroupBox);
        email_input->setObjectName("email_input");
        email_input->setGeometry(QRect(160, 130, 141, 16));
        email_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_11 = new QPushButton(horizontalGroupBox);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(420, 210, 80, 31));
        pushButton_11->setFont(font2);
        pushButton_11->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_12 = new QPushButton(horizontalGroupBox);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(520, 210, 80, 31));
        pushButton_12->setFont(font1);
        pushButton_12->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        label_9 = new QLabel(horizontalGroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 160, 71, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        telephone_input = new QLineEdit(horizontalGroupBox);
        telephone_input->setObjectName("telephone_input");
        telephone_input->setGeometry(QRect(160, 160, 141, 16));
        telephone_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_12 = new QLabel(horizontalGroupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 220, 121, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        dateEdit = new QDateEdit(horizontalGroupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(180, 220, 110, 25));
        label_10 = new QLabel(horizontalGroupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 190, 71, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        cin_input = new QLineEdit(horizontalGroupBox);
        cin_input->setObjectName("cin_input");
        cin_input->setGeometry(QRect(160, 190, 141, 16));
        cin_input->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(horizontalGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 30, 111, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Poppins")});
        font3.setBold(true);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        r1 = new QRadioButton(horizontalGroupBox);
        r1->setObjectName("r1");
        r1->setGeometry(QRect(330, 60, 81, 22));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setItalic(true);
        r1->setFont(font4);
        r1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r2 = new QRadioButton(horizontalGroupBox);
        r2->setObjectName("r2");
        r2->setGeometry(QRect(420, 60, 81, 22));
        r2->setFont(font4);
        r2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r3 = new QRadioButton(horizontalGroupBox);
        r3->setObjectName("r3");
        r3->setGeometry(QRect(510, 60, 101, 22));
        r3->setFont(font4);
        r3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r4 = new QRadioButton(horizontalGroupBox);
        r4->setObjectName("r4");
        r4->setGeometry(QRect(330, 100, 81, 22));
        r4->setFont(font4);
        r4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r5 = new QRadioButton(horizontalGroupBox);
        r5->setObjectName("r5");
        r5->setGeometry(QRect(420, 100, 81, 22));
        r5->setFont(font4);
        r5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r6 = new QRadioButton(horizontalGroupBox);
        r6->setObjectName("r6");
        r6->setGeometry(QRect(510, 100, 81, 22));
        r6->setFont(font4);
        r6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_18 = new QPushButton(horizontalGroupBox);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(320, 210, 80, 31));
        pushButton_18->setFont(font2);
        pushButton_18->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        label_3->raise();
        label_4->raise();
        label_6->raise();
        label_7->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        nom_input->raise();
        prenom_input->raise();
        modpass_input->raise();
        email_input->raise();
        label_9->raise();
        telephone_input->raise();
        label_12->raise();
        dateEdit->raise();
        label_10->raise();
        cin_input->raise();
        label_5->raise();
        r1->raise();
        r2->raise();
        r3->raise();
        r4->raise();
        r5->raise();
        r6->raise();
        pushButton_18->raise();
        tabWidget->addTab(widget, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "FullMark", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Equipement", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Examen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Institut", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Livreur", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Log-out", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Recherche d'equipement avec son cin :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        searchbutt->setText(QString());
        deletebutt->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Prenom:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Modpass:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Telephone:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Date d'embauche:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Role :", nullptr));
        r1->setText(QCoreApplication::translate("MainWindow", "Livreur", nullptr));
        r2->setText(QCoreApplication::translate("MainWindow", "Institut", nullptr));
        r3->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        r4->setText(QCoreApplication::translate("MainWindow", "R.equip", nullptr));
        r5->setText(QCoreApplication::translate("MainWindow", "R.examen", nullptr));
        r6->setText(QCoreApplication::translate("MainWindow", "R.Box", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Ajouter Employ\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionalit\303\251s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
