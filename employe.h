#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe {
private:
    int id;
    QString nom;
    QString prenom;
    QString email;
    QString modpass;
    int telephone;
    int cin;
    QString date_embauche;
    QString role;

public:
    // Constructeurs
    Employe();
    Employe(int id, QString nom, QString prenom, QString modpass, QString email,
            int telephone, int cin, QString date_embauche, QString role);

    // Getters et Setters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getModpass() const;
    int getTelephone() const;
    int getCin() const;
    QString getDateEmbauche() const;
    QString getRole() const;

    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setEmail(QString email);
    void setModpass(QString modpass);
    void setTelephone(int telephone);
    void setCin(int cin);
    void setDateEmbauche(QString date_embauche);
    void setRole(QString role);

    // Méthodes CRUD
    bool ajouter();
    bool modifier(int cin, QString nom, QString prenom, QString email, int telephone, QString date_employe, QString modpass, QString role);
    bool supprimer(int cin);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(int cin);
};

#endif // EMPLOYE_H
