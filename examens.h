#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "arduino2.h"
#include <QMainWindow>
#include <QSqlTableModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QStandardPaths>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPageSize>       // Nouveau pour Qt 6
#include <QPageLayout>     // Nouveau pour Qt 6
#include "examenclass.h"
namespace Ui {
class examens;
}

class examens : public QDialog
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();

private slots:
    void on_addButton_clicked();    // Slot pour le bouton "Valider"
    void on_updateButton_clicked(); // Slot pour le bouton "Modifier"*
    void on_pushButton_18_clicked(); // Slot pour le bouton "supprimer"
    void on_pushButton_12_clicked();  // annulation
    void on_telechargerButton_clicked();
    void on_statsButton_clicked();



    void on_tableView_clicked(const QModelIndex &index);

    // void on_refresh_clicked();


    void stat_niveau();

    void on_updateButton_3_clicked();
    void update_label();


    void on_lineEdit_8_textChanged(const QString &text);


    void on_bt_pdf_clicked();

    void on_comboBoxTri_2_currentTextChanged(const QString &choix);

    void on_bt_envoyer_clicked();

    void on_bt_clear_clicked();



    void on_addButton_2_clicked();    // button arduino







    int sendEmail(QString recipient, QString subject, QString body, QString pdfPath);
    void on_generer_correction_clicked();


private:
    Ui::examens *ui;

    examenclass ex;
    int ID_EXAMEN;
    QString destinataire;
    QString object,body;
    QString extractText;

    QByteArray data3; // variable contenant les données reçues

    Arduino2 A;
    bool test;

};

#endif // MAINWINDOW_H
