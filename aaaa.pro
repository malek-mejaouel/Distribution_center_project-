QT       += core gui serialport
QT       +=core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += sql
QT += sql network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    examenclass.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    arduino.h \
    connection.h \
    examenclass.h \
    mainwindow.h

FORMS += \
    mainwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc


QT += core gui sql printsupport  # Ajoutez printsupport

QT += core gui sql charts
QT += core gui sql printsupport charts




##########################################################















