#ifndef Arduino22_H
#define Arduino22_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class Arduino2
{
public:     //méthodes de la classe Arduino2
    Arduino2();
    int connect_Arduino2(); // permet de connecter le PC à Arduino2
    int close_Arduino2(); // permet de femer la connexion
    void write_to_Arduino2( QByteArray ); // envoyer des données vers Arduino2
    QByteArray read_from_Arduino2();  //recevoir des données de la carte Arduino2
    QSerialPort* getserial();   // accesseur
    QString getArduino2_port_name();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino2.
    static const quint16 Arduino2_uno_vendor_id=9025;
    static const quint16 Arduino2_uno_producy_id=67;
    QString Arduino2_port_name;
    bool Arduino2_is_available;
    QByteArray data;  // contenant les données lues à partir d'Arduino2
};



#endif // Arduino22_H
