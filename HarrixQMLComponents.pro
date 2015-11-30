TEMPLATE = app

QT += qml quick svg
CONFIG += c++11

SOURCES += main.cpp \
    providerwithqml.cpp

RESOURCES += qml.qrc \
    harrixqml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    providerwithqml.h

win32:RC_FILE = myapp.rc

