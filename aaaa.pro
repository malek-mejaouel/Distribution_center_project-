QT += core gui widgets charts
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core serialport
CONFIG += c++17
QT+= sql
QT += printsupport

include($$PWD/QZXing/src/QZXing.pri)  # Adjust path if needed
QT += multimedia  # Required for QZXing
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    box.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    qrdialog.cpp \
    statisticsdialog.cpp \
    trackdialog.cpp

HEADERS += \
    arduino.h \
    box.h \
    connection.h \
    mainwindow.h \
    qrdialog.h \
    statisticsdialog.h \
    trackdialog.h

FORMS += \
    mainwindow.ui \
    qrdialog.ui \
    statisticsdialog.ui \
    trackdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
