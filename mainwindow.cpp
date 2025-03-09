#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "institut.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTimer>
#include <QTableWidgetItem>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    selectedInstitutId("-1")
{
    ui->setupUi(this);

    // Définir les colonnes de tab1
    QStringList headers = {"ID", "Nom", "Adresse", "Responsable", "Téléphone", "Email", "Capacité"};
    ui->tab1->setColumnCount(headers.size());
    ui->tab1->setHorizontalHeaderLabels(headers);

    // Charger les données dès le démarrage
    loadTableData();

    // Créer un timer pour actualiser les données toutes les 5 secondes
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTableData);
    timer->start(5000);  // 5000 ms = 5 secondes

    // Connexion du clic sur une ligne
    connect(ui->tab1, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);

    // Connexion du signal de tri du QComboBox
    connect(ui->tri, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [=](int index) {
                int column = ui->tri->itemData(index).toInt();
                sortTableData(column);
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTableData()
{
    QSqlQuery query;
    query.prepare("SELECT id_inst, nom_inst, adresse_inst, responsable_inst, telephone_inst, email_inst, capacite_inst FROM INSTITUTS");

    if (!query.exec()) {
        qDebug() << "Erreur de chargement des données : " << query.lastError().text();
        return;
    }

    ui->tab1->clearContents();
    ui->tab1->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < 7; col++) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    ui->tab1->resizeColumnsToContents();
}

void MainWindow::updateTableData()
{
    loadTableData();
}

void MainWindow::onTableRowClicked(int row, int column)
{
    if (row < 0) return;

    selectedInstitutId = ui->tab1->item(row, 0)->text();

    ui->nomInst_input->setText(ui->tab1->item(row, 1)->text());
    ui->adresseInst_input->setText(ui->tab1->item(row, 2)->text());
    ui->responsableInst_input->setText(ui->tab1->item(row, 3)->text());
    ui->telephoneInst_input->setText(ui->tab1->item(row, 4)->text());
    ui->emailInst_input->setText(ui->tab1->item(row, 5)->text());
    ui->capaciteInst_input->setText(ui->tab1->item(row, 6)->text());
}

void MainWindow::on_b1_clicked() // Ajouter
{
    if (Institut::ajouter(ui->nomInst_input->text(),
                          ui->adresseInst_input->text(),
                          ui->responsableInst_input->text(),
                          ui->telephoneInst_input->text().toInt(),
                          ui->emailInst_input->text(),
                          ui->capaciteInst_input->text().toInt())) {
        QMessageBox::information(this, "Succès", "Institut ajouté avec succès !");
        loadTableData();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}

void MainWindow::on_b2_clicked() // Annuler
{
    // Réinitialiser les champs d'entrée à vide
    ui->nomInst_input->clear();
    ui->adresseInst_input->clear();
    ui->responsableInst_input->clear();
    ui->telephoneInst_input->clear();
    ui->emailInst_input->clear();
    ui->capaciteInst_input->clear();
}

void MainWindow::on_b3_clicked() // Modifier
{
    if (selectedInstitutId == "-1" || selectedInstitutId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    int id = selectedInstitutId.toInt();

    bool success = Institut::modifier(id,
                                      ui->nomInst_input->text(),
                                      ui->adresseInst_input->text(),
                                      ui->responsableInst_input->text(),
                                      ui->telephoneInst_input->text().toInt(),
                                      ui->emailInst_input->text(),
                                      ui->capaciteInst_input->text().toInt());

    if (success) {
        QMessageBox::information(this, "Succès", "Institut modifié !");
        loadTableData();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}

void MainWindow::on_b4_clicked() // Supprimer
{
    if (selectedInstitutId == "-1") {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    int id = selectedInstitutId.toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cet institut ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = Institut::supprimer(id);
        if (success) {
            QMessageBox::information(this, "Succès", "Institut supprimé !");
            loadTableData();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}

void MainWindow::on_b5_clicked() // Recherche par ID
{
    bool ok;
    int id = ui->recherche->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QSqlQueryModel* model = Institut::rechercherParId(id);

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucun institut trouvé.");
    } else {
        ui->tab1->clearContents();
        ui->tab1->setRowCount(0);

        for (int row = 0; row < model->rowCount(); row++) {
            ui->tab1->insertRow(row);
            for (int col = 0; col < model->columnCount(); col++) {
                ui->tab1->setItem(row, col, new QTableWidgetItem(model->data(model->index(row, col)).toString()));
            }
        }
    }
}

void MainWindow::sortTableData(int column)
{
    // Vérifier si la colonne est numérique
    bool isNumeric = (column == 0 || column == 4 || column == 6);

    ui->tab1->sortItems(column, isNumeric ? Qt::AscendingOrder : Qt::AscendingOrder);

    if (isNumeric) {
        // Trier les lignes en fonction de la colonne numérique
        for (int row = 0; row < ui->tab1->rowCount(); ++row) {
            bool ok;
            int value = ui->tab1->item(row, column)->text().toInt(&ok);
            if (!ok) {
                qDebug() << "Erreur de conversion en nombre pour la ligne :" << row;
            }
            ui->tab1->item(row, column)->setData(Qt::UserRole, value);
        }
        ui->tab1->sortItems(column, Qt::AscendingOrder);
    } else {
        // Trier les lignes en fonction de la colonne alphabétique
        ui->tab1->sortItems(column, Qt::AscendingOrder);
    }
}
