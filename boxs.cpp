#include "boxs.h"
#include "ui_boxs.h"
#include "connection.h"
#include "box.h"
#include "qrdialog.h"
#include "trackdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QVBoxLayout>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QDialog>
#include "dialog.h"
#include "livreurs.h"
#include "equipments.h"



//     the global namespace


boxs::boxs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::boxs)
{
    ui->setupUi(this);


    // Keep form & table in sync
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged,
            this, &boxs::on_tableWidget_itemSelectionChanged);

    // QR, PDF, sort buttons, stats…
    connect(ui->qrButton, &QPushButton::clicked,
            this, &boxs::on_qrButton_clicked);
    connect(ui->pdfButton, &QPushButton::clicked,
            this, &boxs::on_pdfButton_clicked);

    connect(ui->asc, &QPushButton::clicked,
            this, &boxs::on_asc_clicked);
    connect(ui->desc, &QPushButton::clicked,
            this, &boxs::on_desc_clicked);
    /* one pie-series and one chart that we reuse */
    chartViewBox = ui->chartViewBox;                   // convenience alias
    statSeries   = new QPieSeries();
    statChart    = new QChart;
    statChart->addSeries(statSeries);
    chartViewBox->setChart(statChart);
    chartViewBox->setRenderHint(QPainter::Antialiasing);

    /* let the tab rebuild itself when the user reaches Statistics -------- */
    connect(ui->tabWidget, &QTabWidget::currentChanged,
            this, &boxs::on_tabWidget_currentChanged);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &boxs::on_pushButton_15_clicked);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &boxs::on_pushButton_16_clicked);
    connect(ui->pushButton_21, &QPushButton::clicked, this, &boxs::on_pushButton_21_clicked);

    // Track button: open dialog, refresh table on deliveryDone()
    connect(ui->pushButtonTrack, &QPushButton::clicked, this, [&]() {
        TrackDialog dlg(this);
        connect(&dlg, &TrackDialog::deliveryDone, this, [this]() {
            refreshTable();
        });
        dlg.exec();
    });

    setupComboBoxes();
    refreshTable();
}
boxs::~boxs()
{
    delete ui;
}
void boxs::buildChart(const QString &sql, const QString &title)
{
    statSeries->clear();

    QSqlQuery q(sql);
    while (q.next())
        statSeries->append(q.value(0).toString(), q.value(1).toInt());

    statChart->setTitle(title);

    for (auto slice : statSeries->slices())            // show labels %
        slice->setLabel( QString("%1 (%2%)")
                            .arg(slice->label())
                            .arg(slice->percentage()*100.0, 0, 'f', 1) ),
            slice->setLabelVisible(true);
}

/* slot: fires every time user switches tab ----------------------*/
void boxs::on_tabWidget_currentChanged(int idx)
{
    if (ui->tabWidget->widget(idx) == ui->tab_15)      // <--- stats tab
    {
        // default view : statistics by STATUS
        buildChart("SELECT STATUS , COUNT(*) FROM BOXS GROUP BY STATUS",
                   "Répartition par Status");
    }
}

/* optional buttons INSIDE the tab_15 ----------------------------*/
void boxs::on_statusButton_clicked()
{
    buildChart("SELECT STATUS , COUNT(*) FROM BOXS GROUP BY STATUS",
               "Répartition par Status");
}

void boxs::on_etatButton_clicked()
{
    buildChart("SELECT ETAT , COUNT(*) FROM BOXS GROUP BY ETAT",
               "Répartition par État");
}

void boxs::setupComboBoxes()
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

    // Sort ComboBox
    ui->sortComboBox->clear();
    ui->sortComboBox->addItem("ID_BOX");
    ui->sortComboBox->addItem("STATUS");
    ui->sortComboBox->addItem("ETAT");
}
void boxs::on_qrButton_clicked()
{

    // Create and show the QR dialog
    QRDialog *qrDialog = new QRDialog(this);
    qrDialog->setAttribute(Qt::WA_DeleteOnClose); // Auto-delete when closed
    qrDialog->exec();
}
void boxs::refreshTable(const QString &search, const QString &sortColumn, Qt::SortOrder order)
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

    // Sort the table based on the selected column and order
    if (!sortColumn.isEmpty()) {
        int columnIndex = -1;

        if (sortColumn == "ID_BOX") {
            columnIndex = 0;
        } else if (sortColumn == "STATUS") {
            columnIndex = 6;
        } else if (sortColumn == "ETAT") {
            columnIndex = 7;
        }

        if (columnIndex != -1) {
            ui->tableWidget->sortItems(columnIndex, order);
        } else {
            QMessageBox::warning(this, "Error", "Invalid column name for sorting.");
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    delete model;
}

void boxs::clearForm()
{
    ui->examenComboBox->setCurrentIndex(0);
    ui->livreurComboBox->setCurrentIndex(0);
    ui->destinationComboBox->setCurrentIndex(0);
    ui->etatComboBox->setCurrentIndex(0);
    ui->statusComboBox->setCurrentIndex(0);
    ui->searchLineEdit->clear();
}

void boxs::on_tableWidget_itemSelectionChanged()
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

void boxs::on_valider_clicked()
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

void boxs::on_modifier_clicked()
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

void boxs::on_supprimer_clicked()
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

void boxs::on_annuler_clicked()
{
    clearForm();
}

void boxs::on_searchLineEdit_textChanged(const QString &text)
{
    refreshTable(text);
}

void boxs::on_pdfButton_clicked()
{
    exportToPDF();
}

void boxs::on_asc_clicked()
{
    QString sortColumn = ui->sortComboBox->currentText();
    refreshTable("", sortColumn, Qt::AscendingOrder);
}

void boxs::on_desc_clicked()
{
    QString sortColumn = ui->sortComboBox->currentText();
    refreshTable("", sortColumn, Qt::DescendingOrder);
}

/*void boxs::on_statisticsButton_clicked()
{
    StatisticsDialog dialog(this);
    dialog.exec();
}*/

void boxs::exportToPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export to PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument document;
    QString htmlContent;

    htmlContent += R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Box Information</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                margin: 20px;
                background-color: #f4f4f9;
            }
            h1 {
                color: #333;
                text-align: center;
            }
            table {
                width: 100%;
                border-collapse: collapse;
                margin-top: 20px;
            }
            th, td {
                border: 1px solid #ddd;
                padding: 8px;
                text-align: left;
            }
            th {
                background-color: #4CAF50;
                color: white;
            }
            tr:nth-child(even) {
                background-color: #f2f2f2;
            }
            tr:hover {
                background-color: #ddd;
            }
        </style>
    </head>
    <body>
        <h1>Box Information Report</h1>
        <table>
            <thead>
                <tr>
                    <th>ID_Box</th>
                    <th>Examen</th>
                    <th>Date_Creation</th>
                    <th>Livreur</th>
                    <th>Destination</th>
                    <th>Status</th>
                    <th>Etat</th>
                </tr>
            </thead>
            <tbody>)";

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        htmlContent += "<tr>";
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            htmlContent += "<td>" + ui->tableWidget->item(row, col)->text() + "</td>";
        }
        htmlContent += "</tr>";
    }

    // Close the HTML tags
    htmlContent += R"(
            </tbody>
        </table>
    </body>
    </html>)";

    document.setHtml(htmlContent);
    document.print(&printer);

    QMessageBox::information(this, "Export PDF", "PDF file generated successfully!");
}



void boxs::on_pushButton_16_clicked()
{
    Equipments *eqWindow = new Equipments(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}
void boxs::on_pushButton_21_clicked()
{
    livreurs *eqWindow = new livreurs(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}
void boxs::on_pushButton_15_clicked()
{
    Dialog *eqWindow = new Dialog(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}




void boxs::on_pushButton_24_clicked()
{
     this->close();
}

