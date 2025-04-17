// dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(const QString &employeeId, const QString &message, QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QTimer *timer;

private slots:
    void hideDialog();
};

#endif // DIALOG_H
