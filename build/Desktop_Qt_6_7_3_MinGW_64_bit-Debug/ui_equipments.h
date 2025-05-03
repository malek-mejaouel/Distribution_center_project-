/********************************************************************************
** Form generated from reading UI file 'equipments.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTS_H
#define UI_EQUIPMENTS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equipments
{
public:
    QWidget *verticalWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_17;
    QLabel *label_8;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QLineEdit *recherche;
    QLabel *label_9;
    QComboBox *tri;
    QPushButton *b10;
    QPushButton *b7;
    QPushButton *b4;
    QTableWidget *tab1;
    QPushButton *b12;
    QPushButton *b13;
    QWidget *tab_6;
    QWidget *widget_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *labelllll;
    QLabel *label_15;
    QLineEdit *nom_input;
    QLineEdit *quantite_input;
    QLineEdit *marque_input;
    QPushButton *b3;
    QPushButton *b1;
    QDateEdit *dateEdit;
    QLabel *label_16;
    QLineEdit *type_input;
    QLabel *label_17;
    QLineEdit *prix_input;
    QPushButton *b2;
    QWidget *tab_7;
    QChartView *chartViewFunctionalites;
    QWidget *tab_8;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *Equipments)
    {
        if (Equipments->objectName().isEmpty())
            Equipments->setObjectName("Equipments");
        Equipments->resize(912, 587);
        verticalWidget = new QWidget(Equipments);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(0, -20, 211, 671));
        verticalWidget->setStyleSheet(QString::fromUtf8(" background: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #e3f2fd,   /* very light blue */\n"
"        stop: 0.5 #90caf9, /* soft sky blue */\n"
"        stop: 1 #1565c0    /* deep blue */\n"
"    );"));
        pushButton = new QPushButton(verticalWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 130, 121, 51));
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 190, 121, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 250, 121, 51));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        pushButton_10->setIcon(icon1);
        pushButton_13 = new QPushButton(verticalWidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(40, 490, 121, 51));
        pushButton_13->setFont(font);
        pushButton_13->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon5);
        pushButton_17 = new QPushButton(verticalWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 550, 121, 41));
        pushButton_17->setFont(font);
        pushButton_17->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/Ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_17->setIcon(icon6);
        label_8 = new QLabel(verticalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, -10, 201, 191));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        tabWidget = new QTabWidget(Equipments);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(210, 0, 711, 611));
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"font: 700 10pt \"Segoe UI\";\n"
"\n"
" "));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        recherche = new QLineEdit(tab_5);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(30, 60, 236, 41));
        recherche->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(190, 70, 61, 21));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        tri = new QComboBox(tab_5);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(290, 60, 226, 41));
        tri->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        b10 = new QPushButton(tab_5);
        b10->setObjectName("b10");
        b10->setGeometry(QRect(70, 470, 171, 41));
        b10->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Ressources/pdf-file-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b10->setIcon(icon7);
        b7 = new QPushButton(tab_5);
        b7->setObjectName("b7");
        b7->setGeometry(QRect(570, 440, 101, 31));
        b7->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Ressources/update-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b7->setIcon(icon8);
        b4 = new QPushButton(tab_5);
        b4->setObjectName("b4");
        b4->setGeometry(QRect(570, 500, 101, 31));
        b4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b4->setIcon(icon9);
        tab1 = new QTableWidget(tab_5);
        if (tab1->columnCount() < 6)
            tab1->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tab1->setObjectName("tab1");
        tab1->setGeometry(QRect(30, 140, 631, 251));
        tab1->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);\n"
"background-color: rgb(14, 0, 214);\n"
"background-color: rgb(179, 179, 179);\n"
"tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); \n"
"tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents); \n"
""));
        tab1->horizontalHeader()->setCascadingSectionResizes(false);
        tab1->horizontalHeader()->setMinimumSectionSize(45);
        tab1->horizontalHeader()->setDefaultSectionSize(160);
        tab1->horizontalHeader()->setHighlightSections(true);
        tab1->verticalHeader()->setCascadingSectionResizes(false);
        b12 = new QPushButton(tab_5);
        b12->setObjectName("b12");
        b12->setGeometry(QRect(550, 60, 51, 41));
        b12->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        b12->setIcon(icon10);
        b13 = new QPushButton(tab_5);
        b13->setObjectName("b13");
        b13->setGeometry(QRect(620, 60, 51, 41));
        b13->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        b13->setIcon(icon11);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        widget_3 = new QWidget(tab_6);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(40, 30, 641, 521));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_10 = new QLabel(widget_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 30, 101, 41));
        label_10->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(60, 90, 101, 41));
        label_11->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        labelllll = new QLabel(widget_3);
        labelllll->setObjectName("labelllll");
        labelllll->setGeometry(QRect(60, 210, 101, 41));
        labelllll->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_15 = new QLabel(widget_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(60, 270, 101, 41));
        label_15->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nom_input = new QLineEdit(widget_3);
        nom_input->setObjectName("nom_input");
        nom_input->setGeometry(QRect(170, 40, 271, 31));
        nom_input->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nom_input->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        quantite_input = new QLineEdit(widget_3);
        quantite_input->setObjectName("quantite_input");
        quantite_input->setGeometry(QRect(170, 90, 271, 31));
        quantite_input->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        quantite_input->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        marque_input = new QLineEdit(widget_3);
        marque_input->setObjectName("marque_input");
        marque_input->setGeometry(QRect(170, 210, 271, 31));
        marque_input->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        marque_input->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        b3 = new QPushButton(widget_3);
        b3->setObjectName("b3");
        b3->setGeometry(QRect(250, 450, 121, 31));
        b3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        b3->setIcon(icon8);
        b1 = new QPushButton(widget_3);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(60, 450, 121, 31));
        b1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/add-circle-outline-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b1->setIcon(icon12);
        dateEdit = new QDateEdit(widget_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(180, 150, 271, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(widget_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 150, 151, 41));
        label_16->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        type_input = new QLineEdit(widget_3);
        type_input->setObjectName("type_input");
        type_input->setGeometry(QRect(170, 270, 271, 31));
        type_input->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        type_input->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_17 = new QLabel(widget_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(60, 340, 101, 41));
        label_17->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        prix_input = new QLineEdit(widget_3);
        prix_input->setObjectName("prix_input");
        prix_input->setGeometry(QRect(170, 350, 271, 31));
        prix_input->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        prix_input->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        b2 = new QPushButton(widget_3);
        b2->setObjectName("b2");
        b2->setGeometry(QRect(460, 450, 121, 31));
        b2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon13(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        b2->setIcon(icon13);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        chartViewFunctionalites = new QChartView(tab_7);
        chartViewFunctionalites->setObjectName("chartViewFunctionalites");
        chartViewFunctionalites->setGeometry(QRect(20, 20, 661, 511));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        calendarWidget = new QCalendarWidget(tab_8);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 10, 681, 541));
        tabWidget->addTab(tab_8, QString());

        retranslateUi(Equipments);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Equipments);
    } // setupUi

    void retranslateUi(QDialog *Equipments)
    {
        Equipments->setWindowTitle(QCoreApplication::translate("Equipments", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Equipments", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Equipments", "Equipement", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Equipments", "Examen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Equipments", "Institut", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Equipments", "Livreur", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Equipments", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Equipments", "Settings", nullptr));
        pushButton_17->setText(QCoreApplication::translate("Equipments", "Log-out", nullptr));
        label_8->setText(QString());
        recherche->setText(QString());
        recherche->setPlaceholderText(QString());
        label_9->setText(QString());
        b10->setText(QCoreApplication::translate("Equipments", " Generate PDF File", nullptr));
        b7->setText(QCoreApplication::translate("Equipments", " Update", nullptr));
        b4->setText(QCoreApplication::translate("Equipments", " Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Equipments", "ID Equipement", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Equipments", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Equipments", "Maintenance date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Equipments", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Equipments", "Type of", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Equipments", "Price", nullptr));
#if QT_CONFIG(tooltip)
        b12->setToolTip(QCoreApplication::translate("Equipments", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b12->setWhatsThis(QCoreApplication::translate("Equipments", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b12->setText(QString());
#if QT_CONFIG(tooltip)
        b13->setToolTip(QCoreApplication::translate("Equipments", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b13->setWhatsThis(QCoreApplication::translate("Equipments", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Equipments", "Display All", nullptr));
        label_10->setText(QCoreApplication::translate("Equipments", "Name :", nullptr));
        label_11->setText(QCoreApplication::translate("Equipments", "Quantity :", nullptr));
        labelllll->setText(QCoreApplication::translate("Equipments", "Brand :", nullptr));
        label_15->setText(QCoreApplication::translate("Equipments", "Type :", nullptr));
        nom_input->setPlaceholderText(QString());
        quantite_input->setPlaceholderText(QString());
        marque_input->setPlaceholderText(QString());
        b3->setText(QCoreApplication::translate("Equipments", " Update", nullptr));
        b1->setText(QCoreApplication::translate("Equipments", "Add", nullptr));
        label_16->setText(QCoreApplication::translate("Equipments", "Maintenance date :", nullptr));
        type_input->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("Equipments", "Price :", nullptr));
        prix_input->setPlaceholderText(QString());
        b2->setText(QCoreApplication::translate("Equipments", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Equipments", "Update/Add New", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Equipments", "Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("Equipments", "Calendar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Equipments: public Ui_Equipments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTS_H
