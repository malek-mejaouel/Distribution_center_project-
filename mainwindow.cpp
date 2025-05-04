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
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSystemTrayIcon>
#define seuil 65

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
    afficherStatistiquesCapacite();

    // Add a central layout manually
    QVBoxLayout *centralLayout = new QVBoxLayout(ui->centralwidget);
    centralLayout->setContentsMargins(0, 0, 0, 0);
    ui->centralwidget->setLayout(centralLayout);

    loadTableData();
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
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheIdTextChanged);

    connect(ui->tab1, &QTableWidget::itemSelectionChanged, this, &MainWindow::onTableRowClicked);
    connect(ui->noti, &QPushButton::clicked, this, &MainWindow::on_noti_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->employee, &QLineEdit::textChanged, this, &MainWindow::onEmployeeTextChanged);
    connect(ui->b1, &QPushButton::clicked, this, &MainWindow::on_b1_clicked);

    ui->map->setIcon(QIcon(":/ressources/maps.png"));

    ui->noti->setIcon(QIcon(":/ressources/noti.png"));

    updateTableData();
    trayicon=new QSystemTrayIcon(this);
    trayicon->setIcon(QIcon(":/ressources/box-3-48.png"));
    trayicon->show();
    trayicon->setToolTip("instituts ");

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    QByteArray data2=A.read_from_arduino().trimmed();
    if(data.length()==1 || (data2.length()==1 && data.length()!=3 && data2.toInt()<3) )data+=data2;
    else if(!(data.length()==3 && data2.length()==1))    data=data2;
    data=data.trimmed();
    if(data2.length()==0)A.write_to_arduino("1");

    qDebug()<<"data"<<data.trimmed();
    qDebug()<<"data 2"<<data2.trimmed();

    if(data.length()>1 && data.length()<=3){
        ui->label_5->setText(data.trimmed());

        if(data.toInt()>seuil && ui->lineEdit_9->text().length()!=0){
            QSqlQuery query;
            query.prepare("UPDATE INSTITUTS SET "
                          "CAPACITE_INST =CAPACITE_INST-1  "
                          "WHERE ID_INST = :id");
            query.bindValue(":id", ui->lineEdit_9->text());
            query.exec();

            ui->label_55->setText(data.trimmed());
            loadTableData();
        }
    }
}

void MainWindow::on_addButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("select * from INSTITUTS WHERE ID_INST=:id");
    query.bindValue(":id",ui->lineEdit_9->text());

    query.exec();
    if(query.next()){
        A.write_to_arduino("1");}
    else{ A.write_to_arduino("2");
        ui->label_55->setText("id non trouve");}
}

void MainWindow::loadTableData()
{
    Institut institut;
    QSqlQueryModel *model = institut.afficher();
    updateTableWithModel(model);
    afficherStatistiquesCapacite();
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
        ui->employee->setText(ui->tab1->item(row, 7)->text());
    }
}

void MainWindow::onEmployeeTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        // Si le champ est vide, on ne fait rien
        return;
    }

    if (!employeeExists(text)) {
        // Afficher une alerte si l'ID de l'employé n'existe pas
        QMessageBox::warning(this, "Erreur", "L'ID de l'employé n'existe pas dans la base de données.");
        // Vous pouvez également réinitialiser le champ ou prendre une autre action
        ui->employee->clear();
    }
}

bool MainWindow::employeeExists(const QString &employeeId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employees WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", employeeId);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}

void MainWindow::on_b2_clicked()
{
    ui->nomInst_input->clear();
    ui->adresseInst_input->clear();
    ui->responsableInst_input->clear();
    ui->telephoneInst_input->clear();
    ui->emailInst_input->clear();
    ui->capaciteInst_input->clear();
    ui->employee->clear();
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
    institut.setIdEmployee(ui->employee->text().toInt());

    // Vérification des données avant d'essayer l'ajout
    QString erreur;
    if (!institut.validerDonnees(erreur)) {
        qDebug() << "Erreur de validation des données:" << erreur;
        QMessageBox::critical(this, "Erreur", "Les données saisies ne sont pas valides !\n" + erreur);
        return;  // Stopper l'exécution ici si validation échoue
    }

    if (institut.ajouter()) {
        QMessageBox::information(this, "Succès", "Institut ajouté !");
        loadTableData(); // Recharge les données
    } else {
        qDebug() << "Échec de l'ajout de l'institut.";
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'institut.");
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

    int idEmploye = ui->employee->text().toInt();
    institut.setIdEmployee(idEmploye);

    if (institut.modifier()) {
        QMessageBox::information(this, "Succès", "Institut modifié !");
        loadTableData(); // Recharge les données
    }
}

void MainWindow::on_b4_clicked()
{
    if (selectedInstitutId == "-1" || selectedInstitutId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un institut à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de suppression",
                                "Êtes-vous sûr de vouloir supprimer cet institut ?\n"
                                "Cette action est irréversible.",
                                QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Institut institut;
        institut.setId(selectedInstitutId.toInt());

        if (institut.supprimer()) {
            QMessageBox::information(this, "Succès", "L'institut a été supprimé avec succès.");
            
            // Réinitialiser les champs
            ui->nomInst_input->clear();
            ui->adresseInst_input->clear();
            ui->responsableInst_input->clear();
            ui->telephoneInst_input->clear();
            ui->emailInst_input->clear();
            ui->capaciteInst_input->clear();
            ui->employee->clear();
            
            // Réinitialiser l'ID sélectionné
            selectedInstitutId = "-1";
            
            // Rafraîchir la table
            loadTableData();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'institut.\n"
                                "Veuillez vérifier que l'institut existe toujours dans la base de données.");
            qDebug() << "Échec de la suppression de l'institut avec l'ID :" << selectedInstitutId;
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
    qDebug() << "Setting up chart...";

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

    QChart *barChart = new QChart();
    barChart->setTitle("<b style='color:white; font-size:16px;'>Répartition des Instituts par Capacité</b>");
    barChart->setAnimationOptions(QChart::AllAnimations);
    barChart->setBackgroundBrush(QBrush(QColor("#34495e")));
    barChart->setTitleBrush(QBrush(Qt::white));
    barChart->setMargins(QMargins(15, 15, 15, 15));

    // Créer un QBarSet par intervalle avec 3 valeurs (uniquement la position pertinente remplie)
    QBarSet *set0_500 = new QBarSet("0-500 places");
    QBarSet *set501_1000 = new QBarSet("501-1000 places");
    QBarSet *set1001Plus = new QBarSet("1001+ places");

    *set0_500 << intervalCounts[0] << 0 << 0; // Seule la première catégorie a une valeur
    *set501_1000 << 0 << intervalCounts[1] << 0; // Seule la deuxième catégorie a une valeur
    *set1001Plus << 0 << 0 << intervalCounts[2]; // Seule la troisième catégorie a une valeur

    set0_500->setColor(QColor("#3498db"));
    set501_1000->setColor(QColor("#2ecc71"));
    set1001Plus->setColor(QColor("#e74c3c"));

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(set0_500);
    barSeries->append(set501_1000);
    barSeries->append(set1001Plus);

    barChart->addSeries(barSeries);

    // Axe X avec les trois catégories
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(intervals);
    axisX->setLabelsColor(Qt::white);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    // Axe Y
    int maxValue = *std::max_element(intervalCounts, intervalCounts + 3) + 2;
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue);
    axisY->setLabelsColor(Qt::white);
    axisY->setGridLineColor(QColor("#3d566e"));
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    barChart->legend()->setVisible(true);
    barChart->legend()->setLabelColor(Qt::white);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    ui->chartViewFunctionalites->setChart(barChart);

    // Ajuster la position des étiquettes
    QTimer::singleShot(0, this, [=]() {
        for (int i = 0; i < 3; ++i) {
            if (intervalCounts[i] == 0) continue;

            double pourcentage = (static_cast<double>(intervalCounts[i]) / totalInstituts) * 100.0;
            QString labelText = QString("%1%\n%2 instituts\n%3 places")
                                    .arg(pourcentage, 0, 'f', 1)
                                    .arg(intervalCounts[i])
                                    .arg(totalPlaces[i]);

            // Calculer la position en tenant compte du groupe
            QPointF barCenter(i, intervalCounts[i]);
            QPointF scenePos = barChart->mapToPosition(barCenter, barSeries);

            // Ajustement manuel pour centrer l'étiquette sur la barre
            // (dépend de la largeur des barres, ajustez selon vos besoins)
            qreal xOffset = -30 + i * 60; // Ajustement empirique
            QGraphicsTextItem *textItem = new QGraphicsTextItem(labelText);
            textItem->setDefaultTextColor(Qt::white);
            textItem->setFont(QFont("Segoe UI", 9, QFont::Bold));
            textItem->setPos(scenePos.x() + xOffset, scenePos.y() - 50);
            barChart->scene()->addItem(textItem);
        }
    });

    qDebug() << "Chart setup complete.";
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

void MainWindow::on_noti_clicked()
{
    int id = ui->notifylineedit->text().toInt();

    trayicon->showMessage(
        "Alerte Livraison",
        QString("Dear employee %1, your box was successfully delivered.").arg(id),
        QSystemTrayIcon::Warning,
        10000
        );
}

void MainWindow::notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon)
{
    if (trayIcon) {
        trayIcon->showMessage(title, message, icon, 5000);
    }
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

void MainWindow::checkcommandelivre()
{
    // Implementation of checkcommandelivre
}
