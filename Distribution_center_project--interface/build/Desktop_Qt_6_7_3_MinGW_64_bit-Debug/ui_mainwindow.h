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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *User;
    QLabel *label_3;
    QPushButton *log;
    QPushButton *Sign;
    QPushButton *forgotPasswordBtn;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *hide;
    QLineEdit *Pass;
    QLabel *label_6;
    QWidget *page_2;
    QWidget *widget_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_12;
    QPushButton *hide_2;
    QLineEdit *Userset;
    QLineEdit *Passset;
    QLineEdit *Number;
    QLabel *label_13;
    QLabel *label_20;
    QRadioButton *r1;
    QRadioButton *r2;
    QRadioButton *r3;
    QRadioButton *r4;
    QRadioButton *r5;
    QRadioButton *r6;
    QPushButton *handleSignup;
    QPushButton *Log;
    QLabel *label_5;
    QWidget *page_3;
    QWidget *widget_6;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *Sign_8;
    QPushButton *Sign_9;
    QLineEdit *otpInput;
    QPushButton *verifyOtpBtn;
    QLabel *label_11;
    QWidget *page_4;
    QWidget *widget_5;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *Sign_6;
    QPushButton *Sign_7;
    QLineEdit *newPassInput;
    QPushButton *resetPasswordBtn;
    QLabel *label_21;
    QWidget *page_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 594);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-50, 0, 851, 601));
        stackedWidget->setStyleSheet(QString::fromUtf8(" background: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #e3f2fd,   /* very light blue */\n"
"        stop: 0.5 #90caf9, /* soft sky blue */\n"
"        stop: 1 #1565c0    /* deep blue */\n"
"    );"));
        page = new QWidget();
        page->setObjectName("page");
        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(480, 40, 331, 491));
        widget->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 251, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(24);
        font.setWeight(QFont::Black);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 900 24pt \"Segoe UI\";\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 80, 91, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:#333"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        User = new QLineEdit(widget);
        User->setObjectName("User");
        User->setGeometry(QRect(40, 150, 271, 31));
        User->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        User->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 200, 81, 51));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:#333"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        log = new QPushButton(widget);
        log->setObjectName("log");
        log->setGeometry(QRect(50, 380, 231, 41));
        log->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        Sign = new QPushButton(widget);
        Sign->setObjectName("Sign");
        Sign->setGeometry(QRect(220, 440, 101, 41));
        Sign->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        forgotPasswordBtn = new QPushButton(widget);
        forgotPasswordBtn->setObjectName("forgotPasswordBtn");
        forgotPasswordBtn->setGeometry(QRect(20, 320, 161, 41));
        forgotPasswordBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 150, 41, 31));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/user-48.png);"));
        label_15 = new QLabel(widget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 260, 41, 31));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/pngwing.com.png);"));
        hide = new QPushButton(widget);
        hide->setObjectName("hide");
        hide->setGeometry(QRect(290, 270, 31, 20));
        hide->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/clipart1107475.png);\n"
"background:transparent;"));
        Pass = new QLineEdit(widget);
        Pass->setObjectName("Pass");
        Pass->setGeometry(QRect(40, 260, 241, 31));
        Pass->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        Pass->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 20, 471, 491));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(470, 20, 351, 571));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(70, 10, 191, 51));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"font: 900 24pt \"Segoe UI\";"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 50, 91, 61));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color:#333"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 160, 81, 61));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color:#333"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 260, 131, 61));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color:#333"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 120, 41, 31));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/user-48.png);"));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 220, 41, 31));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/pngwing.com.png);"));
        hide_2 = new QPushButton(widget_2);
        hide_2->setObjectName("hide_2");
        hide_2->setGeometry(QRect(290, 230, 31, 21));
        hide_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/clipart1107475.png);\n"
"background:transparent;"));
        Userset = new QLineEdit(widget_2);
        Userset->setObjectName("Userset");
        Userset->setGeometry(QRect(40, 120, 271, 31));
        Userset->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        Userset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Passset = new QLineEdit(widget_2);
        Passset->setObjectName("Passset");
        Passset->setGeometry(QRect(40, 220, 241, 31));
        Passset->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        Passset->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        Number = new QLineEdit(widget_2);
        Number->setObjectName("Number");
        Number->setGeometry(QRect(40, 320, 261, 31));
        Number->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        Number->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 320, 21, 31));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/pngwing.com (1).png);"));
        label_20 = new QLabel(widget_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(-10, 350, 91, 61));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("color:#333"));
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        r1 = new QRadioButton(widget_2);
        r1->setObjectName("r1");
        r1->setGeometry(QRect(20, 400, 81, 22));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(true);
        r1->setFont(font2);
        r1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r2 = new QRadioButton(widget_2);
        r2->setObjectName("r2");
        r2->setGeometry(QRect(120, 400, 81, 22));
        r2->setFont(font2);
        r2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r3 = new QRadioButton(widget_2);
        r3->setObjectName("r3");
        r3->setGeometry(QRect(220, 400, 101, 22));
        r3->setFont(font2);
        r3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r4 = new QRadioButton(widget_2);
        r4->setObjectName("r4");
        r4->setGeometry(QRect(20, 440, 81, 22));
        r4->setFont(font2);
        r4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r5 = new QRadioButton(widget_2);
        r5->setObjectName("r5");
        r5->setGeometry(QRect(120, 440, 81, 22));
        r5->setFont(font2);
        r5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        r6 = new QRadioButton(widget_2);
        r6->setObjectName("r6");
        r6->setGeometry(QRect(220, 440, 81, 22));
        r6->setFont(font2);
        r6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        handleSignup = new QPushButton(widget_2);
        handleSignup->setObjectName("handleSignup");
        handleSignup->setGeometry(QRect(50, 490, 231, 41));
        handleSignup->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        Log = new QPushButton(widget_2);
        Log->setObjectName("Log");
        Log->setGeometry(QRect(0, 10, 41, 31));
        Log->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/new/prefix1/Ressources/back-button-svgrepo-com.svg);\n"
" \n"
""));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 30, 471, 491));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        widget_6 = new QWidget(page_3);
        widget_6->setObjectName("widget_6");
        widget_6->setEnabled(true);
        widget_6->setGeometry(QRect(480, 50, 331, 491));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_18 = new QLabel(widget_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 30, 241, 51));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        label_18->setFont(font3);
        label_18->setStyleSheet(QString::fromUtf8("color:#333"));
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_19 = new QLabel(widget_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 80, 111, 61));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color:#333"));
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Sign_8 = new QPushButton(widget_6);
        Sign_8->setObjectName("Sign_8");
        Sign_8->setEnabled(true);
        Sign_8->setGeometry(QRect(20, 430, 101, 41));
        Sign_8->setStyleSheet(QString::fromUtf8("background-color: #333; color: white; border-radius: 10px; font-weight: bold; padding: 5px;"));
        Sign_9 = new QPushButton(widget_6);
        Sign_9->setObjectName("Sign_9");
        Sign_9->setGeometry(QRect(210, 430, 101, 41));
        Sign_9->setStyleSheet(QString::fromUtf8("background-color: #333; color: white; border-radius: 10px; font-weight: bold; padding: 5px;"));
        otpInput = new QLineEdit(widget_6);
        otpInput->setObjectName("otpInput");
        otpInput->setGeometry(QRect(30, 140, 271, 31));
        otpInput->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        otpInput->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        verifyOtpBtn = new QPushButton(widget_6);
        verifyOtpBtn->setObjectName("verifyOtpBtn");
        verifyOtpBtn->setGeometry(QRect(50, 210, 231, 41));
        verifyOtpBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 10, 471, 491));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        widget_5 = new QWidget(page_4);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(490, 40, 331, 491));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: #D3D3D3; border-radius: 15px;"));
        label_16 = new QLabel(widget_5);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(50, 30, 241, 51));
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8("color:#333"));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_17 = new QLabel(widget_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 100, 141, 61));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color:#333"));
        label_17->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Sign_6 = new QPushButton(widget_5);
        Sign_6->setObjectName("Sign_6");
        Sign_6->setGeometry(QRect(20, 430, 101, 41));
        Sign_6->setStyleSheet(QString::fromUtf8("background-color: #333; color: white; border-radius: 10px; font-weight: bold; padding: 5px;"));
        Sign_7 = new QPushButton(widget_5);
        Sign_7->setObjectName("Sign_7");
        Sign_7->setGeometry(QRect(210, 430, 101, 41));
        Sign_7->setStyleSheet(QString::fromUtf8("background-color: #333; color: white; border-radius: 10px; font-weight: bold; padding: 5px;"));
        newPassInput = new QLineEdit(widget_5);
        newPassInput->setObjectName("newPassInput");
        newPassInput->setGeometry(QRect(30, 170, 271, 31));
        newPassInput->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;"));
        newPassInput->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        resetPasswordBtn = new QPushButton(widget_5);
        resetPasswordBtn->setObjectName("resetPasswordBtn");
        resetPasswordBtn->setGeometry(QRect(50, 240, 231, 41));
        resetPasswordBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;"));
        label_21 = new QLabel(page_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 10, 471, 491));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/Ressources/e0ff5635-a1d6-406a-ae4c-6240633d745e.png);\n"
"background:transparent;"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome Back", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Username :", nullptr));
        User->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your username here", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password :", nullptr));
        log->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Sign->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        forgotPasswordBtn->setText(QCoreApplication::translate("MainWindow", "Forget password ?", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        hide->setText(QString());
        Pass->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your password here", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Username :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Password :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Phone  Number :", nullptr));
        label_4->setText(QString());
        label_12->setText(QString());
        hide_2->setText(QString());
        Userset->setPlaceholderText(QString());
        Passset->setPlaceholderText(QString());
        Number->setPlaceholderText(QString());
        label_13->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Role", nullptr));
        r1->setText(QCoreApplication::translate("MainWindow", "Livreur", nullptr));
        r2->setText(QCoreApplication::translate("MainWindow", "Institut", nullptr));
        r3->setText(QCoreApplication::translate("MainWindow", "Employee", nullptr));
        r4->setText(QCoreApplication::translate("MainWindow", "R.equip", nullptr));
        r5->setText(QCoreApplication::translate("MainWindow", "R.examen", nullptr));
        r6->setText(QCoreApplication::translate("MainWindow", "R.Box", nullptr));
        handleSignup->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        Log->setText(QString());
        label_5->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Password Reset", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "SMS :", nullptr));
        Sign_8->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Sign_9->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        otpInput->setPlaceholderText(QString());
        verifyOtpBtn->setText(QCoreApplication::translate("MainWindow", "Verify", nullptr));
        label_11->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Password Reset", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "New password :", nullptr));
        Sign_6->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Sign_7->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        newPassInput->setPlaceholderText(QString());
        resetPasswordBtn->setText(QCoreApplication::translate("MainWindow", "Valide", nullptr));
        label_21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
