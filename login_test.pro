QT       += core gui widgets printsupport sql serialport multimedia \
            charts quick qml quickcontrols2 positioning network      \
            quickwidgets                 # ←  ADD THIS


CONFIG   += c++17

# ZXing ------------------------------------------------------------------
include($$PWD/QZXing/src/QZXing.pri)

SOURCES += \
    Equipement.cpp \
    User.cpp \
    arduino.cpp \
    arduino1.cpp \
    arduino2.cpp \
    box.cpp \
    boxs.cpp \
    connection.cpp \
    dialog.cpp \
    equipments.cpp \
    examens.cpp \
    institut.cpp \
    instituts.cpp \      # <-- missed before
    livreur.cpp \
    livreurs.cpp \
    main.cpp \
    mainwindow.cpp \
    markermodel.cpp \
    qrdialog.cpp \
    trackdialog.cpp

HEADERS += \
    Equipement.h \
    User.h \
    arduino.h \
    arduino1.h \
    arduino2.h \
    arduino2.h \
    box.h \
    boxs.h \
    connection.h \
    dialog.h \
    equipments.h \
    examens.h \
    institut.h \
    instituts.h \        # <-- missed before
    livreur.h \
    livreurs.h \
    mainwindow.h \
    markermodel.h \
    qrdialog.h \
    styles.h \
    trackdialog.h

FORMS += \
    boxs.ui \
    dialog.ui \
    equipments.ui \
    instituts.ui \
    livreurs.ui \
    mainwindow.ui \
    qrdialog.ui \
    trackdialog.ui

RESOURCES += Ressources.qrc qml.qrc
