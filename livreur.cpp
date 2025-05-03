#include "livreur.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QSet>

Livreur::Livreur() {}

Livreur::Livreur(int cin, QString nom, QString prenom, int telephone, QString vehicule, int nbrMaxBox, QString etat, QString email, QString imagePath)
    : cinLivreur(cin), nomLivreur(nom), prenomLivreur(prenom), telephoneLivreur(telephone),
    vehiculeLivreur(vehicule), nbrMaxBox(nbrMaxBox), etatLivreur(etat), emailLivreur(email), imagePath(imagePath) {}

int Livreur::getId() const { return idLivreur; }
int Livreur::getCin() const { return cinLivreur; }
QString Livreur::getNom() const { return nomLivreur; }
QString Livreur::getPrenom() const { return prenomLivreur; }
int Livreur::getTelephone() const { return telephoneLivreur; }
QString Livreur::getVehicule() const { return vehiculeLivreur; }
int Livreur::getNbrMaxBox() const { return nbrMaxBox; }
QString Livreur::getEtat() const { return etatLivreur; }
QString Livreur::getEmail() const { return emailLivreur; }
QString Livreur::getImagePath() const { return imagePath; }

void Livreur::setId(int id) { idLivreur = id; }
void Livreur::setCin(int cin) { cinLivreur = cin; }
void Livreur::setNom(const QString &nom) { nomLivreur = nom; }
void Livreur::setPrenom(const QString &prenom) { prenomLivreur = prenom; }
void Livreur::setTelephone(int telephone) { telephoneLivreur = telephone; }
void Livreur::setVehicule(const QString &vehicule) { vehiculeLivreur = vehicule; }
void Livreur::setNbrMaxBox(int nbrMaxBox) { this->nbrMaxBox = nbrMaxBox; }
void Livreur::setEtat(const QString &etat) { etatLivreur = etat; }
void Livreur::setEmail(const QString &email) { emailLivreur = email; }
void Livreur::setImagePath(const QString &path) { imagePath = path; }

bool Livreur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO LIVREURES (CINLIVREUR, NOMLIVREUR, PRENOMLIVREUR, TELEPHONELIVREUR, VEHICULELIVREUR, NBRMAXBOX, ETATLIVREUR, EMAILLIVREUR, IMAGEPATH) "
                  "VALUES (:cin, :nom, :prenom, :telephone, :vehicule, :nbrMaxBox, :etat, :email, :imagePath)");
    query.bindValue(":cin", cinLivreur);
    query.bindValue(":nom", nomLivreur);
    query.bindValue(":prenom", prenomLivreur);
    query.bindValue(":telephone", telephoneLivreur);
    query.bindValue(":vehicule", vehiculeLivreur);
    query.bindValue(":nbrMaxBox", nbrMaxBox);
    query.bindValue(":etat", etatLivreur);
    query.bindValue(":email", emailLivreur);
    query.bindValue(":imagePath", imagePath);

    if (query.exec()) {
        int idLivreur = query.lastInsertId().toInt();
        int idBox = obtenirIdBox(idLivreur);
        int idEmploye = obtenirIdEmploye(idLivreur);
        Historique::enregistrerEvenement("Ajout du livreur : " + nomLivreur + " " + prenomLivreur, idLivreur, idBox, idEmploye);
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout du livreur :" << query.lastError().text();
        return false;
    }
}

bool Livreur::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE LIVREURES SET CINLIVREUR = :cin, NOMLIVREUR = :nom, PRENOMLIVREUR = :prenom, "
                  "TELEPHONELIVREUR = :telephone, VEHICULELIVREUR = :vehicule, NBRMAXBOX = :nbrMaxBox, "
                  "ETATLIVREUR = :etat, EMAILLIVREUR = :email, IMAGEPATH = :imagePath WHERE IDLIVREUR = :id");
    query.bindValue(":cin", cinLivreur);
    query.bindValue(":nom", nomLivreur);
    query.bindValue(":prenom", prenomLivreur);
    query.bindValue(":telephone", telephoneLivreur);
    query.bindValue(":vehicule", vehiculeLivreur);
    query.bindValue(":nbrMaxBox", nbrMaxBox);
    query.bindValue(":etat", etatLivreur);
    query.bindValue(":email", emailLivreur);
    query.bindValue(":imagePath", imagePath);
    query.bindValue(":id", idLivreur);

    if (query.exec()) {
        int idBox = obtenirIdBox(idLivreur);
        int idEmploye = obtenirIdEmploye(idLivreur);
        Historique::enregistrerEvenement("Modification du livreur : " + nomLivreur + " " + prenomLivreur, idLivreur, idBox, idEmploye);
        return true;
    } else {
        qDebug() << "Erreur lors de la modification du livreur :" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel *Livreur::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIVREURES");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des livreurs :" << model->lastError().text();
    } else {
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbr Max Box"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("État"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Image"));
    }
    return model;
}


bool Livreur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM LIVREURES WHERE IDLIVREUR = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        int idBox = obtenirIdBox(id);
        int idEmploye = obtenirIdEmploye(id);
        Historique::enregistrerEvenement("Suppression du livreur avec ID : " + QString::number(id), id, idBox, idEmploye);
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression du livreur :" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel *Livreur::rechercherParNom(const QString &name)
{
    return rechercherParAttribut("NOMLIVREUR", name);
}

QSqlQueryModel *Livreur::rechercherParAttribut(const QString &attribut, const QString &value)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT IDLIVREUR, CINLIVREUR, NOMLIVREUR, PRENOMLIVREUR, "
                  "TELEPHONELIVREUR, VEHICULELIVREUR, NBRMAXBOX, ETATLIVREUR, EMAILLIVREUR "
                  "FROM LIVREURES WHERE UPPER(" + attribut + ") LIKE UPPER(:value)");
    query.bindValue(":value", "%" + value + "%");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbr Max Box"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("État"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
    } else {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
    }
    return model;
}

QSqlQueryModel *Livreur::trier(const QString &critere, const QString &ordre)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM LIVREURES ORDER BY " + critere + " " + ordre;
    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri des livreurs :" << model->lastError().text();
    } else {
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbr Max Box"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("État"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
    }
    return model;
}


bool Livreur::validerCin(int cin)
{
    return (cin >= 10000000 && cin <= 99999999);
}

bool Livreur::validerNomPrenom(const QString &nomPrenom)
{
    QRegularExpression nomPrenomRegex("^[A-Za-zÀ-ÿ]+$");
    return nomPrenomRegex.match(nomPrenom).hasMatch();
}

bool Livreur::validerTelephone(int telephone)
{
    return telephone >= 10000000 && telephone <= 99999999;
}

bool Livreur::validerEmail(const QString &email)
{
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

bool Livreur::validerVehicule(const QString &vehicule)
{
    return !vehicule.isEmpty();
}

bool Livreur::validerNbrMaxBox(int nbrMaxBox)
{
    return nbrMaxBox > 0;
}

void Historique::enregistrerEvenement(const QString &evenement, int idLivreur, int idBox, int idEmploye) {
    QFile file("C:/Users/MSI/Desktop/val/historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
               << " - " << evenement
               << " - ID Livreur: " << idLivreur
               << " - ID Box: " << idBox
               << " - ID Employe: " << idEmploye
               << "\n";
        file.close();
        qDebug() << "Événement enregistré dans l'historique.";
    } else {
        qDebug() << "Erreur lors de l'ouverture du fichier historique.";
    }
}

QString Historique::lireHistorique() {
    QFile file("C:/Users/MSI/Desktop/val/historique.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        return stream.readAll();
    }
    qDebug() << "Erreur lors de l'ouverture du fichier historique.";
    return "Aucun historique disponible.";
}

int Livreur::obtenirIdBox(int idLivreur) {
    QSqlQuery query;
    query.prepare("SELECT idBox FROM BOXES WHERE idLivreur = :idLivreur");
    query.bindValue(":idLivreur", idLivreur);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

int Livreur::obtenirIdEmploye(int idLivreur) {
    QSqlQuery query;
    query.prepare("SELECT idEmploye FROM GERER WHERE idLivreur = :idLivreur");
    query.bindValue(":idLivreur", idLivreur);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

void Historique::synchroniserHistorique() {
    QFile file("C:/Users/MSI/Desktop/val/historique.txt");
    QSet<QString> existingEntries;

    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains("ID Livreur:")) {
                QStringList parts = line.split("ID Livreur:");
                if (parts.size() > 1) {
                    QString idStr = parts[1].split(" ")[1];
                    existingEntries.insert(idStr.trimmed());
                }
            }
        }
        file.close();
    }

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QSqlQuery query("SELECT IDLIVREUR, NOMLIVREUR, PRENOMLIVREUR FROM LIVREURES");

        while (query.next()) {
            int idLivreur = query.value(0).toInt();
            QString idStr = QString::number(idLivreur);

            if (!existingEntries.contains(idStr)) {
                QString nom = query.value(1).toString();
                QString prenom = query.value(2).toString();
                int idBox = Livreur::obtenirIdBox(idLivreur);
                int idEmploye = Livreur::obtenirIdEmploye(idLivreur);

                out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")
                    << " - Ajout initial du livreur : " << nom << " " << prenom
                    << " - ID Livreur: " << idLivreur
                    << " - ID Box: " << idBox
                    << " - ID Employe: " << idEmploye
                    << "\n";
            }
        }
        file.close();
    }
}
