#include "institut.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Institut::Institut() {}

bool Institut::ajouter(const QString &nom, const QString &adresse, const QString &responsable, int telephone, const QString &email, int capacite)
{
    QSqlQuery query;
    query.prepare("INSERT INTO INSTITUTS (NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST) "
                  "VALUES (:nom, :adresse, :responsable, :telephone, :email, :capacite)");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":responsable", responsable);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":capacite", capacite);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'institut : " << query.lastError().text();
        return false;
    }
    return true;
}

bool Institut::modifier(int id, const QString &nom, const QString &adresse, const QString &responsable, int telephone, const QString &email, int capacite)
{
    QSqlQuery query;
    query.prepare("UPDATE INSTITUTS SET NOM_INST = :nom, ADRESSE_INST = :adresse, RESPONSABLE_INST = :responsable, "
                  "TELEPHONE_INST = :telephone, EMAIL_INST = :email, CAPACITE_INST = :capacite WHERE ID_INST = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":responsable", responsable);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":capacite", capacite);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Institut::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Institut::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST FROM INSTITUTS");
    return model;
}

QSqlQueryModel* Institut::rechercherParId(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur de recherche:" << query.lastError().text();
    }
    return model;
}
