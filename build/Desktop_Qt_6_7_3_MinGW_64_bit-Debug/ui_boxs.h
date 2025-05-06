/********************************************************************************
** Form generated from reading UI file 'boxs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXS_H
#define UI_BOXS_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boxs
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_13;
    QLineEdit *searchLineEdit;
    QLabel *label_24;
    QComboBox *sortComboBox;
    QPushButton *pdfButton;
    QPushButton *supprimer;
    QTableWidget *tableWidget;
    QPushButton *desc;
    QPushButton *asc;
    QWidget *tab_14;
    QWidget *widget_5;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *labelllll_3;
    QLabel *label_27;
    QPushButton *modifier;
    QPushButton *valider;
    QLabel *label_29;
    QPushButton *annuler;
    QLabel *label_30;
    QComboBox *examenComboBox;
    QComboBox *statusComboBox;
    QComboBox *etatComboBox;
    QComboBox *destinationComboBox;
    QComboBox *livreurComboBox;
    QWidget *tab_15;
    QChartView *chartViewBox;
    QPushButton *etatButton;
    QPushButton *statusButton;
    QWidget *tab_16;
    QPushButton *qrButton;
    QPushButton *pushButtonTrack;
    QWidget *verticalWidget;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLabel *label_31;

    void setupUi(QDialog *boxs)
    {
        if (boxs->objectName().isEmpty())
            boxs->setObjectName("boxs");
        boxs->resize(943, 593);
        tabWidget = new QTabWidget(boxs);
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
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        searchLineEdit = new QLineEdit(tab_13);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(30, 60, 236, 41));
        searchLineEdit->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        label_24 = new QLabel(tab_13);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(190, 70, 61, 21));
        label_24->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/search-3-48.png);"));
        sortComboBox = new QComboBox(tab_13);
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(290, 60, 226, 41));
        sortComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        pdfButton = new QPushButton(tab_13);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(70, 470, 181, 41));
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
        supprimer = new QPushButton(tab_13);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(570, 470, 111, 31));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delete-button-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supprimer->setIcon(icon1);
        tableWidget = new QTableWidget(tab_13);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setBackground(QColor(85, 170, 255));
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 140, 651, 251));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);\n"
"background-color: rgb(14, 0, 214);\n"
"background-color: rgb(179, 179, 179);\n"
"tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); \n"
"tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents); \n"
""));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(45);
        tableWidget->horizontalHeader()->setDefaultSectionSize(160);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        desc = new QPushButton(tab_13);
        desc->setObjectName("desc");
        desc->setGeometry(QRect(550, 60, 51, 41));
        desc->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        desc->setIcon(icon2);
        asc = new QPushButton(tab_13);
        asc->setObjectName("asc");
        asc->setGeometry(QRect(620, 60, 51, 41));
        asc->setStyleSheet(QString::fromUtf8("background-image: url(:/ressources/up-and-down-arrow.png);\n"
"background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        asc->setIcon(icon3);
        tabWidget->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        widget_5 = new QWidget(tab_14);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(20, 10, 641, 521));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_25 = new QLabel(widget_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 70, 121, 41));
        label_25->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_26 = new QLabel(widget_5);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(50, 120, 121, 41));
        label_26->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        labelllll_3 = new QLabel(widget_5);
        labelllll_3->setObjectName("labelllll_3");
        labelllll_3->setGeometry(QRect(50, 170, 121, 41));
        labelllll_3->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        label_27 = new QLabel(widget_5);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(50, 220, 121, 41));
        label_27->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        modifier = new QPushButton(widget_5);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(270, 420, 121, 31));
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
        valider = new QPushButton(widget_5);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(70, 420, 121, 31));
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
        label_29 = new QLabel(widget_5);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(50, 270, 121, 41));
        label_29->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        annuler = new QPushButton(widget_5);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(460, 420, 121, 31));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        annuler->setIcon(icon6);
        label_30 = new QLabel(widget_5);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(150, 10, 281, 41));
        label_30->setStyleSheet(QString::fromUtf8("   color: #1E2350;\n"
"font: 9pt \"Segoe UI\";\n"
"font:  24pt ;"));
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);
        examenComboBox = new QComboBox(tab_14);
        examenComboBox->setObjectName("examenComboBox");
        examenComboBox->setGeometry(QRect(250, 80, 226, 41));
        examenComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        statusComboBox = new QComboBox(tab_14);
        statusComboBox->setObjectName("statusComboBox");
        statusComboBox->setGeometry(QRect(250, 130, 226, 41));
        statusComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        etatComboBox = new QComboBox(tab_14);
        etatComboBox->setObjectName("etatComboBox");
        etatComboBox->setGeometry(QRect(250, 180, 226, 41));
        etatComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        destinationComboBox = new QComboBox(tab_14);
        destinationComboBox->setObjectName("destinationComboBox");
        destinationComboBox->setGeometry(QRect(250, 230, 226, 41));
        destinationComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        livreurComboBox = new QComboBox(tab_14);
        livreurComboBox->setObjectName("livreurComboBox");
        livreurComboBox->setGeometry(QRect(250, 280, 226, 41));
        livreurComboBox->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    padding: 6px 30px 6px 10px;\n"
"    font-size: 14px;\n"
"    min-width: 150px;"));
        tabWidget->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName("tab_15");
        chartViewBox = new QChartView(tab_15);
        chartViewBox->setObjectName("chartViewBox");
        chartViewBox->setGeometry(QRect(20, 20, 661, 511));
        etatButton = new QPushButton(chartViewBox);
        etatButton->setObjectName("etatButton");
        etatButton->setGeometry(QRect(20, 460, 121, 31));
        etatButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        etatButton->setIcon(icon7);
        statusButton = new QPushButton(tab_15);
        statusButton->setObjectName("statusButton");
        statusButton->setGeometry(QRect(40, 520, 121, 31));
        statusButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        statusButton->setIcon(icon7);
        tabWidget->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName("tab_16");
        qrButton = new QPushButton(tab_16);
        qrButton->setObjectName("qrButton");
        qrButton->setGeometry(QRect(80, 130, 141, 31));
        qrButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        qrButton->setIcon(icon8);
        pushButtonTrack = new QPushButton(tab_16);
        pushButtonTrack->setObjectName("pushButtonTrack");
        pushButtonTrack->setGeometry(QRect(270, 130, 141, 31));
        pushButtonTrack->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::NetworkWireless));
        pushButtonTrack->setIcon(icon9);
        tabWidget->addTab(tab_16, QString());
        verticalWidget = new QWidget(boxs);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(0, -20, 211, 671));
        verticalWidget->setStyleSheet(QString::fromUtf8(" background: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #e3f2fd,   /* very light blue */\n"
"        stop: 0.5 #90caf9, /* soft sky blue */\n"
"        stop: 1 #1565c0    /* deep blue */\n"
"    );"));
        pushButton_15 = new QPushButton(verticalWidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(40, 130, 121, 51));
        QFont font;
        font.setBold(true);
        pushButton_15->setFont(font);
        pushButton_15->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/Ressources/user-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_15->setIcon(icon10);
        pushButton_16 = new QPushButton(verticalWidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(40, 190, 121, 51));
        pushButton_16->setFont(font);
        pushButton_16->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/Ressources/tool-box-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_16->setIcon(icon11);
        pushButton_19 = new QPushButton(verticalWidget);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(40, 250, 121, 51));
        pushButton_19->setFont(font);
        pushButton_19->setStyleSheet(QString::fromUtf8(" background-color: #FFFFFF;\n"
"    border: 2px solid #C0E8E0;\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: #1E2350;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/Ressources/paper-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_19->setIcon(icon12);
        pushButton_20 = new QPushButton(verticalWidget);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(40, 310, 121, 51));
        pushButton_20->setFont(font);
        pushButton_20->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/Ressources/building-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_20->setIcon(icon13);
        pushButton_21 = new QPushButton(verticalWidget);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(40, 370, 121, 51));
        pushButton_21->setFont(font);
        pushButton_21->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/Ressources/delivery-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_21->setIcon(icon14);
        pushButton_22 = new QPushButton(verticalWidget);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(40, 430, 121, 51));
        pushButton_22->setFont(font);
        pushButton_22->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_22->setIcon(icon11);
        pushButton_23 = new QPushButton(verticalWidget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(40, 490, 121, 51));
        pushButton_23->setFont(font);
        pushButton_23->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/Ressources/settings-5-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_23->setIcon(icon15);
        pushButton_24 = new QPushButton(verticalWidget);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(40, 550, 121, 41));
        pushButton_24->setFont(font);
        pushButton_24->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/Ressources/logout-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_24->setIcon(icon16);
        label_31 = new QLabel(verticalWidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(0, 30, 201, 111));
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));

        retranslateUi(boxs);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(boxs);
    } // setupUi

    void retranslateUi(QDialog *boxs)
    {
        boxs->setWindowTitle(QCoreApplication::translate("boxs", "Dialog", nullptr));
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QString());
        label_24->setText(QString());
        pdfButton->setText(QCoreApplication::translate("boxs", " Generate PDF File", nullptr));
        supprimer->setText(QCoreApplication::translate("boxs", " Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("boxs", "ID_Box", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("boxs", "Exam", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("boxs", "Delivery", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("boxs", "Creation_Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("boxs", "Destination", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("boxs", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("boxs", "Condition", nullptr));
#if QT_CONFIG(tooltip)
        desc->setToolTip(QCoreApplication::translate("boxs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        desc->setWhatsThis(QCoreApplication::translate("boxs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        desc->setText(QString());
#if QT_CONFIG(tooltip)
        asc->setToolTip(QCoreApplication::translate("boxs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        asc->setWhatsThis(QCoreApplication::translate("boxs", "<html><head/><body><p><img src=\":/ressources/up-and-down-arrow.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        asc->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_13), QCoreApplication::translate("boxs", "Display All", nullptr));
        label_25->setText(QCoreApplication::translate("boxs", "Exam :", nullptr));
        label_26->setText(QCoreApplication::translate("boxs", "Status :", nullptr));
        labelllll_3->setText(QCoreApplication::translate("boxs", "Condition : ", nullptr));
        label_27->setText(QCoreApplication::translate("boxs", "Destination :", nullptr));
        modifier->setText(QCoreApplication::translate("boxs", " Update", nullptr));
        valider->setText(QCoreApplication::translate("boxs", "Add", nullptr));
        label_29->setText(QCoreApplication::translate("boxs", "Delivery :", nullptr));
        annuler->setText(QCoreApplication::translate("boxs", "Cancel", nullptr));
        label_30->setText(QCoreApplication::translate("boxs", "BOX", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_14), QCoreApplication::translate("boxs", "Update/Add New", nullptr));
        etatButton->setText(QCoreApplication::translate("boxs", "Etat", nullptr));
        statusButton->setText(QCoreApplication::translate("boxs", "Status", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_15), QCoreApplication::translate("boxs", "Statistics", nullptr));
        qrButton->setText(QCoreApplication::translate("boxs", "Generate Qr", nullptr));
        pushButtonTrack->setText(QCoreApplication::translate("boxs", "Track", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_16), QCoreApplication::translate("boxs", "Add-Ons", nullptr));
        pushButton_15->setText(QCoreApplication::translate("boxs", "Employee", nullptr));
        pushButton_16->setText(QCoreApplication::translate("boxs", "Equipment", nullptr));
        pushButton_19->setText(QCoreApplication::translate("boxs", "Exam", nullptr));
        pushButton_20->setText(QCoreApplication::translate("boxs", "Institute", nullptr));
        pushButton_21->setText(QCoreApplication::translate("boxs", "Delivery", nullptr));
        pushButton_22->setText(QCoreApplication::translate("boxs", "Box", nullptr));
        pushButton_23->setText(QCoreApplication::translate("boxs", "Settings", nullptr));
        pushButton_24->setText(QCoreApplication::translate("boxs", "Log-out", nullptr));
        label_31->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class boxs: public Ui_boxs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXS_H
