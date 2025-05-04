#ifndef EQUIPMENTS_H
#define EQUIPMENTS_H

#include <QDialog>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QComboBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "Equipement.h"

namespace Ui {
class Equipments;
}

class Equipments : public QDialog
{
    Q_OBJECT

public:
    explicit Equipments(QWidget *parent = nullptr);
    ~Equipments();

private slots:
    void loadTableData(); // Charger les données dans le tableau
    void on_b1_clicked(); // Ajouter un équipement
    void on_b2_clicked(); // Réinitialiser les champs
    void on_b3_clicked(); // Modifier un équipement
    void on_b4_clicked(); // Supprimer un équipement
    void onTableRowClicked(int row, int column); // Sélectionner une ligne du tableau
    void onRechercheTextChanged(const QString &text); // Recherche dynamique par ID
    void onTriComboBoxChanged(int index); // Tri dynamique
    void on_b7_clicked();
    void on_b10_clicked();
    void on_b12_clicked(); // Nouvelle méthode pour changer l'ordre de tri
    void setupChart();
    void on_b13_clicked();
    void onCalendarDateClicked(const QDate &date);

    void on_pushButton_17_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::Equipments *ui;
    QString selectedEquipementId; // ID de l'équipement sélectionné pour modification/suppression
    bool isAscendingOrder; // Indicateur pour l'ordre de tri (true pour ascendant, false pour descendant)
    void setupTable(); // Configurer le tableau
    void setupTriComboBox(); // Remplir la QComboBox "tri" avec les attributs
    void updateCalendarWithMaintenanceDates(); // Mettre à jour le calendrier avec les dates de maintenance
};

#endif // EQUIPMENTS_H
