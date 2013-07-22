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
    MathHarrixLibrary.cpp

HEADERS  += mainwindow.h \
    QtHarrixLibrary.h \
    MathHarrixLibrary.h

FORMS    += mainwindow.ui
