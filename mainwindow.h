#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_b1_clicked(); // Ajouter
    void on_b2_clicked(); // Annuler
    void on_b3_clicked(); // Modifier
    void on_b4_clicked(); // Supprimer
    void on_b5_clicked(); // Afficher les instituts
    void on_tab1_itemSelectionChanged(); // Sélection d'une ligne
    void loadInstituts(); // Charger les instituts

private:
    Ui::MainWindow *ui;
    int currentId; // Pour stocker l'ID de l'institut actuellement sélectionné
};

#endif // MAINWINDOW_H
