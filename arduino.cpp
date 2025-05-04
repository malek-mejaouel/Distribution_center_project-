#include "arduino.h"

Arduino::Arduino()
{
    serial = new QSerialPort;
    arduino_is_available = false;
    portname = "COM5";  // Port Arduino (à adapter si nécessaire)
}

int Arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == portname) {
            arduino_is_available = true;
            serial->setPort(info);
            break;
        }
    }

    if (arduino_is_available) {
        if (serial->open(QIODevice::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0; // succès
        } else {
            return -1; // port trouvé mais pas ouvert
        }
    } else {
        return -1; // port non trouvé
    }
}

void Arduino::close_arduino()
{
    if (serial->isOpen()) serial->close();
}

QSerialPort* Arduino::getserial()
{
    return serial;
}
