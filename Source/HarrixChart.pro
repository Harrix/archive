#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T15:47:28
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HarrixChart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QtHarrixLibrary.cpp \
    MathHarrixLibrary.cpp \
    QtHarrixLibraryForQWebView.cpp

HEADERS  += mainwindow.h \
    QtHarrixLibrary.h \
    MathHarrixLibrary.h \
    QtHarrixLibraryForQWebView.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
