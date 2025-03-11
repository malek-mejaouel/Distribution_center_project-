#include "connection.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    // Using QODBC driver. Ensure your DSN ("test-bd") is properly configured.
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");  // DSN name
    db.setUserName("kinza");        // DB username
    db.setPassword("kinza");        // DB password

    if (db.open()) {
        test = true;
        qDebug() << "Database connection successful. DSN:" << db.databaseName();
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
    }
    return test;
}
