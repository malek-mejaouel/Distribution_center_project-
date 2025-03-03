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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QLineEdit *lineEdit_8;
    QLabel *label_8;
    QTableWidget *tableWidget;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_5;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGroupBox *horizontalGroupBox;
    QLabel *label_3;
    QLineEdit *cin;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *nom;
    QLineEdit *tel;
    QLineEdit *email;
    QPushButton *b1;
    QPushButton *modifier;
    QLabel *label_2;
    QLineEdit *vehicule;
    QLabel *label_10;
    QLabel *label_12;
    QRadioButton *libre;
    QRadioButton *non;
    QSpinBox *nb;
    QLabel *label_5;
    QLineEdit *prenom;
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
"background-color: rgb(175, 175, 175);\n"
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
        tableWidget = new QTableWidget(horizontalWidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        __qtablewidgetitem->setBackground(QColor(9, 20, 81));
        __qtablewidgetitem->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(0, 0, 106));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(10, 21, 91));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(10, 21, 91));
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setBackground(QColor(10, 21, 91));
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(10, 21, 91));
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setBackground(QColor(0, 0, 107));
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setBackground(QColor(0, 0, 90));
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 60, 581, 211));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);\n"
"background-color: rgb(14, 0, 214);\n"
"background-color: rgb(179, 179, 179);"));
        label_11 = new QLabel(horizontalWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(370, 30, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 30, 141, 24));
        pushButton_14 = new QPushButton(horizontalWidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(40, 310, 81, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font2.setBold(true);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ressources/search-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon8);
        pushButton_18 = new QPushButton(horizontalWidget);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(500, 210, 80, 31));
        pushButton_18->setFont(font2);
        pushButton_18->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_19 = new QPushButton(horizontalWidget);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(410, 210, 80, 31));
        pushButton_19->setFont(font2);
        pushButton_19->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
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
        horizontalGroupBox->setGeometry(QRect(-20, -10, 621, 291));
        horizontalGroupBox->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        horizontalGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170);"));
        label_3 = new QLabel(horizontalGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 20, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        cin = new QLineEdit(horizontalGroupBox);
        cin->setObjectName("cin");
        cin->setGeometry(QRect(160, 20, 141, 16));
        cin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(horizontalGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 40, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_6 = new QLabel(horizontalGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 100, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_7 = new QLabel(horizontalGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 160, 81, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        nom = new QLineEdit(horizontalGroupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(160, 50, 141, 16));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tel = new QLineEdit(horizontalGroupBox);
        tel->setObjectName("tel");
        tel->setGeometry(QRect(160, 110, 141, 16));
        tel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        email = new QLineEdit(horizontalGroupBox);
        email->setObjectName("email");
        email->setGeometry(QRect(160, 140, 141, 16));
        email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        b1 = new QPushButton(horizontalGroupBox);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(390, 210, 80, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font3.setBold(true);
        font3.setItalic(true);
        b1->setFont(font3);
        b1->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        modifier = new QPushButton(horizontalGroupBox);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(490, 210, 80, 31));
        modifier->setFont(font2);
        modifier->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        label_2 = new QLabel(horizontalGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 190, 101, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        vehicule = new QLineEdit(horizontalGroupBox);
        vehicule->setObjectName("vehicule");
        vehicule->setGeometry(QRect(160, 160, 141, 16));
        vehicule->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(horizontalGroupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 210, 91, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_12 = new QLabel(horizontalGroupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 130, 81, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        libre = new QRadioButton(horizontalGroupBox);
        libre->setObjectName("libre");
        libre->setGeometry(QRect(150, 210, 110, 24));
        libre->setStyleSheet(QString::fromUtf8("font: 9pt \"Sitka\";"));
        non = new QRadioButton(horizontalGroupBox);
        non->setObjectName("non");
        non->setGeometry(QRect(240, 210, 110, 24));
        non->setStyleSheet(QString::fromUtf8("font: 9pt \"Sitka\";"));
        nb = new QSpinBox(horizontalGroupBox);
        nb->setObjectName("nb");
        nb->setGeometry(QRect(160, 180, 42, 26));
        label_5 = new QLabel(horizontalGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 70, 101, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        prenom = new QLineEdit(horizontalGroupBox);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(160, 80, 141, 16));
        prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3->raise();
        label_4->raise();
        label_6->raise();
        label_7->raise();
        b1->raise();
        modifier->raise();
        cin->raise();
        nom->raise();
        tel->raise();
        email->raise();
        label_2->raise();
        vehicule->raise();
        label_10->raise();
        label_12->raise();
        libre->raise();
        non->raise();
        nb->raise();
        label_5->raise();
        prenom->raise();
        tabWidget->addTab(widget, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Param\303\250tres", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "D\303\251connect\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Recherche d'un livreur par son nom :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "IdLivreur", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "CinLivreur", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "NomLivreur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "PrenomLivreur", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "V\303\251hicule", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Nbmax_debox", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "EtatLivreur", nullptr));
#if QT_CONFIG(tooltip)
        tableWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>background-color:rgb(10, 21, 91)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tableWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_11->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Nb max de box", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "IdLivreur", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "NomLivreur", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "EtatLivreur", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "CinLivreur", nullptr));
        comboBox->setItemText(5, QString());

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_5->setText(QString());
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CinLivreur", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "NomLivreur", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "V\303\251hicule", nullptr));
        b1->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nb max de box", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "EtatLivreur", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        libre->setText(QCoreApplication::translate("MainWindow", "Libre", nullptr));
        non->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "PrenomLivreur", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Ajouter un livreur", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionalit\303\251s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
