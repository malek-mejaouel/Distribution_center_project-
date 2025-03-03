#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QRegularExpression>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation du tableau pour afficher les livreurs
    setupTable();
    loadTableData(); // Charger les données existantes

    // Utilisation d'un timer pour rafraîchir la liste périodiquement (toutes les 5 secondes)
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::loadTableData);
    timer->start(5000);  // Rafraîchissement automatique
}

MainWindow::~MainWindow()
{
    delete ui;
}

// **Méthode pour configurer le tableau tab1**
void MainWindow::setupTable()
{
    ui->tab1->setColumnCount(9); // Ajout d'une colonne pour ID Livre
    ui->tab1->setHorizontalHeaderLabels({"ID", "CIN", "Nom", "Prénom", "Téléphone", "Véhicule", "Nbr Max Box", "État", "Email"});
    ui->tab1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connecter le signal de sélection de ligne pour modifier ou supprimer
    connect(ui->tab1, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);
}

// **Méthode pour charger les données dans tab1**
void MainWindow::loadTableData()
{
    QSqlQuery query("SELECT IDLIVREUR, CINLIVREUR, NOMLIVREUR, PRENOMLIVREUR, "
                    "TELEPHONELIVREUR, VEHICULELIVREUR, NBRMAXBOX, ETATLIVREUR, EMAILLIVREUR FROM LIVREURES");

    ui->tab1->setRowCount(0); // Réinitialisation du tableau avant d'ajouter les nouvelles lignes
    int row = 0;

    while (query.next()) {
        ui->tab1->insertRow(row);
        ui->tab1->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID Livre
        ui->tab1->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // CIN
        ui->tab1->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Nom
        ui->tab1->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Prénom
        ui->tab1->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Téléphone
        ui->tab1->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Véhicule
        ui->tab1->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Nombre max box
        ui->tab1->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // État
        ui->tab1->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // Email

        row++;
    }
}

// **Ajout d'un livreur à la base de données**
void MainWindow::on_b1_clicked()
{
    // Récupérer les données du formulaire
    QString cinLivreur = ui->cin->text();
    QString nomLivreur = ui->nom->text();
    QString prenomLivreur = ui->prenom->text();
    QString telephoneStr = ui->tel->text();
    QString vehiculeLivreur = ui->vehicule->text();
    QString nbrMaxBoxStr = ui->nb->text();
    QString emailLivreur = ui->email->text();

    // Expressions régulières pour la validation des entrées
    QRegularExpression cinRegex("^[0-9]{8}$");
    QRegularExpression nomPrenomRegex("^[A-Za-zÀ-ÿ]+$");
    QRegularExpression telRegex("^[0-9]{8}$");
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

    if (!cinRegex.match(cinLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "CIN invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!nomPrenomRegex.match(nomLivreur).hasMatch() || !nomPrenomRegex.match(prenomLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }
    if (!telRegex.match(telephoneStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }
    if (!emailRegex.match(emailLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide !");
        return;
    }

    QString etatLivreur;
    if (ui->libre->isChecked()) {
        etatLivreur = "Libre";
    } else if (ui->non->isChecked()) {
        etatLivreur = "Non";
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner l'état du livreur !");
        return;
    }

    bool boxOk;
    int nbrMaxBox = nbrMaxBoxStr.toInt(&boxOk);
    if (!boxOk || nbrMaxBox <= 0) {
        QMessageBox::warning(this, "Erreur", "Nombre maximal de box invalide !");
        return;
    }

    if (cinLivreur.isEmpty() || nomLivreur.isEmpty() || prenomLivreur.isEmpty() || vehiculeLivreur.isEmpty() || emailLivreur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Requête d'insertion
    QSqlQuery query;
    query.prepare("INSERT INTO LIVREURES (CINLIVREUR, NOMLIVREUR, PRENOMLIVREUR, TELEPHONELIVREUR, "
                  "VEHICULELIVREUR, NBRMAXBOX, ETATLIVREUR, EMAILLIVREUR) "
                  "VALUES (:cinLivreur, :nomLivreur, :prenomLivreur, :telephone, "
                  ":vehiculeLivreur, :nbrMaxBox, :etatLivreur, :emailLivreur)");

    query.bindValue(":cinLivreur", cinLivreur);
    query.bindValue(":nomLivreur", nomLivreur);
    query.bindValue(":prenomLivreur", prenomLivreur);
    query.bindValue(":telephone", telephoneStr.toInt());
    query.bindValue(":vehiculeLivreur", vehiculeLivreur);
    query.bindValue(":nbrMaxBox", nbrMaxBox);
    query.bindValue(":etatLivreur", etatLivreur);
    query.bindValue(":emailLivreur", emailLivreur);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Livreur ajouté avec succès !");
        loadTableData(); // Mettre à jour la table immédiatement après l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur d'ajout : " + query.lastError().text());
    }
}

// **Réinitialisation des champs**
void MainWindow::on_b2_clicked()
{
    ui->cin->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->tel->clear();
    ui->vehicule->clear();
    ui->nb->clear();
    ui->email->clear();
    ui->libre->setChecked(false);
    ui->non->setChecked(false);
}

// **Méthode pour modifier un livreur dans la base de données**
void MainWindow::on_b3_clicked()
{
    if (selectedLivreurId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un livreur à modifier !");
        return;
    }

    // Récupérer les valeurs des champs
    QString cinLivreur = ui->cin->text();
    QString nomLivreur = ui->nom->text();
    QString prenomLivreur = ui->prenom->text();
    QString telephoneStr = ui->tel->text();
    QString vehiculeLivreur = ui->vehicule->text();
    QString nbrMaxBoxStr = ui->nb->text();
    QString emailLivreur = ui->email->text();

    // Expressions régulières pour la validation des entrées
    QRegularExpression cinRegex("^[0-9]{8}$");
    QRegularExpression nomPrenomRegex("^[A-Za-zÀ-ÿ]+$");
    QRegularExpression telRegex("^[0-9]{8}$");
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

    if (!cinRegex.match(cinLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "CIN invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!nomPrenomRegex.match(nomLivreur).hasMatch() || !nomPrenomRegex.match(prenomLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }
    if (!telRegex.match(telephoneStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }
    if (!emailRegex.match(emailLivreur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide !");
        return;
    }

    QString etatLivreur;
    if (ui->libre->isChecked()) {
        etatLivreur = "Libre";
    } else if (ui->non->isChecked()) {
        etatLivreur = "Non";
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner l'état du livreur !");
        return;
    }

    bool boxOk;
    int nbrMaxBox = nbrMaxBoxStr.toInt(&boxOk);
    if (!boxOk || nbrMaxBox <= 0) {
        QMessageBox::warning(this, "Erreur", "Nombre maximal de box invalide !");
        return;
    }

    if (cinLivreur.isEmpty() || nomLivreur.isEmpty() || prenomLivreur.isEmpty() || vehiculeLivreur.isEmpty() || emailLivreur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Requête de mise à jour
    QSqlQuery query;
    query.prepare("UPDATE LIVREURES SET CINLIVREUR = :cinLivreur, NOMLIVREUR = :nomLivreur, "
                  "PRENOMLIVREUR = :prenomLivreur, TELEPHONELIVREUR = :telephone, "
                  "VEHICULELIVREUR = :vehiculeLivreur, NBRMAXBOX = :nbrMaxBox, "
                  "ETATLIVREUR = :etatLivreur, EMAILLIVREUR = :emailLivreur WHERE IDLIVREUR = :id");

    query.bindValue(":cinLivreur", cinLivreur);
    query.bindValue(":nomLivreur", nomLivreur);
    query.bindValue(":prenomLivreur", prenomLivreur);
    query.bindValue(":telephone", telephoneStr.toInt());
    query.bindValue(":vehiculeLivreur", vehiculeLivreur);
    query.bindValue(":nbrMaxBox", nbrMaxBox);
    query.bindValue(":etatLivreur", etatLivreur);
    query.bindValue(":emailLivreur", emailLivreur);
    query.bindValue(":id", selectedLivreurId);  // L'ID sélectionné pour modification

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Livreur modifié avec succès !");
        loadTableData();  // Mettre à jour la table après modification
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur de modification : " + query.lastError().text());
    }
}

// **Méthode pour supprimer un livreur de la base de données**
void MainWindow::on_b4_clicked()
{
    if (selectedLivreurId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un livreur à supprimer !");
        return;
    }

    // Demander confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce livreur ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM LIVREURES WHERE IDLIVREUR = :id");
        query.bindValue(":id", selectedLivreurId);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Livreur supprimé avec succès !");
            loadTableData();  // Mettre à jour la table après suppression
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur de suppression : " + query.lastError().text());
        }
    }
}

// **Sélectionner une ligne du tableau pour la modification ou suppression**
void MainWindow::onTableRowClicked(int row, int column)
{
    // Récupérer l'ID du livreur à partir de la première colonne
    selectedLivreurId = ui->tab1->item(row, 0)->text();

    // Remplir les champs avec les informations du livreur sélectionné
    ui->cin->setText(ui->tab1->item(row, 1)->text());
    ui->nom->setText(ui->tab1->item(row, 2)->text());
    ui->prenom->setText(ui->tab1->item(row, 3)->text());
    ui->tel->setText(ui->tab1->item(row, 4)->text());
    ui->vehicule->setText(ui->tab1->item(row, 5)->text());
    ui->nb->setValue(ui->tab1->item(row, 6)->text().toInt());
    ui->email->setText(ui->tab1->item(row, 8)->text());

    // Remplir le statut de l'état
    QString etat = ui->tab1->item(row, 7)->text();
    if (etat == "Libre") {
        ui->libre->setChecked(true);
        ui->non->setChecked(false);
    } else {
        ui->non->setChecked(true);
        ui->libre->setChecked(false);
    }
}
