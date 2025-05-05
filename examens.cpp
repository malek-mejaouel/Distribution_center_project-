
#include "examens.h"
#include "ui_examens.h"
#include "examenclass.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug> // Pour le débogage
#include <QDesktopServices>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlTableModel>

// pour stat

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QFileInfo>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRandomGenerator>







#include <QRegularExpressionValidator>
#define seuil 65





examens::examens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::examens)
{
    ui->setupUi(this);

    test=false;
    ui->tableView->setModel( ex.afficher());

    QIntValidator *intvalidator= new QIntValidator(0,10000,this);//0 -> 99 999
    ui->dureeExamenLimeEdit->setValidator(intvalidator);

    QRegularExpressionValidator     *charValidator=new QRegularExpressionValidator(QRegularExpression("[A-Za-z0-9]*"));
    ui-> nomExamenLineEdit->setValidator(charValidator);
    ui-> matiereExamenLineEdit->setValidator(charValidator);
    ui->niveauSpinBox->setMaximum(5);
    ui->niveauSpinBox->setMinimum(1);
    ui->dateExamenDateEdit->setDate(QDate::currentDate());
    stat_niveau();
    int ret=A.connect_arduino2(); // lancer la connexion à arduino2
    switch(ret){
    case(0):qDebug()<< "arduino2 is available and connected to : "<< A.getarduino2_port_name();
        break;
    case(1):qDebug() << "arduino2 is available but not connected to :" <<A.getarduino2_port_name();
        break;
    case(-1):qDebug() << "arduino2 is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

examens::~examens()
{
    delete ui;
}

void examens::update_label()
{

    QByteArray data2=A.read_from_arduino2().trimmed();
    if(data.length()==1 || (data2.length()==1 && data.length()!=3 && data2.toInt()<3) )data+=data2;
    else if(!(data.length()==3 && data2.length()==1))    data=data2;
    data=data.trimmed();
    if(data2.length()==0)A.write_to_arduino2("1");




    // QString data2=A.read_from_arduino2();
    qDebug()<<"data"<<data.trimmed();
    qDebug()<<"data 2"<<data2.trimmed();
    // qDebug()<<"data2"<<data2.trimmed();


    if(data.length()>1 && data.length()<=3){
        ui->label_5->setText(data.trimmed());
        if(data.toInt()>seuil && ui->lineEdit_9->text().length()!=0){
            QSqlQuery query;
            query.prepare("UPDATE  EXAMENS SET NBRCOPIES=NBRCOPIES-1  WHERE IDEXAMEN=:id ");
            query.bindValue(":id", ui->lineEdit_9->text());
            query.exec();

            ui->label_5->setText(data.trimmed());
            /*else {
                      ui->label_5->setText("id non trouve");
                      A.write_to_arduino2("2");

                      qDebug()<<"non okayy";
                      */



        }


    }


    // si les données reçues de arduino2 via la liaison série sont égales à 1
    // alors afficher ON

    // si les données reçues de arduino2 via la liaison série sont égales à 0
    //alors afficher ON
}




void examens::on_addButton_clicked()
{
    // Récupérer les valeurs saisies par l'utilisateur
    QString nomExamen = ui->nomExamenLineEdit->text();
    QString matiereExamen = ui->matiereExamenLineEdit->text();
    QString dateExamen = ui->dateExamenDateEdit->text();
    QString dureeExamen = ui->dureeExamenLimeEdit->text();
    int nbrCopies = ui->nbcopiesSpinBox->value();
    int  niveau = ui->niveauSpinBox->value();
    //class

    examenclass C (nomExamen,matiereExamen,dateExamen,dureeExamen,nbrCopies,niveau);  // a editer

    bool test = C.ajouter();
    // Vérifier que les champs obligatoires ne sont pas vides
    if (nomExamen.isEmpty() || matiereExamen.isEmpty() || dateExamen.isEmpty() || dureeExamen.isEmpty()  ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    if(niveau==0 || niveau>5){
        QMessageBox::warning(this, "Niveau invalide ! ", "Veuillez remplacer le champ niveau par un niveau existant.");
        return;
    }

    if(nbrCopies==0){
        QMessageBox::warning(this, " Copies nulles ! ", "Veuillez Saisir au moins une copie.");
        return;
    }

    // Exécuter la requête
    if (test) {
        QMessageBox::information(this, "Succès", "Examen ajouté avec succès !");
        stat_niveau();

        ui->tableView->setModel( ex.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'examen : ");
    }
}


void examens::on_updateButton_clicked() {


    // Récupérer les valeurs saisies par l'utilisateur
    QString nomExamen = ui->nomExamenLineEdit->text();
    QString matiereExamen = ui->matiereExamenLineEdit->text();
    QString dateExamen = ui->dateExamenDateEdit->text();
    QString dureeExamen = ui->dureeExamenLimeEdit->text();
    int nbrCopies = ui->nbcopiesSpinBox->value();
    int  niveau = ui->niveauSpinBox->value();
    //class

    examenclass C (ID_EXAMEN,nomExamen,matiereExamen,dateExamen,dureeExamen,nbrCopies,niveau);  // a editer

    bool test = C.modifier();
    // Vérifier que les champs obligatoires ne sont pas vides
    if (nomExamen.isEmpty() || matiereExamen.isEmpty() || dateExamen.isEmpty() || dureeExamen.isEmpty()  ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    if(niveau==0 || niveau>5){
        QMessageBox::warning(this, "Niveau invalide ! ", "Veuillez remplacer le champ niveau par un niveau existant.");
        return;
    }

    if(nbrCopies==0){
        QMessageBox::warning(this, " Copies nulles ! ", "Veuillez Saisir au moins une copie.");
        return;
    }

    // Exécuter la requête
    if (test) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
        // 1. Réinitialiser les champs de saisie
        ui->nomExamenLineEdit->clear();
        ui->matiereExamenLineEdit->clear();
        ui->dateExamenDateEdit->setDate(QDate::currentDate());
        ui->dureeExamenLimeEdit->clear();
        ui->nbcopiesSpinBox->setValue(1);
        ui->niveauSpinBox->setValue(1);
        ui->lineEdit_8->clear(); // Champ de recherche

        // 2. Réinitialiser le comboBox de tri
        ui->comboBoxTri->setCurrentIndex(0);
        ID_EXAMEN=0;
        ui->tableView->setModel( ex.afficher());
        stat_niveau();

    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de l'examen : ");
    }
}




void examens::on_pushButton_18_clicked() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Êtes-vous sûr de vouloir supprimer cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }



    bool submitSuccess =ex.supprimer(ID_EXAMEN);
    if (submitSuccess) {
        QMessageBox::information(this, "Succès", "Examen supprimé avec succès !");
        ui->tableView->setModel( ex.afficher());
        stat_niveau();


    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : ");
    }
}







// boutton pour l annulation des taches
void examens::on_pushButton_12_clicked()
{
    // 1. Réinitialiser les champs de saisie
    ui->nomExamenLineEdit->clear();
    ui->matiereExamenLineEdit->clear();
    ui->dateExamenDateEdit->setDate(QDate::currentDate());
    ui->dureeExamenLimeEdit->clear();
    ui->nbcopiesSpinBox->setValue(1);
    ui->niveauSpinBox->setValue(1);
    ui->lineEdit_8->clear(); // Champ de recherche

    // 2. Réinitialiser le comboBox de tri
    ui->comboBoxTri->setCurrentIndex(0);



    // 5. Optionnel : Message de confirmation
    QMessageBox::information(this, "Réinitialisation", "Tous les champs ont été réinitialisés.");
}















// debut metiers / metiers avancees


void examens::on_telechargerButton_clicked()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";
    QPrinter printer;
    printer.setOutputFileName(path);

    QTextDocument doc;
    doc.setPlainText("Test PDF - Si ceci fonctionne, le problème vient du contenu HTML");
    doc.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}









void examens::on_statsButton_clicked() {
    qDebug() << "Slot on_statsButton_clicked() appelé !";
    QMessageBox::information(this, "Test", "Le bouton fonctionne !");  // Affiche un popup
}




void examens::on_tableView_clicked(const QModelIndex &index)
{
    QAbstractItemModel* model = ui->tableView->model();

    if (!model) {
        qDebug() << "Model is null!";
        return;
    }

    int row = index.row();
    int id = model->data(model->index(row, 0)).toInt();
    qDebug() << row;
    qDebug() << id;

    QString nom = model->data(model->index(row, 1)).toString();
    QString matiereExamen = model->data(model->index(row, 2)).toString();
    QDate dateExamen = model->data(model->index(row, 3)).toDate();
    QString dureeExamen = model->data(model->index(row, 4)).toString();
    int nbrCopies = model->data(model->index(row, 5)).toInt();
    int niveau = model->data(model->index(row, 6)).toInt();

    ui->nomExamenLineEdit->setText(nom);
    ui->matiereExamenLineEdit->setText(matiereExamen);
    ui->dateExamenDateEdit->setDate(dateExamen);
    ui->dureeExamenLimeEdit->setText(dureeExamen);
    ui->nbcopiesSpinBox->setValue(nbrCopies);
    ui->niveauSpinBox->setValue(niveau);

    ID_EXAMEN = id;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Notification",
                                  "Tu peux generer un examen?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QMessageBox::information(this, "Test", "examen généré selon le nom: " + nom + " niveau: " + QString::number(niveau));
        QString userMessage="Proposer un examen de la matiere  "+matiereExamen+" de esprit de niveau:"+QString::number(niveau) + " qui commence par le mot Début: et qui termine par Fin:";

        ui->textEdit->append("<b style='color:blue'>User</b>: " + userMessage);

        ui->lineEdit_message->clear();

        QString apiKey = "5011e20f5fmsh2662a3e2666366ap197782jsn551a6129a06d";
        QString endpoint = "https://chatgpt-api8.p.rapidapi.com/";
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);

        QNetworkRequest request;
        request.setUrl(QUrl(endpoint));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("X-RapidAPI-Key", apiKey.toUtf8());
        request.setRawHeader("X-RapidAPI-Host", "chatgpt-api8.p.rapidapi.com");

        QJsonArray messagesArray;
        QJsonObject userMessageObject;
        userMessageObject["content"] = userMessage;
        userMessageObject["role"] = "user";
        messagesArray.append(userMessageObject);
        QJsonDocument doc(messagesArray);
        QByteArray postData = doc.toJson();

        QNetworkReply *reply = manager->post(request, postData);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                qDebug() << responseData;

                QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
                QJsonObject responseObject = jsonResponse.object();

                if (responseObject.contains("text")) {
                    QString botResponse = responseObject["text"].toString();
                    ui->textEdit->append("<b style='color:green'>ChatGPT</b>: " + botResponse);

                    int start = botResponse.indexOf("Début:") + QString("Début:").length();
                    int end = botResponse.indexOf("Fin:");

                    if (start != -1 && end != -1 && end > start) {
                        extractText = botResponse.mid(start, end - start).trimmed();


                        // Ask user where to save the PDF
                        QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
                        if (!filePath.isEmpty()) {
                            if (!filePath.endsWith(".pdf"))
                                filePath += ".pdf";

                            QPdfWriter writer(filePath);
                            writer.setPageSize(QPageSize::A4);
                            QPainter painter(&writer);

                            QRect rect = painter.viewport();
                            QFont font("Times", 12);
                            painter.setFont(font);
                            painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, extractText);

                            painter.end();
                            QMessageBox::information(this, "PDF Created", "PDF saved to:\n" + filePath);
                        }
                    } else {
                        qDebug() << "Could not extract text between 'debut:' and 'fin:'";
                    }
                }
                else {
                    ui->textEdit->append("<b style='color:red'>Error</b>: Invalid response format, missing 'text' field");
                }
            } else {
                ui->textEdit->append("<b style='color:red'>Error</b>: " + reply->errorString());
            }
        });

    }



}


void examens::stat_niveau()
{
    QList<QWidget*> childWidgets = ui->label_stat->findChildren<QWidget*>();
    for (QWidget* childWidget : childWidgets) {
        childWidget->deleteLater();

    }
    //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
    ui->label_stat->clear();
    ui->label_stat->hide();

    int s0, s1,s2,s3,s4;

    s0 = ex.countNiveau(5);
    s1= ex.countNiveau(4);
    s2= ex.countNiveau(3);
    s3= ex.countNiveau(2);
    s4= ex.countNiveau(1);





    int total = s0 + s1 +s2+s3+s4  ;
    // Calculate percentages
    float x;
    if(total != 0)
    {
        x=(s0 * 100.0f) / total;
    }
    else
        x=0.0f;


    float x1 = (total != 0) ? (s1 * 100.0f) / total : 0.0f;
    float x2 = (total != 0) ? (s2 * 100.0f) / total : 0.0f;
    float x3 = (total != 0) ? (s3 * 100.0f) / total : 0.0f;
    float x4 = (total != 0) ? (s4 * 100.0f) / total : 0.0f;


    // Adjust the percentages to ensure they sum up to 100%
    float totalPercentage = x + x1  +x2+x3+x4;
    if (totalPercentage != 100.0f && total != 0) {
        float correction = 100.0f - totalPercentage;
        x += correction;  // Apply correction to one of the slices (usually the largest one)
    }



    //qDebug() <<  x <<endl;
    // N5 25.00%
    QString ch1 = QString("N5 %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("N4 %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("N3 %2%").arg(QString::number(x2, 'f', 2));
    QString ch4 = QString("N2 %2%").arg(QString::number(x3, 'f', 2));
    QString ch5 = QString("N1 %2%").arg(QString::number(x4, 'f', 2));






    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);

    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::black));
    slice->setBrush(QColor(Qt::green));//changer


    QPieSlice *slice1= series->append(ch2,x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::black));
    slice1->setBrush(QColor(Qt::black));//changer


    QPieSlice *slice2= series->append(ch3,x2);
    slice2->setLabelVisible();
    slice2->setLabelColor(QColor(Qt::black));
    slice2->setBrush(QColor(Qt::yellow));//changer


    QPieSlice *slice3= series->append(ch4,x3);
    slice3->setLabelVisible();
    slice3->setLabelColor(QColor(Qt::black));
    slice3->setBrush(QColor(Qt::blue));//changer


    QPieSlice *slice4= series->append(ch5,x4);
    slice4->setLabelVisible();
    slice4->setLabelColor(QColor(Qt::black));
    slice4->setBrush(QColor(Qt::red));//changer

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBrush backgroundBrush(QColor(187,93,87,0));
    chart->setBackgroundBrush(backgroundBrush);
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->label_stat->size());
    chartview->setParent(ui->label_stat);
    ui->label_stat->setStyleSheet("background:transparent; color:white; ");
    ui->label_stat->show();

}

void examens::on_updateButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}




void examens::on_lineEdit_8_textChanged(const QString &valeur)
{
    QString critere = ui->comboBoxTri->currentText();

    examenclass exam;
    QSqlQueryModel *model = nullptr;

    if(critere == "niveau") {
        bool ok;
        int niveau = valeur.toInt(&ok);
        if(ok) {
            model = exam.ChercherParNiveau(niveau);
            ui->tableView->setModel(model);
        } else {
            ui->tableView->setModel(ex.afficher());
        }
    }
    else if(critere == "matière") {
        model = exam.ChercherParMatiere(valeur);
        ui->tableView->setModel(model);

    }
    else if(critere == "date") {
        // Validation simple de la date (à améliorer)
        if(QDate::fromString(valeur, "dd/MM/yyyy").isValid()) {
            model = exam.ChercherParDate(valeur);
            ui->tableView->setModel(model);

        } else {
            ui->tableView->setModel(ex.afficher());
        }
    }


}




void examens::on_bt_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           "<title>%1</title>\n"
           "<style>\n"
           "table {\n"
           "    width: 100%;\n"
           "    border-collapse: collapse;\n"
           "}\n"
           "th, td {\n"
           "    padding: 8px;\n"
           "    text-align: left;\n"
           "    border-bottom: 1px solid #ddd;\n"
           "}\n"
           "tr:nth-child(even) {\n"
           "    background-color: #f2f2f2;\n"
           "}\n"
           "</style>\n"
           "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<center> <H1>Liste des examens</H1></center><br/><br/>\n"
           "<img src=\"/Downloads/inter%(2)/inter/ressources/user.svg\" alt=\"Description of image\" style=\"max-width: 100%; height: auto;\">\n"
           "<table>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableView->isColumnHidden(column))
        {
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView->isColumnHidden(column))
            {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }



    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}


void examens::on_comboBoxTri_2_currentTextChanged(const QString &choix)
{
    QString critere = ui->comboBoxTri->currentText();

    examenclass exam;
    QSqlQueryModel *model = nullptr;
    if(choix!="Selectionner Ordre")
    {
        if(critere == "niveau") {


            model = exam.TRI("NIVEAU",choix);
            ui->tableView->setModel(model);
        }
        if(critere == "matière") {
            model = exam.TRI("MATIEREEXAMEN",choix);
            ui->tableView->setModel(model);

        }
        if(critere == "date") {
            model = exam.TRI("DATEEXAMEN",choix);
            ui->tableView->setModel(model);

        }
    }
    else
    {
        ui->tableView->setModel(ex.afficher());

    }
}


void examens::on_bt_envoyer_clicked()
{
    QString userMessage = ui->lineEdit_message->text();

    ui->textEdit->append("<b style='color:blue'>User</b>: " + userMessage);

    ui->lineEdit_message->clear();

    QString apiKey = "5011e20f5fmsh2662a3e2666366ap197782jsn551a6129a06d";
    QString endpoint = "https://chatgpt-api8.p.rapidapi.com/";
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request;
    request.setUrl(QUrl(endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", apiKey.toUtf8());
    request.setRawHeader("X-RapidAPI-Host", "chatgpt-api8.p.rapidapi.com");

    QJsonArray messagesArray;
    QJsonObject userMessageObject;
    userMessageObject["content"] = userMessage;
    userMessageObject["role"] = "user";
    messagesArray.append(userMessageObject);
    QJsonDocument doc(messagesArray);
    QByteArray postData = doc.toJson();

    QNetworkReply *reply = manager->post(request, postData);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << responseData;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject responseObject = jsonResponse.object();

            if (responseObject.contains("text")) {
                QString botResponse = responseObject["text"].toString();
                ui->textEdit->append("<b style='color:green'>ChatGPT</b>: " + botResponse);
            } else {
                ui->textEdit->append("<b style='color:red'>Error</b>: Invalid response format, missing 'text' field");
            }
        } else {
            ui->textEdit->append("<b style='color:red'>Error</b>: " + reply->errorString());
        }
    });

}


void examens::on_bt_clear_clicked()
{
    ui->textEdit->clear();

}





/*
int examens::sendEmail(QString dist, QString obj, QString bdy)
{

    qDebug()<<"sslLibraryBuildVersionString: "<<QSslSocket::sslLibraryBuildVersionString();
    qDebug()<<"sslLibraryVersionNumber: "<<QSslSocket::sslLibraryVersionNumber();
    qDebug()<<"supportsSsl: "<<QSslSocket::supportsSsl();;
    qDebug()<<QCoreApplication::libraryPaths();
    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // Adjust this based on your SMTP server configuration
    QString username = "rayensassi1235@gmail.com";
    QString password = "camx avha gsaz dzvx";
    //opuc ifgh tjle ciag
    // Sender and recipient information
    QString from = "rayensassi1235@gmail.com";
    QString to =dist;
    QString subject = obj;
    QString body = bdy;

    // Create a TCP socket
    QSslSocket socket;

    // Connect to the SMTP server
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error connecting to the server:" << socket.errorString();
        return -1;
    }

    // Wait for the greeting from the server
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Connected to the server.";

    // Send the HELO command
    socket.write("HELO localhost\r\n");
    socket.waitForBytesWritten();

    // Read the response from the server
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the authentication information
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the username
    socket.write(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the password
    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the MAIL FROM command
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the RCPT TO command
    socket.write("RCPT TO:<" + to.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the DATA command
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the email content
    socket.write("From: " + from.toUtf8() + "\r\n");
    socket.write("To: " + to.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("\r\n");  // Empty line before the body
    socket.write(body.toUtf8() + "\r\n");
    socket.write(".\r\n");  // End of email content
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the QUIT command
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Email sent successfully.";

    // Close the socket
    socket.close();
    return 0;
}

*/
void examens::on_generer_correction_clicked()
{

    QString userMessage="Proposer une correction de cette examen:"+extractText+"en limitant le message de la correction par le mot Début: et pour finir le mot Fin:";

    ui->textEdit->append("<b style='color:blue'>User</b>: " + userMessage);

    ui->lineEdit_message->clear();

    QString apiKey = "5011e20f5fmsh2662a3e2666366ap197782jsn551a6129a06d";
    QString endpoint = "https://chatgpt-api8.p.rapidapi.com/";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request;
    request.setUrl(QUrl(endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-RapidAPI-Key", apiKey.toUtf8());
    request.setRawHeader("X-RapidAPI-Host", "chatgpt-api8.p.rapidapi.com");

    QJsonArray messagesArray;
    QJsonObject userMessageObject;
    userMessageObject["content"] = userMessage;
    userMessageObject["role"] = "user";
    messagesArray.append(userMessageObject);
    QJsonDocument doc(messagesArray);
    QByteArray postData = doc.toJson();

    QNetworkReply *reply = manager->post(request, postData);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << responseData;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject responseObject = jsonResponse.object();

            if (responseObject.contains("text")) {
                QString botResponse = responseObject["text"].toString();
                ui->textEdit->append("<b style='color:green'>ChatGPT</b>: " + botResponse);

                int start = botResponse.indexOf("Début:") + QString("Début:").length();
                int end = botResponse.indexOf("Fin:");

                if (start != -1 && end != -1 && end > start) {
                    extractText = botResponse.mid(start, end - start).trimmed();


                    // Ask user where to save the PDF
                    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
                    if (!filePath.isEmpty()) {
                        if (!filePath.endsWith(".pdf"))
                            filePath += ".pdf";

                        QPdfWriter writer(filePath);
                        writer.setPageSize(QPageSize::A4);
                        QPainter painter(&writer);

                        QRect rect = painter.viewport();
                        QFont font("Times", 12);
                        painter.setFont(font);
                        painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, extractText);

                        painter.end();
                        int result = sendEmail("ezzedine.zouiten@gmail.com", "Correction examen", "fichier pdf", filePath);

                        QMessageBox::information(this, "PDF Created", "PDF saved to:\n" + filePath);
                    }
                } else {
                    qDebug() << "Could not extract text between 'debut:' and 'fin:'";
                }
            }
            else {
                ui->textEdit->append("<b style='color:red'>Error</b>: Invalid response format, missing 'text' field");
            }
        } else {
            ui->textEdit->append("<b style='color:red'>Error</b>: " + reply->errorString());
        }
    });



}

#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QTextStream>

int examens::sendEmail(QString recipient, QString subject, QString body, QString pdfPath)
{
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;
    QString username = "rayensassi1235@gmail.com";
    QString password = "onlu picg yuyo vfle";//changer selon le pc !!!  t7el el email fel pc o t3awed ta5o ell mote de pass d'apllication , gerer compte -> securite -> validation 2 facteur -> mote de passe d'aplcation -> create new -> copier le code !!!

    QString from = username;
    QString to = recipient;

    QFile pdfFile(pdfPath);
    if (!pdfFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open PDF file.";
        return -1;
    }

    QByteArray pdfData = pdfFile.readAll();
    pdfFile.close();

    QString pdfFilename = QFileInfo(pdfPath).fileName();
    QString boundary = "----=_Boundary_" + QString::number(rand());

    // Split base64 into 76-char lines
    QByteArray encodedPdf;
    for (int i = 0; i < pdfData.size(); i += 57) { // 57 bytes encode to ~76 chars
        encodedPdf += pdfData.mid(i, 57).toBase64() + "\r\n";
    }

    // Compose MIME message
    QString mime;
    QTextStream stream(&mime);
    stream << "From: " << from << "\r\n";
    stream << "To: " << to << "\r\n";
    stream << "Subject: " << subject << "\r\n";
    stream << "MIME-Version: 1.0\r\n";
    stream << "Content-Type: multipart/mixed; boundary=\"" << boundary << "\"\r\n";
    stream << "\r\n";

    // Plain text part
    stream << "--" << boundary << "\r\n";
    stream << "Content-Type: text/plain; charset=\"UTF-8\"\r\n";
    stream << "Content-Transfer-Encoding: 7bit\r\n\r\n";
    stream << body << "\r\n\r\n";

    // Attachment part
    stream << "--" << boundary << "\r\n";
    stream << "Content-Type: application/pdf; name=\"" << pdfFilename << "\"\r\n";
    stream << "Content-Transfer-Encoding: base64\r\n";
    stream << "Content-Disposition: attachment; filename=\"" << pdfFilename << "\"\r\n\r\n";
    stream << encodedPdf;
    stream << "\r\n--" << boundary << "--\r\n";

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Connection failed:" << socket.errorString();
        return -1;
    }

    auto waitForResponse = [&]() {
        if (!socket.waitForReadyRead()) {
            qDebug() << "Read error:" << socket.errorString();
            return false;
        }
        qDebug() << "Server:" << socket.readAll();
        return true;
    };

    auto sendCmd = [&](const QString &cmd) {
        socket.write(cmd.toUtf8() + "\r\n");
        socket.waitForBytesWritten();
        return waitForResponse();
    };

    if (!waitForResponse()) return -1;
    if (!sendCmd("HELO localhost")) return -1;
    if (!sendCmd("AUTH LOGIN")) return -1;
    if (!sendCmd(username.toUtf8().toBase64())) return -1;
    if (!sendCmd(password.toUtf8().toBase64())) return -1;
    if (!sendCmd("MAIL FROM:<" + from + ">")) return -1;
    if (!sendCmd("RCPT TO:<" + to + ">")) return -1;
    if (!sendCmd("DATA")) return -1;

    socket.write(mime.toUtf8());
    socket.write("\r\n.\r\n");
    socket.waitForBytesWritten();
    if (!waitForResponse()) return -1;

    sendCmd("QUIT");
    socket.disconnectFromHost();

    qDebug() << "Email with PDF sent!";
    return 0;
}






void examens::on_addButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("select * from EXAMENS WHERE IDEXAMEN=:id");
    query.bindValue(":id",ui->lineEdit_9->text());

    query.exec();
    if(query.next()){
        A.write_to_arduino2("1");}
    else{ A.write_to_arduino2("2");
        ui->label_5->setText("id non trouve");}


}





