#include "connection.h"
#include <QMessageBox>

Connection::Connection()
{
    // Constructeur
}

bool Connection::createconnect()
{
    bool test = false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet"); // Nom de la source de données ODBC
    db.setUserName("kinza");     // Nom d'utilisateur
    db.setPassword("kinza");     // Mot de passe

    if (db.open()) {
        test = true;
    } else {
        // Afficher un message d'erreur si la connexion échoue
        QMessageBox::critical(nullptr, QObject::tr("Erreur de connexion"),
                              QObject::tr("Impossible de se connecter à la base de données.\n"
                                          "Erreur : %1").arg(db.lastError().text()), QMessageBox::Ok);
    }

    return test;
}

void Connection::closeconnect(){db.close();}



