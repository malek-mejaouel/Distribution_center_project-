#ifndef BOX_H
#define BOX_H

#include <QString>
#include <QSqlQueryModel>

class Box
{
public:
    Box();
    Box(int idExamen, int idLivreur, int idInst,
        const QString &destination,
        const QString &status,
        const QString &etat);

    int idExamen;
    int idLivreur;
    int idInst;
    QString destination;
    QString status;
    QString etat;

    bool ajouter();
    bool modifier(int idBox);
    bool supprimer(int idBox);

    static QSqlQueryModel* afficher(const QString &search = QString());
};

#endif // BOX_H
