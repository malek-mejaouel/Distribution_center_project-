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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadTableData();  // Charger les données dans QTableWidget
    void updateTableData();  // Mise à jour automatique avec QTimer
    void onTableRowClicked(int row, int column);  // Sélectionner une ligne
    void on_b1_clicked();    // Ajouter un institut
    void on_b2_clicked();
    void on_b3_clicked();  // Modifier un institut
    void on_b4_clicked();  // Supprimer un institut
    void on_b5_clicked();  // Recherche par ID
    void sortTableData(int column);  // Trier les données du tableau

private:
    Ui::MainWindow *ui;
    QString selectedInstitutId;
    QTimer *timer;  // Timer pour actualisation automatique
};

#endif // MAINWINDOW_H
