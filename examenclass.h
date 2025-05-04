#ifndef EXAMENCLASS_H
#define EXAMENCLASS_H
#include <Qstring>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include <QMessageBox>



class examenclass
{   QString nomExamen, matiereExamen ,dateExamen, dureeExamen;
    int niveau, nbrCopies,idexamen;
public:
    //constructeurs
    examenclass(){};
    examenclass(QString,QString,QString,QString,int,int);
    examenclass(int,QString,QString,QString,QString,int,int);

    // Getters
    QString getnomExamen(){ return nomExamen;}
    QString getmatiereExamen(){ return matiereExamen; }
    QString getdateExamen(){ return dateExamen;}
    QString getdureeExamen(){return dureeExamen; }
    int getniveau(){ return niveau;}
    int getnbrCopies(){ return nbrCopies;}


    // setters
    void setnomExamen(QString n){ nomExamen=n;}
    void setmatiereExamen(QString m){ matiereExamen=m;}
    void setdateExamen(QString d){ dateExamen=d;}
    void setdureeExamen(QString dur){ dureeExamen=dur;}
    void setnbrCopies(int nbrCopies){ this->nbrCopies=nbrCopies;}
    void setniveau(int niveau){ this->niveau=niveau;}



    // fonctionalites

    bool ajouter();
   bool supprimer(int rowId, QSqlTableModel * model);  // Nouvelle signature
    QSqlQueryModel* afficher() ;
   bool supprimer(int id) ;
    bool modifier();

    QSqlQueryModel* ChercherParNiveau(int niveau);
    QSqlQueryModel* ChercherParMatiere(QString matiere);
    QSqlQueryModel* ChercherParDate(QString date);

    QSqlQueryModel* TRI(QString column,QString ordre) ;

    int countNiveau(int niveau) ;



};


#endif // EXAMENCLASS_H





