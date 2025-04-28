#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>

class Arduino : public QObject {
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connectArduino(const QString &portName = QString());
    void writeData(const QByteArray &data);

signals:
    void distanceUpdated(float cm);
    void messageReceived(const QString &msg);

private slots:
    void onReadyRead();

private:
    QSerialPort *serial;
    QByteArray   buffer;
};

#endif // ARDUINO_H
