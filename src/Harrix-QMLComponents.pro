QT += qml quick quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    handlersignals.cpp

RESOURCES += qml.qrc \
    HarrixQML.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    handlersignals.h
