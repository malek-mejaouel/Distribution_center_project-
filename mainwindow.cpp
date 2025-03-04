#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    Connection conn;
    if (conn.createconnect()) {
        loadDatabase();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    }

    // Connexion des boutons radio à la fonction onRoleSelected
    connect(ui->r1, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r2, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r3, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r4, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r5, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r6, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    QString nom = ui->nom_input->text();
    QString prenom = ui->prenom_input->text();
    QString email = ui->email_input->text();
    int telephone = ui->telephone_input->text().toInt();
    int cin = ui->cin_input->text().toInt();
    QString date_employe = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString modpass = ui->modpass_input->text();

    // Obtenir le rôle sélectionné via les boutons radio
    QString role = getSelectedRole();
    if (role.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un rôle.");
        return;
    }

    Employe e(0, nom, prenom, modpass, email, telephone, cin, date_employe, role);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        loadDatabase();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter l'employé.");
    }
}



void MainWindow::loadDatabase()
{
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEES");

    if (query.exec()) {
        model->setQuery(query);
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données : " + query.lastError().text());
    }
}

void MainWindow::onRoleSelected()
{
    QString role = getSelectedRole();
    if (!role.isEmpty()) {
        QMessageBox::information(this, "Rôle Sélectionné", "Vous avez sélectionné : " + role);
    }
}

// Fonction pour récupérer le rôle sélectionné
QString MainWindow::getSelectedRole()
{
    if (ui->r1->isChecked()) return "Livreur";
    else if (ui->r2->isChecked()) return "Institut";
    else if (ui->r3->isChecked()) return "Employe";
    else if (ui->r4->isChecked()) return "R.equip";
    else if (ui->r5->isChecked()) return "R.exame";
    else if (ui->r6->isChecked()) return "R.Box";
    return ""; // Aucun rôle sélectionné
}
void MainWindow::on_searchbutt_clicked()
{
    QString searchText = ui->search_input->text().trimmed();

    if (searchText.isEmpty()) {
        loadDatabase();  // Show all employees if the search field is empty
        return;
    }

    int cin = searchText.toInt();

    if (cin == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un cin valide !");
        return;
    }

    Employe e;
    QSqlQueryModel* model = e.rechercher(cin);

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec cet cin.");
    }
}








void MainWindow::on_deletebutt_clicked()
{
    QString searchText = ui->search_input->text().trimmed();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un cin à supprimer !");
        return;
    }

    int cin = searchText.toInt();

    if (cin == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un cin valide !");
        return;
    }

    Employe e;
    bool success = e.supprimer(cin);

    if (success) {
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
        loadDatabase();  // Refresh the table
        ui->search_input->clear();  // Clear the search field
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'employé.");
    }
}

