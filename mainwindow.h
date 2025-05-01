#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QFileDialog>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "livreur.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Livreur currentLivreur;
    int selectedLivreurId;
    QString currentOrder;
    QSerialPort *serial;

    void updateTableWithModel(QSqlQueryModel *model);
    void setupTable();
    void loadTableData();
    void updateTableData();
    void clearInputFields();
    void showStatistics();
    Arduino A;  // Assurez-vous que cette ligne est présente
    void verifierEtatLivreur(QString id);  // Fonction pour vérifier l'état du livreur


private slots:
    void on_valider_clicked();
    void on_annuler_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void onTableRowClicked(int row, int column);
    void on_recherche_clicked();
    void onRechTextChanged(const QString &text);
    void onAscButtonClicked();
    void onDescButtonClicked();
    void onTriComboBoxChanged(int index);
    void on_statsButton_clicked();
    void on_pdfButton_clicked();
    void exportToPDF(QSqlQueryModel *model);
    void on_historiqueButton_clicked();
    void on_imageButton_clicked();
    void on_serialDataReceived();

};

#endif // MAINWINDOW_H
