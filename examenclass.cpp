#include "examenclass.h"
#include <QMessageBox>
#include <qsqlerror.h>

examenclass::examenclass( QString nomExamen , QString matiereExamen, QString dateExamen ,QString dureeExamen ,int nbrCopies , int niveau){
    this->idexamen=idexamen;
    this->nomExamen=nomExamen;
    this->matiereExamen=matiereExamen;
    this->dateExamen=dateExamen;
    this->dureeExamen=dureeExamen;
    this->niveau=niveau;
    this->nbrCopies=nbrCopies;

}

examenclass::examenclass(int id, QString nomExamen , QString matiereExamen, QString dateExamen ,QString dureeExamen ,int nbrCopies , int niveau){
    this->idexamen=idexamen;
    this->nomExamen=nomExamen;
    this->matiereExamen=matiereExamen;
    this->dateExamen=dateExamen;
    this->dureeExamen=dureeExamen;
    this->niveau=niveau;
    this->nbrCopies=nbrCopies;
    this->idexamen=id;
}


bool examenclass::ajouter(){


    QSqlQuery query;
    query.prepare("INSERT INTO EXAMENS (NOMEXAMEN, MATIEREEXAMEN, DATEEXAMEN, DUREEEXAMEN, NBRCOPIES, NIVEAU) "
                  "VALUES (:nomExamen, :matiereExamen, :dateExamen, :dureeExamen, :nbrCopies, :niveau)");
    query.bindValue(":nomExamen", nomExamen);
    query.bindValue(":matiereExamen", matiereExamen);
    query.bindValue(":dateExamen", dateExamen);
    query.bindValue(":dureeExamen", dureeExamen);
    query.bindValue(":nbrCopies", nbrCopies); // Utilisez nbrCopies au lieu de nbcopies
    query.bindValue(":niveau", niveau);



    return query.exec();
}

bool examenclass::modifier(){


    QSqlQuery query;
    query.prepare("UPDATE  EXAMENS SET NOMEXAMEN=:nomExamen,MATIEREEXAMEN=:matiereExamen,DATEEXAMEN=:dateExamen,DUREEEXAMEN=:dureeExamen,NBRCOPIES=:nbrCopies,NIVEAU=:niveau WHERE IDEXAMEN=:id ");
    query.bindValue(":nomExamen", nomExamen);
    query.bindValue(":matiereExamen", matiereExamen);
    query.bindValue(":dateExamen", dateExamen);
    query.bindValue(":dureeExamen", dureeExamen);
    query.bindValue(":nbrCopies", nbrCopies); // Utilisez nbrCopies au lieu de nbcopies
    query.bindValue(":niveau", niveau);
    query.bindValue(":id", idexamen);



    return query.exec();
}


bool examenclass::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE  FROM EXAMENS WHERE IDEXAMEN=:id");
    query.bindValue(":id", id);
    return query.exec()==true;

}

QSqlQueryModel* examenclass::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EXAMENS ");
    query.exec();
    model->setQuery(query);
    return model;
}


QSqlQueryModel* examenclass::ChercherParNiveau(int niveau) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EXAMENS WHERE NIVEAU = :niveau");
    query.bindValue(":niveau", niveau);
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* examenclass::ChercherParMatiere(QString matiere) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EXAMENS WHERE MATIEREEXAMEN LIKE :matiere");
    query.bindValue(":matiere", "%" + matiere + "%");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* examenclass::ChercherParDate(QString date) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EXAMENS WHERE DATEEXAMEN = :date");
    query.bindValue(":date", date);
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* examenclass::TRI(QString column,QString ordre) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EXAMENS ORDER BY "+column+" "+ordre);
    query.exec();
    model->setQuery(query);
    return model;
}



int examenclass::countNiveau(int niveau) {
    QSqlQuery query;
    int count=0;
    query.prepare("SELECT COUNT(*)  FROM EXAMENS WHERE NIVEAU=:n");
    query.bindValue(":n", niveau);
    if(query.exec())
    {
        if(query.next())
        {
            count=query.value(0).toInt();
        }
    }
    return count;
}


/***************************************************/

