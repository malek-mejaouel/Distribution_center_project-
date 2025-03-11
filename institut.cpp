#include "institut.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>

Institut::Institut()
    : id(-1), telephone(0), capacite(0) {}

// Getters
int Institut::getId() const {
    return id;
}

QString Institut::getNom() const {
    return nom;
}

QString Institut::getAdresse() const {
    return adresse;
}

QString Institut::getResponsable() const {
    return responsable;
}

int Institut::getTelephone() const {
    return telephone;
}

QString Institut::getEmail() const {
    return email;
}

int Institut::getCapacite() const {
    return capacite;
}

// Setters
void Institut::setId(int id) {
    this->id = id;
}

void Institut::setNom(const QString &nom) {
    this->nom = nom;
}

void Institut::setAdresse(const QString &adresse) {
    this->adresse = adresse;
}

void Institut::setResponsable(const QString &responsable) {
    this->responsable = responsable;
}

void Institut::setTelephone(int telephone) {
    this->telephone = telephone;
}

void Institut::setEmail(const QString &email) {
    this->email = email;
}

void Institut::setCapacite(int capacite) {
    this->capacite = capacite;
}

bool Institut::ajouter()
{
    if (!validerDonnees()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO INSTITUTS (NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST) "
                  "VALUES (:nom, :adresse, :responsable, :telephone, :email, :capacite)");

    query.bindValue(":nom", this->nom);
    query.bindValue(":adresse", this->adresse);
    query.bindValue(":responsable", this->responsable);
    query.bindValue(":telephone", this->telephone);
    query.bindValue(":email", this->email);
    query.bindValue(":capacite", this->capacite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'institut : " << query.lastError().text();
        return false;
    }
    return true;
}

bool Institut::modifier()
{
    if (!validerDonnees()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE INSTITUTS SET NOM_INST = :nom, ADRESSE_INST = :adresse, RESPONSABLE_INST = :responsable, "
                  "TELEPHONE_INST = :telephone, EMAIL_INST = :email, CAPACITE_INST = :capacite WHERE ID_INST = :id");

    query.bindValue(":nom", this->nom);
    query.bindValue(":adresse", this->adresse);
    query.bindValue(":responsable", this->responsable);
    query.bindValue(":telephone", this->telephone);
    query.bindValue(":email", this->email);
    query.bindValue(":capacite", this->capacite);
    query.bindValue(":id", this->id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Institut::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", this->id);
    return query.exec();
}

QSqlQueryModel* Institut::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST FROM INSTITUTS");
    return model;
}

QSqlQueryModel* Institut::rechercherParId()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", this->id);
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur de recherche:" << query.lastError().text();
    }
    return model;
}

bool Institut::validerDonnees()
{
    // Validation de l'email
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    if (!emailRegex.match(this->email).hasMatch()) {
        qDebug() << "Email invalide.";
        return false;
    }

    // Validation du numéro de téléphone (8 chiffres)
    if (QString::number(this->telephone).length() != 8) {
        qDebug() << "Numéro de téléphone invalide. Il doit contenir 8 chiffres.";
        return false;
    }



    return true;
}
