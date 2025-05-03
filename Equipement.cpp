#include "Equipement.h"
#include <QRegularExpression>

Equipement::Equipement()
    : id(0), quantite(0), prix(0.0) {}

Equipement::Equipement(int id, const QString &nom, const QString &marque, const QString &type, int quantite, double prix, const QDate &dateMaintenance)
    : id(id), nom(nom), marque(marque), type(type), quantite(quantite), prix(prix), dateMaintenance(dateMaintenance) {}

bool Equipement::ajouterEquipement() {
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENTS (NOM_EQUIPEMENT, MARQUE, TYPE, QUANTITE, PRIX_EQUIPEMENT, DATE_MAINTENANCE) "
                  "VALUES (:nom, :marque, :type, :quantite, :prix, TO_DATE(:dateMaintenance, 'YYYY-MM-DD'))");

    query.bindValue(":nom", nom);
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":dateMaintenance", dateMaintenance.toString("yyyy-MM-dd"));

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur d'ajout : " + query.lastError().text());
        return false;
    }
}

bool Equipement::modifierEquipement() {
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENTS SET NOM_EQUIPEMENT = :nom, MARQUE = :marque, TYPE = :type, "
                  "QUANTITE = :quantite, PRIX_EQUIPEMENT = :prix, DATE_MAINTENANCE = TO_DATE(:dateMaintenance, 'YYYY-MM-DD') "
                  "WHERE ID_EQUIPEMENTS = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":dateMaintenance", dateMaintenance.toString("yyyy-MM-dd"));
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur de modification : " + query.lastError().text());
        return false;
    }
}

bool Equipement::supprimerEquipement() {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPEMENTS WHERE ID_EQUIPEMENTS = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur de suppression : " + query.lastError().text());
        return false;
    }
}

int Equipement::getId() const {
    return id;
}

QString Equipement::getNom() const {
    return nom;
}

QString Equipement::getMarque() const {
    return marque;
}

QString Equipement::getType() const {
    return type;
}

int Equipement::getQuantite() const {
    return quantite;
}

double Equipement::getPrix() const {
    return prix;
}

QDate Equipement::getDateMaintenance() const {
    return dateMaintenance;
}
