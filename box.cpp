#include "box.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Box::Box()
{
}

Box::Box(int idExamen, int idLivreur, int idInst,
         const QString &destination,
         const QString &status,
         const QString &etat)
{
    this->idExamen   = idExamen;
    this->idLivreur  = idLivreur;
    this->idInst     = idInst;
    this->destination= destination;
    this->status     = status;
    this->etat       = etat;
}

bool Box::ajouter()
{
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO KINZA.BOXS
        (IDEXAMEN, IDLIVREUR, ID_INST, DESTINATION, STATUS, ETAT)
        VALUES (:idExam, :idLiv, :idInst, :dest, :status, :etat)
    )");
    query.bindValue(":idExam",   idExamen);
    query.bindValue(":idLiv",    idLivreur);
    query.bindValue(":idInst",   idInst);
    query.bindValue(":dest",     destination);
    query.bindValue(":status",   status);
    query.bindValue(":etat",     etat);

    if(query.exec()) {
        return true;
    } else {
        qDebug() << "Box ajouter() error:" << query.lastError().text();
        return false;
    }
}

bool Box::modifier(int idBox)
{
    QSqlQuery query;
    query.prepare(R"(
        UPDATE KINZA.BOXS
        SET IDEXAMEN = :idExam,
            IDLIVREUR = :idLiv,
            ID_INST = :idInst,
            DESTINATION = :dest,
            STATUS = :status,
            ETAT = :etat
        WHERE ID_BOX = :idBox
    )");
    query.bindValue(":idExam",   idExamen);
    query.bindValue(":idLiv",    idLivreur);
    query.bindValue(":idInst",   idInst);
    query.bindValue(":dest",     destination);
    query.bindValue(":status",   status);
    query.bindValue(":etat",     etat);
    query.bindValue(":idBox",    idBox);

    if(query.exec()) {
        return true;
    } else {
        qDebug() << "Box modifier() error:" << query.lastError().text();
        return false;
    }
}

bool Box::supprimer(int idBox)
{
    QSqlQuery query;
    query.prepare("DELETE FROM KINZA.BOXS WHERE ID_BOX = :idBox");
    query.bindValue(":idBox", idBox);

    if(query.exec()) {
        return true;
    } else {
        qDebug() << "Box supprimer() error:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Box::afficher(const QString &search)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString baseQuery = R"(
        SELECT
            ID_BOX,
            IDEXAMEN,
            IDLIVREUR,
            ID_INST,
            DATE_CREATION,
            DESTINATION,
            STATUS,
            ETAT
        FROM KINZA.BOXS
    )";

    if(!search.isEmpty()) {
        baseQuery += " WHERE TO_CHAR(ID_BOX) LIKE '%" + search + "%'";
    }
    baseQuery += " ORDER BY ID_BOX";

    model->setQuery(baseQuery);
    return model;
}
