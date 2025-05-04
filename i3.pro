QT += core gui sql widgets network printsupport serialport
QT += quick quickwidgets
QT += charts
QT += positioning location

CONFIG += c++11
CONFIG += c++17 qml_debug
CONFIG += warn_on release



# Sources
SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    institut.cpp \
    markermodel.cpp

# Headers
HEADERS += \
    arduino.h \
    connection.h \
    mainwindow.h \
    institut.h \
    markermodel.h

# Forms
FORMS += \
    mainwindow.ui

# Resources
RESOURCES += \
    qml.qrc \
    ressource.qrc \
    ressources.qrc

# Fichiers QML
OTHER_FILES += \
    map.qml

# Configuration du débuggeur QML
debug {
    DEFINES += QT_QML_DEBUG
    QML_IMPORT_PATH =
    QML_DESIGNER_IMPORT_PATH =
    QML_IMPORT_TRACE=1
}

# Options de compilation pour Windows
win32 {
    CONFIG += console
    DEFINES += QML_DECLARATIVE_DEBUG
}

# Options de compilation pour Linux/Unix
unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += Qt5Quick Qt5Positioning
}

DISTFILES += \
    ressources/box-3-48.png \
    ressources/building-48.png \
    ressources/delivery-48.png \
    ressources/log-out.svg \
    ressources/logout-48.png \
    ressources/maps.png \
    ressources/mqq.jpg \
    ressources/noti.png \
    ressources/paper-48.png \
    ressources/search-3-48.png \
    ressources/settings-5-48.png \
    ressources/settings.svg \
    ressources/stat.jpg \
    ressources/tool-box-48.png \
    ressources/user-48.png \
    ressources/user.svg
