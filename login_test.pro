###############################################################################
#  FullMark - Qt(5/6)  .pro
###############################################################################

# ---------- Qt modules -------------------------------------------------------
QT += core gui widgets sql serialport printsupport multimedia
QT += charts
# ---------- Compiler ---------------------------------------------------------
CONFIG += c++17

# ---------- 3rd-party : QZXing ----------------------------------------------
# (needs the Multimedia module, already added above)
include($$PWD/QZXing/src/QZXing.pri)

# ---------- Sources / headers / forms ---------------------------------------
SOURCES += \
    Equipement.cpp \
    User.cpp \
    arduino.cpp \
    arduino1.cpp \
    box.cpp \
    boxs.cpp \
    connection.cpp \
    dialog.cpp \
    equipments.cpp \
    livreur.cpp \
    livreurs.cpp \
    main.cpp \
    mainwindow.cpp \
    qrdialog.cpp \
    trackdialog.cpp

HEADERS += \
    Equipement.h \
    User.h \
    arduino.h \
    arduino1.h \
    box.h \
    boxs.h \
    connection.h \
    dialog.h \
    equipments.h \
    livreur.h \
    livreurs.h \
    mainwindow.h \
    qrdialog.h \
    styles.h \
    trackdialog.h

FORMS += \
    boxs.ui \
    dialog.ui \
    equipments.ui \
    livreurs.ui \
    mainwindow.ui \
    qrdialog.ui \
    trackdialog.ui

# ---------- Resources --------------------------------------------------------
RESOURCES += Ressources.qrc

# ---------- Deployment rules (leave as is) ----------------------------------
qnx: target.path = /tmp/$${TARGET}/bin
else:unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
