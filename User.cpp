#include "User.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
// Default constructor
User::User() {
    user = "";
    pass = "";
    numberp = 0;
    id = 0;
    role = "";
}

// Parameterized constructor
User::User(const QString& username, const QString& password, int numberp, const QString& role) {
    this->user = username;
    this->pass = password;
    this->numberp = numberp;
    this->id = 0;
    this->role = role;
}

// Getters
QString User::getUser() const { return user; }
QString User::getPass() const { return pass; }
int User::getNumberP() const { return numberp; }
int User::getId() const { return id; }
QString User::getRole() const { return role; }

// Setters
void User::setUser(const QString& user) { this->user = user; }
void User::setPass(const QString& pass) { this->pass = pass; }
void User::setNumberP(int number) { this->numberp = number; }
void User::setId(int id) { this->id = id; }
void User::setRole(const QString& role) { this->role = role; }

// Add user to database
bool User::ajouterP() {
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYEES (ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, ROLE) "
                  "VALUES (EMPLOYEES_SEQ.NEXTVAL, :username, :password, :phone, :role)");


    query.bindValue(":username", user);
    query.bindValue(":password", pass);  // Optional: hash before storing
    query.bindValue(":phone", numberp);
    query.bindValue(":role", role);

    if (!query.exec()) {
        qDebug() << "SQL Error (add user): " << query.lastError().text();
        return false;
    }

    return true;
}
bool User::modifierP(int id) {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEES SET USERNAME = :username, PASSWORD = :password, NUMBERP = :phone, ROLE = :role "
                  "WHERE ID_EMPLOYE = :id");

    query.bindValue(":username", user);
    query.bindValue(":password", pass);
    query.bindValue(":phone", numberp);
    query.bindValue(":role", role);
    query.bindValue(":id", id);  // use the id passed as parameter

    if (!query.exec()) {
        qDebug() << "❌ SQL Error (modification): " << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "❗️Aucune ligne modifiée (ID inexistant ou aucune donnée changée)";
        return false;
    }

    return true;
}
bool User::supprimerP(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur de suppression : " + query.lastError().text());
        return false;
    }
}


// Login method
bool User::login(const QString& username, const QString& password) {
    QSqlQuery query;

    query.prepare("SELECT ID_EMPLOYE, NUMBERP, ROLE FROM EMPLOYEES "
                  "WHERE USERNAME = :username AND PASSWORD = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Login failed: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        id = query.value("ID_EMPLOYE").toInt();
        numberp = query.value("NUMBERP").toInt();
        role = query.value("ROLE").toString();
        return true;
    }

    return false;
}

// Get phone number by username
QString User::getPhoneNumber(QString username) {
    QSqlQuery query;

    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        return "";
    }

    query.prepare("SELECT NUMBERP FROM EMPLOYEES WHERE USERNAME = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Phone number lookup failed: " << query.lastError().text();
        return "";
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "User not found: " << username;
        return "";
    }
}

// Show all users (admin use-case)
QSqlQueryModel* User::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone Number"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
    return model;
}
