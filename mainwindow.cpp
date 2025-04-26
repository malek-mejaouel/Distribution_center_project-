#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QDate>
#include <QSet>
#include "Equipement.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isAscendingOrder(true) // Initialiser l'ordre de tri à ascendant
{
    ui->setupUi(this);

    // Initialisation du tableau pour afficher les équipements
    setupTable();
    loadTableData(); // Charger les données existantes de la base

    // Remplir la QComboBox "tri" avec les attributs disponibles
    setupTriComboBox();

    // Initialiser le QChartView dans l'onglet "Fonctionnalités"
    setupChart();

    // Connecter les signaux
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheTextChanged);
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriComboBoxChanged);
    connect(ui->b10, &QPushButton::clicked, this, &MainWindow::on_b10_clicked);
    connect(ui->b12, &QPushButton::clicked, this, &MainWindow::on_b12_clicked); // Connecter le bouton b12
    connect(ui->b13, &QPushButton::clicked, this, &MainWindow::on_b13_clicked); // Connecter le bouton b13
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b7_clicked()
{
    loadTableData(); // Charger les données existantes dans le tableau
}

// **Méthode pour remplir la QComboBox "tri" avec les attributs disponibles**
void MainWindow::setupTriComboBox()
{
    // Ajouter les attributs disponibles (sauf ID)
    ui->tri->addItem("Nom");
    ui->tri->addItem("Marque");
    ui->tri->addItem("Type");
    ui->tri->addItem("Quantité");
    ui->tri->addItem("Prix");
    ui->tri->addItem("Date Maintenance");
}

// **Méthode pour configurer le tableau tab1**
void MainWindow::setupTable()
{
    ui->tab1->setColumnCount(7); // 7 colonnes pour les équipements
    ui->tab1->setHorizontalHeaderLabels({"ID", "Nom", "Marque", "Type", "Quantité", "Prix", "Date Maintenance"});
    ui->tab1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connecter le signal de sélection de ligne pour modifier ou supprimer
    connect(ui->tab1, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);
}

// **Méthode pour charger les données dans tab1**
void MainWindow::loadTableData()
{
    QSqlQuery query("SELECT ID_EQUIPEMENTS, NOM_EQUIPEMENT, MARQUE, TYPE, QUANTITE, PRIX_EQUIPEMENT, DATE_MAINTENANCE FROM EQUIPEMENTS");

    ui->tab1->setRowCount(0); // Réinitialisation du tableau avant d'ajouter les nouvelles lignes
    int row = 0;

    while (query.next()) {
        ui->tab1->insertRow(row);
        ui->tab1->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        ui->tab1->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
        ui->tab1->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Marque
        ui->tab1->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Type
        ui->tab1->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Quantité
        ui->tab1->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Prix
        ui->tab1->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Date Maintenance
        row++;
    }

    // Mettre à jour le graphique après avoir chargé les données
    setupChart();

    // Mettre à jour le calendrier après avoir chargé les données
    updateCalendarWithMaintenanceDates();
}

// **Ajout d'un équipement à la base de données**
void MainWindow::on_b1_clicked()
{
    // Récupérer les données du formulaire
    QString nom = ui->nom_input->text();
    QString marque = ui->marque_input->text();
    QString type = ui->type_input->text();
    int quantite = ui->quantite_input->text().toInt();
    double prix = ui->prix_input->text().toDouble();
    QDate dateMaintenance = ui->dateEdit->date();

    // Validation des champs
    QRegularExpression regex("^[a-zA-Z]+$");

    if (nom.isEmpty() || !regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Nom doit contenir uniquement des caractères alphabétiques (a-z, A-Z) !");
        return;
    }

    if (marque.isEmpty() || !regex.match(marque).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Marque doit contenir uniquement des caractères alphabétiques (a-z, A-Z) !");
        return;
    }

    if (type.isEmpty() || !regex.match(type).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Type doit contenir uniquement des caractères alphabétiques (a-z, A-Z) !");
        return;
    }

    if (quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être supérieure à zéro !");
        return;
    }

    if (prix <= 0) {
        QMessageBox::warning(this, "Erreur", "Le prix doit être supérieur à zéro !");
        return;
    }
    if (dateMaintenance <= QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de maintenance doit être supérieure à la date d'aujourd'hui !");
        return;
    }

    // Créer un objet Equipement et ajouter l'équipement
    Equipement equipement(0, nom, marque, type, quantite, prix, dateMaintenance);
    if (equipement.ajouterEquipement()) {
        QMessageBox::information(this, "Succès", "Équipement ajouté avec succès !");
        loadTableData(); // Mettre à jour la table immédiatement après l'ajout
    }
}

// **Réinitialisation des champs**
void MainWindow::on_b2_clicked()
{
    ui->nom_input->clear();
    ui->marque_input->clear();
    ui->type_input->clear();
    ui->quantite_input->clear();
    ui->prix_input->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    selectedEquipementId.clear();
}

// **Méthode pour modifier un équipement dans la base de données**
void MainWindow::on_b3_clicked()
{
    if (selectedEquipementId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un équipement à modifier !");
        return;
    }

    // Récupérer les valeurs des champs
    QString nom = ui->nom_input->text();
    QString marque = ui->marque_input->text();
    QString type = ui->type_input->text();
    int quantite = ui->quantite_input->text().toInt();
    double prix = ui->prix_input->text().toDouble();
    QDate dateMaintenance = ui->dateEdit->date();

    // Validation des champs
    if (nom.isEmpty() || marque.isEmpty() || type.isEmpty() || quantite <= 0 || prix <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement !");
        return;
    }

    // Créer un objet Equipement et modifier l'équipement
    Equipement equipement(selectedEquipementId.toInt(), nom, marque, type, quantite, prix, dateMaintenance);
    if (equipement.modifierEquipement()) {
        QMessageBox::information(this, "Succès", "Équipement modifié avec succès !");
        loadTableData();  // Mettre à jour la table après modification
    }
}

// **Méthode pour supprimer un équipement de la base de données**
void MainWindow::on_b4_clicked()
{
    if (selectedEquipementId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un équipement à supprimer !");
        return;
    }

    // Demander confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cet équipement ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Equipement equipement(selectedEquipementId.toInt(), "", "", "", 0, 0.0, QDate());
        if (equipement.supprimerEquipement()) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès !");
            loadTableData();  // Mettre à jour la table après suppression
        }
    }
}

// **Sélectionner une ligne du tableau pour la modification ou suppression**
void MainWindow::onTableRowClicked(int row, int column)
{
    // Récupérer l'ID de l'équipement à partir de la première colonne
    selectedEquipementId = ui->tab1->item(row, 0)->text();

    // Remplir les champs avec les informations de l'équipement sélectionné
    ui->nom_input->setText(ui->tab1->item(row, 1)->text());
    ui->marque_input->setText(ui->tab1->item(row, 2)->text());
    ui->type_input->setText(ui->tab1->item(row, 3)->text());
    ui->quantite_input->setText(ui->tab1->item(row, 4)->text());
    ui->prix_input->setText(ui->tab1->item(row, 5)->text());
    ui->dateEdit->setDate(QDate::fromString(ui->tab1->item(row, 6)->text(), "yyyy-MM-dd"));
}

// **Recherche dynamique par ID**
void MainWindow::onRechercheTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        // Si la recherche est vide, on recharge toutes les données
        loadTableData();
        return;
    }

    // Préparer la requête SQL pour filtrer par ID
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPEMENTS, NOM_EQUIPEMENT, MARQUE, TYPE, QUANTITE, PRIX_EQUIPEMENT, DATE_MAINTENANCE "
                  "FROM EQUIPEMENTS "
                  "WHERE ID_EQUIPEMENTS = :id");
    query.bindValue(":id", text);

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche : " + query.lastError().text());
        return;
    }

    // Réinitialiser le tableau avant d'ajouter les nouvelles lignes
    ui->tab1->setRowCount(0);

    // Remplir le tableau avec les résultats filtrés
    int row = 0;
    while (query.next()) {
        ui->tab1->insertRow(row);
        ui->tab1->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        ui->tab1->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
        ui->tab1->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Marque
        ui->tab1->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Type
        ui->tab1->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Quantité
        ui->tab1->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Prix
        ui->tab1->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Date Maintenance
        row++;
    }
}

// **Tri dynamique en fonction de l'attribut sélectionné dans la QComboBox "tri"**
void MainWindow::onTriComboBoxChanged(int index)
{
    // Récupérer l'attribut sélectionné
    QString attribut;
    switch (index) {
    case 0: attribut = "NOM_EQUIPEMENT"; break;
    case 1: attribut = "MARQUE"; break;
    case 2: attribut = "TYPE"; break;
    case 3: attribut = "QUANTITE"; break;
    case 4: attribut = "PRIX_EQUIPEMENT"; break;
    case 5: attribut = "DATE_MAINTENANCE"; break;
    default: return; // Si aucun attribut n'est sélectionné
    }

    // Préparer la requête SQL pour trier par l'attribut sélectionné
    QString order = isAscendingOrder ? "ASC" : "DESC";
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPEMENTS, NOM_EQUIPEMENT, MARQUE, TYPE, QUANTITE, PRIX_EQUIPEMENT, DATE_MAINTENANCE "
                  "FROM EQUIPEMENTS "
                  "ORDER BY " + attribut + " " + order);

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri : " + query.lastError().text());
        return;
    }

    // Réinitialiser le tableau avant d'ajouter les nouvelles lignes
    ui->tab1->setRowCount(0);

    // Remplir le tableau avec les résultats triés
    int row = 0;
    while (query.next()) {
        ui->tab1->insertRow(row);
        ui->tab1->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        ui->tab1->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
        ui->tab1->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Marque
        ui->tab1->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Type
        ui->tab1->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Quantité
        ui->tab1->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Prix
        ui->tab1->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Date Maintenance
        row++;
    }
}

// **Méthode pour exporter le tableau en PDF**
void MainWindow::on_b10_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Définir les marges pour les quatre côtés de la page
    QPageLayout pageLayout = printer.pageLayout();
    QMarginsF margins(20, 20, 20, 20); // Marges raisonnables
    pageLayout.setUnits(QPageLayout::Millimeter);
    pageLayout.setMargins(margins);
    printer.setPageLayout(pageLayout);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exportation en PDF !");
        return;
    }

    int rowCount = ui->tab1->rowCount();
    int columnCount = ui->tab1->columnCount();

    QFont font = painter.font();
    font.setPointSize(10); // Taille de la police
    painter.setFont(font);

    // Dessiner les en-têtes de colonne
    QStringList headers;
    for (int col = 0; col < columnCount; ++col) {
        headers << ui->tab1->horizontalHeaderItem(col)->text();
    }
    painter.drawText(20, 20, headers.join("\t")); // Dessiner les en-têtes

    // Dessiner les lignes du tableau
    int yOffset = 40; // Décalage initial pour la première ligne
    for (int row = 0; row < rowCount; ++row) {
        QStringList rowData;
        for (int col = 0; col < columnCount; ++col) {
            rowData << ui->tab1->item(row, col)->text();
        }
        yOffset += 800; // Espacement entre les lignes
        painter.drawText(20, yOffset, rowData.join("\t")); // Dessiner chaque ligne
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Tableau exporté en PDF avec succès !");
}

void MainWindow::setupChart()
{
    qDebug() << "Setting up chart...";

    // Calculer les statistiques
    int countExpired = 0;
    int countNotExpired = 0;

    QDate currentDate = QDate::currentDate();

    for (int row = 0; row < ui->tab1->rowCount(); ++row) {
        QString maintenanceDateStr = ui->tab1->item(row, 6)->text().left(10);
        QDate maintenanceDate = QDate::fromString(maintenanceDateStr, "yyyy-MM-dd");

        // Vérifiez si la conversion de la date a réussi
        if (!maintenanceDate.isValid()) {
            qDebug() << "Invalid date format at row:" << row << "Value:" << maintenanceDateStr;
            continue;
        }

        qDebug() << "Row:" << row << "Maintenance Date:" << maintenanceDate;

        if (maintenanceDate < currentDate) {
            countExpired++;
            qDebug() << "Maintenance dépassée pour l'équipement à la ligne:" << row;
        } else {
            countNotExpired++;
            qDebug() << "Maintenance à venir pour l'équipement à la ligne:" << row;
        }
    }

    qDebug() << "Expired count:" << countExpired;
    qDebug() << "Not expired count:" << countNotExpired;

    // Créer les ensembles de données
    QBarSet *expiredSet = new QBarSet("Dépassée");
    QBarSet *notExpiredSet = new QBarSet("À venir");

    // Définir des couleurs différentes pour chaque série
    expiredSet->setColor(Qt::blue);
    notExpiredSet->setColor(Qt::green);

    *expiredSet << countExpired;
    *notExpiredSet << countNotExpired;

    // Créer la série de barres
    QBarSeries *series = new QBarSeries();
    series->append(expiredSet);
    series->append(notExpiredSet);

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques de Maintenance");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Définir les axes
    QStringList categories;
    categories << "Maintenance";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Ajouter le graphique à la vue dans l'onglet "Fonctionnalités"
    ui->chartViewFunctionalites->setChart(chart);
    ui->chartViewFunctionalites->setRenderHint(QPainter::Antialiasing);

    qDebug() << "Chart setup complete.";
}

// Méthode pour mettre à jour le calendrier avec les dates de maintenance
void MainWindow::updateCalendarWithMaintenanceDates()
{
    // Récupérer la date actuelle
    QDate currentDate = QDate::currentDate();

    // Parcourir les lignes du tableau pour obtenir les dates de maintenance
    for (int row = 0; row < ui->tab1->rowCount(); ++row) {
        QString maintenanceDateStr = ui->tab1->item(row, 6)->text().left(10);
        QDate maintenanceDate = QDate::fromString(maintenanceDateStr, "yyyy-MM-dd");

        // Vérifier si la conversion de la date a réussi
        if (!maintenanceDate.isValid()) {
            continue;
        }

        // Définir le format de la date dans le calendrier
        QTextCharFormat format;
        if (maintenanceDate < currentDate) {
            format.setForeground(Qt::red); // Date dépassée
            format.setToolTip("Maintenance dépassée");
        } else {
            format.setForeground(Qt::green); // Date à venir
            format.setToolTip("Maintenance à venir");
        }

        // Mettre à jour le calendrier avec la date et le format
        ui->calendarWidget->setDateTextFormat(maintenanceDate, format);
    }
}

// Nouvelle méthode pour changer l'ordre de tri

void MainWindow::on_b12_clicked()
{
    // Trier par ordre ascendant
    isAscendingOrder = true;
    onTriComboBoxChanged(ui->tri->currentIndex()); // Réutiliser la méthode de tri existante
}

void MainWindow::on_b13_clicked()
{
    // Trier par ordre descendant
    isAscendingOrder = false;
    onTriComboBoxChanged(ui->tri->currentIndex()); // Réutiliser la méthode de tri existante
}
void MainWindow::onCalendarDateClicked(const QDate &date)
{
    // Préparer la requête SQL pour filtrer par date de maintenance
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPEMENTS, NOM_EQUIPEMENT, MARQUE, TYPE, QUANTITE, PRIX_EQUIPEMENT, DATE_MAINTENANCE "
                  "FROM EQUIPEMENTS "
                  "WHERE DATE_MAINTENANCE = :date");
    query.bindValue(":date", date);

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche : " + query.lastError().text());
        return;
    }

    // Réinitialiser le tableau avant d'ajouter les nouvelles lignes
    ui->tab1->setRowCount(0);

    // Remplir le tableau avec les résultats filtrés
    int row = 0;
    while (query.next()) {
        ui->tab1->insertRow(row);
        ui->tab1->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
        ui->tab1->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
        ui->tab1->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Marque
        ui->tab1->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Type
        ui->tab1->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Quantité
        ui->tab1->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Prix
        ui->tab1->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // Date Maintenance
        row++;
    }

    // Changer vers l'onglet tab_5
    ui->tabWidget->setCurrentIndex(0); // L'index de tab_5 est 4 (car les indices commencent à 0)
}

