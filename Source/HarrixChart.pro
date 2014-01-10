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
    HarrixQtLibrary.cpp \
    HarrixMathLibrary.cpp \
    HarrixQtLibraryForQWebView.cpp \
    mtrand.cpp \
    HarrixQtLibraryForLaTeX.cpp

HEADERS  += mainwindow.h \
    HarrixQtLibrary.h \
    HarrixMathLibrary.h \
    HarrixQtLibraryForQWebView.h \
    mtrand.h \
    HarrixQtLibraryForLaTeX.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
