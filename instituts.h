/* -------------------------------------------------- */
/*  instituts.h  –  final, Qt-6 compatible            */
/* -------------------------------------------------- */
#ifndef INSTITUTS_H
#define INSTITUTS_H

/*  Qt Widgets / Charts / Quick  */
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtQuickWidgets/QQuickWidget>

/*  Qt SQL / Network / Misc. */
#include <QtSql>                   // <-- single include for QSql*
#include <QNetworkReply>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QQmlContext>             // rootContext()

/*  Application headers  */
#include "arduino2.h"
#include "markermodel.h"
#include "institut.h"

/*  You keep   using namespace QtCharts;   in the .cpp – that is valid in Qt 6   */

QT_BEGIN_NAMESPACE
namespace Ui { class instituts; }
QT_END_NAMESPACE

class instituts : public QDialog
{
    Q_OBJECT
    constexpr static int SEUIL = 65;          // threshold you use in update_label()

public:
    explicit instituts(QWidget *parent = nullptr);
    ~instituts() override;

private slots:
    /* helpers / validation */
    void onemployee_in_TextChanged(const QString &text);
    bool employee_inExists(const QString &id);

    /* CRUD / table maintenance */
    void loadTableData();
    void updateTableData();
    void updateTableWithModel(QSqlQueryModel *model);
    void performSearch (const QString &text);
    void performSorting(const QString &order);
    void onTableRowClicked();

    /* UI callbacks */
    void on_b1_in_clicked();
    void on_b2_in_clicked();
    void on_b3_in_clicked();
    void on_b4_in_clicked();
    void on_addButton_in_clicked();
    void onTri_inComboBoxChanged(int idx);
    void onCroissantButtonClicked();
    void onDecroissantButtonClicked();
    void onrecherche_inIdTextChanged(const QString &text);
    void on_pdf_in_clicked();
    void on_noti_in_clicked();
    void on_map_in_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();

    /* Arduino */
    void update_label_in();

    /* Stats / Charts */
    void afficherStatistiquesCapacite();

    /* Map / Geocoding */
    void onGeoCodeReply(QNetworkReply *reply);
    void searchLocation(const QString &address);
    void searchInstitut (const QString &name);

    /* Misc */

    void notifyUser(const QString &title,
                    const QString &message,
                    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information);

    void on_pushButton_18_clicked();

signals:
    void marqueurAjoute(double lat, double lon);
    void centerMap     (double lat, double lon);

private:
    /* data --------------------------------------------------------------- */
    Ui::instituts        *ui               {nullptr};
    QString               selectedInstitutId;
    QByteArray            data;                  // serial-buffer
    QTimer               *timer            {nullptr};
    QNetworkAccessManager*networkManager   {nullptr};
    QSystemTrayIcon      *trayIcon         {nullptr};
    MarkerModel          *m_markerModel    {nullptr};   // **pointer** – see .cpp
    Arduino2              A;

    /* helpers ------------------------------------------------------------ */
    bool isInstitutSelected() const;
};

#endif  // INSTITUTS_H
