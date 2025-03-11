#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "box.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::on_tableWidget_itemSelectionChanged);
    setupComboBoxes();
    refreshTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupComboBoxes()
{
    // EXAMENS
    ui->examenComboBox->clear();
    ui->examenComboBox->insertItem(0, "Sélectionnez l'examen");
    ui->examenComboBox->setCurrentIndex(0);
    {
        QSqlQuery query("SELECT IDEXAMEN, NOMEXAMEN FROM KINZA.EXAMENS ORDER BY IDEXAMEN");
        while(query.next()){
            int idExam = query.value("IDEXAMEN").toInt();
            QString nomExam = query.value("NOMEXAMEN").toString();
            ui->examenComboBox->addItem(nomExam, idExam);
        }
    }

    // LIVREURES
    ui->livreurComboBox->clear();
    ui->livreurComboBox->insertItem(0, "Sélectionnez le livreur");
    ui->livreurComboBox->setCurrentIndex(0);
    {
        QSqlQuery query("SELECT IDLIVREUR, NOMLIVREUR FROM KINZA.LIVREURES ORDER BY IDLIVREUR");
        while(query.next()){
            int idLiv = query.value("IDLIVREUR").toInt();
            QString nomLiv = query.value("NOMLIVREUR").toString();
            ui->livreurComboBox->addItem(nomLiv, idLiv);
        }
    }

    // INSTITUTS
    ui->destinationComboBox->clear();
    ui->destinationComboBox->insertItem(0, "Sélectionnez l'institut");
    ui->destinationComboBox->setCurrentIndex(0);
    {
        QSqlQuery query("SELECT ID_INST, NOM_INST FROM KINZA.INSTITUTS ORDER BY ID_INST");
        while(query.next()){
            int idInst = query.value("ID_INST").toInt();
            QString nomInst = query.value("NOM_INST").toString();
            ui->destinationComboBox->addItem(nomInst, idInst);
        }
    }

    // ETAT
    ui->etatComboBox->clear();
    ui->etatComboBox->insertItem(0, "Sélectionnez l'état");
    ui->etatComboBox->addItem("livrée");
    ui->etatComboBox->addItem("non-livrée");
    ui->etatComboBox->addItem("en cours");
    ui->etatComboBox->setCurrentIndex(0);

    // STATUS
    ui->statusComboBox->clear();
    ui->statusComboBox->insertItem(0, "Sélectionnez le status");
    ui->statusComboBox->addItem("fermer-arriver");
    ui->statusComboBox->addItem("ouvert");
    ui->statusComboBox->addItem("non-arriver");
    ui->statusComboBox->setCurrentIndex(0);
}

void MainWindow::refreshTable(const QString &search)
{
    QSqlQueryModel* model = Box::afficher(search);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);

    QStringList headers;
    headers << "ID_BOX" << "IDEXAMEN" << "IDLIVREUR" << "ID_INST"
            << "DATE_CREATION" << "DESTINATION" << "STATUS" << "ETAT";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int rows = model->rowCount();
    for(int r = 0; r < rows; r++){
        ui->tableWidget->insertRow(r);
        for(int c = 0; c < 8; c++){
            QString val = model->data(model->index(r, c)).toString();
            QTableWidgetItem* item = new QTableWidgetItem(val);
            ui->tableWidget->setItem(r, c, item);
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    delete model;
}

void MainWindow::clearForm()
{
    ui->examenComboBox->setCurrentIndex(0);
    ui->livreurComboBox->setCurrentIndex(0);
    ui->destinationComboBox->setCurrentIndex(0);
    ui->etatComboBox->setCurrentIndex(0);
    ui->statusComboBox->setCurrentIndex(0);
    ui->searchLineEdit->clear();
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
    if(selection.isEmpty()) return;
    int row = selection.first()->row();

    int idExam = ui->tableWidget->item(row, 1)->text().toInt();
    ui->examenComboBox->setCurrentIndex(ui->examenComboBox->findData(idExam));

    int idLivreur = ui->tableWidget->item(row, 2)->text().toInt();
    ui->livreurComboBox->setCurrentIndex(ui->livreurComboBox->findData(idLivreur));

    int idInst = ui->tableWidget->item(row, 3)->text().toInt();
    ui->destinationComboBox->setCurrentIndex(ui->destinationComboBox->findData(idInst));

    QString status = ui->tableWidget->item(row, 6)->text();
    ui->statusComboBox->setCurrentIndex(ui->statusComboBox->findText(status));

    QString etat = ui->tableWidget->item(row, 7)->text();
    if(etat.compare("livree", Qt::CaseInsensitive) == 0)
        etat = "livrée";
    else if(etat.compare("non-livree", Qt::CaseInsensitive) == 0)
        etat = "non-livrée";

    ui->etatComboBox->setCurrentIndex(ui->etatComboBox->findText(etat));
}

void MainWindow::on_valider_clicked()
{
    if(ui->examenComboBox->currentIndex() == 0 ||
        ui->livreurComboBox->currentIndex() == 0 ||
        ui->destinationComboBox->currentIndex() == 0 ||
        ui->etatComboBox->currentIndex() == 0 ||
        ui->statusComboBox->currentIndex() == 0)
    {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner toutes les options !");
        return;
    }

    int idExamen  = ui->examenComboBox->currentData().toInt();
    int idLivreur = ui->livreurComboBox->currentData().toInt();
    int idInst    = ui->destinationComboBox->currentData().toInt();
    QString etat   = ui->etatComboBox->currentText();
    QString status = ui->statusComboBox->currentText();
    QString dest   = ui->destinationComboBox->currentText();

    Box box(idExamen, idLivreur, idInst, dest, status, etat);
    if(box.ajouter()){
        QMessageBox::information(this, "Succès", "Box ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de la Box.");
    }
    refreshTable();
    clearForm();
}

void MainWindow::on_modifier_clicked()
{
    QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
    if(selection.isEmpty()){
        QMessageBox::warning(this, "Modifier", "Sélectionnez une ligne à modifier.");
        return;
    }

    int row = selection.first()->row();
    int idBox = ui->tableWidget->item(row, 0)->text().toInt();

    if(ui->examenComboBox->currentIndex() == 0 ||
        ui->livreurComboBox->currentIndex() == 0 ||
        ui->destinationComboBox->currentIndex() == 0 ||
        ui->etatComboBox->currentIndex() == 0 ||
        ui->statusComboBox->currentIndex() == 0)
    {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner toutes les options !");
        return;
    }

    int idExamen  = ui->examenComboBox->currentData().toInt();
    int idLivreur = ui->livreurComboBox->currentData().toInt();
    int idInst    = ui->destinationComboBox->currentData().toInt();
    QString etat   = ui->etatComboBox->currentText();
    QString status = ui->statusComboBox->currentText();
    QString dest   = ui->destinationComboBox->currentText();

    Box box(idExamen, idLivreur, idInst, dest, status, etat);
    if(box.modifier(idBox)){
        QMessageBox::information(this, "Succès", "Box modifié avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de la Box.");
    }
    refreshTable();
    clearForm();
}

void MainWindow::on_supprimer_clicked()
{
    QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
    if(selection.isEmpty()){
        QMessageBox::warning(this, "Supprimer", "Sélectionnez une ligne à supprimer.");
        return;
    }
    int row = selection.first()->row();
    int idBox = ui->tableWidget->item(row, 0)->text().toInt();

    Box box;
    if(box.supprimer(idBox)){
        QMessageBox::information(this, "Succès", "Box supprimé avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de la Box.");
    }
    refreshTable();
    clearForm();
}

void MainWindow::on_annuler_clicked()
{
    clearForm();
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    refreshTable(text);
}
