#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel> // Include QSqlQueryModel for database handling

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
    QString getSelectedRole();

private slots:
    void on_pushButton_11_clicked(); // Slot for the button click
    void onRoleSelected();
       // Slot for radio button selection

    void on_searchbutt_clicked();

    void on_deletebutt_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;

    void loadDatabase();
};

#endif // MAINWINDOW_H
