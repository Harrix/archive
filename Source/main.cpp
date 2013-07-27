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
