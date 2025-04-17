#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QQuickWidget>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "institut.h"
#include "markermodel.h"
#include <QNetworkReply>
#include <QStandardPaths>
#include <QCheckBox>
#include <QUrlQuery>
#include "dialog.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QQmlApplicationEngine>
#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , selectedInstitutId("-1")
    , networkManager(new QNetworkAccessManager(this))
    , m_markerModel(new MarkerModel(this))
{
    ui->setupUi(this);
    QStringList headers = {"ID", "Nom", "Adresse", "Responsable", "Téléphone", "Email", "Capacité", "ID Employee"};
    ui->tab1->setColumnCount(headers.size());
    ui->tab1->setHorizontalHeaderLabels(headers);

    // Add a central layout manually
    QVBoxLayout *centralLayout = new QVBoxLayout(ui->centralwidget);
    centralLayout->setContentsMargins(0, 0, 0, 0);
    ui->centralwidget->setLayout(centralLayout);

    loadTableData();
    loadEmployeeNames(); // Charger les noms des employés
    afficherIdsEmployes();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTableData);
    timer->start(5000);

    ui->tri->clear();
    ui->tri->addItem("ID", 0);
    ui->tri->addItem("Nom", 1);
    ui->tri->addItem("Adresse", 2);
    ui->tri->addItem("Responsable", 3);
    ui->tri->addItem("Téléphone", 4);
    ui->tri->addItem("Email", 5);
    ui->tri->addItem("Capacité", 6);
    ui->tri->addItem("ID Employee", 7);

    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onTriComboBoxChanged);
    connect(ui->ASC, &QPushButton::clicked, this, &MainWindow::onCroissantButtonClicked);
    connect(ui->DESC, &QPushButton::clicked, this, &MainWindow::onDecroissantButtonClicked);

    // Connexion des signaux et slots
    connect(ui->map, &QPushButton::clicked, this, &MainWindow::on_map_clicked);
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriComboBoxChanged);
    connect(ui->ASC, &QPushButton::clicked, this, &MainWindow::onCroissantButtonClicked);
    connect(ui->DESC, &QPushButton::clicked, this, &MainWindow::onDecroissantButtonClicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheIdTextChanged);
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesCapacite);
    connect(ui->tab1, &QTableWidget::itemSelectionChanged, this, &MainWindow::onTableRowClicked);
    connect(ui->noti, &QPushButton::clicked, this, &MainWindow::on_noti_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);

    ui->map->setIcon(QIcon(":/ressources/maps.png"));
    ui->stat->setIcon(QIcon(":/ressources/stat.jpg"));
    ui->noti->setIcon(QIcon(":/ressources/noti.png"));

    updateTableData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTableData()
{
    qDebug() << "Début de loadTableData()";

    Institut institut;
    QSqlQueryModel *model = institut.afficher();
    if (!model) {
        qDebug() << "Erreur: modèle non créé";
        return;
    }

    ui->tab1->clearContents();
    ui->tab1->setRowCount(0);

    qDebug() << "Nombre de lignes dans le modèle:" << model->rowCount();

    int row = 0;
    while (model->canFetchMore()) {
        model->fetchMore();
    }

    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < model->columnCount(); col++) {
            QVariant data = model->data(model->index(i, col));
            qDebug() << "Ligne" << i << "Colonne" << col << ":" << data.toString();
            ui->tab1->setItem(row, col, new QTableWidgetItem(data.toString()));
        }
        row++;
    }
    ui->tab1->resizeColumnsToContents();
    delete model; // Libérer la mémoire

    qDebug() << "Fin de loadTableData()";
}

void MainWindow::updateTableData()
{
    Institut institut;
    QSqlQueryModel *model = institut.afficher();
    updateTableWithModel(model);
}

void MainWindow::onTableRowClicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tab1->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();

        // Mise à jour des champs standards
        selectedInstitutId = ui->tab1->item(row, 0)->text();
        ui->nomInst_input->setText(ui->tab1->item(row, 1)->text());
        ui->adresseInst_input->setText(ui->tab1->item(row, 2)->text());
        ui->responsableInst_input->setText(ui->tab1->item(row, 3)->text());
        ui->telephoneInst_input->setText(ui->tab1->item(row, 4)->text());
        ui->emailInst_input->setText(ui->tab1->item(row, 5)->text());
        ui->capaciteInst_input->setText(ui->tab1->item(row, 6)->text());

        // Gestion du QComboBox employee
        QTableWidgetItem* employeeItem = ui->tab1->item(row, 7);
        if (employeeItem) {
            QString idStr = employeeItem->text();
            bool ok;
            int employeeId = idStr.toInt(&ok);

            if (ok && employeeId > 0) {
                qDebug() << "Recherche de l'employé ID:" << employeeId;
                for (int i = 0; i < ui->employee->count(); ++i) {
                    if (ui->employee->itemData(i).toInt() == employeeId) {
                        ui->employee->setCurrentIndex(i);
                        qDebug() << "Employé trouvé à l'index:" << i;
                        return;
                    }
                }
                qDebug() << "Employé non trouvé dans la liste";
            }
        }
        ui->employee->setCurrentIndex(0); // Fallback
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

void MainWindow::loadEmployeeNames()
{
    ui->employee->clear();
    ui->employee->addItem("Sélectionnez un employé", -1);

    QSqlQuery query("SELECT ID_EMPLOYE, NOM_EMPLOYE FROM EMPLOYEES ORDER BY NOM_EMPLOYE");
    if (!query.exec()) {
        qDebug() << "Erreur SQL (loadEmployeeNames):" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int id = query.value("ID_EMPLOYE").toInt();
        QString name = query.value("NOM_EMPLOYE").toString();
        ui->employee->addItem(name, id);
        qDebug() << "Employé ajouté:" << name << "(ID:" << id << ")";
    }
    ui->employee->setCurrentIndex(0);
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

    int idEmploye = ui->employee->currentData().toInt();
    if (idEmploye <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé valide");
        return;
    }
    institut.setIdEmployee(idEmploye);

    // Vérification des données avant d'essayer l'ajout
    if (!institut.validerDonnees()) {
        QMessageBox::critical(this, "Erreur", "Les données saisies ne sont pas valides !");
        return;  // Stopper l'exécution ici si validation échoue
    }

    if (institut.ajouter()) {
        QMessageBox::information(this, "Succès", "Institut ajouté !");
        loadTableData(); // Recharge les données
    }
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

    int idEmploye = ui->employee->currentData().toInt();
    institut.setIdEmployee(idEmploye);

    if (institut.modifier()) {
        QMessageBox::information(this, "Succès", "Institut modifié !");
        loadTableData(); // Recharge les données
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

void MainWindow::onTriComboBoxChanged(int index)
{
    QString critere, ordre;

    switch (index) {
    case 0: critere = "ID_INST"; ordre = "ASC"; break;
    case 1: critere = "ID_INST"; ordre = "DESC"; break;
    case 2: critere = "NOM_INST"; ordre = "ASC"; break;
    case 3: critere = "NOM_INST"; ordre = "DESC"; break;
    case 4: critere = "ADRESSE_INST"; ordre = "ASC"; break;
    case 5: critere = "ADRESSE_INST"; ordre = "DESC"; break;
    case 6: critere = "RESPONSABLE_INST"; ordre = "ASC"; break;
    case 7: critere = "RESPONSABLE_INST"; ordre = "DESC"; break;
    case 8: critere = "TELEPHONE_INST"; ordre = "ASC"; break;
    case 9: critere = "TELEPHONE_INST"; ordre = "DESC"; break;
    case 10: critere = "EMAIL_INST"; ordre = "ASC"; break;
    case 11: critere = "EMAIL_INST"; ordre = "DESC"; break;
    case 12: critere = "CAPACITE_INST"; ordre = "ASC"; break;
    case 13: critere = "CAPACITE_INST"; ordre = "DESC"; break;
    case 14: critere = "ID_EMPLOYE"; ordre = "ASC"; break;
    case 15: critere = "ID_EMPLOYE"; ordre = "DESC"; break;
    default: critere = "ID_INST"; ordre = "ASC"; break;
    }

    Institut institut;
    QSqlQueryModel *model = institut.trier(critere, ordre);
    updateTableWithModel(model);
}

void MainWindow::onCroissantButtonClicked() {
    performSorting("ASC");
}

void MainWindow::onDecroissantButtonClicked() {
    performSorting("DESC");
}

void MainWindow::performSorting(const QString &order)
{
    QString critere = ui->tri->currentText();
    QString columnName;

    if (critere == "Nom") {
        columnName = "NOM_INST";
    } else if (critere == "Adresse") {
        columnName = "ADRESSE_INST";
    } else if (critere == "Responsable") {
        columnName = "RESPONSABLE_INST";
    } else if (critere == "Téléphone") {
        columnName = "TELEPHONE_INST";
    } else if (critere == "Email") {
        columnName = "EMAIL_INST";
    } else if (critere == "Capacité") {
        columnName = "CAPACITE_INST";
    } else if (critere == "ID Employee") {
        columnName = "ID_EMPLOYE";
    } else if (critere == "ID") {
        columnName = "ID_INST";
    } else {
        columnName = "ID_INST";
    }

    Institut institut;
    QSqlQueryModel *model = institut.trier(columnName, order);
    updateTableWithModel(model);
}

void MainWindow::updateTableWithModel(QSqlQueryModel *model)
{
    // Sauvegarder les largeurs de colonnes actuelles
    QList<int> columnWidths;
    for (int i = 0; i < ui->tab1->columnCount(); ++i) {
        columnWidths << ui->tab1->columnWidth(i);
    }

    ui->tab1->setRowCount(0);

    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tab1->insertRow(row);
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QTableWidgetItem *item = new QTableWidgetItem(model->data(index).toString());
            ui->tab1->setItem(row, column, item);
        }
    }

    // Restaurer les largeurs de colonnes
    for (int i = 0; i < columnWidths.size() && i < ui->tab1->columnCount(); ++i) {
        ui->tab1->setColumnWidth(i, columnWidths[i]);
    }

    delete model;
}

void MainWindow::onRechercheIdTextChanged(const QString &text)
{
    performSearch(text);
}

void MainWindow::performSearch(const QString &text)
{
    Institut institut;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour rechercher uniquement par ID
    QSqlQuery query;
    query.prepare("SELECT * FROM INSTITUTS WHERE ID_INST LIKE :text");
    query.bindValue(":text", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Erreur de recherche:" << query.lastError().text();
        return;
    }

    model->setQuery(std::move(query)); // Use std::move to pass the query
    updateTableWithModel(model);
}

void MainWindow::afficherStatistiquesCapacite()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des Capacités des Instituts");
    dialog->resize(1100, 800);
    dialog->setStyleSheet("background-color: #2c3e50; color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Intervalles
    QStringList intervals = {"0-500 places", "501-1000 places", "1001+ places"};
    int intervalCounts[3] = {0, 0, 0};
    int totalInstituts = 0;
    int totalPlaces[3] = {0, 0, 0};

    QSqlQuery query;
    if (query.exec("SELECT CAPACITE_INST FROM INSTITUTS")) {
        while (query.next()) {
            int capacite = query.value(0).toInt();
            totalInstituts++;
            if (capacite <= 500) {
                intervalCounts[0]++;
                totalPlaces[0] += capacite;
            } else if (capacite <= 1000) {
                intervalCounts[1]++;
                totalPlaces[1] += capacite;
            } else {
                intervalCounts[2]++;
                totalPlaces[2] += capacite;
            }
        }
    }

    // Créer le graphique
    QChart *barChart = new QChart();
    barChart->setTitle("<b style='color:white; font-size:16px;'>Répartition des Instituts par Capacité</b>");
    barChart->setAnimationOptions(QChart::AllAnimations);
    barChart->setBackgroundBrush(QBrush(QColor("#34495e")));
    barChart->setTitleBrush(QBrush(Qt::white));
    barChart->setMargins(QMargins(15, 15, 15, 15));

    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Instituts");

    for (int i = 0; i < 3; ++i) {
        *barSet << intervalCounts[i];
    }

    // Style des barres
    QLinearGradient barGradient(0, 0, 0, 1);
    barGradient.setColorAt(0, QColor("#3498db"));
    barGradient.setColorAt(1, QColor("#2980b9"));
    barGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    barSet->setBrush(barGradient);
    barSet->setBorderColor(QColor("#2c3e50"));

    barSeries->append(barSet);
    barSeries->setLabelsVisible(false); // Nous ajouterons manuellement nos labels

    barChart->addSeries(barSeries);

    // Axe X
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(intervals);
    axisX->setLabelsColor(Qt::white);
    axisX->setTitleBrush(QBrush(Qt::white));
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    // Axe Y
    int maxValue = *std::max_element(intervalCounts, intervalCounts + 3) + 2;
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue);
    axisY->setLabelsColor(Qt::white);
    axisY->setGridLineColor(QColor("#3d566e"));
    axisY->setLinePenColor(Qt::white);
    axisY->setTitleText("Nombre d'Instituts");
    axisY->setTitleBrush(QBrush(Qt::white));
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    // Légende
    barChart->legend()->setVisible(true);
    barChart->legend()->setLabelColor(Qt::white);
    barChart->legend()->setAlignment(Qt::AlignBottom);
    barChart->legend()->setFont(QFont("Segoe UI", 9));

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(barChartView);

    // Bouton de fermeture
    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet(R"(
        QPushButton {
            background-color: #e74c3c;
            color: white;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            font-family: 'Segoe UI';
            font-size: 12px;
            font-weight: bold;
            min-width: 100px;
        }
        QPushButton:hover {
            background-color: #c0392b;
        }
    )");
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    dialog->setLayout(mainLayout);
    dialog->show();

    // Ajouter les textes personnalisés au-dessus de chaque barre
    QTimer::singleShot(0, dialog, [=]() {
        for (int i = 0; i < 3; ++i) {
            if (intervalCounts[i] == 0) continue;

            double pourcentage = totalInstituts > 0 ? (static_cast<double>(intervalCounts[i]) / totalInstituts * 100.0) : 0.0;
            QString labelText = QString("%1%\n%2 instituts\n%3 places")
                                    .arg(pourcentage, 0, 'f', 1)
                                    .arg(intervalCounts[i])
                                    .arg(totalPlaces[i]);

            // Position logique au centre de la barre
            QPointF barCenter(i, intervalCounts[i]);
            QPointF scenePos = barChart->mapToPosition(barCenter, barSeries);

            // Créer le texte
            QGraphicsTextItem *textItem = new QGraphicsTextItem(labelText);
            textItem->setDefaultTextColor(Qt::white);
            textItem->setFont(QFont("Segoe UI", 9, QFont::Bold));
            textItem->setZValue(10);
            textItem->setTextWidth(120);
            textItem->setPos(scenePos.x() - 60, scenePos.y() - 60);  // Ajuster position
            textItem->setTextWidth(120);

            barChart->scene()->addItem(textItem);
        }
    });
}

void MainWindow::on_pdf_clicked()
{
    qDebug() << "📄 Bouton PDF cliqué !";

    // Emplacement par défaut dans "Documents"
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/liste_instituts.pdf";

    // Ouvre le dialogue pour choisir le nom et emplacement du fichier
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        defaultPath,
        "PDF (*.pdf)"
        );

    if (filePath.isEmpty()) {
        qDebug() << "🚫 Export annulé par l'utilisateur.";
        return;
    }

    Institut inst;
    if (inst.exporterPDF(filePath)) {
        QMessageBox::information(this, "✅ Succès", "PDF généré :\n" + filePath);
        qDebug() << "✅ Fichier PDF créé avec succès :" << filePath;
    } else {
        QMessageBox::critical(this, "❌ Erreur", "Échec de la création du PDF.");
        qDebug() << "❌ Échec lors de l'export PDF.";
    }
}

void MainWindow::afficherIdsEmployes()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte.";
        return;
    }

    Institut institut;
    QList<int> idsEmployes = institut.obtenirIdsEmployes();
    qDebug() << "IDs des employés récupérés :" << idsEmployes;

    // Assurez-vous que la table a le bon nombre de lignes
    int currentRowCount = ui->tab1->rowCount();
    int newRowCount = idsEmployes.size();

    if (newRowCount > currentRowCount) {
        ui->tab1->setRowCount(newRowCount);
    }

    // Remplissez la colonne "ID Employee" avec les IDs récupérés
    for (int i = 0; i < idsEmployes.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(idsEmployes[i]));
        ui->tab1->setItem(i, 7, item); // 7 est l'index de la colonne "ID Employee"
    }
}

void MainWindow::showNotificationInLayout(const QString &employeeId, const QString &message, const QString &institutName, const QString &institutId)
{
    if (!employeeExists(employeeId)) {
        QMessageBox::warning(this, "Erreur", "L'employé avec l'ID " + employeeId + " n'existe pas.");
        return;
    }

    QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString fullMessage = QString("Date: %1\n %2 à l'institut %3 (ID: %4)")
                              .arg(currentDate)
                              .arg(message)
                              .arg(institutName)
                              .arg(institutId);

    Dialog *notificationDialog = new Dialog(employeeId, fullMessage, this);
    notificationDialog->show();
}

void MainWindow::on_noti_clicked()
{
    if (selectedInstitutId == "-1") {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    showNotificationDialogLayout();
}

void MainWindow::showNotificationDialogLayout()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Envoyer une Notification");
    dialog.setMinimumSize(400, 300);
    dialog.setStyleSheet("background-color: #2c3e50; color: white;");

    QVBoxLayout* layout = new QVBoxLayout(&dialog);

    QLabel* labelIdEmploye = new QLabel("ID de l'employé :", &dialog);
    labelIdEmploye->setStyleSheet("color: white; font-size: 14px;");
    layout->addWidget(labelIdEmploye);

    QLineEdit* lineEditIdEmploye = new QLineEdit(&dialog);
    lineEditIdEmploye->setPlaceholderText("Entrez l'ID de l'employé");
    lineEditIdEmploye->setStyleSheet("background-color: white; color: black; padding: 5px; border-radius: 5px;");
    layout->addWidget(lineEditIdEmploye);

    QCheckBox *checkBoxCommandeArrivee = new QCheckBox("Commande arrivée", &dialog);
    checkBoxCommandeArrivee->setStyleSheet("color: white; font-size: 14px;");
    layout->addWidget(checkBoxCommandeArrivee);

    QCheckBox* checkBoxCommandeNonArrivee = new QCheckBox("Commande non arrivée", &dialog);
    checkBoxCommandeNonArrivee->setStyleSheet("color: white; font-size: 14px;");
    layout->addWidget(checkBoxCommandeNonArrivee);

    // Empêcher de cocher les deux cases
    connect(checkBoxCommandeArrivee, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked) {
            checkBoxCommandeNonArrivee->setChecked(false);
        }
    });

    connect(checkBoxCommandeNonArrivee, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked) {
            checkBoxCommandeArrivee->setChecked(false);
        }
    });

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* okButton = new QPushButton("Envoyer", &dialog);
    QPushButton* cancelButton = new QPushButton("Annuler", &dialog);

    okButton->setStyleSheet(R"(
        QPushButton {
            background-color: #2ecc71;
            color: white;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            font-family: 'Segoe UI';
            font-size: 12px;
            font-weight: bold;
            min-width: 100px;
        }
        QPushButton:hover {
            background-color: #27ae60;
        }
    )");

    cancelButton->setStyleSheet(R"(
        QPushButton {
            background-color: #e74c3c;
            color: white;
            border: none;
            padding: 10px 20px;
            border-radius: 5px;
            font-family: 'Segoe UI';
            font-size: 12px;
            font-weight: bold;
            min-width: 100px;
        }
        QPushButton:hover {
            background-color: #c0392b;
        }
    )");

    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, [&]() {
        QString idEmployeText = lineEditIdEmploye->text();
        bool idEmployeValid = !idEmployeText.isEmpty();
        bool commandeArriveeChecked = checkBoxCommandeArrivee->isChecked();
        bool commandeNonArriveeChecked = checkBoxCommandeNonArrivee->isChecked();

        if (!idEmployeValid) {
            QMessageBox::warning(&dialog, "Erreur", "Veuillez entrer l'ID de l'employé.");
            return;
        }

        if (!commandeArriveeChecked && !commandeNonArriveeChecked) {
            QMessageBox::warning(&dialog, "Erreur", "Veuillez sélectionner une option de commande.");
            return;
        }

        QString message = commandeArriveeChecked ? "Commande arrivée" : "Commande non arrivée";
        QString institutName = ui->nomInst_input->text();
        QString institutId = selectedInstitutId;

        // Afficher la notification dans l'interface
        showNotificationInLayout(idEmployeText, message, institutName, institutId);

        dialog.accept();
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    dialog.exec();
}

void MainWindow::notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon)
{
    if (trayIcon) {
        trayIcon->showMessage(title, message, icon, 5000);
    }
}

bool MainWindow::employeeExists(const QString &employeeId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", employeeId);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}

void MainWindow::onGeoCodeReply(QNetworkReply *reply)
{
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response);
        QJsonArray results = json.array();

        if (!results.isEmpty()) {
            QJsonObject firstResult = results.first().toObject();

            if (firstResult.contains("lat") && firstResult.contains("lon")) {
                double lat = firstResult["lat"].toString().toDouble();
                double lon = firstResult["lon"].toString().toDouble();
                QString institutName = reply->request().attribute(QNetworkRequest::User).toString();

                qDebug() << "🌍 Coordonnées reçues pour" << institutName << ":" << lat << lon;

                // Ajouter le marqueur avec le nom de l'institut
                m_markerModel.addLocation(institutName, lat, lon);
                emit marqueurAjoute(lat, lon); // Emit the signal here
                emit centerMap(lat, lon); // Nouveau signal pour centrer la carte
            }
        }
    }
    reply->deleteLater();
}

void MainWindow::searchLocation(const QString &address)
{
    if (address.trimmed().isEmpty()) {
        qDebug() << "Adresse vide, aucune recherche.";
        return;
    }

    // Encodage de l'adresse pour l'URL
    QString encodedAddress = QUrl::toPercentEncoding(address);

    QUrl url("https://nominatim.openstreetmap.org/search");
    QUrlQuery query;
    query.addQueryItem("q", encodedAddress);
    query.addQueryItem("format", "json");
    query.addQueryItem("limit", "1");
    query.addQueryItem("addressdetails", "1");
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "InstitutApp/1.0");

    // Envoyer la requête
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument json = QJsonDocument::fromJson(response);
            QJsonArray results = json.array();

            if (!results.isEmpty()) {
                QJsonObject firstResult = results.first().toObject();

                if (firstResult.contains("lat") && firstResult.contains("lon")) {
                    double lat = firstResult["lat"].toString().toDouble();
                    double lon = firstResult["lon"].toString().toDouble();
                    QString localisation = QUrlQuery(reply->url()).queryItemValue("q");

                    qDebug() << "🌍 Coordonnées reçues pour" << localisation << ":" << lat << lon;

                    // Ajouter le marqueur au modèle
                    m_markerModel.addLocation(localisation, lat, lon);

                    // Émettre un signal pour QML
                    emit marqueurAjoute(lat, lon); // Emit the signal here

                    // Centrez la carte sur l'institut trouvé
                    emit centerMap(lat, lon);

                } else {
                    qWarning() << "❌ Les clés 'lat' ou 'lon' sont absentes dans le résultat JSON.";
                }
            } else {
                qWarning() << "❌ Aucun résultat pour l'adresse.";
            }
        } else {
            qWarning() << "❌ Erreur dans la requête :" << reply->errorString();
        }

        reply->deleteLater();
    });

    qDebug() << "🔍 Recherche de l'adresse:" << address;
}

void MainWindow::searchInstitut(const QString &name)
{
    m_markerModel.clear();

    QSqlQuery query;
    query.prepare("SELECT ADRESSE_INST, NOM_INST FROM INSTITUTS WHERE NOM_INST LIKE :name");
    query.bindValue(":name", "%" + name + "%");

    if (query.exec() && query.next()) {
        QString adresse = query.value(0).toString();
        QString nomInstitut = query.value(1).toString();

        QString encodedAddress = QUrl::toPercentEncoding(adresse);
        QUrl url("https://nominatim.openstreetmap.org/search");
        QUrlQuery queryParams;
        queryParams.addQueryItem("q", encodedAddress);
        queryParams.addQueryItem("format", "json");
        queryParams.addQueryItem("limit", "1");
        queryParams.addQueryItem("addressdetails", "1");
        url.setQuery(queryParams);

        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::UserAgentHeader, "InstitutApp/1.0");

        request.setAttribute(QNetworkRequest::User, nomInstitut);

        networkManager->get(request);
    } else {
        qDebug() << "Aucun institut trouvé avec le nom :" << name;
    }
}

void MainWindow::on_map_clicked()
{
    QDialog *mapDialog = new QDialog(this);
    QQuickWidget *quickWidget = new QQuickWidget(mapDialog);
    quickWidget->setSource(QUrl("qrc:/map.qml"));
    quickWidget->rootContext()->setContextProperty("markerModel", &m_markerModel);
    quickWidget->rootContext()->setContextProperty("mainWindow", this);

    QVBoxLayout *layout = new QVBoxLayout(mapDialog);
    layout->addWidget(quickWidget);
    mapDialog->setLayout(layout);

    m_markerModel.loadFromJson();

    mapDialog->exec();
}
