#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class StatisticsDialog; }
QT_END_NAMESPACE

class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsDialog(QWidget *parent = nullptr);
    ~StatisticsDialog();

private slots:
    void showStatusChart();
    void showEtatChart();

private:
    void updateChart();

    Ui::StatisticsDialog *ui;
    QChart *chart;
    QPieSeries *pieSeries;
    QChartView *chartView;
};

#endif // STATISTICSDIALOG_H
