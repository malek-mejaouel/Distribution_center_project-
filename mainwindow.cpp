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

    QStringList headers = {"ID", "Nom", "Adresse", "Responsable", "Téléphone", "Email", "Capacité"};
    ui->tab1->setColumnCount(headers.size());
    ui->tab1->setHorizontalHeaderLabels(headers);

    loadTableData();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTableData);
    timer->start(5000);

    connect(ui->tab1, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);

    connect(ui->tri, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [=](int index) {
                int column = ui->tri->itemData(index).toInt();
                sortTableData(column);
            });
    connect(ui->b1, &QPushButton::clicked, this, &MainWindow::on_b1_clicked);
    connect(ui->b2, &QPushButton::clicked, this, &MainWindow::on_b2_clicked);
    connect(ui->b3, &QPushButton::clicked, this, &MainWindow::on_b3_clicked);
    connect(ui->b4, &QPushButton::clicked, this, &MainWindow::on_b4_clicked);
    connect(ui->b5, &QPushButton::clicked, this, &MainWindow::on_b5_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTableData()
{
    Institut institut;
    QSqlQueryModel* model = institut.afficher();

    ui->tab1->clearContents();
    ui->tab1->setRowCount(0);

    int row = 0;
    while (model->canFetchMore()) {
        model->fetchMore();
    }
    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < model->columnCount(); col++) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(model->data(model->index(i, col)).toString()));
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

void MainWindow::on_b1_clicked()
{
    Institut institut;
    institut.setNom(ui->nomInst_input->text());
    institut.setAdresse(ui->adresseInst_input->text());
    institut.setResponsable(ui->responsableInst_input->text());
    institut.setTelephone(ui->telephoneInst_input->text().toInt());
    institut.setEmail(ui->emailInst_input->text());
    institut.setCapacite(ui->capaciteInst_input->text().toInt());

    // Vérification des données avant d'essayer l'ajout
    if (!institut.validerDonnees()) {
        QMessageBox::critical(this, "Erreur", "Les données saisies ne sont pas valides !");
        return;  // Stopper l'exécution ici si validation échoue
    }

    // Tentative d'ajout
    if (institut.ajouter()) {
        QMessageBox::information(this, "Succès", "Institut ajouté avec succès !");
        loadTableData();
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
}

void MainWindow::on_b3_clicked()
{
    if (selectedInstitutId == "-1" || selectedInstitutId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    Institut institut;
    institut.setId(selectedInstitutId.toInt());
    institut.setNom(ui->nomInst_input->text());
    institut.setAdresse(ui->adresseInst_input->text());
    institut.setResponsable(ui->responsableInst_input->text());
    institut.setTelephone(ui->telephoneInst_input->text().toInt());
    institut.setEmail(ui->emailInst_input->text());
    institut.setCapacite(ui->capaciteInst_input->text().toInt());

    bool success = institut.modifier();

    if (success) {
        QMessageBox::information(this, "Succès", "Institut modifié !");
        loadTableData();}
    else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification. Veuillez vérifier les données saisies.");
    }
}

void MainWindow::on_b4_clicked()
{
    if (selectedInstitutId == "-1") {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    Institut institut;
    institut.setId(selectedInstitutId.toInt());

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cet institut ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool success = institut.supprimer();
        if (success) {
            QMessageBox::information(this, "Succès", "Institut supprimé !");
            loadTableData();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}

void MainWindow::on_b5_clicked()
{
    bool ok;
    int id = ui->recherche->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    Institut institut;
    institut.setId(id);
    QSqlQueryModel* model = institut.rechercherParId();

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
    bool isNumeric = (column == 0 || column == 4 || column == 6);

    ui->tab1->sortItems(column, isNumeric ? Qt::AscendingOrder : Qt::AscendingOrder);

    if (isNumeric) {
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
        ui->tab1->sortItems(column, Qt::AscendingOrder);
    }
}
