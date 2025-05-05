#include "Arduino2.h"

Arduino2::Arduino2()
{
    data="";
    Arduino2_port_name="";
    Arduino2_is_available=false;
    serial=new QSerialPort;
}

QString Arduino2::getArduino2_port_name()
{
    return Arduino2_port_name;
}

QSerialPort *Arduino2::getserial()
{
    return serial;
}
int Arduino2::connect_Arduino2()
{   // recherche du port sur lequel la carte Arduino2 identifée par  Arduino2_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == Arduino2_uno_vendor_id && serial_port_info.productIdentifier()
                                                                                    == Arduino2_uno_producy_id) {
                Arduino2_is_available = true;
                Arduino2_port_name=serial_port_info.portName();
            } } }
    qDebug() << "Arduino2_port_name is :" << Arduino2_port_name;
    if(Arduino2_is_available){ // configuration de la communication ( débit...)
        serial->setPortName(Arduino2_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
            serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
            serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino2::close_Arduino2()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray Arduino2::read_from_Arduino2()
{
    if(serial->isReadable()){
        data=serial->readAll(); //récupérer les données reçues

        return data;
    }
}


void Arduino2::write_to_Arduino2( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino2
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
