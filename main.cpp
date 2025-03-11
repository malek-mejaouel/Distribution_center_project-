#include <QApplication>
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Établir la connexion à la base de données
    Connection c;
    if (!c.createconnect()) {
        return 1; // Quitte l'application si la connexion échoue
    }

    MainWindow w;
    w.show();
    return a.exec();
}
