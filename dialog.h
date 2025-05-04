#ifndef DIALOG_H
#define DIALOG_H
#include <QtCharts/QChartView>
#include <QSqlQueryModel>
#include <QDialog>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString getSelectedRole();

signals:
    void signOutRequested();  // Add this signal definition

private slots:
    void onTableRowClicked(int row, int column);
    void on_pushButton_17_clicked();
    void loadTableData();
    void onRechercheTextChanged(const QString &text);
    void onRoleSelected();
    void on_pushButton_6_clicked();
    void on_r1_clicked();               // Role 1 selection handler
    void on_r2_clicked();               // Role 2 selection handler
    void on_r3_clicked();               // Role 3 selection handler
    void on_r4_clicked();               // Role 4 selection handler
    void on_r5_clicked();               // Role 5 selection handler
    void on_r6_clicked();
    void on_pushButton_12_clicked();
    void populateTab3WithRoleTables();
    QChartView* createStationConsumptionChart();
    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();
    void on_pushButton_10_clicked();


    void on_pushButton_8_clicked();
    void onFilterRoleChanged(const QString &role);


    void on_b13_clicked();
    void loadSortedData(const QString &orderBy, bool ascending);
    void on_b12_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Dialog *ui;
    QString selectedUserId;
     QChartView *chartView = nullptr;
     void updateChart();
};

#endif // DIALOG_H
