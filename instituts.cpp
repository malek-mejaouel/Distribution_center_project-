/* --------------- instituts.cpp (full, self-contained) ---------------- */
#include "instituts.h"
#include "ui_instituts.h"
#include <QtCharts>                  // <-- brings the QtCharts namespace

/* 1️⃣ – GUI / Qt Quick / Charts headers */
#include <QtQuickWidgets/QQuickWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>

/* 2️⃣ – Qt core / sql / network */
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QSystemTrayIcon>

/* 3️⃣ – app-specific headers */
#include "institut.h"
#include "markermodel.h"
#include "arduino2.h"
#include "dialog.h"
#include "livreurs.h"
#include "equipments.h"
#include "boxs.h"

#define SEUIL_CAPACITE 65
QT_USE_NAMESPACE ;
static const QStringList sortColumns {
    "ID_INST",
    "NOM_INST",
    "ADRESSE_INST",
    "RESPONSABLE_INST",
    "TELEPHONE_INST",
    "EMAIL_INST",
    "CAPACITE_INST",
    "ID_EMPLO"
};
instituts::instituts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::instituts)
    , selectedInstitutId("-1")
    , networkManager(new QNetworkAccessManager(this))
    , m_markerModel(new MarkerModel(this))
{
    ui->setupUi(this);

    // — set up the table’s columns & fixed headers once
    const QStringList headers{ "ID", "Nom", "Adresse", "Responsable",
                              "Téléphone", "Email", "Capacité", "ID employé" };
    ui->tab1_in->setColumnCount(headers.size());
    ui->tab1_in->setHorizontalHeaderLabels(headers);

    // — initial load + 5s timer
    loadTableData();
    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &instituts::updateTableData);
    timer->start(5000);
    /* ---------- populate/ wire the “tri” combo + buttons -------------------- */
    ui->tri_in->addItems(
        { "ID", "Nom", "Adresse", "Responsable",
         "Téléphone", "Email", "Capacité", "ID employee" } );

    connect(ui->tri_in , QOverload<int>::of(&QComboBox::currentIndexChanged),
            this       , &instituts::onTri_inComboBoxChanged);
    connect(ui->ASC_in , &QPushButton::clicked, this, &instituts::onCroissantButtonClicked);
    connect(ui->DESC_in, &QPushButton::clicked, this, &instituts::onDecroissantButtonClicked);

    /* ---------- search field & row-selection ------------------------------- */
    connect(ui->recherche_in, &QLineEdit::textChanged,
            this, &instituts::performSearch);
    connect(ui->tab1_in, &QTableWidget::itemSelectionChanged,
            this, &instituts::onTableRowClicked);

    /* ---------- misc. buttons ---------------------------------------------- */
    connect(ui->pdf_in , &QPushButton::clicked, this, &instituts::on_pdf_in_clicked);
    connect(ui->noti_in, &QPushButton::clicked, this, &instituts::on_noti_in_clicked);
    connect(ui->map_in , &QPushButton::clicked, this, &instituts::on_map_in_clicked);

    /* ---------- small, single-shot icons ----------------------------------- */
    ui->map_in ->setIcon(QIcon(":/ressources/maps.png"));
    ui->noti_in->setIcon(QIcon(":/ressources/noti.png"));

    /* ---------- system-tray ------------------------------------------------- */
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/new/prefix1/Ressources/logo.png"));
    trayIcon->show();
    trayIcon->setToolTip("FullMark ");

    /* ---------- Arduino 2 --------------------------------------------------- */
    connect(A.getserial(), &QSerialPort::readyRead,
            this          , &instituts::update_label_in);
   // switch (A.connect_Arduino2())
    //{
    //case  0: qDebug() << "Arduino2 connected on"  << A.getArduino2_port_name(); break;
    //case  1: qDebug() << "Arduino2 found but busy" << A.getArduino2_port_name(); break;
    //default: qDebug() << "Arduino2 not available";                               break;
    //}
}

instituts::~instituts()
{
    delete ui;
}

void instituts::update_label_in()
{
    QByteArray data2 = A.read_from_arduino2().trimmed();

    if (data.length()==1 || (data2.length()==1 && data.length()!=3 && data2.toInt()<3))
        data += data2;
    else if (!(data.length()==3 && data2.length()==1))
        data = data2;

    data = data.trimmed();
    if (data2.length()==0) A.write_to_arduino2("1");

    qDebug()<<"data"<<data<<"data2"<<data2;

    if (data.length()>1 && data.length()<=3) {
        ui->label_in->setText(data);

        if (data.toInt()>SEUIL_CAPACITE && !ui->lineEdit_in->text().isEmpty()) {
            QSqlQuery q; q.prepare("UPDATE INSTITUTS SET CAPACITE_INST=CAPACITE_INST-1 WHERE ID_INST=:id");
            q.bindValue(":id", ui->lineEdit_in->text());
            q.exec();
            loadTableData();
        }
    }
}
void instituts::on_addButton_in_clicked()
{
    QSqlQuery query;
    query.prepare("select * from INSTITUTS WHERE ID_INST=:id");
    query.bindValue(":id", ui->lineEdit_in->text());

    query.exec();
    if (query.next()) {
        A.write_to_arduino2("1");
    }
    else {
        A.write_to_arduino2("2");
        ui->label_in->setText("id non trouve");
    }
}

void instituts::loadTableData()
{
    Institut inst;
    QSqlQueryModel *model = inst.afficher();
    updateTableWithModel(model);
    afficherStatistiquesCapacite();
    delete model;
}

void instituts::updateTableData()
{
    Institut inst;
    QSqlQueryModel *model = inst.afficher();
    updateTableWithModel(model);
    delete model;
}

void instituts::onTableRowClicked()
{
    int row = ui->tab1_in->currentRow();
    if (row < 0) return;

    auto safe = [&](int c){
        auto *it = ui->tab1_in->item(row, c);
        return it ? it->text() : QString();
    };

    selectedInstitutId              = safe(0);
    ui->nomInst_input_in->setText(      safe(1));
    ui->adresseInst_input_in->setText(  safe(2));
    ui->responsableInst_input_in->setText(safe(3));
    ui->telephoneInst_input_in->setText( safe(4));
    ui->emailInst_input_in->setText(     safe(5));
    ui->capaciteInst_input_in->setText(  safe(6));
    ui->employee_in->setText(            safe(7));
}


void instituts::onemployee_in_TextChanged(const QString &text)
{
    if (text.isEmpty()) {
        // Si le champ est vide, on ne fait rien
        return;
    }

    if (!employee_inExists(text)) {
        // Afficher une alerte si l'ID de l'employé n'existe pas
        QMessageBox::warning(this, "Erreur", "L'ID de l'employé n'existe pas dans la base de données.");
        // Vous pouvez également réinitialiser le champ ou prendre une autre action
        ui->employee_in->clear();
    }
}

bool instituts::employee_inExists(const QString &employee_inId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", employee_inId);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}

void instituts::on_b2_in_clicked()
{
    ui->nomInst_input_in->clear();
    ui->adresseInst_input_in->clear();
    ui->responsableInst_input_in->clear();
    ui->telephoneInst_input_in->clear();
    ui->emailInst_input_in->clear();
    ui->capaciteInst_input_in->clear();
    ui->employee_in->clear();
}

void instituts::on_b1_in_clicked()
{
    Institut institut;
    institut.setNom(ui->nomInst_input_in->text());
    institut.setAdresse(ui->adresseInst_input_in->text());
    institut.setResponsable(ui->responsableInst_input_in->text());
    institut.setTelephone(ui->telephoneInst_input_in->text().toInt());
    institut.setEmail(ui->emailInst_input_in->text());
    institut.setCapacite(ui->capaciteInst_input_in->text().toInt());
    institut.setIdEmployee(ui->employee_in->text().toInt());

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

void instituts::on_b3_in_clicked()
{
    if (selectedInstitutId == "-1" || selectedInstitutId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun institut sélectionné.");
        return;
    }

    Institut institut;
    institut.setId(selectedInstitutId.toInt());
    institut.setNom(ui->nomInst_input_in->text());
    institut.setAdresse(ui->adresseInst_input_in->text());
    institut.setResponsable(ui->responsableInst_input_in->text());
    institut.setTelephone(ui->telephoneInst_input_in->text().toInt());
    institut.setEmail(ui->emailInst_input_in->text());
    institut.setCapacite(ui->capaciteInst_input_in->text().toInt());

    int idEmploye = ui->employee_in->text().toInt();
    institut.setIdEmployee(idEmploye);

    if (institut.modifier()) {
        QMessageBox::information(this, "Succès", "Institut modifié !");
        loadTableData(); // Recharge les données
    }
}

void instituts::on_b4_in_clicked()
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
            ui->nomInst_input_in->clear();
            ui->adresseInst_input_in->clear();
            ui->responsableInst_input_in->clear();
            ui->telephoneInst_input_in->clear();
            ui->emailInst_input_in->clear();
            ui->capaciteInst_input_in->clear();
            ui->employee_in->clear();

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

void instituts::onTri_inComboBoxChanged(int index)
{
    if (index < 0 || index >= sortColumns.size())
        return;

    Institut inst;
    QSqlQueryModel *m = inst.trier(sortColumns.at(index), "ASC");
    updateTableWithModel(m);
}

void instituts::onCroissantButtonClicked()
{
    int idx = ui->tri_in->currentIndex();
    if (idx < 0 || idx >= sortColumns.size())
        return;

    Institut inst;
    QSqlQueryModel *m = inst.trier(sortColumns.at(idx), "ASC");
    updateTableWithModel(m);
}
void instituts::onDecroissantButtonClicked()
{
    int idx = ui->tri_in->currentIndex();
    if (idx < 0 || idx >= sortColumns.size())
        return;

    Institut inst;
    QSqlQueryModel *m = inst.trier(sortColumns.at(idx), "DESC");
    updateTableWithModel(m);
}
void instituts::performSorting(const QString &order)
{
    QString critere = ui->tri_in->currentText();
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
    } else if (critere == "ID employee") {
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

// 2️⃣ – rewrite this one completely  ----------------------------------
void instituts::updateTableWithModel(QSqlQueryModel *model)
{
    // always reset contents, then repopulate headers + cells
    const int rows = model ? model->rowCount()     : 0;
    const int cols = model ? model->columnCount()  : 0;

    ui->tab1_in->clearContents();    // only erase cells
    ui->tab1_in->setRowCount(rows);
    ui->tab1_in->setColumnCount(cols);

    // fixed, “pretty” headers
    const QStringList headers{ "ID", "Nom", "Adresse", "Responsable",
                              "Téléphone", "Email", "Capacité", "ID employé" };
    if (headers.size() == cols)
        ui->tab1_in->setHorizontalHeaderLabels(headers);

    // fill every cell from the model
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            QString text = model->data(model->index(r, c)).toString();
            ui->tab1_in->setItem(r, c, new QTableWidgetItem(text));
        }
    }
}

void instituts::onrecherche_inIdTextChanged(const QString &text)
{
    performSearch(text);
}

void instituts::performSearch(const QString &text)
{
    Institut institut;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour recherche uniquement par ID
    QSqlQuery query;
    query.prepare("SELECT * FROM INSTITUTS WHERE ID_INST LIKE :text");
    query.bindValue(":text", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Erreur de recherche" << query.lastError().text();
        return;
    }

    model->setQuery(std::move(query)); // Use std::move to pass the query
    updateTableWithModel(model);
}

void instituts::afficherStatistiquesCapacite()
{
    /* 1️⃣ – Collect data -------------------------------------------------- */
    const QStringList intervals{ "0-500", "501-1000", "1001+" };
    int  nb[3]{0,0,0}, sum[3]{0,0,0}, total = 0;

    QSqlQuery q("SELECT CAPACITE_INST FROM INSTITUTS");
    while (q.next())
    {
        const int cap = q.value(0).toInt();
        ++total;
        (cap<=500   ? nb[0]++, sum[0]+=cap :
         cap<=1000  ? nb[1]++, sum[1]+=cap :
         nb[2]++, sum[2]+=cap);
    }

    /* 2️⃣ – Build bar-chart ---------------------------------------------- */
    auto chart      = new QChart;
    chart->setTitle("<b style='color:white;font-size:16px'>Répartition des Instituts</b>");
    chart->setBackgroundBrush(QColor("#34495e"));
    chart->setTitleBrush(Qt::white);
    chart->setAnimationOptions(QChart::AllAnimations);

    auto s0 = new QBarSet(intervals[0]); *s0 << nb[0] << 0     << 0;
    auto s1 = new QBarSet(intervals[1]); *s1 << 0     << nb[1] << 0;
    auto s2 = new QBarSet(intervals[2]); *s2 << 0     << 0     << nb[2];
    s0->setColor("#3498db"); s1->setColor("#2ecc71"); s2->setColor("#e74c3c");

    auto barSeries = new QBarSeries; barSeries->append({s0,s1,s2});
    chart->addSeries(barSeries);

    auto axX = new QBarCategoryAxis; axX->append(intervals); axX->setLabelsColor(Qt::white);
    chart->addAxis(axX, Qt::AlignBottom); barSeries->attachAxis(axX);

    const int ymax = *std::max_element(nb, nb+3) + 2;
    auto axY = new QValueAxis; axY->setRange(0, ymax); axY->setLabelsColor(Qt::white);
    chart->addAxis(axY, Qt::AlignLeft);  barSeries->attachAxis(axY);

    chart->legend()->setLabelColor(Qt::white);

    /* 3️⃣ – Obtain / create the view from the .ui ------------------------ */
    QChartView *view = ui->chartViewFunctionalites_2;
    if (!view) {                                  // if you accidentally removed it
        view = new QChartView(this);
        view->setObjectName("chartViewFunctionalites_2");
        ui->verticalWidget_2->layout()->addWidget(view);
    }
    view->setRenderHint(QPainter::Antialiasing);
    view->setChart(chart);

    /* 4️⃣ – Add % labels once the layout pass is done ------------------- */
    QTimer::singleShot(0, this, [=]{
        for (int i=0;i<3;++i) if (nb[i]) {
                double pct = 100. * nb[i] / total;
                QString txt = QString("%1 % – %2 inst.\n%3 places")
                                  .arg(pct,0,'f',1).arg(nb[i]).arg(sum[i]);
                QPointF barCentre(i, nb[i]);
                QPointF scene = chart->mapToPosition(barCentre, barSeries);
                auto label = new QGraphicsTextItem(txt);
                label->setDefaultTextColor(Qt::white);
                label->setFont(QFont("Segoe UI", 8, QFont::Bold));
                label->setPos(scene.x()-25+i*50, scene.y()-45);
                chart->scene()->addItem(label);
            }
    });
}

void instituts::on_pdf_in_clicked()
{
    qDebug() << "📄 Bouton pdfcliqué !";

    // Emplacement par défaut dans "Documents"
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/liste_instituts.pdf";

    // Ouvre le dialogue pour choisir le nom et emplacement du fichier
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter en pdf",
        defaultPath,
        "pdf (*.pdf)"
        );

    if (filePath.isEmpty()) {
        qDebug() << "🚫 Export annulé par l'utilisateur.";
        return;
    }

    Institut inst;
    if (inst.exporterPDF(filePath)) {
        QMessageBox::information(this, "✅ Succès", "pdf_in généré :\n" + filePath);
        qDebug() << "✅ Fichier pdf_in créé avec succès :" << filePath;
    } else {
        QMessageBox::critical(this, "❌ Erreur", "Échec de la création du pdf_in.");
        qDebug() << "❌ Échec lors de l'export pdf_in.";
    }
}

/*void instituts::afficherIdsEmployes()
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
    int currentRowCount = ui->tab1_in->rowCount();
    int newRowCount = idsEmployes.size();

    if (newRowCount > currentRowCount) {
        ui->tab1_in->setRowCount(newRowCount);
    }

    // Remplissez la colonne "ID employee" avec les IDs récupérés
    for (int i = 0; i < idsEmployes.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(idsEmployes[i]));
        ui->tab1_in->setItem(i, 7, item); // 7 est l'index de la colonne "ID employee"
    }
}*/

void instituts::on_noti_in_clicked()
{
    bool ok;
    int id = ui->notifylineedit_in->text().toInt(&ok);

    // Vérification de la conversion numérique
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID employé invalide !");
        return;
    }

    // Vérification de l'existence dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_EMPLOYE FROM EMPLOYEES WHERE ID_EMPLOYE = :id");
    checkQuery.bindValue(":id", id);

    if (!checkQuery.exec()) {
        qDebug() << "Erreur de vérification ID:" << checkQuery.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur de base de données !");
        return;
    }

    if (checkQuery.next()) {
        // ID existe -> envoyer notification
        trayIcon->showMessage(
            "Alerte Livraison",
            QString("Dear employee %1, your box was successfully delivered.").arg(id),
            QSystemTrayIcon::Information,
            10000
            );
    } else {
        // ID n'existe pas -> afficher alerte
        QMessageBox::warning(this, "Non trouvé",
                             QString("Aucun employé avec l'ID %1 trouvé dans la base de données !").arg(id));
    }
}

void instituts::notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon)
{
    if (trayIcon) {
        trayIcon->showMessage(title, message, icon, 5000);
    }
}

void instituts::onGeoCodeReply(QNetworkReply *reply)
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
                m_markerModel->addLocation(institutName, lat, lon);
                emit marqueurAjoute(lat, lon); // Emit the signal here
                emit centerMap(lat, lon); // Nouveau signal pour centrer la carte
            }
        }
    }
    reply->deleteLater();
}

void instituts::searchLocation(const QString &address)
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
                    m_markerModel->addLocation(localisation, lat, lon);

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

    qDebug() << "🔍 recherche de l'adresse:" << address;
}

void instituts::searchInstitut(const QString &name)
{
    m_markerModel->clear();

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

void instituts::on_map_in_clicked()
{
    auto mapDlg = new QDialog(this);
    auto qw     = new QQuickWidget(mapDlg);

    qw->rootContext()->setContextProperty("markerModel", m_markerModel);
    qw->rootContext()->setContextProperty("instituts"  , this);
    qw->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qw->setSource(QUrl("qrc:/map.qml"));

    auto lay = new QVBoxLayout(mapDlg); lay->setContentsMargins(0,0,0,0);
    lay->addWidget(qw);

    if (m_markerModel->count()==0)        //  ← fixed
        m_markerModel->loadFromJson();

    mapDlg->resize(900,600);
    mapDlg->exec();
}
void instituts::on_pushButton_5_clicked()
{
    Dialog *eqWindow = new Dialog(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}
void instituts::on_pushButton_6_clicked()
{
    Equipments *eqWindow = new Equipments(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}
void instituts::on_pushButton_11_clicked()
{
    livreurs *eqWindow = new livreurs(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}

void instituts::on_pushButton_12_clicked()
{
    boxs *eqWindow = new boxs(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}
