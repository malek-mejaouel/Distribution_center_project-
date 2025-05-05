/********************************************************************************
** Form generated from reading UI file 'livreurs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVREURS_H
#define UI_LIVREURS_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_livreurs
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QLineEdit *rech;
    QLabel *label_9;
    QComboBox *trie;
    QPushButton *pdfButton;
    QTableWidget *tab1;
    QPushButton *DescButton;
    QPushButton *AscButton;
    QPushButton *stateButton;
    QWidget *tab_6;
    QWidget *widget_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *labelllll;
    QLabel *label_13;
    QLabel *label_15;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *email;
    QPushButton *modifier;
    QPushButton *valider;
    QLabel *label_16;
    QLineEdit *vehicule;
    QLabel *label_17;
    QPushButton *annuler;
    QLineEdit *tel;
    QLabel *label_12;
    QLineEdit *cin;
    QLabel *label_18;
    QSpinBox *nb;
    QRadioButton *libre;
    QRadioButton *non;
    QLineEdit *imagePath;
    QPushButton *imageButton;
    QPushButton *supprimer;
    QWidget *tab_7;
    QChartView *chartView;
    QWidget *tab;
    QWidget *tab_8;
    QPushButton *historiqueButton;
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

    void setupUi(QDialog *livreurs)
    {
        if (livreurs->objectName().isEmpty())
            livreurs->setObjectName("livreurs");
        livreurs->resize(994, 668);
        tabWidget = new QTabWidget(livreurs);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(210, 0, 791, 761));
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
        rech = new QLineEdit(tab_5);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(30, 60, 236, 41));
        rech->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(190, 70, 71, 21));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        trie = new QComboBox(tab_5);
        trie->setObjectName("trie");
        trie->setGeometry(QRect(290, 60, 226, 41));
        trie->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        pdfButton = new QPushButton(tab_5);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(30, 490, 191, 41));
        pdfButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Ressources/pdf-file-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfButton->setIcon(icon);
        tab1 = new QTableWidget(tab_5);
        if (tab1->columnCount() < 9)
            tab1->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setBackground(QColor(85, 170, 255));
        tab1->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tab1->setObjectName("tab1");
        tab1->setGeometry(QRect(0, 140, 711, 291));
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
        DescButton = new QPushButton(tab_5);
        DescButton->setObjectName("DescButton");
        DescButton->setGeometry(QRect(550, 60, 51, 41));
        DescButton->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        DescButton->setIcon(icon1);
        AscButton = new QPushButton(tab_5);
        AscButton->setObjectName("AscButton");
        AscButton->setGeometry(QRect(620, 60, 51, 41));
        AscButton->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        AscButton->setIcon(icon2);
        stateButton = new QPushButton(tab_5);
        stateButton->setObjectName("stateButton");
        stateButton->setGeometry(QRect(570, 510, 111, 31));
        stateButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeLow));
        stateButton->setIcon(icon3);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        widget_3 = new QWidget(tab_6);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 801, 651));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_10 = new QLabel(widget_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 120, 121, 41));
        label_10->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 170, 121, 41));
        label_11->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        labelllll = new QLabel(widget_3);
        labelllll->setObjectName("labelllll");
        labelllll->setGeometry(QRect(30, 270, 121, 41));
        labelllll->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(210, 10, 191, 41));
        label_13->setStyleSheet(QString::fromUtf8("   color: #1E2350;\n"
"font: 9pt \"Segoe UI\";\n"
"font:  24pt ;"));
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15 = new QLabel(widget_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 320, 121, 41));
        label_15->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nom = new QLineEdit(widget_3);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(160, 120, 271, 41));
        nom->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nom->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        prenom = new QLineEdit(widget_3);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(160, 170, 271, 41));
        prenom->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        prenom->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        email = new QLineEdit(widget_3);
        email->setObjectName("email");
        email->setGeometry(QRect(160, 270, 271, 41));
        email->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        email->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        modifier = new QPushButton(widget_3);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(230, 520, 121, 31));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Ressources/update-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modifier->setIcon(icon4);
        valider = new QPushButton(widget_3);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(50, 520, 121, 31));
        valider->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Ressources/add-circle-outline-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        valider->setIcon(icon5);
        label_16 = new QLabel(widget_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 220, 121, 41));
        label_16->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        vehicule = new QLineEdit(widget_3);
        vehicule->setObjectName("vehicule");
        vehicule->setGeometry(QRect(160, 320, 271, 41));
        vehicule->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        vehicule->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_17 = new QLabel(widget_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 420, 121, 41));
        label_17->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        annuler = new QPushButton(widget_3);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(410, 520, 121, 31));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        annuler->setIcon(icon6);
        tel = new QLineEdit(widget_3);
        tel->setObjectName("tel");
        tel->setGeometry(QRect(160, 220, 271, 41));
        tel->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        tel->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_12 = new QLabel(widget_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 70, 121, 41));
        label_12->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        cin = new QLineEdit(widget_3);
        cin->setObjectName("cin");
        cin->setGeometry(QRect(160, 70, 271, 41));
        cin->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        cin->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_18 = new QLabel(widget_3);
        label_18->setObjectName("label_18");
        label_18->setEnabled(true);
        label_18->setGeometry(QRect(30, 370, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        nb = new QSpinBox(widget_3);
        nb->setObjectName("nb");
        nb->setGeometry(QRect(160, 380, 261, 25));
        libre = new QRadioButton(widget_3);
        libre->setObjectName("libre");
        libre->setGeometry(QRect(170, 430, 91, 22));
        non = new QRadioButton(widget_3);
        non->setObjectName("non");
        non->setGeometry(QRect(310, 430, 91, 22));
        imagePath = new QLineEdit(widget_3);
        imagePath->setObjectName("imagePath");
        imagePath->setGeometry(QRect(470, 110, 151, 41));
        imagePath->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        imagePath->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        imageButton = new QPushButton(widget_3);
        imageButton->setObjectName("imageButton");
        imageButton->setGeometry(QRect(480, 70, 121, 31));
        imageButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        imageButton->setIcon(icon7);
        supprimer = new QPushButton(widget_3);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(590, 520, 111, 31));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supprimer->setIcon(icon8);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        chartView = new QChartView(tab_7);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(0, 0, 781, 721));
        tabWidget->addTab(tab_7, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        historiqueButton = new QPushButton(tab_8);
        historiqueButton->setObjectName("historiqueButton");
        historiqueButton->setGeometry(QRect(280, 200, 121, 31));
        historiqueButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPageSetup));
        historiqueButton->setIcon(icon9);
        tabWidget->addTab(tab_8, QString());
        verticalWidget = new QWidget(livreurs);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(0, 0, 211, 961));
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/Ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon10);
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
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon11);
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
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon12);
        pushButton_4 = new QPushButton(verticalWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 310, 121, 51));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/Ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon13);
        pushButton_9 = new QPushButton(verticalWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 370, 121, 51));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon14);
        pushButton_10 = new QPushButton(verticalWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 430, 121, 51));
        pushButton_10->setFont(font1);
        pushButton_10->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_10->setIcon(icon11);
        pushButton_13 = new QPushButton(verticalWidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(40, 490, 121, 51));
        pushButton_13->setFont(font1);
        pushButton_13->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/Ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon15);
        pushButton_17 = new QPushButton(verticalWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(40, 550, 121, 41));
        pushButton_17->setFont(font1);
        pushButton_17->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/Ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_17->setIcon(icon16);
        label_8 = new QLabel(verticalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 10, 201, 131));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));

        retranslateUi(livreurs);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(livreurs);
    } // setupUi

    void retranslateUi(QDialog *livreurs)
    {
        livreurs->setWindowTitle(QCoreApplication::translate("livreurs", "Dialog", nullptr));
        rech->setText(QString());
        rech->setPlaceholderText(QString());
        label_9->setText(QString());
        pdfButton->setText(QCoreApplication::translate("livreurs", " Generate PDF File", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("livreurs", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("livreurs", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("livreurs", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("livreurs", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("livreurs", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("livreurs", "Vehicle", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab1->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("livreurs", "Max number", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab1->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("livreurs", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tab1->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("livreurs", "Picture", nullptr));
#if QT_CONFIG(tooltip)
        DescButton->setToolTip(QCoreApplication::translate("livreurs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        DescButton->setWhatsThis(QCoreApplication::translate("livreurs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        DescButton->setText(QString());
#if QT_CONFIG(tooltip)
        AscButton->setToolTip(QCoreApplication::translate("livreurs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        AscButton->setWhatsThis(QCoreApplication::translate("livreurs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        AscButton->setText(QString());
        stateButton->setText(QCoreApplication::translate("livreurs", "State", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("livreurs", "Display All", nullptr));
        label_10->setText(QCoreApplication::translate("livreurs", "Last Name", nullptr));
        label_11->setText(QCoreApplication::translate("livreurs", "First Name", nullptr));
        labelllll->setText(QCoreApplication::translate("livreurs", "Email", nullptr));
        label_13->setText(QCoreApplication::translate("livreurs", "DELIVERY", nullptr));
        label_15->setText(QCoreApplication::translate("livreurs", "Vehicle", nullptr));
        nom->setPlaceholderText(QString());
        prenom->setPlaceholderText(QString());
        email->setPlaceholderText(QString());
        modifier->setText(QCoreApplication::translate("livreurs", " Update", nullptr));
        valider->setText(QCoreApplication::translate("livreurs", "Add", nullptr));
        label_16->setText(QCoreApplication::translate("livreurs", "Phone", nullptr));
        vehicule->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("livreurs", "State", nullptr));
        annuler->setText(QCoreApplication::translate("livreurs", "Cancel", nullptr));
        tel->setPlaceholderText(QString());
        label_12->setText(QCoreApplication::translate("livreurs", "     CIN", nullptr));
        cin->setPlaceholderText(QString());
        label_18->setText(QCoreApplication::translate("livreurs", "Max number", nullptr));
        libre->setText(QCoreApplication::translate("livreurs", "Free", nullptr));
        non->setText(QCoreApplication::translate("livreurs", "Not free", nullptr));
        imagePath->setPlaceholderText(QString());
        imageButton->setText(QCoreApplication::translate("livreurs", "Picture", nullptr));
        supprimer->setText(QCoreApplication::translate("livreurs", " Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("livreurs", "Update/Add New", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("livreurs", "Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("livreurs", "Charts", nullptr));
        historiqueButton->setText(QCoreApplication::translate("livreurs", "History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("livreurs", "History", nullptr));
        pushButton->setText(QCoreApplication::translate("livreurs", "Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("livreurs", "Equipment", nullptr));
        pushButton_3->setText(QCoreApplication::translate("livreurs", "Exam", nullptr));
        pushButton_4->setText(QCoreApplication::translate("livreurs", "Institute", nullptr));
        pushButton_9->setText(QCoreApplication::translate("livreurs", "Delivery", nullptr));
        pushButton_10->setText(QCoreApplication::translate("livreurs", "Box", nullptr));
        pushButton_13->setText(QCoreApplication::translate("livreurs", "Settings", nullptr));
        pushButton_17->setText(QCoreApplication::translate("livreurs", "Log-out", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class livreurs: public Ui_livreurs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVREURS_H
