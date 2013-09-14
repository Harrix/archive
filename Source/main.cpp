//HarrixChart
//Программа распространяется по лицензии Apache License, Version 2.0.
//Приложение по отображению графиков из данных формата *.hdata.
//https://github.com/Harrix/HarrixChart

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString FileNameA = argc > 1 ? QString::fromLocal8Bit(argv[1]) : QString();//проверка - есть ли имя файла в аргументах запуска программы

    MainWindow w(NULL,FileNameA);
    w.showMaximized();
    
    return a.exec();
}
