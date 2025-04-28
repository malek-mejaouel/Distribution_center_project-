#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool connected = c.createconnect();
    QSqlDatabase db = QSqlDatabase::database();
    qDebug() << "Database connection open:" << db.isOpen();

    if(!connected) {
        qDebug() << "Connection error:" << db.lastError().text();
        QMessageBox::critical(nullptr, QObject::tr("Database Not Open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."), QMessageBox::Cancel);
        return -1;
    }
    int ret = QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                       QObject::tr("Connection successful.\nClick Cancel to exit."),
                                       QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QMessageBox::Cancel) {
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
