#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QTextEdit>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QPrinter> // Ajout de l'inclusion pour QPrinter
#include <QSerialPort>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    selectedLivreurId(-1),
    currentOrder("ASC")



{
    ui->setupUi(this);
    int test = A.connect_arduino(); // A est ton objet ArduinoConnection (je suppose)

    if (test == 0) {
        QMessageBox::information(this, "Connexion", "Connexion Arduino réussie sur port COM5.");

        // Si connexion OK, tu récupères directement le QSerialPort
        serial = A.getserial(); // Tu récupères l'objet connecté

        qDebug() << "Port série connecté avec succès.";
    }
    else {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion Arduino sur port COM5.");
    }




    QSqlQueryModel *defaultModel = currentLivreur.trier("IDLIVREUR", "ASC");
    updateTableWithModel(defaultModel);
    loadTableData();
    Historique::synchroniserHistorique();
    setupTable();

    ui->trie->clear();
    ui->trie->addItem("ID ", 0);
    ui->trie->addItem("Nom ", 1);
    ui->trie->addItem("Prénom ", 2);
    ui->trie->addItem("CIN ", 3);
    ui->trie->addItem("Téléphone ", 4);
    ui->trie->addItem("Véhicule ", 5);
    ui->trie->addItem("Nbr Max Box ", 6);
    ui->trie->addItem("État ", 7);
    ui->trie->addItem("Email ", 8);

    connect(ui->rech, &QLineEdit::textChanged, this, &MainWindow::onRechTextChanged);
    connect(ui->trie, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriComboBoxChanged);
    connect(ui->imageButton, &QPushButton::clicked, this, &MainWindow::on_imageButton_clicked);
    connect(ui->AscButton, &QPushButton::clicked, this, &MainWindow::onAscButtonClicked);
    connect(ui->DescButton, &QPushButton::clicked, this, &MainWindow::onDescButtonClicked);
    // Connexion du signal de réception série
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::on_serialDataReceived);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTable()
{
    ui->tab1->setColumnCount(10);
    ui->tab1->setHorizontalHeaderLabels({"ID", "CIN", "Nom", "Prénom", "Téléphone", "Véhicule", "Nbr Max Box", "État", "Email", "Image"});
    ui->tab1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->tab1, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);
}

void MainWindow::updateTableWithModel(QSqlQueryModel *model)
{
    ui->tab1->setRowCount(0);
    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tab1->insertRow(row);
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QTableWidgetItem *item = new QTableWidgetItem(model->data(index).toString());
            ui->tab1->setItem(row, column, item);
        }
    }
}

void MainWindow::loadTableData()
{
    Livreur Livreur;
    QSqlQueryModel* model = Livreur.afficher();
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

void MainWindow::onRechTextChanged(const QString &text) {
    if (text.isEmpty()) {
        loadTableData();
    } else {
        QSqlQueryModel *model = currentLivreur.rechercherParAttribut("NOMLIVREUR", text);
        updateTableWithModel(model);
    }
}

void MainWindow::on_valider_clicked()
{
    int cinLivreur = ui->cin->text().toInt();
    QString nomLivreur = ui->nom->text();
    QString prenomLivreur = ui->prenom->text();
    int telephoneLivreur = ui->tel->text().toInt();
    QString vehiculeLivreur = ui->vehicule->text();
    int nbrMaxBox = ui->nb->text().toInt();
    QString emailLivreur = ui->email->text();
    QString imagePath = ui->imagePath->text();

    if (!currentLivreur.validerCin(cinLivreur)) {
        QMessageBox::warning(this, "Erreur", "CIN invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!currentLivreur.validerNomPrenom(nomLivreur) || !currentLivreur.validerNomPrenom(prenomLivreur)) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }
    if (!currentLivreur.validerTelephone(telephoneLivreur)) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!currentLivreur.validerEmail(emailLivreur)) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide !");
        return;
    }
    if (!currentLivreur.validerVehicule(vehiculeLivreur)) {
        QMessageBox::warning(this, "Erreur", "Le champ véhicule ne peut pas être vide.");
        return;
    }
    if (!currentLivreur.validerNbrMaxBox(nbrMaxBox)) {
        QMessageBox::warning(this, "Erreur", "Nombre maximal de box invalide !");
        return;
    }

    // Vérification si le chemin de l'image existe déjà dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM LIVREURES WHERE IMAGEPATH = :imagePath");
    query.bindValue(":imagePath", imagePath);
    query.exec();
    if (query.next() && query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Le chemin de l'image existe déjà .");
        return;
    }

    // Vérification si le chemin de l'image existe
    if (!QFile::exists(imagePath)) {
        QMessageBox::warning(this, "Erreur", "Le chemin de l'image n'existe pas.");
        return;
    }

    QString etatLivreur = ui->libre->isChecked() ? "Libre" : "Non";

    currentLivreur.setCin(cinLivreur);
    currentLivreur.setNom(nomLivreur);
    currentLivreur.setPrenom(prenomLivreur);
    currentLivreur.setTelephone(telephoneLivreur);
    currentLivreur.setVehicule(vehiculeLivreur);
    currentLivreur.setNbrMaxBox(nbrMaxBox);
    currentLivreur.setEmail(emailLivreur);
    currentLivreur.setEtat(etatLivreur);
    currentLivreur.setImagePath(imagePath);

    bool success = currentLivreur.ajouter();
    if (success) {
        QMessageBox::information(this, "Succès", "Livreur ajouté avec succès !");
        loadTableData();
        clearInputFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur d'ajout : Impossible d'ajouter le livreur.");
    }
}

void MainWindow::on_annuler_clicked()
{
    clearInputFields();
}

void MainWindow::on_modifier_clicked()
{
    if (selectedLivreurId == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un livreur à modifier !");
        return;
    }

    int cinLivreur = ui->cin->text().toInt();
    QString nomLivreur = ui->nom->text();
    QString prenomLivreur = ui->prenom->text();
    int telephoneLivreur = ui->tel->text().toInt();
    QString vehiculeLivreur = ui->vehicule->text();
    int nbrMaxBox = ui->nb->text().toInt();
    QString emailLivreur = ui->email->text();
    QString imagePath = ui->imagePath->text();

    if (!currentLivreur.validerCin(cinLivreur)) {
        QMessageBox::warning(this, "Erreur", "CIN invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!currentLivreur.validerNomPrenom(nomLivreur) || !currentLivreur.validerNomPrenom(prenomLivreur)) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }
    if (!currentLivreur.validerTelephone(telephoneLivreur)) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide ! Il doit contenir exactement 8 chiffres.");
        return;
    }
    if (!currentLivreur.validerEmail(emailLivreur)) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide !");
        return;
    }
    if (!currentLivreur.validerVehicule(vehiculeLivreur)) {
        QMessageBox::warning(this, "Erreur", "Le champ véhicule ne peut pas être vide.");
        return;
    }
    if (!currentLivreur.validerNbrMaxBox(nbrMaxBox)) {
        QMessageBox::warning(this, "Erreur", "Nombre maximal de box invalide !");
        return;
    }

    // Vérification si le chemin de l'image existe
    if (!QFile::exists(imagePath)) {
        QMessageBox::warning(this, "Erreur", "Le chemin de l'image n'existe pas.");
        return;
    }

    QString etatLivreur = ui->libre->isChecked() ? "Libre" : "Non";

    currentLivreur.setId(selectedLivreurId);
    currentLivreur.setCin(cinLivreur);
    currentLivreur.setNom(nomLivreur);
    currentLivreur.setPrenom(prenomLivreur);
    currentLivreur.setTelephone(telephoneLivreur);
    currentLivreur.setVehicule(vehiculeLivreur);
    currentLivreur.setNbrMaxBox(nbrMaxBox);
    currentLivreur.setEmail(emailLivreur);
    currentLivreur.setEtat(etatLivreur);
    currentLivreur.setImagePath(imagePath);

    bool success = currentLivreur.modifier();
    if (success) {
        QMessageBox::information(this, "Succès", "Livreur modifié avec succès !");
        loadTableData();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur de modification : Impossible de modifier le livreur.");
    }
}

void MainWindow::on_supprimer_clicked()
{
    if (selectedLivreurId == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un livreur à supprimer !");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        "Êtes-vous sûr de vouloir supprimer ce livreur ?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        bool success = currentLivreur.supprimer(selectedLivreurId);
        if (success) {
            QMessageBox::information(this, "Succès", "Livreur supprimé avec succès !");
            loadTableData();
            clearInputFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur de suppression : Impossible de supprimer le livreur.");
        }
    }
}

void MainWindow::onTableRowClicked(int row, int)
{
    selectedLivreurId = ui->tab1->item(row, 0)->text().toInt();

    ui->cin->setText(ui->tab1->item(row, 1)->text());
    ui->nom->setText(ui->tab1->item(row, 2)->text());
    ui->prenom->setText(ui->tab1->item(row, 3)->text());
    ui->tel->setText(ui->tab1->item(row, 4)->text());
    ui->vehicule->setText(ui->tab1->item(row, 5)->text());
    ui->nb->setValue(ui->tab1->item(row, 6)->text().toInt());
    ui->email->setText(ui->tab1->item(row, 8)->text());
    ui->imagePath->setText(ui->tab1->item(row, 9)->text());

    QString etat = ui->tab1->item(row, 7)->text();
    ui->libre->setChecked(etat == "Libre");
    ui->non->setChecked(etat != "Libre");
}

void MainWindow::on_recherche_clicked()
{
    QString name = ui->rech->text();
    if (name.isEmpty()) {
        loadTableData();
        return;
    }

    QSqlQueryModel *model = currentLivreur.rechercherParAttribut("NOMLIVREUR", name);
    updateTableWithModel(model);
}

void MainWindow::onAscButtonClicked() {
    currentOrder = "ASC";
    onTriComboBoxChanged(ui->trie->currentIndex());
}

void MainWindow::onDescButtonClicked() {
    currentOrder = "DESC";
    onTriComboBoxChanged(ui->trie->currentIndex());
}

void MainWindow::onTriComboBoxChanged(int index) {
    QString critere;

    switch (index) {
    case 0: critere = "IDLIVREUR"; break;
    case 1: critere = "NOMLIVREUR"; break;
    case 2: critere = "PRENOMLIVREUR"; break;
    case 3: critere = "CINLIVREUR"; break;
    case 4: critere = "TELEPHONELIVREUR"; break;
    case 5: critere = "VEHICULELIVREUR"; break;
    case 6: critere = "NBRMAXBOX"; break;
    case 7: critere = "ETATLIVREUR"; break;
    case 8: critere = "EMAILLIVREUR"; break;
    default: critere = "IDLIVREUR"; break;
    }

    QSqlQueryModel *model = currentLivreur.trier(critere, currentOrder);
    updateTableWithModel(model);
}

void MainWindow::clearInputFields()
{
    ui->cin->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->tel->clear();
    ui->vehicule->clear();
    ui->nb->clear();
    ui->email->clear();
    ui->imagePath->clear();
    ui->libre->setChecked(false);
    ui->non->setChecked(false);
    selectedLivreurId = -1;
}

void MainWindow::showStatistics()
{
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("📊 Tableau de Bord des Livreurs");
    statsDialog->resize(800, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(statsDialog);

    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(16);

    auto createStyledGroupBox = [](const QString &title) {
        QGroupBox *box = new QGroupBox(title);
        box->setStyleSheet(R"(
            QGroupBox {
                font-weight: bold;
                font-size: 17px;
                color: #2C3E50;
                border: 2px solid #3498DB;
                border-radius: 20px;
                margin-top: 20px;
                background-color: #F9F9F9;
                padding: 20px;
            }
            QGroupBox::title {
                subcontrol-origin: margin;
                subcontrol-position: top center;
                padding: 10px;
                font-size: 18px;
                color: #1A5276;
            })");
        return box;
    };

    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM LIVREURES");
    int totalLivreurs = countQuery.next() ? countQuery.value(0).toInt() : 0;

    QChartView *pieChartView = new QChartView();
    QPieSeries *pieSeries = new QPieSeries();

    QSqlQuery query;
    query.exec("SELECT VEHICULELIVREUR, COUNT(*) FROM LIVREURES GROUP BY VEHICULELIVREUR");

    static const QStringList colors = {"#3498DB", "#F39C12", "#2ECC71", "#E74C3C", "#9B59B6", "#16A085"};

    int sliceIndex = 0;
    while (query.next()) {
        QString vehicule = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = totalLivreurs > 0 ? (100.0 * count / totalLivreurs) : 0;

        QPieSlice *slice = pieSeries->append(vehicule, count);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2 livreurs\n%3%")
                            .arg(vehicule)
                            .arg(count)
                            .arg(percentage, 0, 'f', 1));
        slice->setColor(QColor(colors.at(sliceIndex % colors.size())));
        sliceIndex++;
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("📌 Répartition par Type de Véhicule (Total: " + QString::number(totalLivreurs) + ")");
    pieChart->setTitleFont(titleFont);
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignRight);
    pieChart->setAnimationOptions(QChart::SeriesAnimations);
    pieChartView->setChart(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    pieChartView->setMinimumHeight(270);

    QGroupBox *pieBox = createStyledGroupBox("🛵 Répartition des Livreurs par Véhicule");
    QVBoxLayout *pieLayout = new QVBoxLayout(pieBox);
    pieLayout->addWidget(pieChartView);

    QChartView *stackedBarView = new QChartView();
    QStackedBarSeries *stackedSeries = new QStackedBarSeries();

    query.exec("SELECT VEHICULELIVREUR, ETATLIVREUR, COUNT(*) FROM LIVREURES GROUP BY VEHICULELIVREUR, ETATLIVREUR");

    QMap<QString, QBarSet*> barSets;
    QStringList categories;

    while (query.next()) {
        QString vehicule = query.value(0).toString();
        QString etat = query.value(1).toString();
        int count = query.value(2).toInt();

        if (!categories.contains(vehicule)) {
            categories << vehicule;
        }

        if (!barSets.contains(etat)) {
            QBarSet *set = new QBarSet(etat);
            if (etat == "Libre") {
                set->setColor(QColor("#2ECC71"));
            } else {
                set->setColor(QColor("#E74C3C"));
            }
            barSets[etat] = set;
        }

        int index = categories.indexOf(vehicule);
        while (barSets[etat]->count() <= index) {
            barSets[etat]->append(0);
        }
        barSets[etat]->replace(index, count);
    }

    foreach (QBarSet *set, barSets) {
        stackedSeries->append(set);
    }

    QChart *stackedBarChart = new QChart();
    stackedBarChart->addSeries(stackedSeries);
    stackedBarChart->setTitle("📈 Disponibilité par Type de Véhicule");
    stackedBarChart->setTitleFont(titleFont);
    stackedBarChart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    stackedBarChart->addAxis(axisX, Qt::AlignBottom);
    stackedSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de livreurs");
    stackedBarChart->addAxis(axisY, Qt::AlignLeft);
    stackedSeries->attachAxis(axisY);

    stackedBarChart->legend()->setVisible(true);
    stackedBarChart->legend()->setAlignment(Qt::AlignBottom);
    stackedBarView->setChart(stackedBarChart);
    stackedBarView->setRenderHint(QPainter::Antialiasing);
    stackedBarView->setMinimumHeight(250);

    QGroupBox *barBox = createStyledGroupBox("📊 Disponibilité des Livreurs");
    QVBoxLayout *barLayout = new QVBoxLayout(barBox);
    barLayout->addWidget(stackedBarView);

    QGroupBox *infoBox = createStyledGroupBox("🔎 Indicateurs Clés");
    QGridLayout *infoLayout = new QGridLayout();

    int libre = 0;
    query.exec("SELECT COUNT(*) FROM LIVREURES WHERE ETATLIVREUR = 'Libre'");
    if (query.next()) {
        libre = query.value(0).toInt();
    }

    auto createInfoLabel = [](const QString &text, const QString &color) {
        QLabel *label = new QLabel(text);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString(R"(
            QLabel {
                background-color: %1;
                color: white;
                padding: 8px;
                border-radius: 12px;
                font-weight: bold;
                font-size: 13px;
                min-width: 140px;
            })").arg(color));
        return label;
    };

    infoLayout->addWidget(createInfoLabel(QString("🚚 Total Livreurs: %1").arg(totalLivreurs), "#2980B9"), 0, 0);
    infoLayout->addWidget(createInfoLabel(QString("✅ Disponibles: %1 (%2%)")
                                              .arg(libre)
                                              .arg(totalLivreurs > 0 ? 100.0 * libre / totalLivreurs : 0, 0, 'f', 1),
                                          "#27AE60"), 0, 1);

    infoBox->setLayout(infoLayout);

    mainLayout->addWidget(infoBox);
    mainLayout->addWidget(pieBox);
    mainLayout->addWidget(barBox);

    statsDialog->setLayout(mainLayout);
    statsDialog->exec();
}

void MainWindow::on_statsButton_clicked()
{
    showStatistics();
}

void MainWindow::on_pdfButton_clicked()
{
    QDialog *exportDialog = new QDialog(this);
    exportDialog->setWindowTitle("Exportation des Livreurs");
    exportDialog->resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(exportDialog);

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT IDLIVREUR, CINLIVREUR, NOMLIVREUR, PRENOMLIVREUR, TELEPHONELIVREUR, VEHICULELIVREUR, NBRMAXBOX, ETATLIVREUR, EMAILLIVREUR, IMAGEPATH FROM LIVREURES");

    QTableView *tableView = new QTableView(exportDialog);
    tableView->setModel(model);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->resizeColumnsToContents();

    QPushButton *pdfExportButton = new QPushButton("Exporter en PDF", exportDialog);
    QPushButton *closeButton = new QPushButton("Fermer", exportDialog);

    QString buttonStyle = "QPushButton { padding: 8px; font-weight: bold; }";
    pdfExportButton->setStyleSheet(buttonStyle + "background-color: #e74c3c; color: white;");
    closeButton->setStyleSheet(buttonStyle + "background-color: #95a5a6; color: white;");

    layout->addWidget(tableView);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(pdfExportButton);
    buttonLayout->addWidget(closeButton);

    layout->addLayout(buttonLayout);

    connect(pdfExportButton, &QPushButton::clicked, this, [this, model]() {
        exportToPDF(model);
    });

    connect(closeButton, &QPushButton::clicked, exportDialog, &QDialog::accept);

    exportDialog->exec();
}



void MainWindow::exportToPDF(QSqlQueryModel *model)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QString html;
    html += "<html><head><meta charset='utf-8'></head><body>";
    html += "<h1 style='text-align:center; color:#2c3e50;'>Liste des Livreurs</h1>";
    html += "<p style='text-align:center;'>Généré le " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='5' width='100%' style='border-collapse:collapse;'>";

    html += "<tr style='background-color:#3498db; color:white;'>";
    for (int col = 0; col < model->columnCount(); ++col) {
        html += "<th style='padding:8px; text-align:center;'>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    for (int row = 0; row < model->rowCount(); ++row) {
        QString rowColor = (row % 2 == 0) ? "#ffffff" : "#f2f2f2";
        html += "<tr style='background-color:" + rowColor + ";'>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant data = model->data(model->index(row, col));
            QString displayText;

            QString header = model->headerData(col, Qt::Horizontal).toString();
            if (header == "IMAGEPATH") {
                QString imagePath = data.toString();
                QImage image(imagePath);
                if (!image.isNull()) {
                    QString imageBase64;
                    QBuffer buffer;
                    image.save(&buffer, "PNG");
                    imageBase64 = QString::fromLatin1(buffer.data().toBase64());
                    displayText = "<img src='data:image/png;base64," + imageBase64 + "' width='50' height='50'/>";
                } else {
                    displayText = "Image non trouvée";
                }
            } else {
                displayText = data.toString();
            }

            html += "<td style='padding:8px; text-align:center;'>" + displayText + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::on_historiqueButton_clicked() {
    Historique::synchroniserHistorique();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Historique complet");
    dialog->resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QTextEdit *textEdit = new QTextEdit(dialog);
    textEdit->setReadOnly(true);
    textEdit->setPlainText(Historique::lireHistorique());

    QPushButton *closeButton = new QPushButton("Fermer", dialog);
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    layout->addWidget(textEdit);
    layout->addWidget(closeButton);

    dialog->exec();
}

void MainWindow::on_imageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Sélectionner une image"), "", tr("Images (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        ui->imagePath->setText(fileName);
    }
}


void MainWindow::on_serialDataReceived()
{
    static QByteArray buffer; // Pour accumuler les données
    buffer.append(serial->readAll());

    qDebug() << "Buffer reçu : " << buffer;

    // Traiter toutes les lignes complètes reçues
    while (buffer.contains('\n')) {
        int newlinePos = buffer.indexOf('\n');
        QByteArray line = buffer.left(newlinePos).trimmed();
        buffer = buffer.mid(newlinePos + 1);

        qDebug() << "Ligne traitée : " << line;

        if (line.isEmpty()) {
            continue; // Ignorer les lignes vides
        }

        QString id = QString::fromUtf8(line);
        qDebug() << "ID reçu : " << id;

        // Vérifier dans la base
        verifierEtatLivreur(id);
    }
}


void MainWindow::verifierEtatLivreur(QString id)
{
    qDebug() << "Vérification de l'ID : " << id;

    // Supprimer les espaces et caractères non désirés
    id = id.trimmed();

    // Vérifier que l'ID n'est pas vide
    if (id.isEmpty()) {
        qDebug() << "ID vide reçu";
        serial->write("NOT_FOUND\n");
        return;
    }

    // Convertir en entier
    bool ok;
    int idInt = id.toInt(&ok);

    // Vérifier que la conversion a réussi et que l'ID est >= 1
    if (!ok || idInt < 1) {
        qDebug() << "ID invalide (doit être un nombre >= 1) : " << id;
        serial->write("NOT_FOUND\n");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT etatlivreur FROM LIVREURES WHERE IDLIVREUR = :id");
    query.bindValue(":id", idInt);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        serial->write("NOT_FOUND\n");
        return;
    }

    if (query.next()) {
        QString etat = query.value(0).toString().trimmed().toLower();
        qDebug() << "État du livreur : " << etat;

        if (etat == "libre") {
            serial->write("OK\n");
            qDebug() << "Livreur libre. Réponse envoyée: OK";
        } else {
            serial->write("BUSY\n");
            qDebug() << "Livreur occupé. Réponse envoyée: BUSY";
        }
    } else {
        serial->write("NOT_FOUND\n");
        qDebug() << "ID introuvable dans la base de données. Réponse envoyée: NOT_FOUND";
    }
}
