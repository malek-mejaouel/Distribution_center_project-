/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *LeftMenu;
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
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *recherche;
    QLabel *label;
    QComboBox *comboFilterRole;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QTableWidget *tab1;
    QPushButton *b12;
    QPushButton *b13;
    QWidget *tab_2;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *Userset;
    QLineEdit *Passset;
    QLineEdit *Number;
    QWidget *widget_2;
    QRadioButton *r3;
    QRadioButton *r6;
    QRadioButton *r2;
    QRadioButton *r5;
    QRadioButton *r1;
    QRadioButton *r4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QTextBrowser *chatHistory;
    QLineEdit *messageEdit;
    QPushButton *sendBtn;
    QListWidget *listWidget;
    QWidget *page_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(917, 595);
        LeftMenu = new QWidget(Dialog);
        LeftMenu->setObjectName("LeftMenu");
        LeftMenu->setGeometry(QRect(-1, -1, 211, 601));
        verticalWidget = new QWidget(LeftMenu);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(0, -10, 211, 671));
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
        label_8->setGeometry(QRect(0, 30, 201, 111));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(209, -1, 711, 601));
        page = new QWidget();
        page->setObjectName("page");
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 711, 611));
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
        tab = new QWidget();
        tab->setObjectName("tab");
        recherche = new QLineEdit(tab);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(30, 60, 236, 41));
        recherche->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 70, 61, 21));
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        comboFilterRole = new QComboBox(tab);
        comboFilterRole->setObjectName("comboFilterRole");
        comboFilterRole->setGeometry(QRect(290, 60, 226, 41));
        comboFilterRole->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(70, 470, 171, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Ressources/pdf-file-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon7);
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(570, 440, 101, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Ressources/update-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon8);
        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(570, 500, 101, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon9);
        tab1 = new QTableWidget(tab);
        if (tab1->columnCount() < 5)
            tab1->setColumnCount(5);
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
        tab1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
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
        b12 = new QPushButton(tab);
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
        b13 = new QPushButton(tab);
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        widget = new QWidget(tab_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 30, 641, 521));
        widget->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 110, 101, 41));
        label_2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 180, 101, 41));
        label_3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 250, 101, 41));
        label_4->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 20, 201, 41));
        label_5->setStyleSheet(QString::fromUtf8("   color: #1E2350;\n"
"font: 9pt \"Segoe UI\";\n"
"font:  24pt ;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 10, 81, 61));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/user-profile-svgrepo-com.svg);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 320, 101, 41));
        label_7->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Userset = new QLineEdit(widget);
        Userset->setObjectName("Userset");
        Userset->setGeometry(QRect(180, 110, 271, 41));
        Userset->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Userset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Passset = new QLineEdit(widget);
        Passset->setObjectName("Passset");
        Passset->setGeometry(QRect(180, 180, 271, 41));
        Passset->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Passset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Number = new QLineEdit(widget);
        Number->setObjectName("Number");
        Number->setGeometry(QRect(180, 250, 271, 41));
        Number->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Number->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(180, 320, 391, 91));
        widget_2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r3 = new QRadioButton(widget_2);
        r3->setObjectName("r3");
        r3->setGeometry(QRect(260, 10, 121, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        font1.setItalic(false);
        r3->setFont(font1);
        r3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r6 = new QRadioButton(widget_2);
        r6->setObjectName("r6");
        r6->setGeometry(QRect(260, 50, 121, 31));
        r6->setFont(font1);
        r6->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r2 = new QRadioButton(widget_2);
        r2->setObjectName("r2");
        r2->setGeometry(QRect(120, 10, 121, 31));
        r2->setFont(font1);
        r2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r5 = new QRadioButton(widget_2);
        r5->setObjectName("r5");
        r5->setGeometry(QRect(120, 50, 121, 31));
        r5->setFont(font1);
        r5->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r1 = new QRadioButton(widget_2);
        r1->setObjectName("r1");
        r1->setGeometry(QRect(10, 10, 101, 31));
        r1->setFont(font1);
        r1->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r4 = new QRadioButton(widget_2);
        r4->setObjectName("r4");
        r4->setGeometry(QRect(10, 50, 101, 31));
        r4->setFont(font1);
        r4->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(360, 450, 121, 31));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        pushButton_11->setIcon(icon8);
        pushButton_12 = new QPushButton(widget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(170, 450, 121, 31));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/add-circle-outline-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_12->setIcon(icon12);
        widget_2->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        Userset->raise();
        Passset->raise();
        Number->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        chatHistory = new QTextBrowser(tab_5);
        chatHistory->setObjectName("chatHistory");
        chatHistory->setGeometry(QRect(25, 41, 461, 341));
        messageEdit = new QLineEdit(tab_5);
        messageEdit->setObjectName("messageEdit");
        messageEdit->setGeometry(QRect(100, 390, 311, 31));
        messageEdit->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        sendBtn = new QPushButton(tab_5);
        sendBtn->setObjectName("sendBtn");
        sendBtn->setGeometry(QRect(200, 430, 111, 41));
        sendBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        listWidget = new QListWidget(tab_5);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(530, 40, 161, 341));
        tabWidget->addTab(tab_5, QString());
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Equipment", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "Exam", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "Institute", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Dialog", "Delivery", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Dialog", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Dialog", "Settings", nullptr));
        pushButton_17->setText(QCoreApplication::translate("Dialog", "Log-out", nullptr));
        label_8->setText(QString());
        recherche->setText(QString());
        recherche->setPlaceholderText(QString());
        label->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("Dialog", " Generate PDF File", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", " Update", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", " Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dialog", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dialog", "Password", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dialog", "Phone Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dialog", "Role", nullptr));
#if QT_CONFIG(tooltip)
        b12->setToolTip(QCoreApplication::translate("Dialog", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b12->setWhatsThis(QCoreApplication::translate("Dialog", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b12->setText(QString());
#if QT_CONFIG(tooltip)
        b13->setToolTip(QCoreApplication::translate("Dialog", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b13->setWhatsThis(QCoreApplication::translate("Dialog", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dialog", "Display All", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Number", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "My Profile", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("Dialog", " Role", nullptr));
        Userset->setPlaceholderText(QString());
        Passset->setPlaceholderText(QString());
        Number->setPlaceholderText(QString());
        r3->setText(QCoreApplication::translate("Dialog", "Employee", nullptr));
        r6->setText(QCoreApplication::translate("Dialog", "R.Box", nullptr));
        r2->setText(QCoreApplication::translate("Dialog", "Institut", nullptr));
        r5->setText(QCoreApplication::translate("Dialog", "R.examen", nullptr));
        r1->setText(QCoreApplication::translate("Dialog", "Livreur", nullptr));
        r4->setText(QCoreApplication::translate("Dialog", "R.equip", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Dialog", " Update", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Dialog", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Dialog", "Update/Add New", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Dialog", "Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Dialog", "Charts", nullptr));
        sendBtn->setText(QCoreApplication::translate("Dialog", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Dialog", "Chatroom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
