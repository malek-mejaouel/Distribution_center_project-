#ifndef INSTITUT_H
#define INSTITUT_H

#include <QString>
#include <QSqlQueryModel>

class Institut
{
public:
    Institut();

    // Getters
    int getId() const;
    QString getNom() const;
    QString getAdresse() const;
    QString getResponsable() const;
    int getTelephone() const;
    QString getEmail() const;
    int getCapacite() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setAdresse(const QString &adresse);
    void setResponsable(const QString &responsable);
    void setTelephone(int telephone);
    void setEmail(const QString &email);
    void setCapacite(int capacite);

    bool ajouter();
    bool modifier();
    bool supprimer();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercherParId();

    // Ajoutez cette déclaration
    bool validerDonnees();

private:
    int id;
    QString nom;
    QString adresse;
    QString responsable;
    int telephone;
    QString email;
    int capacite;
};

#endif // INSTITUT_H
