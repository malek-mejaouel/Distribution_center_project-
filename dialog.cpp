// dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QScreen>
#include <QDateTime>

Dialog::Dialog(const QString &employeeId, const QString &message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Configurer le titre avec l'ID de l'employé
    QString title = QString("Notification pour l'employé d'ID %1").arg(employeeId);
    ui->titleLabel->setText(title);

    // Configurer le message avec le choix de l'utilisateur et la date actuelle
    QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString fullMessage = QString("%1\n").arg(message);
    ui->messageLabel->setText(fullMessage);

    // Appliquer des styles pour améliorer le design
    setStyleSheet("QDialog { background-color: #f9f9f9; border: 1px solid #ddd; border-radius: 10px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2); }"
                  "QLabel#titleLabel { font-size: 18px; font-weight: bold; color: #333; margin-bottom: 10px; }"
                  "QLabel#messageLabel { font-size: 14px; color: #555; }");

    // Positionner la boîte de dialogue en haut à droite de l'écran
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = screenGeometry.width() - width() - 20;
    int y = 20;
    move(x, y);

    // Masquer la boîte de dialogue après 5 secondes
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dialog::hideDialog);
    timer->start(5000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::hideDialog()
{
    hide();
    deleteLater();
}
