#ifndef INSTITUT_H
#define INSTITUT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class Institut
{
public:
    Institut();
    static bool ajouter(const QString &nom, const QString &adresse, const QString &responsable, int telephone, const QString &email, int capacite);
    static bool modifier(int id, const QString &nom, const QString &adresse, const QString &responsable, int telephone, const QString &email, int capacite);
    static bool supprimer(int id);
    static QSqlQueryModel* afficher();  // Retourne les données sous forme de modèle
    static QSqlQueryModel* rechercherParId(int id); // Recherche un institut par ID
};

#endif // INSTITUT_H
