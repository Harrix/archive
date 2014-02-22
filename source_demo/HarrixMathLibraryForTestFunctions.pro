#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T21:40:47
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HarrixMathLibraryForTestFunctions
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    HarrixQtLibrary.cpp \
    HarrixQtLibraryForQWebView.cpp \
    mtrand.cpp \
    HarrixMathLibraryForTestFunctions.cpp \
    HarrixMathLibrary.cpp

HEADERS  += mainwindow.h \
    HarrixQtLibrary.h \
    HarrixQtLibraryForQWebView.h \
    mtrand.h \
    HarrixMathLibraryForTestFunctions.h \
    HarrixMathLibrary.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
