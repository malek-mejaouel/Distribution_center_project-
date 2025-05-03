QT       += core gui
QT += core gui sql
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += core gui sql printsupport
QT += charts

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Equipement.cpp \
    User.cpp \
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    equipments.cpp \
    livreur.cpp \
    livreurs.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Equipement.h \
    User.h \
    arduino.h \
    connection.h \
    dialog.h \
    equipments.h \
    livreur.h \
    livreurs.h \
    mainwindow.h \
    styles.h

FORMS += \
    dialog.ui \
    equipments.ui \
    livreurs.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
