#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getSelectedRole();  // Get the selected role from the radio buttons

private slots:
    void handleSignup();        // Handles user sign-up
    void handleLogin();         // Handles user login
    void onRoleSelected();      // Slot for handling role selection
    void on_Sign_clicked();     // Switch to sign-up page
    void on_Log_clicked();      // Switch to login page

    void on_forget_clicked();           // Forgot password page
    void on_Get_SMS_clicked();          // Switch to OTP page
    void on_checksms_clicked();         // Check OTP
    void on_checkpassword_clicked();    // Switch to reset password page
    void on_resetPasswordBtn_clicked();  // Reset the password
    void on_verifyOtpBtn_clicked();     // Verify OTP

    void on_Sign_8_clicked();           // Back to login page
    void on_Sign_6_clicked();           // Back to login page
    void on_hide_clicked();             // Show/hide password in login page
    void on_hide_2_clicked();           // Show/hide password in signup page

    void on_forgotPasswordBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString currentOTP;       // Stores the OTP for forgot password
    QString resetUsername;    // Stores the username during reset
    int failedLoginAttempts = 0;
      QTimer *lockoutTimer;
    void resetLoginAttempts();
    void sendSMS(const QString &phoneNumber, const QString &message);  // Send SMS with OTP
    QString generateOTP();  // Generate a random OTP
};

#endif // MAINWINDOW_H
