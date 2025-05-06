// institut.h
#ifndef INSTITUT_H
#define INSTITUT_H

#include <QString>
#include <QSqlQueryModel>
#include <QList>

class Institut
{
public:
    Institut();
    virtual ~Institut() = default;

    // Getters
    int getId() const;
    QString getNom() const;
    QString getAdresse() const;
    QString getResponsable() const;
    int getTelephone() const;
    QString getEmail() const;
    int getCapacite() const;
    int getIdEmployee() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setAdresse(const QString &adresse);
    void setResponsable(const QString &responsable);
    void setTelephone(int telephone);
    void setEmail(const QString &email);
    void setCapacite(int capacite);
    void setIdEmployee(int idEmployee);

    // CRUD + fetch operations
    bool ajouter();
    bool modifier();
    bool supprimer();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercherParId(int id);
    QSqlQueryModel* trier(const QString &critere, const QString &ordre);

    // Validation
    bool validerDonnees();
    bool validerDonnees(QString &erreur);

    // Statistics
    void calculerStatistiquesCapacite(int &total, double &average, int &min, int &max);

    // PDF export
    bool exporterPDF(const QString &filePath);

    // Employee IDs
    QList<int> obtenirIdsEmployes();
    bool associerEmploye(int idInstitut, int idEmploye);

private:
    int    id;
    QString nom;
    QString adresse;
    QString responsable;
    int    telephone;
    QString email;
    int    capacite;
    int    idEmployee;
};

#endif // INSTITUT_H
