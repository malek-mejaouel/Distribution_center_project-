#ifndef TRACKDIALOG_H
#define TRACKDIALOG_H

#include <QDialog>
#include "arduino.h"

namespace Ui { class TrackDialog; }

class TrackDialog : public QDialog {
    Q_OBJECT

public:
    explicit TrackDialog(QWidget *parent = nullptr);
    ~TrackDialog();

private slots:
    void on_comboBoxBoxes_currentIndexChanged(int idx);
    void updateDistance(float cm);

private:
    Ui::TrackDialog *ui;
    Arduino         *arduino;
    int              currentBoxId;      // the selected box ID
    float            targetDistance;    // DISTANCE_INST from DB

    bool             matchedAlerted;    // true once we've fired the “matched” alert
    bool             surpassedAlerted;  // true once we've fired the “surpassed” alert
signals:
    /// Emitted once when the box is marked delivered
    void deliveryDone();
};

#endif // TRACKDIALOG_H
