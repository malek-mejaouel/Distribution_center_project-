#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

class Equipement {
public:
    Equipement();
    Equipement(int id, const QString &nom, const QString &marque, const QString &type, int quantite, double prix, const QDate &dateMaintenance);

    bool ajouterEquipement();
    bool modifierEquipement();
    bool supprimerEquipement();

    int getId() const;
    QString getNom() const;
    QString getMarque() const;
    QString getType() const;
    int getQuantite() const;
    double getPrix() const;
    QDate getDateMaintenance() const;

private:
    int id;
    QString nom;
    QString marque;
    QString type;
    int quantite;
    double prix;
    QDate dateMaintenance;
};

#endif // EQUIPEMENT_H
