#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QNetworkReply> // Pour QNetworkReply
#include <QtCharts> // Pour les graphiques
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QSystemTrayIcon>
#include <QtQuickWidgets/QQuickWidget>
#include "institut.h"
#include "arduino.h"
#include "markermodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEmployeeTextChanged(const QString &text);
    bool employeeExists(const QString &employeeId); // Déclaration unique
    void loadTableData();
    void updateTableData();
    void onTableRowClicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void onTriComboBoxChanged(int index);
    void onCroissantButtonClicked();
    void onDecroissantButtonClicked();
    void onRechercheIdTextChanged(const QString &text);
    void afficherStatistiquesCapacite();
    void on_pdf_clicked();
    void on_noti_clicked();
    void notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information);
    void on_map_clicked();
    void afficherIdsEmployes();
    void onGeoCodeReply(QNetworkReply* reply);
    void searchLocation(const QString &address);
    void update_label();
    void on_addButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedInstitutId;
    QString currentOrder;
    QTimer *timer;
    QTimer *searchTimer;
    QDialog *notificationDialog;
    QDialog *mapDialog;
    QSystemTrayIcon *trayIcon;
    QNetworkAccessManager *networkManager; // Déclaration de networkManager
    QSystemTrayIcon*trayicon;
    MarkerModel m_markerModel;
    void updateTableWithModel(QSqlQueryModel *model);
    void performSearch(const QString &text);
    void performSorting(const QString &order);
    bool isInstitutSelected();
    void searchInstitut(const QString &name);

    double latitude;
    double longitude;
    QByteArray data; // variable contenant les données reçues
    Arduino A;
    bool test;

signals:
    void marqueurAjoute(double lat, double lon);
    void centerMap(double lat, double lon);
};

#endif // MAINWINDOW_H
