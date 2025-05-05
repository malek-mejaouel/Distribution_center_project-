#include "dialog.h"
#include "ui_dialog.h"
#include "connection.h"
#include "User.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "equipments.h"
#include "livreurs.h"
#include "boxs.h"
#include "instituts.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    if (!ui->tab_3->layout()) {
        ui->tab_3->setLayout(new QVBoxLayout());
    }
    // Setup chart in tab 4
    chartView = createStationConsumptionChart();
    QVBoxLayout *layoutTab4 = new QVBoxLayout(ui->tab_4);
    layoutTab4->addWidget(chartView);


    loadTableData();
    ui->comboFilterRole->addItems({"Tous", "Livreur", "Institut", "Employe", "R.equip", "R.exame", "R.Box"});

    connect(ui->recherche, &QLineEdit::textChanged, this, &Dialog::onRechercheTextChanged);
    connect(ui->pushButton_17, &QPushButton::clicked, this, &Dialog::on_pushButton_17_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &Dialog::on_pushButton_10_clicked);
    connect(ui->comboFilterRole, &QComboBox::currentTextChanged,
            this, &Dialog::onFilterRoleChanged);

    connect(ui->r1, &QRadioButton::clicked, this, &Dialog::onRoleSelected);
    connect(ui->r2, &QRadioButton::clicked, this, &Dialog::onRoleSelected);
    connect(ui->r3, &QRadioButton::clicked, this, &Dialog::onRoleSelected);
    connect(ui->r4, &QRadioButton::clicked, this, &Dialog::onRoleSelected);
    connect(ui->r5, &QRadioButton::clicked, this, &Dialog::onRoleSelected);
    connect(ui->r6, &QRadioButton::clicked, this, &Dialog::onRoleSelected);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index){
        if (index == 2) {
            populateTab3WithRoleTables();
        }
    });
}

Dialog::~Dialog()
{
    delete ui;
}
QChartView* Dialog::createStationConsumptionChart()
{
    // Query to get role counts
    QSqlQuery query;
    if (!query.exec("SELECT role, COUNT(*) FROM EMPLOYEES GROUP BY role")) {
        qDebug() << "Query Error:" << query.lastError().text();
        return nullptr;
    }

    QStringList categories;
    QBarSet *set = new QBarSet("Employees");
    int maxY = 0;

    // Loop through the query results
    while (query.next()) {
        QString role = query.value(0).toString();
        int count = query.value(1).toInt();

        categories << role;
        *set << count;

        if (count > maxY)
            maxY = count;
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Chart setup
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Number of Employees per Role");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false); // optional

    // X-Axis (roles)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Y-Axis (number of employees)
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Number of Employees");
    axisY->setRange(0, maxY + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}


void Dialog::populateTab3WithRoleTables()
{
    QLayout *oldLayout = ui->tab_3->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) delete item->widget();
            delete item;
        }
    }

    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->tab_3->layout());
    if (!layout) return;

    QStringList roles = {"Livreur", "Institut", "Employe", "R.equip", "R.exame", "R.Box"};

    for (const QString &role : roles) {
        QGroupBox *groupBox = new QGroupBox("🎯 Rôle : " + role);

        QVBoxLayout *vbox = new QVBoxLayout(groupBox);

        QTableWidget *table = new QTableWidget();
        table->setColumnCount(4);
        table->setHorizontalHeaderLabels({"ID", "Nom", "T\u00E9l\u00E9phone", "Mot de passe"});
        table->horizontalHeader()->setStretchLastSection(true);

        QSqlQuery query;
        query.prepare("SELECT ID_EMPLOYE, USERNAME, NUMBERP, PASSWORD FROM EMPLOYEES WHERE role = :role");
        query.bindValue(":role", role);
        if (query.exec()) {
            int row = 0;
            while (query.next()) {
                table->insertRow(row);
                for (int col = 0; col < 4; ++col) {
                    table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
                }
                row++;
            }
        }

        vbox->addWidget(table);
        layout->addWidget(groupBox);
    }

    layout->addStretch();
}

QString Dialog::getSelectedRole()
{
    if (ui->r1->isChecked()) return "Livreur";
    if (ui->r2->isChecked()) return "Institut";
    if (ui->r3->isChecked()) return "Employe";
    if (ui->r4->isChecked()) return "R.equip";
    if (ui->r5->isChecked()) return "R.exame";
    if (ui->r6->isChecked()) return "R.Box";
    return "";
}

void Dialog::onRoleSelected()
{
    QString selectedRole = getSelectedRole();
    qDebug() << "Selected Role: " << selectedRole;
}

void Dialog::on_pushButton_17_clicked()
{
    emit signOutRequested();
    this->close();
}

void Dialog::loadTableData()
{
    QSqlQuery query("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES");

    ui->tab1->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < 5; ++col) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
    connect(ui->tab1, &QTableWidget::cellClicked, this, &Dialog::onTableRowClicked);

}


void Dialog::onRechercheTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        loadTableData();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", text);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche : " + query.lastError().text());
        return;
    }

    ui->tab1->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < 5; ++col) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

void Dialog::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QMarginsF margins(20, 20, 20, 20);
    QPageLayout layout = printer.pageLayout();
    layout.setUnits(QPageLayout::Millimeter);
    layout.setMargins(margins);
    printer.setPageLayout(layout);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exportation en PDF !");
        return;
    }

    int rowCount = ui->tab1->rowCount();
    int columnCount = ui->tab1->columnCount();

    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);

    QStringList headers;
    for (int col = 0; col < columnCount; ++col) {
        headers << ui->tab1->horizontalHeaderItem(col)->text();
    }
    painter.drawText(20, 20, headers.join("\t"));

    int yOffset = 40;
    for (int row = 0; row < rowCount; ++row) {
        QStringList rowData;
        for (int col = 0; col < columnCount; ++col) {
            rowData << ui->tab1->item(row, col)->text();
        }
        yOffset += 800;
        painter.drawText(20, yOffset, rowData.join("\t"));
    }

    painter.end();
    QMessageBox::information(this, "Succ\u00E8s", "Tableau export\u00E9 en PDF avec succ\u00E8s !");
}

void Dialog::on_pushButton_12_clicked()
{
    QString username = ui->Userset->text();
    QString password = ui->Passset->text();
    int phoneNumber = ui->Number->text().toInt();
    QString role = getSelectedRole();

    if (username.isEmpty() || password.isEmpty() || phoneNumber == 0 || role.isEmpty()) {
        QMessageBox::warning(this, "Adding Failed", "All fields must be filled.");
        return;
    }

    User e(username, password, phoneNumber, role);
    if (e.ajouterP()) {
        QMessageBox::information(this, "Info", "User Add Successful");
        loadTableData();
        ui->Userset->clear();
        ui->Passset->clear();
        ui->Number->clear();
        ui->comboFilterRole->setCurrentIndex(0);

        // Refresh the chart
        QLayout *layout = ui->tab_4->layout();
        if (layout && chartView) {
            layout->removeWidget(chartView);
            chartView->deleteLater();
        }

        chartView = createStationConsumptionChart();
        if (layout) {
            layout->addWidget(chartView);
        }

    }
    updateChart();

}

void Dialog::onTableRowClicked(int row, int column)
{
    ui->tabWidget->setCurrentIndex(1);
    Q_UNUSED(column);
    selectedUserId = ui->tab1->item(row, 0)->text();
    ui->Userset->setText(ui->tab1->item(row, 1)->text());
    ui->Passset->setText(ui->tab1->item(row, 2)->text());
    ui->Number->setText(ui->tab1->item(row, 3)->text());

    QString role = ui->tab1->item(row, 4)->text();
    if (role == "Livreur") ui->r1->setChecked(true);
    else if (role == "Institut") ui->r2->setChecked(true);
    else if (role == "Employe") ui->r3->setChecked(true);
    else if (role == "R.equip") ui->r4->setChecked(true);
    else if (role == "R.exame") ui->r5->setChecked(true);
    else if (role == "R.Box") ui->r6->setChecked(true);
}



void Dialog::on_pushButton_11_clicked()
{
    if (selectedUserId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un équipement à modifier !");
        return;
    }

    QString username = ui->Userset->text();
    QString password = ui->Passset->text();
    int phoneNumber = ui->Number->text().toInt();
    QString role = getSelectedRole();

    if (username.isEmpty() || password.isEmpty() || phoneNumber == 0 || role.isEmpty()) {
        QMessageBox::warning(this, "Échec", "Tous les champs doivent être remplis.");
        return;
    }

    // Create the user without id
    User e(username, password, phoneNumber, role);

    // Pass the id directly
    if (e.modifierP(selectedUserId.toInt())) {
        QMessageBox::information(this, "Succès", "Équipement modifié avec succès !");
        ui->Userset->clear();
        ui->Passset->clear();
        ui->Number->clear();
        ui->comboFilterRole->setCurrentIndex(0); // or reset radio buttons

        loadTableData();
        updateChart();

        QLayout *layout = ui->tab_4->layout();
        if (layout && chartView) {
            layout->removeWidget(chartView);
            chartView->deleteLater();
        }

        chartView = createStationConsumptionChart();
        if (layout) {
            layout->addWidget(chartView);
        }
                       // Reload table
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}



void Dialog::on_pushButton_7_clicked()
{
    loadTableData();
}


void Dialog::on_pushButton_8_clicked()
{
    if (selectedUserId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "U need to select an user to delete it!");
        return;
    }

    // Demander confirmation avant de supprimer
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Do u wanna delete this user?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        User e( "", "", 0,"");
        if (e.supprimerP(selectedUserId.toInt())) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès !");
            loadTableData();
            updateChart();
            // Mettre à jour la table après suppression
        }
    }
}
void Dialog::onFilterRoleChanged(const QString &role)
{
    QString selectedRole = ui->comboFilterRole->currentText();

    QSqlQuery query;
    if (selectedRole == "Tous") {
        query.prepare("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES");
    } else {
        query.prepare("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES WHERE role = :role");
        query.bindValue(":role", selectedRole);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du filtrage : " + query.lastError().text());
        return;
    }

    ui->tab1->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tab1->insertRow(row);
        for (int col = 0; col < 5; ++col) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}
void Dialog::on_b12_clicked()
{
    qDebug() << "Tri croissant cliqué !";
    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES ORDER BY TO_NUMBER(ID_EMPLOYE) ASC");


    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri croissant : " + query.lastError().text());
        return;
    }

    ui->tab1->setRowCount(0);
    ui->tab1->clearContents();
    int row = 0;
    while (query.next()) {
        qDebug() << "ID:" << query.value(0).toInt();
        ui->tab1->insertRow(row);
        for (int col = 0; col < 5; ++col) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}


void Dialog::on_b13_clicked()
{
    qDebug() << "Tri croissant cliqué !";
    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, USERNAME, PASSWORD, NUMBERP, role FROM EMPLOYEES ORDER BY TO_NUMBER(ID_EMPLOYE) DESC");


    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri croissant : " + query.lastError().text());
        return;
    }

    ui->tab1->setRowCount(0);
    ui->tab1->clearContents();
    int row = 0;
    while (query.next()) {
        qDebug() << "ID:" << query.value(0).toInt();
        ui->tab1->insertRow(row);
        for (int col = 0; col < 5; ++col) {
            ui->tab1->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}
void Dialog::updateChart() {
    if (chartView) {
        ui->tab_4->layout()->removeWidget(chartView);
        chartView->deleteLater();
        chartView = nullptr;
    }

    chartView = createStationConsumptionChart();
    if (chartView && ui->tab_4->layout()) {
        ui->tab_4->layout()->addWidget(chartView);
    }
}




void Dialog::on_pushButton_2_clicked()
{
    Equipments *eqWindow = new Equipments(this); // 'this' as parent to handle memory
    eqWindow->show();
     this->close();    // Show non-modally
}


void Dialog::on_pushButton_9_clicked()
{
    livreurs *eqWindow = new livreurs(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally

}


void Dialog::on_pushButton_10_clicked()
{
    boxs *eqWindow = new boxs(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}


void Dialog::on_pushButton_4_clicked()
{
    instituts *eqWindow = new instituts(this); // 'this' as parent to handle memory
    eqWindow->show();
    this->close();    // Show non-modally
}

