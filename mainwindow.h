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

private:
    Ui::MainWindow *ui;
    QString selectedLivreurId;
private slots:
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();  // Modifier un livreur
    void on_b4_clicked();  // Supprimer un livreur
    void onTableRowClicked(int row, int column);

private:
    void loadTableData();
    void setupTable();


};

#endif // MAINWINDOW_H
