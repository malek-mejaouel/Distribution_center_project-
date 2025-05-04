#include "institut.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QTextDocument>
#include <QPrinter>
#include <QDate>
#include <QFileInfo>
#include <QSqlRecord>

Institut::Institut() :
    id(-1), telephone(0), capacite(0), idEmployee(0)
{
}

int Institut::getId() const {
    return id;
}

QString Institut::getNom() const {
    return nom;
}

QString Institut::getAdresse() const {
    return adresse;
}

QString Institut::getResponsable() const {
    return responsable;
}

int Institut::getTelephone() const {
    return telephone;
}

QString Institut::getEmail() const {
    return email;
}

int Institut::getCapacite() const {
    return capacite;
}

int Institut::getIdEmployee() const {
    return idEmployee;
}

void Institut::setId(int id) {
    this->id = id;
}

void Institut::setNom(const QString &nom) {
    this->nom = nom;
}

void Institut::setAdresse(const QString &adresse) {
    this->adresse = adresse;
}

void Institut::setResponsable(const QString &responsable) {
    this->responsable = responsable;
}

void Institut::setTelephone(int telephone) {
    this->telephone = telephone;
}

void Institut::setEmail(const QString &email) {
    this->email = email;
}

void Institut::setCapacite(int capacite) {
    this->capacite = capacite;
}

void Institut::setIdEmployee(int idEmployee) {
    this->idEmployee = idEmployee;
}

QSqlQueryModel* Institut::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, "
                       "TELEPHONE_INST, EMAIL_INST, CAPACITE_INST, "
                       "COALESCE(ID_EMPLOYE, 0) AS ID_EMPLOYE " // Garantit un ID même si NULL
                       "FROM INSTITUTS";

    model->setQuery(queryStr);

    // Débogage des données récupérées
    qDebug() << "Nombre d'instituts:" << model->rowCount();
    if (model->rowCount() > 0) {
        qDebug() << "Premier institut - ID Employee:" << model->record(0).value("ID_EMPLOYE").toInt();
    }

    return model;
}

bool Institut::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO INSTITUTS (NOM_INST, ADRESSE_INST, RESPONSABLE_INST, "
                  "TELEPHONE_INST, EMAIL_INST, CAPACITE_INST, ID_EMPLOYE) "
                  "VALUES (:nom, :adresse, :responsable, :telephone, :email, :capacite, :id_employe)");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":responsable", responsable);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":capacite", capacite);
    query.bindValue(":id_employe", idEmployee > 0 ? idEmployee : QVariant(QVariant::Int)); // Gère NULL si idEmployee <= 0

    if (!query.exec()) {
        qDebug() << "Erreur d'ajout:" << query.lastError().text();
        qDebug() << "Requête SQL:" << query.lastQuery();
        return false;
    }
    return true;
}



bool Institut::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE INSTITUTS SET "
                  "NOM_INST = :nom, "
                  "ADRESSE_INST = :adresse, "
                  "RESPONSABLE_INST = :responsable, "
                  "TELEPHONE_INST = :telephone, "
                  "EMAIL_INST = :email, "
                  "CAPACITE_INST = :capacite, "
                  "ID_EMPLOYE = :id_employe "
                  "WHERE ID_INST = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":responsable", responsable);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":capacite", capacite);
    query.bindValue(":id_employe", idEmployee > 0 ? idEmployee : QVariant(QVariant::Int));
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur de modification:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Institut::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", this->id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'institut : " << query.lastError().text();
        return false;
    }
    return true;
}


bool Institut::validerDonnees()
{
    QString erreur; // Variable locale non utilisée
    return validerDonnees(erreur);
}

bool Institut::validerDonnees(QString &erreur)
{
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    if (!emailRegex.match(this->email).hasMatch()) {
        erreur = "Email invalide.";
        return false;
    }

    QString phoneNumber = QString::number(this->telephone);
    QRegularExpression phoneRegex("^[25794]\\d{7}$");
    if (phoneNumber.length() != 8 || !phoneRegex.match(phoneNumber).hasMatch()) {
        erreur = "Numéro de téléphone invalide. Il doit contenir 8 chiffres et commencer par 2, 5, 7, 9 ou 4.";
        return false;
    }

    int capaciteVerifiee = this->capacite;
    if (capaciteVerifiee <= 0 || capaciteVerifiee > 1000000) {
        erreur = "Capacité invalide. Elle doit être un nombre positif et ne pas dépasser 1,000,000.";
        return false;
    }

    if (this->nom.isEmpty()) {
        erreur = "Le nom de l'institut ne peut pas être vide.";
        return false;
    }

    if (this->adresse.isEmpty()) {
        erreur = "L'adresse de l'institut ne peut pas être vide.";
        return false;
    }

    QRegularExpression responsableRegex("^[A-Za-z\\s]+$");
    if (!responsableRegex.match(this->responsable).hasMatch()) {
        erreur = "Le nom du responsable ne peut contenir que des lettres et des espaces.";
        return false;
    }

    return true;
}

QSqlQueryModel* Institut::rechercherParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM INSTITUTS WHERE ID_INSTITUT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur recherche:" << query.lastError();
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    // Configurer les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    // ... autres en-têtes

    return model;
}

QSqlQueryModel* Institut::trier(const QString &critere, const QString &ordre)
{
    QStringList colonnesValides = {
        "ID_INST", "NOM_INST", "ADRESSE_INST", "RESPONSABLE_INST",
        "TELEPHONE_INST", "EMAIL_INST", "CAPACITE_INST", "ID_EMPLOYE"
    };

    if (!colonnesValides.contains(critere)) {
        qDebug() << "Critère de tri invalide :" << critere;
        return nullptr;
    }

    if (ordre != "ASC" && ordre != "DESC") {
        qDebug() << "Ordre de tri invalide :" << ordre;
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QString requete = QString(
        "SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, "
        "TELEPHONE_INST, EMAIL_INST, CAPACITE_INST, ID_EMPLOYE "
        "FROM INSTITUTS "
        );

    if (critere == "ADRESSE_INST") {
        requete += "ORDER BY LOWER(ADRESSE_INST) " + ordre;
    } else {
        requete += "ORDER BY " + critere + " " + ordre;
    }

    model->setQuery(requete);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

void Institut::calculerStatistiquesCapacite(int &total, double &average, int &min, int &max)
{
    QSqlQuery query;
    if (!query.exec("SELECT CAPACITE_INST FROM INSTITUTS")) {
        qDebug() << "Erreur lors de la récupération des capacités : " << query.lastError().text();
        return;
    }

    total = 0;
    int count = 0;
    min = std::numeric_limits<int>::max();
    max = std::numeric_limits<int>::min();

    while (query.next()) {
        int capacite = query.value(0).toInt();
        total += capacite;
        count++;
        if (capacite < min) min = capacite;
        if (capacite > max) max = capacite;
    }

    if (count > 0) {
        average = static_cast<double>(total) / count;
    } else {
        average = 0;
    }
}

bool Institut::exporterPDF(const QString &filePath)
{
    qDebug() << "Début de l'export PDF vers:" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "Erreur: chemin vide";
        return false;
    }

    QSqlQuery query;
    if (!query.exec("SELECT * FROM INSTITUTS")) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return false;
    }

    QString html;
    html += "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
    html += "<style>";
    html += "body { font-family: Arial; margin: 1cm; }";
    html += "h1 { color: #2c3e50; text-align: center; }";
    html += "table { width: 100%; border-collapse: collapse; margin-top: 20px; }";
    html += "th { background-color: #3498db; color: white; padding: 10px; text-align: left; }";
    html += "td { padding: 8px; border: 1px solid #ddd; }";
    html += "</style></head><body>";
    html += "<h1>Liste des Instituts</h1>";
    html += "<table><tr>";

    QSqlRecord record = query.record();
    for (int i = 0; i < record.count(); ++i) {
        html += "<th>" + record.fieldName(i) + "</th>";
    }
    html += "</tr>";

    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < record.count(); ++i) {
            html += "<td>" + query.value(i).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    qDebug() << "PDF généré avec succès";
    return true;
}

QList<int> Institut::obtenirIdsEmployes()
{
    QList<int> idsEmployes;
    QSqlQuery query;

    if (!query.exec("SELECT ID_EMPLOYE FROM employees")) {
        qDebug() << "Erreur lors de la récupération des IDs des employés : " << query.lastError().text();
        return idsEmployes; // Retourne une liste vide en cas d'erreur
    }

    while (query.next()) {
        int idEmploye = query.value(0).toInt();
        idsEmployes.append(idEmploye);
    }

    return idsEmployes;
}

bool Institut::associerEmploye(int idInstitut, int idEmploye)
{
    QSqlQuery query;
    query.prepare("UPDATE INSTITUTS SET ID_EMPLOYE = :id_employe WHERE ID_INST = :id_inst");
    query.bindValue(":id_employe", idEmploye);
    query.bindValue(":id_inst", idInstitut);

    return query.exec();
}
