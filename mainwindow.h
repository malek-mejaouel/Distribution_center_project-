#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

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
    void on_addButton_clicked();    // Slot pour le bouton "Valider"
    void on_updateButton_clicked(); // Slot pour le bouton "Modifier"*
    void on_pushButton_18_clicked(); // Slot pour le bouton "supprimer"



private:
    Ui::MainWindow *ui;
    QSqlTableModel *model; // Modèle pour interagir avec la base de données
};

#endif // MAINWINDOW_H
