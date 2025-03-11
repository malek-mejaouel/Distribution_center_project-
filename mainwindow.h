#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    void setupComboBoxes();
    void refreshTable(const QString &search = QString());
    void clearForm();
};

#endif // MAINWINDOW_H
