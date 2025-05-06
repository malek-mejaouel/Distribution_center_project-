/********************************************************************************
** Form generated from reading UI file 'examens.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMENS_H
#define UI_EXAMENS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examens
{
public:
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
    QPushButton *addmyprofile;
    QWidget *tab_3;
    QWidget *tab_21;
    QWidget *tab_4;
    QWidget *page_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QLineEdit *lineEdit_8;
    QLabel *label_9;
    QComboBox *comboBoxTri_2;
    QPushButton *bt_pdf;
    QPushButton *pushButton_18;
    QTableView *tableView;
    QComboBox *comboBoxTri;
    QLabel *label_12;
    QLabel *label_14;
    QWidget *tab_6;
    QWidget *widget_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *labelllll;
    QLabel *label_13;
    QLabel *label_15;
    QLineEdit *nomExamenLineEdit;
    QLineEdit *matiereExamenLineEdit;
    QLineEdit *dureeExamenLimeEdit;
    QPushButton *updateButton;
    QPushButton *addButton;
    QDateEdit *dateExamenDateEdit;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_12;
    QSpinBox *nbcopiesSpinBox;
    QSpinBox *niveauSpinBox;
    QWidget *tab_8;
    QPushButton *bt_clear;
    QPushButton *bt_envoyer;
    QPushButton *generer_correction;
    QLineEdit *lineEdit_message;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *textEdit;
    QWidget *tab_7;
    QLabel *label_stat;
    QWidget *tab_22;
    QLineEdit *lineEdit_9;
    QPushButton *addButton_2;
    QLabel *label_5;
    QWidget *page_3;
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

    void setupUi(QDialog *examens)
    {
        if (examens->objectName().isEmpty())
            examens->setObjectName("examens");
        examens->resize(920, 599);
        stackedWidget = new QStackedWidget(examens);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(210, 0, 711, 601));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Ressources/pdf-file-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Ressources/update-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon1);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon2);
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        b12->setIcon(icon3);
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
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        b13->setIcon(icon4);
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
        Userset->setGeometry(QRect(170, 120, 271, 31));
        Userset->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Userset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Passset = new QLineEdit(widget);
        Passset->setObjectName("Passset");
        Passset->setGeometry(QRect(170, 190, 271, 31));
        Passset->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Passset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Number = new QLineEdit(widget);
        Number->setObjectName("Number");
        Number->setGeometry(QRect(170, 260, 271, 31));
        Number->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        Number->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(180, 320, 351, 91));
        widget_2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r3 = new QRadioButton(widget_2);
        r3->setObjectName("r3");
        r3->setGeometry(QRect(240, 10, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        r3->setFont(font);
        r3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r6 = new QRadioButton(widget_2);
        r6->setObjectName("r6");
        r6->setGeometry(QRect(240, 50, 101, 31));
        r6->setFont(font);
        r6->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r2 = new QRadioButton(widget_2);
        r2->setObjectName("r2");
        r2->setGeometry(QRect(120, 10, 101, 31));
        r2->setFont(font);
        r2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r5 = new QRadioButton(widget_2);
        r5->setObjectName("r5");
        r5->setGeometry(QRect(120, 50, 101, 31));
        r5->setFont(font);
        r5->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r1 = new QRadioButton(widget_2);
        r1->setObjectName("r1");
        r1->setGeometry(QRect(10, 10, 101, 31));
        r1->setFont(font);
        r1->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        r4 = new QRadioButton(widget_2);
        r4->setObjectName("r4");
        r4->setGeometry(QRect(10, 50, 101, 31));
        r4->setFont(font);
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
        pushButton_11->setIcon(icon1);
        addmyprofile = new QPushButton(widget);
        addmyprofile->setObjectName("addmyprofile");
        addmyprofile->setGeometry(QRect(170, 450, 121, 31));
        addmyprofile->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Ressources/add-circle-outline-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addmyprofile->setIcon(icon5);
        widget_2->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_6->raise();
        label_7->raise();
        Userset->raise();
        Passset->raise();
        Number->raise();
        pushButton_11->raise();
        addmyprofile->raise();
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_21 = new QWidget();
        tab_21->setObjectName("tab_21");
        tabWidget->addTab(tab_21, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        tabWidget_2 = new QTabWidget(page_2);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 711, 611));
        tabWidget_2->setMinimumSize(QSize(0, 611));
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
        lineEdit_8 = new QLineEdit(tab_5);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 100, 321, 41));
        lineEdit_8->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(270, 110, 61, 20));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        comboBoxTri_2 = new QComboBox(tab_5);
        comboBoxTri_2->addItem(QString());
        comboBoxTri_2->addItem(QString());
        comboBoxTri_2->addItem(QString());
        comboBoxTri_2->setObjectName("comboBoxTri_2");
        comboBoxTri_2->setGeometry(QRect(430, 100, 226, 41));
        comboBoxTri_2->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        bt_pdf = new QPushButton(tab_5);
        bt_pdf->setObjectName("bt_pdf");
        bt_pdf->setGeometry(QRect(300, 440, 171, 41));
        bt_pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        bt_pdf->setIcon(icon);
        pushButton_18 = new QPushButton(tab_5);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(500, 440, 161, 41));
        pushButton_18->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        pushButton_18->setIcon(icon2);
        tableView = new QTableView(tab_5);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 170, 641, 241));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBoxTri = new QComboBox(tab_5);
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->setObjectName("comboBoxTri");
        comboBoxTri->setGeometry(QRect(430, 40, 226, 41));
        comboBoxTri->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 40, 231, 41));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(340, 40, 111, 41));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        widget_3 = new QWidget(tab_6);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 10, 681, 521));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_10 = new QLabel(widget_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 100, 151, 41));
        label_10->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 160, 151, 41));
        label_11->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        labelllll = new QLabel(widget_3);
        labelllll->setObjectName("labelllll");
        labelllll->setGeometry(QRect(20, 280, 151, 41));
        labelllll->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(200, 20, 201, 41));
        label_13->setStyleSheet(QString::fromUtf8("   color: #1E2350;\n"
"font: 9pt \"Segoe UI\";\n"
"font:  24pt ;"));
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15 = new QLabel(widget_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 340, 151, 41));
        label_15->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nomExamenLineEdit = new QLineEdit(widget_3);
        nomExamenLineEdit->setObjectName("nomExamenLineEdit");
        nomExamenLineEdit->setGeometry(QRect(200, 110, 271, 31));
        nomExamenLineEdit->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nomExamenLineEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        matiereExamenLineEdit = new QLineEdit(widget_3);
        matiereExamenLineEdit->setObjectName("matiereExamenLineEdit");
        matiereExamenLineEdit->setGeometry(QRect(200, 170, 271, 31));
        matiereExamenLineEdit->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        matiereExamenLineEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        dureeExamenLimeEdit = new QLineEdit(widget_3);
        dureeExamenLimeEdit->setObjectName("dureeExamenLimeEdit");
        dureeExamenLimeEdit->setGeometry(QRect(200, 290, 271, 31));
        dureeExamenLimeEdit->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        dureeExamenLimeEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        updateButton = new QPushButton(widget_3);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(510, 380, 121, 41));
        updateButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        updateButton->setIcon(icon1);
        addButton = new QPushButton(widget_3);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(340, 440, 131, 41));
        addButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        addButton->setIcon(icon5);
        dateExamenDateEdit = new QDateEdit(widget_3);
        dateExamenDateEdit->setObjectName("dateExamenDateEdit");
        dateExamenDateEdit->setGeometry(QRect(200, 220, 271, 41));
        dateExamenDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(widget_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 220, 151, 41));
        label_16->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 400, 151, 41));
        label_17->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        pushButton_12 = new QPushButton(widget_3);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(510, 440, 121, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        pushButton_12->setIcon(icon6);
        nbcopiesSpinBox = new QSpinBox(widget_3);
        nbcopiesSpinBox->setObjectName("nbcopiesSpinBox");
        nbcopiesSpinBox->setGeometry(QRect(210, 350, 44, 29));
        niveauSpinBox = new QSpinBox(widget_3);
        niveauSpinBox->setObjectName("niveauSpinBox");
        niveauSpinBox->setGeometry(QRect(210, 400, 44, 29));
        tabWidget_2->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        bt_clear = new QPushButton(tab_8);
        bt_clear->setObjectName("bt_clear");
        bt_clear->setGeometry(QRect(520, 460, 131, 51));
        bt_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        bt_clear->setIcon(icon6);
        bt_envoyer = new QPushButton(tab_8);
        bt_envoyer->setObjectName("bt_envoyer");
        bt_envoyer->setGeometry(QRect(520, 390, 131, 51));
        bt_envoyer->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        bt_envoyer->setIcon(icon5);
        generer_correction = new QPushButton(tab_8);
        generer_correction->setObjectName("generer_correction");
        generer_correction->setGeometry(QRect(450, 40, 201, 41));
        generer_correction->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        generer_correction->setIcon(icon);
        lineEdit_message = new QLineEdit(tab_8);
        lineEdit_message->setObjectName("lineEdit_message");
        lineEdit_message->setGeometry(QRect(40, 390, 451, 51));
        lineEdit_message->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        lineEdit_message->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        scrollArea = new QScrollArea(tab_8);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 90, 611, 271));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 609, 269));
        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 0, 611, 271));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget_2->addTab(tab_8, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        label_stat = new QLabel(tab_7);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(40, 20, 641, 511));
        tabWidget_2->addTab(tab_7, QString());
        tab_22 = new QWidget();
        tab_22->setObjectName("tab_22");
        lineEdit_9 = new QLineEdit(tab_22);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(180, 240, 281, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        lineEdit_9->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        addButton_2 = new QPushButton(tab_22);
        addButton_2->setObjectName("addButton_2");
        addButton_2->setGeometry(QRect(240, 310, 171, 41));
        addButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        addButton_2->setIcon(icon5);
        label_5 = new QLabel(tab_22);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 140, 281, 71));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        tabWidget_2->addTab(tab_22, QString());
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        LeftMenu = new QWidget(examens);
        LeftMenu->setObjectName("LeftMenu");
        LeftMenu->setGeometry(QRect(0, 0, 211, 601));
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
        QFont font1;
        font1.setBold(true);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon7);
        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 190, 121, 51));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon8);
        pushButton_3 = new QPushButton(verticalWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 250, 121, 51));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon9);
        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 310, 121, 51));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/Ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon10);
        pushButton_9 = new QPushButton(verticalWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 370, 121, 51));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon11);
        pushButton_10 = new QPushButton(verticalWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 430, 121, 51));
        pushButton_10->setFont(font1);
        pushButton_10->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_10->setIcon(icon8);
        pushButton_13 = new QPushButton(verticalWidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(40, 490, 121, 51));
        pushButton_13->setFont(font1);
        pushButton_13->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon12);
        pushButton_17 = new QPushButton(verticalWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 550, 121, 41));
        pushButton_17->setFont(font1);
        pushButton_17->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/Ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_17->setIcon(icon13);
        label_8 = new QLabel(verticalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, -10, 201, 191));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));

        retranslateUi(examens);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(examens);
    } // setupUi

    void retranslateUi(QDialog *examens)
    {
        examens->setWindowTitle(QCoreApplication::translate("examens", "Dialog", nullptr));
        recherche->setText(QString());
        recherche->setPlaceholderText(QString());
        label->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("examens", " Generate PDF File", nullptr));
        pushButton_7->setText(QCoreApplication::translate("examens", " Update", nullptr));
        pushButton_8->setText(QCoreApplication::translate("examens", " Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("examens", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("examens", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("examens", "Password", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("examens", "Phone Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("examens", "Role", nullptr));
#if QT_CONFIG(tooltip)
        b12->setToolTip(QCoreApplication::translate("examens", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b12->setWhatsThis(QCoreApplication::translate("examens", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b12->setText(QString());
#if QT_CONFIG(tooltip)
        b13->setToolTip(QCoreApplication::translate("examens", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        b13->setWhatsThis(QCoreApplication::translate("examens", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        b13->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("examens", "Display All", nullptr));
        label_2->setText(QCoreApplication::translate("examens", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("examens", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("examens", "Number", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("examens", " Role", nullptr));
        Userset->setPlaceholderText(QString());
        Passset->setPlaceholderText(QString());
        Number->setPlaceholderText(QString());
        r3->setText(QCoreApplication::translate("examens", "Employee", nullptr));
        r6->setText(QCoreApplication::translate("examens", "R.Box", nullptr));
        r2->setText(QCoreApplication::translate("examens", "Institut", nullptr));
        r5->setText(QCoreApplication::translate("examens", "R.examen", nullptr));
        r1->setText(QCoreApplication::translate("examens", "Livreur", nullptr));
        r4->setText(QCoreApplication::translate("examens", "R.equip", nullptr));
        pushButton_11->setText(QCoreApplication::translate("examens", " Update", nullptr));
        addmyprofile->setText(QCoreApplication::translate("examens", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("examens", "Update/Add New", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("examens", "Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_21), QCoreApplication::translate("examens", "Arduino", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("examens", "Charts", nullptr));
        lineEdit_8->setText(QString());
        lineEdit_8->setPlaceholderText(QString());
        label_9->setText(QString());
        comboBoxTri_2->setItemText(0, QCoreApplication::translate("examens", "Selectionner Ordre", nullptr));
        comboBoxTri_2->setItemText(1, QCoreApplication::translate("examens", "ASC", nullptr));
        comboBoxTri_2->setItemText(2, QCoreApplication::translate("examens", "DESC", nullptr));

        bt_pdf->setText(QCoreApplication::translate("examens", " Generate PDF File", nullptr));
        pushButton_18->setText(QCoreApplication::translate("examens", " Delete", nullptr));
        comboBoxTri->setItemText(0, QCoreApplication::translate("examens", "niveau", nullptr));
        comboBoxTri->setItemText(1, QCoreApplication::translate("examens", "mati\303\250re", nullptr));
        comboBoxTri->setItemText(2, QCoreApplication::translate("examens", "date", nullptr));

        label_12->setText(QCoreApplication::translate("examens", "Search Exam ", nullptr));
        label_14->setText(QCoreApplication::translate("examens", "Sort By ", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("examens", "Display All", nullptr));
        label_10->setText(QCoreApplication::translate("examens", "Exam Name", nullptr));
        label_11->setText(QCoreApplication::translate("examens", "Exam Subject", nullptr));
        labelllll->setText(QCoreApplication::translate("examens", "Exam Duration", nullptr));
        label_13->setText(QCoreApplication::translate("examens", "EXAM", nullptr));
        label_15->setText(QCoreApplication::translate("examens", "Copie Number", nullptr));
        nomExamenLineEdit->setPlaceholderText(QString());
        matiereExamenLineEdit->setPlaceholderText(QString());
        dureeExamenLimeEdit->setPlaceholderText(QString());
        updateButton->setText(QCoreApplication::translate("examens", " Update", nullptr));
        addButton->setText(QCoreApplication::translate("examens", "Add", nullptr));
        label_16->setText(QCoreApplication::translate("examens", "Exam Date", nullptr));
        label_17->setText(QCoreApplication::translate("examens", "Level", nullptr));
        pushButton_12->setText(QCoreApplication::translate("examens", "Cancel", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("examens", "Update/Add New", nullptr));
        bt_clear->setText(QCoreApplication::translate("examens", "Clear", nullptr));
        bt_envoyer->setText(QCoreApplication::translate("examens", "send ", nullptr));
        generer_correction->setText(QCoreApplication::translate("examens", "Generate Correction", nullptr));
        lineEdit_message->setPlaceholderText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("examens", "Chat", nullptr));
        label_stat->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("examens", "Statistics", nullptr));
        lineEdit_9->setPlaceholderText(QString());
        addButton_2->setText(QCoreApplication::translate("examens", "Check ID", nullptr));
        label_5->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_22), QCoreApplication::translate("examens", "Arduino", nullptr));
        pushButton->setText(QCoreApplication::translate("examens", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("examens", "Equipement", nullptr));
        pushButton_3->setText(QCoreApplication::translate("examens", "Examen", nullptr));
        pushButton_4->setText(QCoreApplication::translate("examens", "Institut", nullptr));
        pushButton_9->setText(QCoreApplication::translate("examens", "Livreur", nullptr));
        pushButton_10->setText(QCoreApplication::translate("examens", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("examens", "Settings", nullptr));
        pushButton_17->setText(QCoreApplication::translate("examens", "Log-out", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class examens: public Ui_examens {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMENS_H
