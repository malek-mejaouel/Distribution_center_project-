#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"
#include <QSqlQuery>

StatisticsDialog::StatisticsDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);

    // Initialize chart and series
    chart = new QChart();
    pieSeries = new QPieSeries();
    chart->addSeries(pieSeries); // Chart> series

    ui->chartView->setChart(chart); // ChartView > chart
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    connect(ui->statusButton, &QPushButton::clicked, this, &StatisticsDialog::showStatusChart);
    connect(ui->etatButton, &QPushButton::clicked, this, &StatisticsDialog::showEtatChart);
    this->setStyleSheet(R"(
        QDialog {
            background-color: #ffffff;
        }
        QPushButton {
            background-color: #4CAF50;
            color: white;
            border: none;
            padding: 10px 20px;
            font: bold 12px 'Arial';
            border-radius: 5px;
            min-width: 150px;
            margin: 5px;
        }
        QPushButton:hover {
            background-color: #45a049;
        }
        QPushButton:pressed {
            background-color: #3d8b40;
        }
    )");

    showStatusChart(); // Initial chart
}

StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

void StatisticsDialog::showStatusChart()
{
    pieSeries->clear();
    QSqlQuery query("SELECT STATUS, COUNT(*) FROM BOXS GROUP BY STATUS");
    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();
        pieSeries->append(status, count);
    }
    updateChart();
}

void StatisticsDialog::showEtatChart()
{
    pieSeries->clear();
    QSqlQuery query("SELECT ETAT, COUNT(*) FROM BOXS GROUP BY ETAT");
    while (query.next()) {
        QString etat = query.value(0).toString();
        int count = query.value(1).toInt();
        pieSeries->append(etat, count);
    }
    updateChart();
}

void StatisticsDialog::updateChart()
{
    chart->setTitle("Statistics");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    for (QPieSlice *slice : pieSeries->slices()) {
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1 (%2%)")
                            .arg(slice->label())
                            .arg(100 * slice->percentage(), 0, 'f', 1));
    }
}
