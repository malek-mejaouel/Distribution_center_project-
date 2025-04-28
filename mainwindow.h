// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QPrinter>

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
    void on_valider_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_annuler_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void on_tableWidget_itemSelectionChanged();
    void on_pdfButton_clicked();
    void on_asc_clicked();
    void on_desc_clicked();
    void on_statisticsButton_clicked();
    void on_qrButton_clicked();

private:
    Ui::MainWindow *ui;
    void setupComboBoxes();
    void clearForm();
    void exportToPDF();

    // Refresh with optional filters/sorting. Defaults: no search, no sort, ascending.
    void refreshTable(const QString &search = QString(),
                      const QString &sortColumn = QString(),
                      Qt::SortOrder order = Qt::AscendingOrder);

    int lastSortedColumn = -1;
    Qt::SortOrder currentSortOrder = Qt::AscendingOrder;
};

#endif // MAINWINDOW_H
