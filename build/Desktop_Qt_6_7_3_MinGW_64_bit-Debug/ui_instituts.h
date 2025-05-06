/********************************************************************************
** Form generated from reading UI file 'instituts.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTITUTS_H
#define UI_INSTITUTS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_instituts
{
public:
    QWidget *LeftMenu;
    QWidget *verticalWidget_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QPushButton *pushButton_18;
    QLabel *label_12;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QLabel *label_13;
    QComboBox *tri_in;
    QPushButton *pdf_in;
    QPushButton *b4_in;
    QTableWidget *tab1_in;
    QPushButton *DESC_in;
    QPushButton *ASC_in;
    QLineEdit *recherche_in;
    QLabel *label_23;
    QWidget *tab_6;
    QWidget *widget_2;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_56;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *nomInst_input_in;
    QLineEdit *adresseInst_input_in;
    QLineEdit *emailInst_input_in;
    QPushButton *b2_in;
    QPushButton *b1_in;
    QLineEdit *responsableInst_input_in;
    QLineEdit *telephoneInst_input_in;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *capaciteInst_input_in;
    QLabel *label_21;
    QLineEdit *employee_in;
    QPushButton *b3_in;
    QWidget *tab_7;
    QChartView *chartViewFunctionalites_2;
    QWidget *tab_8;
    QPushButton *map_in;
    QWidget *notificationwidget_2;
    QLineEdit *notifylineedit_in;
    QPushButton *noti_in;
    QPushButton *addButton_in;
    QLineEdit *lineEdit_in;
    QLineEdit *label_in;
    QWidget *page_4;

    void setupUi(QDialog *instituts)
    {
        if (instituts->objectName().isEmpty())
            instituts->setObjectName("instituts");
        instituts->resize(912, 585);
        LeftMenu = new QWidget(instituts);
        LeftMenu->setObjectName("LeftMenu");
        LeftMenu->setGeometry(QRect(0, 0, 211, 601));
        verticalWidget_2 = new QWidget(LeftMenu);
        verticalWidget_2->setObjectName("verticalWidget_2");
        verticalWidget_2->setGeometry(QRect(0, -40, 211, 671));
        verticalWidget_2->setStyleSheet(QString::fromUtf8(" background: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #e3f2fd,   /* very light blue */\n"
"        stop: 0.5 #90caf9, /* soft sky blue */\n"
"        stop: 1 #1565c0    /* deep blue */\n"
"    );"));
        pushButton_6 = new QPushButton(verticalWidget_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 190, 121, 51));
        QFont font;
        font.setBold(true);
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon);
        pushButton_7 = new QPushButton(verticalWidget_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 250, 121, 51));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon1);
        pushButton_8 = new QPushButton(verticalWidget_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 310, 121, 51));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon2);
        pushButton_11 = new QPushButton(verticalWidget_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(40, 370, 121, 51));
        pushButton_11->setFont(font);
        pushButton_11->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_11->setIcon(icon3);
        pushButton_12 = new QPushButton(verticalWidget_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(40, 430, 121, 51));
        pushButton_12->setFont(font);
        pushButton_12->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_12->setIcon(icon4);
        pushButton_14 = new QPushButton(verticalWidget_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(40, 490, 121, 51));
        pushButton_14->setFont(font);
        pushButton_14->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon5.addFile(QString::fromUtf8(":/ressources/settings.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_14->setIcon(icon5);
        pushButton_18 = new QPushButton(verticalWidget_2);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(40, 550, 121, 41));
        pushButton_18->setFont(font);
        pushButton_18->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/Ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_18->setIcon(icon6);
        label_12 = new QLabel(verticalWidget_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 40, 201, 91));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        pushButton = new QPushButton(verticalWidget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 130, 121, 51));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon7);
        stackedWidget = new QStackedWidget(instituts);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(210, 0, 711, 601));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tabWidget_2 = new QTabWidget(page_3);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(-10, -10, 711, 611));
        tabWidget_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget_2->setAutoFillBackground(true);
        tabWidget_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 8pt \"Segoe UI\";\n"
"font: 700 10pt \"Segoe UI\";\n"
"\n"
" "));
        tabWidget_2->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget_2->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget_2->setElideMode(Qt::TextElideMode::ElideNone);
        tabWidget_2->setMovable(false);
        tabWidget_2->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        label_13 = new QLabel(tab_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(190, 70, 61, 21));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        tri_in = new QComboBox(tab_5);
        tri_in->setObjectName("tri_in");
        tri_in->setGeometry(QRect(290, 60, 226, 41));
        tri_in->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        pdf_in = new QPushButton(tab_5);
        pdf_in->setObjectName("pdf_in");
        pdf_in->setGeometry(QRect(70, 470, 171, 41));
        pdf_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Ressources/pdf-file-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf_in->setIcon(icon8);
        b4_in = new QPushButton(tab_5);
        b4_in->setObjectName("b4_in");
        b4_in->setGeometry(QRect(490, 470, 101, 31));
        b4_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b4_in->setIcon(icon9);
        tab1_in = new QTableWidget(tab_5);
        if (tab1_in->columnCount() < 8)
            tab1_in->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setBackground(QColor(85, 170, 255));
        tab1_in->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tab1_in->setObjectName("tab1_in");
        tab1_in->setGeometry(QRect(30, 140, 991, 251));
        tab1_in->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);\n"
"background-color: rgb(14, 0, 214);\n"
"background-color: rgb(179, 179, 179);\n"
"tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); \n"
"tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents); \n"
""));
        tab1_in->horizontalHeader()->setCascadingSectionResizes(false);
        tab1_in->horizontalHeader()->setMinimumSectionSize(45);
        tab1_in->horizontalHeader()->setDefaultSectionSize(160);
        tab1_in->horizontalHeader()->setHighlightSections(true);
        tab1_in->verticalHeader()->setCascadingSectionResizes(false);
        DESC_in = new QPushButton(tab_5);
        DESC_in->setObjectName("DESC_in");
        DESC_in->setGeometry(QRect(550, 60, 51, 41));
        DESC_in->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        DESC_in->setIcon(icon10);
        ASC_in = new QPushButton(tab_5);
        ASC_in->setObjectName("ASC_in");
        ASC_in->setGeometry(QRect(620, 60, 51, 41));
        ASC_in->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        ASC_in->setIcon(icon11);
        recherche_in = new QLineEdit(tab_5);
        recherche_in->setObjectName("recherche_in");
        recherche_in->setGeometry(QRect(30, 60, 236, 41));
        recherche_in->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(190, 70, 61, 21));
        label_23->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        widget_2 = new QWidget(tab_6);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 0, 711, 571));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 90, 101, 41));
        label_14->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(60, 150, 101, 41));
        label_15->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(60, 210, 101, 41));
        label_16->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_56 = new QLabel(widget_2);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(200, 20, 201, 41));
        label_56->setStyleSheet(QString::fromUtf8("   color: #1E2350;\n"
"font: 9pt \"Segoe UI\";\n"
"font:  24pt ;"));
        label_56->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_17 = new QLabel(widget_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 10, 81, 61));
        label_17->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/user-profile-svgrepo-com.svg);"));
        label_18 = new QLabel(widget_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(60, 270, 101, 41));
        label_18->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nomInst_input_in = new QLineEdit(widget_2);
        nomInst_input_in->setObjectName("nomInst_input_in");
        nomInst_input_in->setGeometry(QRect(170, 90, 271, 31));
        nomInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nomInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        adresseInst_input_in = new QLineEdit(widget_2);
        adresseInst_input_in->setObjectName("adresseInst_input_in");
        adresseInst_input_in->setGeometry(QRect(170, 150, 271, 31));
        adresseInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        adresseInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        emailInst_input_in = new QLineEdit(widget_2);
        emailInst_input_in->setObjectName("emailInst_input_in");
        emailInst_input_in->setGeometry(QRect(170, 210, 271, 31));
        emailInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        emailInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        b2_in = new QPushButton(widget_2);
        b2_in->setObjectName("b2_in");
        b2_in->setGeometry(QRect(60, 500, 121, 31));
        b2_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/update-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b2_in->setIcon(icon12);
        b1_in = new QPushButton(widget_2);
        b1_in->setObjectName("b1_in");
        b1_in->setGeometry(QRect(210, 500, 121, 31));
        b1_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/Ressources/add-circle-outline-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        b1_in->setIcon(icon13);
        responsableInst_input_in = new QLineEdit(widget_2);
        responsableInst_input_in->setObjectName("responsableInst_input_in");
        responsableInst_input_in->setGeometry(QRect(170, 330, 271, 31));
        responsableInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        responsableInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        telephoneInst_input_in = new QLineEdit(widget_2);
        telephoneInst_input_in->setObjectName("telephoneInst_input_in");
        telephoneInst_input_in->setGeometry(QRect(170, 270, 271, 31));
        telephoneInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        telephoneInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_19 = new QLabel(widget_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(60, 330, 101, 41));
        label_19->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_20 = new QLabel(widget_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(60, 390, 101, 41));
        label_20->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        capaciteInst_input_in = new QLineEdit(widget_2);
        capaciteInst_input_in->setObjectName("capaciteInst_input_in");
        capaciteInst_input_in->setGeometry(QRect(170, 390, 271, 31));
        capaciteInst_input_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        capaciteInst_input_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_21 = new QLabel(widget_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(60, 450, 101, 41));
        label_21->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        employee_in = new QLineEdit(widget_2);
        employee_in->setObjectName("employee_in");
        employee_in->setGeometry(QRect(170, 450, 271, 31));
        employee_in->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        employee_in->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        b3_in = new QPushButton(widget_2);
        b3_in->setObjectName("b3_in");
        b3_in->setGeometry(QRect(370, 500, 101, 31));
        b3_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        b3_in->setIcon(icon12);
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        chartViewFunctionalites_2 = new QChartView(tab_7);
        chartViewFunctionalites_2->setObjectName("chartViewFunctionalites_2");
        chartViewFunctionalites_2->setGeometry(QRect(10, 10, 621, 521));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        map_in = new QPushButton(tab_8);
        map_in->setObjectName("map_in");
        map_in->setGeometry(QRect(70, 460, 121, 31));
        map_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/Ressources/location-marker-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        map_in->setIcon(icon14);
        notificationwidget_2 = new QWidget(tab_8);
        notificationwidget_2->setObjectName("notificationwidget_2");
        notificationwidget_2->setGeometry(QRect(80, 60, 381, 181));
        notifylineedit_in = new QLineEdit(notificationwidget_2);
        notifylineedit_in->setObjectName("notifylineedit_in");
        notifylineedit_in->setGeometry(QRect(110, 20, 141, 31));
        notifylineedit_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        noti_in = new QPushButton(notificationwidget_2);
        noti_in->setObjectName("noti_in");
        noti_in->setGeometry(QRect(110, 80, 141, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        font1.setItalic(false);
        noti_in->setFont(font1);
        noti_in->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/Ressources/notification-bell-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        noti_in->setIcon(icon15);
        noti_in->setIconSize(QSize(20, 20));
        addButton_in = new QPushButton(tab_8);
        addButton_in->setObjectName("addButton_in");
        addButton_in->setGeometry(QRect(220, 370, 91, 31));
        addButton_in->setFont(font1);
        addButton_in->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon16(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        addButton_in->setIcon(icon16);
        addButton_in->setIconSize(QSize(13, 13));
        lineEdit_in = new QLineEdit(tab_8);
        lineEdit_in->setObjectName("lineEdit_in");
        lineEdit_in->setGeometry(QRect(210, 280, 113, 28));
        label_in = new QLineEdit(tab_8);
        label_in->setObjectName("label_in");
        label_in->setGeometry(QRect(210, 330, 121, 31));
        tabWidget_2->addTab(tab_8, QString());
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);

        retranslateUi(instituts);

        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(instituts);
    } // setupUi

    void retranslateUi(QDialog *instituts)
    {
        instituts->setWindowTitle(QCoreApplication::translate("instituts", "Dialog", nullptr));
        pushButton_6->setText(QCoreApplication::translate("instituts", "Equipments", nullptr));
        pushButton_7->setText(QCoreApplication::translate("instituts", "Exam", nullptr));
        pushButton_8->setText(QCoreApplication::translate("instituts", "Institut", nullptr));
        pushButton_11->setText(QCoreApplication::translate("instituts", "Delivery", nullptr));
        pushButton_12->setText(QCoreApplication::translate("instituts", "Box", nullptr));
        pushButton_14->setText(QCoreApplication::translate("instituts", "Settings", nullptr));
        pushButton_18->setText(QCoreApplication::translate("instituts", "Log-out", nullptr));
        label_12->setText(QString());
        pushButton->setText(QCoreApplication::translate("instituts", "Employee", nullptr));
        label_13->setText(QString());
        pdf_in->setText(QCoreApplication::translate("instituts", " Generate PDF File", nullptr));
        b4_in->setText(QCoreApplication::translate("instituts", " Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1_in->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("instituts", "ID Institut", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1_in->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("instituts", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1_in->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("instituts", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1_in->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("instituts", "Supervisor", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1_in->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("instituts", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1_in->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("instituts", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab1_in->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("instituts", "Capacite", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab1_in->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("instituts", "ID Employee", nullptr));
#if QT_CONFIG(tooltip)
        DESC_in->setToolTip(QCoreApplication::translate("instituts", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        DESC_in->setWhatsThis(QCoreApplication::translate("instituts", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        DESC_in->setText(QString());
#if QT_CONFIG(tooltip)
        ASC_in->setToolTip(QCoreApplication::translate("instituts", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        ASC_in->setWhatsThis(QCoreApplication::translate("instituts", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        ASC_in->setText(QString());
        recherche_in->setText(QString());
        recherche_in->setPlaceholderText(QString());
        label_23->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("instituts", "Display All", nullptr));
        label_14->setText(QCoreApplication::translate("instituts", "Name", nullptr));
        label_15->setText(QCoreApplication::translate("instituts", "Adress", nullptr));
        label_16->setText(QCoreApplication::translate("instituts", "Email", nullptr));
        label_56->setText(QCoreApplication::translate("instituts", "Institut", nullptr));
        label_17->setText(QString());
        label_18->setText(QCoreApplication::translate("instituts", "Phone", nullptr));
        nomInst_input_in->setPlaceholderText(QString());
        adresseInst_input_in->setPlaceholderText(QString());
        emailInst_input_in->setPlaceholderText(QString());
        b2_in->setText(QCoreApplication::translate("instituts", "Cancel", nullptr));
        b1_in->setText(QCoreApplication::translate("instituts", "Add", nullptr));
        responsableInst_input_in->setPlaceholderText(QString());
        telephoneInst_input_in->setPlaceholderText(QString());
        label_19->setText(QCoreApplication::translate("instituts", "Chief", nullptr));
        label_20->setText(QCoreApplication::translate("instituts", "Capacity", nullptr));
        capaciteInst_input_in->setPlaceholderText(QString());
        label_21->setText(QCoreApplication::translate("instituts", "Employee", nullptr));
        employee_in->setPlaceholderText(QString());
        b3_in->setText(QCoreApplication::translate("instituts", "modify", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("instituts", "Update/Add New", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("instituts", "Statistics", nullptr));
        map_in->setText(QCoreApplication::translate("instituts", "MAP", nullptr));
        noti_in->setText(QCoreApplication::translate("instituts", "Notification", nullptr));
        addButton_in->setText(QCoreApplication::translate("instituts", "arduino", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("instituts", "Charts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instituts: public Ui_instituts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTITUTS_H
