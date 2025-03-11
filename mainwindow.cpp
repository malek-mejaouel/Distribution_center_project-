#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug> // Pour le débogage

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialiser le modèle de la table
    model = new QSqlTableModel(this);
    model->setTable("EXAMENS"); // Remplacez par le nom de votre table
    model->select(); // Charger les données de la table

    // Lier le modèle à la QTableView
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    // Récupérer les valeurs saisies par l'utilisateur
    QString nomExamen = ui->nomExamenLineEdit->text();
    QString matiereExamen = ui->matiereExamenLineEdit->text();
    QString dateExamen = ui->dateExamenDateEdit->text();
    QString dureeExamen = ui->dureeExamenLimeEdit->text();
    int nbrCopies = ui->nbcopiesSpinBox->value();
    int  niveau = ui->niveauSpinBox->value();

    // Vérifier que les champs obligatoires ne sont pas vides
    if (nomExamen.isEmpty() || matiereExamen.isEmpty() || dateExamen.isEmpty() || dureeExamen.isEmpty()  ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    if(niveau==0 || niveau>5){
        QMessageBox::warning(this, "Niveau invalide ! ", "Veuillez remplacer le champ niveau par un niveau existant.");
        return;
    }

    if(nbrCopies==0){
        QMessageBox::warning(this, " Copies nulles ! ", "Veuillez Saisir au moins une copie.");
        return;
    }


    // Préparer la requête SQL pour insérer un nouvel examen
    QSqlQuery query;
    query.prepare("INSERT INTO EXAMENS (NOMEXAMEN, MATIEREEXAMEN, DATEEXAMEN, DUREEEXAMEN, NBRCOPIES, NIVEAU) "
                  "VALUES (:nomExamen, :matiereExamen, :dateExamen, :dureeExamen, :nbrCopies, :niveau)");
    query.bindValue(":nomExamen", nomExamen);
    query.bindValue(":matiereExamen", matiereExamen);
    query.bindValue(":dateExamen", dateExamen);
    query.bindValue(":dureeExamen", dureeExamen);
    query.bindValue(":nbrCopies", nbrCopies); // Utilisez nbrCopies au lieu de nbcopies
    query.bindValue(":niveau", niveau);

    // Exécuter la requête
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Examen ajouté avec succès !");
        model->select(); // Rafraîchir la table pour afficher le nouvel examen
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'examen : " + query.lastError().text());
    }
}


void MainWindow::on_updateButton_clicked() {
    // Récupérer l'index de la ligne sélectionnée dans la table
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un examen à modifier.");
        return;
    }

    // Récupérer l'IDEXAMEN de la ligne sélectionnée
    int idExamen = model->data(model->index(index.row(), 0)).toInt(); // Colonne 0 : IDEXAMEN
    if (idExamen <= 0) {
        QMessageBox::critical(this, "Erreur", "IDEXAMEN invalide.");
        return;
    }

    // Récupérer les nouvelles valeurs saisies par l'utilisateur
    QString nomExamen = ui->nomExamenLineEdit->text();
    QString matiereExamen = ui->matiereExamenLineEdit->text();
    QString dateExamen = ui->dateExamenDateEdit->text();
    QString dureeExamen = ui->dureeExamenLimeEdit->text();
    int nbrCopies = ui->nbcopiesSpinBox->value();
    int niveau = ui->niveauSpinBox->value();

    // Vérifier si au moins un champ a été modifié
    bool hasUpdate = false;

    // Préparer la requête SQL pour mettre à jour l'examen
    QString queryStr = "UPDATE EXAMENS SET ";
    if (!nomExamen.isEmpty()) {
        queryStr += "NOMEXAMEN = :nomExamen, ";
        hasUpdate = true;
    }
    if (!matiereExamen.isEmpty()) {
        queryStr += "MATIEREEXAMEN = :matiereExamen, ";
        hasUpdate = true;
    }
    if (!dateExamen.isEmpty()) {
        queryStr += "DATEEXAMEN = :dateExamen, ";
        hasUpdate = true;
    }
    if (!dureeExamen.isEmpty()) {
        queryStr += "DUREEEXAMEN = :dureeExamen, ";
        hasUpdate = true;
    }
    if (nbrCopies > 0) {
        queryStr += "NBRCOPIES = :nbrCopies, ";
        hasUpdate = true;
    }
    if (niveau > 0 && niveau <= 5) { // Vérifier que le niveau est valide (1 à 5)
        queryStr += "NIVEAU = :niveau, ";
        hasUpdate = true;
    }

    // Supprimer la dernière virgule et ajouter la clause WHERE
    if (hasUpdate) {
        queryStr = queryStr.left(queryStr.length() - 2); // Supprimer la dernière virgule et l'espace
        queryStr += " WHERE IDEXAMEN = :idExamen";
    } else {
        QMessageBox::warning(this, "Aucune modification", "Aucun champ à modifier.");
        return;
    }

    // Exécuter la requête SQL pour mettre à jour la base de données
    QSqlQuery query;
    query.prepare(queryStr);
    if (!nomExamen.isEmpty()) query.bindValue(":nomExamen", nomExamen);
    if (!matiereExamen.isEmpty()) query.bindValue(":matiereExamen", matiereExamen);
    if (!dateExamen.isEmpty()) query.bindValue(":dateExamen", dateExamen);
    if (!dureeExamen.isEmpty()) query.bindValue(":dureeExamen", dureeExamen);
    if (nbrCopies > 0) query.bindValue(":nbrCopies", nbrCopies);
    if (niveau > 0 && niveau <= 5) query.bindValue(":niveau", niveau);
    query.bindValue(":idExamen", idExamen);

    // Afficher la requête SQL et les valeurs bindées pour le débogage
    qDebug() << "Requête SQL :" << query.lastQuery();
    qDebug() << "Valeurs bindées :";
    qDebug() << "nomExamen :" << nomExamen;
    qDebug() << "matiereExamen :" << matiereExamen;
    qDebug() << "dateExamen :" << dateExamen;
    qDebug() << "dureeExamen :" << dureeExamen;
    qDebug() << "nbrCopies :" << nbrCopies;
    qDebug() << "niveau :" << niveau;
    qDebug() << "idExamen :" << idExamen;

    // Exécuter la requête
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès dans la base de données !");
        model->select(); // Rafraîchir la table pour afficher les modifications
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text(); // Afficher l'erreur SQL
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification : " + query.lastError().text());
    }
}
void MainWindow::on_pushButton_18_clicked() {
    qDebug() << "Bouton Supprimer cliqué.";

    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        qDebug() << "Aucune ligne sélectionnée.";
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un examen à supprimer.");
        return;
    }

    qDebug() << "Ligne sélectionnée :" << index.row();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Êtes-vous sûr de vouloir supprimer cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        qDebug() << "Suppression annulée par l'utilisateur.";
        return;
    }

    qDebug() << "Tentative de suppression de la ligne :" << index.row();
    bool removeSuccess = model->removeRow(index.row());
    if (!removeSuccess) {
        qDebug() << "Erreur lors de la suppression de la ligne :" << model->lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : " + model->lastError().text());
        return;
    }

    qDebug() << "Ligne supprimée du modèle. Tentative de soumission à la base de données...";
    bool submitSuccess = model->submitAll();
    if (submitSuccess) {
        qDebug() << "Suppression réussie dans la base de données.";
        QMessageBox::information(this, "Succès", "Examen supprimé avec succès !");
        model->select(); // Rafraîchir la table
    } else {
        qDebug() << "Erreur lors de la soumission à la base de données :" << model->lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : " + model->lastError().text());
    }
}


