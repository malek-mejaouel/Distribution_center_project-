#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino
{
public:
    Arduino();
    int connect_arduino();      // Retourne 0 si success, -1 si échec
    void close_arduino();       // Fermer la connexion
    QSerialPort* getserial();   // Accès au port série

private:
    QSerialPort *serial;
    QString portname;
    bool arduino_is_available;
};

#endif // ARDUINO_H
