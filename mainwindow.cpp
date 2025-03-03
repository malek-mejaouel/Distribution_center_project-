 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentId(-1) // Initialiser avec une valeur non valide
{
    ui->setupUi(this);

    // Définir la table avec 7 colonnes
    ui->tab1->setColumnCount(7);
    ui->tab1->setHorizontalHeaderLabels({"ID", "Nom", "Adresse", "Responsable", "Téléphone", "Email", "Capacité"});

    // Connecter le signal de sélection de ligne
    connect(ui->tab1, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_tab1_itemSelectionChanged);

    loadInstituts(); // Charger les instituts au démarrage
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b1_clicked()
{
    QString nomInst = ui->nomInst_input->text();
    QString adresseInst = ui->adresseInst_input->text();
    QString responsableInst = ui->responsableInst_input->text();
    QString telephoneStr = ui->telephoneInst_input->text();
    QString emailInst = ui->emailInst_input->text();
    QString capaciteStr = ui->capaciteInst_input->text();

    bool ok;
    int telephoneInst = telephoneStr.toInt(&ok);
    if (!ok || telephoneInst <= 0) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }

    int capaciteInst = capaciteStr.toInt(&ok);
    if (!ok || capaciteInst <= 0) {
        QMessageBox::warning(this, "Erreur", "Capacité invalide !");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO INSTITUTS (ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST) "
                  "VALUES (INSTITUTS_SEQ.NEXTVAL, :nomInst, :adresseInst, :responsableInst, :telephoneInst, :emailInst, :capaciteInst)");

    query.bindValue(":nomInst", nomInst);
    query.bindValue(":adresseInst", adresseInst);
    query.bindValue(":responsableInst", responsableInst);
    query.bindValue(":telephoneInst", telephoneInst);
    query.bindValue(":emailInst", emailInst);
    query.bindValue(":capaciteInst", capaciteInst);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Institut ajouté avec succès !");
        loadInstituts();  // Rafraîchir la table après ajout
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Erreur d'ajout : " + query.lastError().text());
    }
}

void MainWindow::on_b2_clicked()
{
    ui->nomInst_input->clear();
    ui->adresseInst_input->clear();
    ui->responsableInst_input->clear();
    ui->telephoneInst_input->clear();
    ui->emailInst_input->clear();
    ui->capaciteInst_input->clear();
    currentId = -1; // Réinitialiser l'ID actuel
}

void MainWindow::on_b3_clicked()
{
    if (currentId == -1) {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné pour la modification.");
        return;
    }

    QString nomInst = ui->nomInst_input->text();
    QString adresseInst = ui->adresseInst_input->text();
    QString responsableInst = ui->responsableInst_input->text();
    QString telephoneStr = ui->telephoneInst_input->text();
    QString emailInst = ui->emailInst_input->text();
    QString capaciteStr = ui->capaciteInst_input->text();

    bool ok;
    int telephoneInst = telephoneStr.toInt(&ok);
    if (!ok || telephoneInst <= 0) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }

    int capaciteInst = capaciteStr.toInt(&ok);
    if (!ok || capaciteInst <= 0) {
        QMessageBox::warning(this, "Erreur", "Capacité invalide !");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE INSTITUTS SET NOM_INST = :nomInst, ADRESSE_INST = :adresseInst, RESPONSABLE_INST = :responsableInst, "
                  "TELEPHONE_INST = :telephoneInst, EMAIL_INST = :emailInst, CAPACITE_INST = :capaciteInst WHERE ID_INST = :id");

    query.bindValue(":nomInst", nomInst);
    query.bindValue(":adresseInst", adresseInst);
    query.bindValue(":responsableInst", responsableInst);
    query.bindValue(":telephoneInst", telephoneInst);
    query.bindValue(":emailInst", emailInst);
    query.bindValue(":capaciteInst", capaciteInst);
    query.bindValue(":id", currentId);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Institut modifié avec succès !");
        loadInstituts();  // Rafraîchir la table après modification
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Erreur de modification : " + query.lastError().text());
    }
}

void MainWindow::on_b4_clicked()
{
    if (currentId == -1) {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné pour la suppression.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM INSTITUTS WHERE ID_INST = :id");
    query.bindValue(":id", currentId);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Institut supprimé avec succès !");
        loadInstituts();  // Rafraîchir la table après suppression
        currentId = -1; // Réinitialiser l'ID actuel
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Erreur de suppression : " + query.lastError().text());
    }
}

void MainWindow::on_b5_clicked()
{
    loadInstituts(); // Charger et afficher les instituts
}

void MainWindow::on_tab1_itemSelectionChanged()
{
    QList<QTableWidgetItem*> selectedItems = ui->tab1->selectedItems();
    if (selectedItems.count() == 7) {
        currentId = selectedItems.at(0)->text().toInt();

        // Remplir les champs avec les données de l'institut sélectionné
        ui->nomInst_input->setText(selectedItems.at(1)->text());
        ui->adresseInst_input->setText(selectedItems.at(2)->text());
        ui->responsableInst_input->setText(selectedItems.at(3)->text());
        ui->telephoneInst_input->setText(selectedItems.at(4)->text());
        ui->emailInst_input->setText(selectedItems.at(5)->text());
        ui->capaciteInst_input->setText(selectedItems.at(6)->text());
    }
}

void MainWindow::loadInstituts()
{
    QSqlQuery query("SELECT ID_INST, NOM_INST, ADRESSE_INST, RESPONSABLE_INST, TELEPHONE_INST, EMAIL_INST, CAPACITE_INST FROM INSTITUTS");

    ui->tab1->setRowCount(0); // Vider la table avant de la remplir
    int row = 0;

    while (query.next()) {
        ui->tab1->insertRow(row);

        for (int col = 0; col < 7; col++) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        row++;
    }
}
