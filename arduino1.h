#ifndef Arduino1_H
#define Arduino1_H

#include <QObject>
#include <QSerialPort>

class Arduino1 : public QObject {
    Q_OBJECT
public:
    explicit Arduino1(QObject *parent = nullptr);
    ~Arduino1();

    bool connectArduino1(const QString &portName = QString());
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

#endif // Arduino1_H
