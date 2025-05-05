#ifndef QRDIALOG_H
#define QRDIALOG_H

#include <QDialog>
#include <QSqlQuery>

// Forward declaration
namespace Ui {
class QRDialog;
}

class QRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRDialog(QWidget *parent = nullptr);
    ~QRDialog();

private slots:
    void on_boxComboBox_currentIndexChanged(int index);
    void on_downloadButton_clicked();

private:
    Ui::QRDialog *ui;
    void loadBoxes();
    void generateQRCode(const QString &data);
    QString getBoxInfo(int boxId);
};

#endif // QRDIALOG_H
