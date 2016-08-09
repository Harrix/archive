QT += qml quick quickcontrols2 svg

CONFIG += c++11

SOURCES += main.cpp \
    handlersignals.cpp

RESOURCES += qml.qrc \
    HarrixQML.qrc

QML_IMPORT_PATH =

include(deployment.pri)

HEADERS += \
    handlersignals.h

VERSION = 1.0

RC_ICONS = harrix.ico
