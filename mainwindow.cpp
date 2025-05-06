#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "User.h"
#include "dialog.h"
#include "livreurs.h"
#include "examens.h"
#include "equipments.h"
#include "instituts.h"
#include "boxs.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QProcess>
#include <QRandomGenerator>
#include <QCryptographicHash>  // Needed for password hashing
#include <QTimer>

// Indexes for your QStackedWidget pages
const int loginPageIndex = 0;
const int signupPageIndex = 1;
const int otpPageIndex = 2;
const int resetPasswordPageIndex = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lockoutTimer = new QTimer(this);
    connect(lockoutTimer, &QTimer::timeout, this, &MainWindow::resetLoginAttempts);
    connect(ui->handleSignup, &QPushButton::clicked, this, &MainWindow::handleSignup);
    connect(ui->log, &QPushButton::clicked, this, &MainWindow::handleLogin);
    ui->stackedWidget->setCurrentIndex(loginPageIndex);
    connect(ui->r1, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r2, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r3, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r4, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r5, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r6, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
}

MainWindow::~MainWindow() {
    delete ui;
}

// 🔐 SIGN-UP HANDLER
void MainWindow::handleSignup() {
    QString username = ui->Userset->text();
    QString password = ui->Passset->text();
    int phoneNumber = ui->Number->text().toInt();
    QString role = getSelectedRole(); // Assuming it's a QComboBox

    if (username.isEmpty() || password.isEmpty() || phoneNumber == 0 || role.isEmpty()) {
        QMessageBox::warning(this, "Sign Up Failed", "All fields must be filled.");
        return;
    }

    User e(username, password, phoneNumber, role); // Updated constructor with role
    if (e.ajouterP()) {
        QMessageBox::information(this, "Sign Up Successful", "Welcome, " + username + "!");
    } else {
        QMessageBox::critical(this, "Sign Up Failed", "Error occurred while registering.");
    }
}

void MainWindow::handleLogin() {
    QString username = ui->User->text();
    QString password = ui->Pass->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter username and password.");
        return;
    }

    User user;

    if (user.login(username, password)) {
        QString role = user.checkRole(username);

        failedLoginAttempts = 0; // Reset counter

        if (role == "Employe") {
            Dialog *dia = new Dialog(this);
            dia->show();

        } else if (role == "Livreur") {
            livreurs *eqWindow = new livreurs(this); // 'this' as parent to handle memory
            eqWindow->show();

        } else if (role == "Institut") {
            instituts *eqWindow = new instituts(this); // 'this' as parent to handle memory
            eqWindow->show();

        } else if (role == "R.equip") {
            Equipments *eqWindow = new Equipments(this);
            eqWindow->show();

        } else if (role == "R.box") {
            boxs *eqWindow = new boxs(this); // 'this' as parent to handle memory
            eqWindow->show();

        } else {
            QMessageBox::warning(this, "Login Failed", "Unknown user role.");
        }

    } else {
        failedLoginAttempts++;

        if (failedLoginAttempts >= 3) {
            ui->log->setEnabled(false);
            lockoutTimer->start(10000);  // 10 seconds lockout
            QMessageBox::critical(this, "Blocked", "Too many failed attempts. You are temporarily blocked.");
        } else {
            QMessageBox::critical(this, "Login Failed",
                                  "Invalid username or password. Attempt " + QString::number(failedLoginAttempts) + " of 3.");
        }
    }
}


void MainWindow::resetLoginAttempts() {
    failedLoginAttempts = 0;
    ui->log->setEnabled(true);  // Re-enable login button
    lockoutTimer->stop();       // Stop the timer
    QMessageBox::information(this, "Access Restored", "You can now attempt to log in again.");
}

// Function to get the selected role
QString MainWindow::getSelectedRole()
{
    if (ui->r1->isChecked()) return "Livreur";
    if (ui->r2->isChecked()) return "Institut";
    if (ui->r3->isChecked()) return "Employe";
    if (ui->r4->isChecked()) return "R.equip";
    if (ui->r5->isChecked()) return "R.exame";
    if (ui->r6->isChecked()) return "R.Box";
    return ""; // No role selected
}

// 🔏 Handle the role selection
void MainWindow::onRoleSelected() {
    QString selectedRole = getSelectedRole();  // Get the selected role from the radio buttons
    qDebug() << "Selected Role: " << selectedRole;  // You can log or use this role for further processing
}

// 🔁 PAGE SWITCHING
void MainWindow::on_Sign_clicked() { ui->stackedWidget->setCurrentIndex(signupPageIndex); }
void MainWindow::on_Log_clicked()  { ui->stackedWidget->setCurrentIndex(loginPageIndex); }

// 🔑 OTP GENERATION
QString MainWindow::generateOTP() {
    int otp = QRandomGenerator::global()->bounded(100000, 999999);
    return QString::number(otp);
}

// 📤 SEND SMS FUNCTION
void MainWindow::sendSMS(const QString &phoneNumber, const QString &message) {
    QString accountSID = "AC04a563baab8565e5af27b3791c6635ce";
    QString authToken = "3bf30fa7010a6b25cadf016b0140648c";
    QString fromNumber = "+1 845 472 3817";
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json";

    QStringList arguments;
    arguments << "-u" << accountSID + ":" + authToken
              << "-d" << "To=" + phoneNumber
              << "-d" << "From=" + fromNumber
              << "-d" << "Body=" + message
              << url;

    QProcess process;
    process.start("curl", arguments);
    process.waitForFinished();

    qDebug() << "SMS sent:" << process.readAllStandardOutput();
    qDebug() << "Error (if any):" << process.readAllStandardError();
}

void MainWindow::on_forget_clicked()           { ui->stackedWidget->setCurrentIndex(signupPageIndex); }
void MainWindow::on_Get_SMS_clicked()          { ui->stackedWidget->setCurrentIndex(otpPageIndex); }
void MainWindow::on_checksms_clicked()         { ui->stackedWidget->setCurrentIndex(resetPasswordPageIndex); }
void MainWindow::on_checkpassword_clicked()    { ui->stackedWidget->setCurrentIndex(loginPageIndex); } // Adjust as needed





void MainWindow::on_forgotPasswordBtn_clicked()
{
    QString username = ui->User->text().trimmed();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }
    ui->stackedWidget->setCurrentIndex(otpPageIndex);
    User user;
    QString phoneNumber = user.getPhoneNumber(username).trimmed();

    if (!phoneNumber.startsWith("+")) {
        phoneNumber = "+216" + phoneNumber; // assuming Tunisian numbers
    }

    if (phoneNumber.isEmpty()) {
        QMessageBox::warning(this, "Error", "User not found!");
        return;
    }

    resetUsername = username;
    currentOTP = generateOTP();
    sendSMS(phoneNumber, "Your OTP is: " + currentOTP);

    QMessageBox::information(this, "OTP Sent", "OTP sent to your registered number.");
}
void MainWindow::on_resetPasswordBtn_clicked() {
    QString newPassword = ui->newPassInput->text().trimmed();
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEES SET PASSWORD = :password WHERE USERNAME = :username");
    query.bindValue(":password", newPassword);
    query.bindValue(":username", resetUsername);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Password reset successfully.");
        ui->stackedWidget->setCurrentIndex(loginPageIndex);
    } else {
        QMessageBox::critical(this, "Error", "Failed to reset password.");
    }
}
void MainWindow::on_verifyOtpBtn_clicked() {
    QString enteredOtp = ui->otpInput->text();

    if (enteredOtp == currentOTP) {
        QMessageBox::information(this, "Success", "OTP verified. Set your new password.");
        ui->stackedWidget->setCurrentIndex(resetPasswordPageIndex);
    } else {
        QMessageBox::warning(this, "Error", "Incorrect OTP.");
    }
}

void MainWindow::on_Sign_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(loginPageIndex);
}
void MainWindow::on_Sign_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(loginPageIndex);
}

void MainWindow::on_hide_clicked()
{
    if (ui->Pass->echoMode() == QLineEdit::Password) {
        ui->Pass->setEchoMode(QLineEdit::Normal);
    } else {
        ui->Pass->setEchoMode(QLineEdit::Password);
    }
}void MainWindow::on_hide_2_clicked()
{
    if (ui->Passset->echoMode() == QLineEdit::Password) {
        ui->Passset->setEchoMode(QLineEdit::Normal);
    } else {
        ui->Passset->setEchoMode(QLineEdit::Password);
    }

}

