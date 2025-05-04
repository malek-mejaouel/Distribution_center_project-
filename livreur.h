#ifndef LIVREUR_H
#define LIVREUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Livreur
{
    int idLivreur;
    int cinLivreur;
    QString nomLivreur;
    QString prenomLivreur;
    int telephoneLivreur;
    QString vehiculeLivreur;
    int nbrMaxBox;
    QString etatLivreur;
    QString emailLivreur;
    QString imagePath;

public:
    Livreur();
    Livreur(int cin, QString nom, QString prenom, int telephone, QString vehicule, int nbrMaxBox, QString etat, QString email, QString imagePath);

    int getId() const;
    int getCin() const;
    QString getNom() const;
    QString getPrenom() const;
    int getTelephone() const;
    QString getVehicule() const;
    int getNbrMaxBox() const;
    QString getEtat() const;
    QString getEmail() const;
    QString getImagePath() const;

    void setId(int id);
    void setCin(int cin);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setTelephone(int telephone);
    void setVehicule(const QString &vehicule);
    void setNbrMaxBox(int nbrMaxBox);
    void setEtat(const QString &etat);
    void setEmail(const QString &email);
    void setImagePath(const QString &imagePath);

    bool ajouter();
    bool modifier();
    QSqlQueryModel *afficher();
    bool supprimer(int id);
    QSqlQueryModel *rechercherParNom(const QString &name);
    QSqlQueryModel *rechercherParAttribut(const QString &attribut, const QString &value);
    QSqlQueryModel *trier(const QString &critere, const QString &ordre);

    bool validerCin(int cin);
    bool validerNomPrenom(const QString &nomPrenom);
    bool validerTelephone(int telephone);
    bool validerEmail(const QString &email);
    bool validerVehicule(const QString &vehicule);
    bool validerNbrMaxBox(int nbrMaxBox);
    static int obtenirIdBox(int idLivreur);
    static int obtenirIdEmploye(int idLivreur);
};

class Historique
{
public:
    static void enregistrerEvenement(const QString &evenement, int idLivreur, int idBox, int idEmploye);
    static QString lireHistorique();
    static void synchroniserHistorique();
};

#endif // LIVREUR_H
