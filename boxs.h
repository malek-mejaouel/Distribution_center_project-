#ifndef boxs_H
#define boxs_H
#include <QDialog>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
QT_USE_NAMESPACE          // <-- lifts QChart / QPieSeries into
//     the global namespace
//  ⟵ NEW
#include <QPrinter>

namespace Ui {
class boxs;
}

class boxs : public QDialog
{
    Q_OBJECT

public:
    explicit boxs(QWidget *parent = nullptr);
    ~boxs();

private slots:
    /* CRUD & utility buttons that already existed */
    void on_valider_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_annuler_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_tableWidget_itemSelectionChanged();
    void on_pdfButton_clicked();
    void on_asc_clicked();
    void on_desc_clicked();
    void on_qrButton_clicked();

    /* ---------- NEW:  triggered whenever the user switches tab ---------- */
    void on_tabWidget_currentChanged(int index);

    /* ---------- OPTIONAL: two little buttons inside Statistics tab to   *
     *             toggle chart type (call them only if you add the
     *             buttons in Designer; otherwise you may omit)            */
    void on_statusButton_clicked();   // counts by STATUS
    void on_etatButton_clicked();     // counts by ETAT

    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

private:
    /* helper that executes the query and (re)builds the pie‐chart */
    void buildChart(const QString &sql, const QString &chartTitle);

    /* your existing helpers */
    void setupComboBoxes();
    void clearForm();
    void exportToPDF();
    void refreshTable(const QString &search = QString(),
                      const QString &sortColumn = QString(),
                      Qt::SortOrder order = Qt::AscendingOrder);

    /* data */
    Ui::boxs *ui;
    int           lastSortedColumn   = -1;
    Qt::SortOrder currentSortOrder   = Qt::AscendingOrder;


    /* … */
    QChartView          *chartViewBox;   // already on the ui file
    QChart              *statChart  = nullptr;
    QPieSeries          *statSeries = nullptr;
};

#endif // boxs_H
