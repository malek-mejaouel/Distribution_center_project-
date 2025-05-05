#include "Arduino1.h"
#include <QSerialPortInfo>
#include <QDebug>

Arduino1::Arduino1(QObject *parent)
    : QObject(parent),
    serial(new QSerialPort(this))
{
    connect(serial, &QSerialPort::readyRead,
            this,   &Arduino1::onReadyRead);
}

Arduino1::~Arduino1() {
    if (serial->isOpen()) serial->close();
}

bool Arduino1::connectArduino1(const QString &portName) {
    if (serial->isOpen()) serial->close();

    if (!portName.isEmpty()) {
        serial->setPortName(portName);
    } else {
        for (auto info : QSerialPortInfo::availablePorts()) {
            if (info.vendorIdentifier()) {
                serial->setPort(info);
                break;
            }
        }
    }

    if (!serial->open(QIODevice::ReadWrite)) {
        qWarning() << "Serial open failed:" << serial->errorString();
        return false;
    }

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    return true;
}

void Arduino1::writeData(const QByteArray &data) {
    if (serial->isOpen()) serial->write(data);
}

void Arduino1::onReadyRead() {
    buffer.append(serial->readAll());
    while (true) {
        int idx = buffer.indexOf('\n');
        if (idx < 0) break;
        QByteArray line = buffer.left(idx).trimmed();
        buffer.remove(0, idx+1);

        bool ok = false;
        float cm = line.toFloat(&ok);
        if (ok) {
            emit distanceUpdated(cm);
        } else {
            emit messageReceived(QString::fromUtf8(line));
        }
    }
}
