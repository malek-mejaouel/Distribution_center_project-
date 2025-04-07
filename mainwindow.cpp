#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new QSqlQueryModel(this)), selectedCin(0)
{
    ui->setupUi(this);
    Connection conn;

    if (conn.createconnect()) {
        loadDatabase();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    }

    // Connect radio buttons to role selection function
    connect(ui->r1, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r2, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r3, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r4, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r5, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);
    connect(ui->r6, &QRadioButton::clicked, this, &MainWindow::onRoleSelected);

    // Connect table view selection
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::validateInputs() {
    QString nom = ui->nom_input->text().trimmed();
    QString prenom = ui->prenom_input->text().trimmed();
    QString email = ui->email_input->text().trimmed();
    QString telephone = ui->telephone_input->text().trimmed();
    QString cin = ui->cin_input->text().trimmed();
    QString modpass = ui->modpass_input->text().trimmed();

    // Vérifier que les champs ne sont pas vides
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || telephone.isEmpty() || cin.isEmpty() || modpass.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return false;
    }

    // Vérification du format de l'email
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse e-mail valide !");
        return false;
    }

    // Vérification du format du numéro de téléphone (8 chiffres)
    QRegularExpression phoneRegex("^\\d{8}$");
    if (!phoneRegex.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return false;
    }

    // Vérification du CIN (8 chiffres)
    QRegularExpression cinRegex("^\\d{8}$");
    if (!cinRegex.match(cin).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 8 chiffres !");
        return false;
    }

    // Vérification de la longueur minimale du mot de passe
    if (modpass.length() < 6) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins 6 caractères !");
        return false;
    }

    return true;  // Toutes les validations sont passées
}

// Add a new employee
void MainWindow::on_pushButton_11_clicked() {
    if (!validateInputs()) return;  // Vérification avant d'ajouter

    resetSequenceIfEmpty();
    QString nom = ui->nom_input->text();
    QString prenom = ui->prenom_input->text();
    QString email = ui->email_input->text();
    int telephone = ui->telephone_input->text().toInt();
    int cin = ui->cin_input->text().toInt();
    QString date_employe = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString modpass = ui->modpass_input->text();
    QString role = getSelectedRole();

    Employe e(0, nom, prenom, modpass, email, telephone, cin, date_employe, role);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        loadDatabase();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter l'employé.");
    }
}


// Load the database into the table
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

// Handle radio button selection
void MainWindow::onRoleSelected()
{
    QString role = getSelectedRole();
    if (!role.isEmpty()) {
        QMessageBox::information(this, "Rôle Sélectionné", "Vous avez sélectionné : " + role);
    }
}

// Retrieve selected role
QString MainWindow::getSelectedRole()
{
    if (ui->r1->isChecked()) return "Livreur";
    if (ui->r2->isChecked()) return "Institut";
    if (ui->r3->isChecked()) return "Employe";
    if (ui->r4->isChecked()) return "R.equip";
    if (ui->r5->isChecked()) return "R.exame";
    if (ui->r6->isChecked()) return "R.Box";
    return ""; // No role selected
}

// Search for an employee by CIN
void MainWindow::on_searchbutt_clicked()
{

    QString searchText = ui->search_input->text().trimmed();

    if (searchText.isEmpty()) {
        loadDatabase();
        return;
    }

    int cin = searchText.toInt();
    if (cin == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un CIN valide !");
        return;
    }

    Employe e;
    QSqlQueryModel* model = e.rechercher(cin);

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec ce CIN.");
    }
}

// Select a user from the table
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

        if (!index.isValid()) return;

        int row = index.row();

        // Retrieve CIN column dynamically
        int cinColumn = -1;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal).toString().toLower() == "cin") {
                cinColumn = i;
                break;
            }
        }

        if (cinColumn == -1) {
            QMessageBox::warning(this, "Erreur", "Impossible de trouver la colonne CIN !");
            return;
        }

        // Get selected CIN
        QModelIndex cinIndex = model->index(row, cinColumn);
        selectedCin = model->data(cinIndex).toInt();

        // Check if row index is valid for other columns
        if (row < 0 || row >= model->rowCount()) {
            QMessageBox::warning(this, "Erreur", "Index de ligne invalide.");
            return;
        }

        // Retrieve and set other fields
        ui->nom_input->setText(model->data(model->index(row, 0)).toString());
        ui->prenom_input->setText(model->data(model->index(row, 1)).toString());
        ui->email_input->setText(model->data(model->index(row, 4)).toString());
        ui->telephone_input->setText(model->data(model->index(row, 2)).toString());
        ui->cin_input->setText(QString::number(selectedCin));
        ui->dateEdit->setDate(QDate::fromString(model->data(model->index(row, 5)).toString(), "yyyy-MM-dd"));
        ui->modpass_input->setText(model->data(model->index(row, 3)).toString());

        // Set the role radio button
        QString role = model->data(model->index(row, 6)).toString();
        if (role == "Livreur") ui->r1->setChecked(true);
        else if (role == "Institut") ui->r2->setChecked(true);
        else if (role == "Employe") ui->r3->setChecked(true);
        else if (role == "R.equip") ui->r4->setChecked(true);
        else if (role == "R.exame") ui->r5->setChecked(true);
        else if (role == "R.Box") ui->r6->setChecked(true);
    }


// Delete the selected employee
    void MainWindow::on_deletebutt_clicked() {
        if (selectedCin == 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à supprimer !");
            return;
        }

        Employe e;
        bool success = e.supprimer(selectedCin);

        if (success) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
            loadDatabase();
            resetSequenceIfEmpty(); // Reset sequence if table is empty
            selectedCin = 0;  // Reset selection
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de supprimer l'employé.");
        }
    }
    void MainWindow::on_pushButton_18_clicked() {
        if (selectedCin == 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à modifier !");
            return;
        }

        if (!validateInputs()) return;  // Vérification avant modification

        QString nom = ui->nom_input->text();
        QString prenom = ui->prenom_input->text();
        QString email = ui->email_input->text();
        int telephone = ui->telephone_input->text().toInt();
        int cin = ui->cin_input->text().toInt();
        QString date_employe = ui->dateEdit->date().toString("yyyy-MM-dd");
        QString modpass = ui->modpass_input->text();
        QString role = getSelectedRole();

        Employe e(selectedCin, nom, prenom, modpass, email, telephone, cin, date_employe, role);
        if (e.modifier(selectedCin, nom, prenom, email, telephone, date_employe, modpass, role)) {
            QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
            loadDatabase();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la mise à jour.");
        }
    }

void MainWindow::resetSequenceIfEmpty() {
    QSqlQuery query;

    // Check if the table is empty
    query.prepare("SELECT COUNT(*) FROM EMPLOYEES");
    if (query.exec() && query.next() && query.value(0).toInt() == 0) {
        // Drop the sequence
        query.prepare("DROP SEQUENCE EMPLOYEES_SEQ");
        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la suppression de la séquence : " + query.lastError().text());
            return;
        }

        // Recreate the sequence starting from 1
        query.prepare("CREATE SEQUENCE EMPLOYEES_SEQ START WITH 1 INCREMENT BY 1 NOCACHE NOCYCLE");
        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la création de la séquence : " + query.lastError().text());
        }
    }
}




void MainWindow::on_tabWidget_tabBarClicked(int index)
{

        QSqlQuery query;
        query.prepare("SELECT ROLE, COUNT(*) FROM EMPLOYEES GROUP BY ROLE");

        if (query.exec()) {
            ui->statsList->clear(); // Clear previous stats

            while (query.next()) {
                QString role = query.value(0).toString();
                int count = query.value(1).toInt();
                QString statLine = QString("%1 : %2 employé(s)").arg(role).arg(count);
                ui->statsList->addItem(statLine); // Add to the list
            }
        } else {
            ui->statsList->clear();
            ui->statsList->addItem("Erreur lors du chargement des statistiques !");
        }
    }



