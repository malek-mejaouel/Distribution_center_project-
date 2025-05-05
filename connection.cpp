#include "connection.h"
#include <QSqlError>
#include <QMessageBox>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;

    // Check if a connection already exists
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        qDebug() << "Reusing existing database connection.";
        return true;  // Avoid creating a new connection
    }

    // Initialize the database connection using ODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "qt_sql_default_connection"); // Specify connection name
    db.setDatabaseName("base");  // Replace with your actual DSN name
    db.setUserName("kinza");
    db.setPassword("kinza");

    if (db.open()) {
        test = true;
        qDebug() << "Database connected successfully!";
    } else {
        qDebug() << "Database connection failed: " << db.lastError().text();
        QMessageBox::critical(0, "Database Connection Error", db.lastError().text());
    }

    return test;
}

