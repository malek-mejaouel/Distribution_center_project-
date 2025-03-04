#include "Employe.h"
#include <QSqlError>
#include <QDebug>

// Constructeurs
Employe::Employe() : id(0), nom(""), prenom(""), email(""),modpass(""), telephone(0), cin(0), date_embauche(""), role("") {}

Employe::Employe(int id, QString nom, QString prenom,QString modpass, QString email, int telephone, int cin, QString date_embauche, QString role)
    : id(id), nom(nom), prenom(prenom),modpass(modpass), email(email), telephone(telephone), cin(cin), date_embauche(date_embauche), role(role) {}

// Getters
int Employe::getId() const { return id; }
QString Employe::getNom() const { return nom; }
QString Employe::getPrenom() const { return prenom; }
QString Employe::getModpass() const { return modpass; }
QString Employe::getEmail() const { return email; }
int Employe::getTelephone() const { return telephone; }
int Employe::getCin() const { return cin; }
QString Employe::getDateEmbauche() const { return date_embauche; }
QString Employe::getRole() const { return role; }

// Setters
void Employe::setId(int id) { this->id = id; }
void Employe::setNom(QString nom) { this->nom = nom; }
void Employe::setModpass(QString modpass) { this->modpass = modpass; }
void Employe::setPrenom(QString prenom) { this->prenom = prenom; }
void Employe::setEmail(QString email) { this->email = email; }
void Employe::setTelephone(int telephone) { this->telephone = telephone; }
void Employe::setCin(int cin) { this->cin = cin; }
void Employe::setDateEmbauche(QString date_embauche) { this->date_embauche = date_embauche; }
void Employe::setRole(QString role) { this->role = role; }

// Ajouter un employé à la base de données
bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEES (NOM_EMPLOYE, PRENOM_EMPLOE, MODPASS, EMAIL, TELEPHONE, CIN, DATE_EMPLOYE, ROLE) "
                  "VALUES (:nom, :prenom, :modpass, :email, :telephone, :cin, TO_DATE(:date_embauche, 'YYYY-MM-DD'), :role)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":modpass", modpass);  // Ajout du champ modpass
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":cin", cin);
    query.bindValue(":date_embauche", date_embauche);
    query.bindValue(":role", role);

    if (query.exec()) {
        qDebug() << "Employé ajouté avec succès!";
        return true;
    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text();
        return false;
    }
}


// Modifier un employé existant
bool Employe::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEES SET NOM_EMPLOYE=:nom, PRENOM_EMPLOYE=:prenom, EMAIL=:email, "
                  "TELEPHONE=:telephone, CIN=:cin, DATE_EMPLOYE=TO_DATE(:date_embauche, 'YYYY-MM-DD'), ROLE=:role "
                  "WHERE ID_EMPLOYE=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":cin", cin);
    query.bindValue(":date_embauche", date_embauche);
    query.bindValue(":role", role);

    return query.exec();
}

// Supprimer un employé par ID
bool Employe::supprimer(int cin) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEES WHERE CIN = :cin");
    query.bindValue(":cin", cin);
    return query.exec();
}

// Afficher la liste des employés
QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEES");
    return model;
}
QSqlQueryModel* Employe::rechercher(int cin)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYEES WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de recherche: " << query.lastError().text();
        return nullptr;  // Return null if the query fails
    }

    model->setQuery(query);
    return model;
}
