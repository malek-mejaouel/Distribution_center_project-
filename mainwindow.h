#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadTableData();
    void updateTableData();
    void onTableRowClicked(int row, int column);
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void sortTableData(int column);

private:
    Ui::MainWindow *ui;
    QString selectedInstitutId;
    QTimer *timer;
};

#endif // MAINWINDOW_H
