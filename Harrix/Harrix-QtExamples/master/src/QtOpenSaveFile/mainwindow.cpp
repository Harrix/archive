#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDebug>

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QString ReadFile(QString filename)
{
    filename = QDir::toNativeSeparators(filename);
    QFile file(filename);
    QString line;
    if(!file.exists()) {
        qDebug() << "Не существует "<<filename;
        return line;
    }else{
        qDebug() << filename<<" загружается...";
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        line=file.readAll();
    file.close();
    return line;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString S;
    S = ReadFile("C:\\1.txt");

     QStringList lines = S.split( " ", QString::SkipEmptyParts );

     s=0;

     for (int i=0;i<lines.count();i++)
     {
         ui->textEdit->insertPlainText(lines.at(i)+"\n");
         s = s + lines.at(i).toInt();
     }

     int a = lines.at(0).toInt();
     int b = lines.at(1).toInt();

     int c = a+b;
}
