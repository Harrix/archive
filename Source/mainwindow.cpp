#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <typeinfo>

#include "QtHarrixLibrary.h"
#include "MathHarrixLibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);

    DS=QDir::separator();
    path=QGuiApplication::applicationDirPath()+DS;//путь к папке
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        QString Html;
        Html=HQt_BeginHtml ();

        QStringList List = HQt_ReadFileToQStringList(path+"16.hdata");
        int NX1=HQt_CountOfRowsFromQStringList(List,0);
        int NY1=HQt_CountOfRowsFromQStringList(List,1);
        int NX2=HQt_CountOfRowsFromQStringList(List,2);
        int NY2=HQt_CountOfRowsFromQStringList(List,3);
        double *dataX1=new double [NX1];
        double *dataY1=new double [NY1];
        double *dataX2=new double [NX2];
        double *dataY2=new double [NY2];

        THQt_ReadColFromQStringList(List,0,dataX1);
        THQt_ReadColFromQStringList(List,1,dataY1);
        THQt_ReadColFromQStringList(List,2,dataX2);
        THQt_ReadColFromQStringList(List,3,dataY2);

        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов");

        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов",false,true,true,true);
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов",true,false,true,true);
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,false,true);
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,false);

        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y",true,true,true,true);
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,"Тестовый график","x","y","количество деревьев","количество домов");
        Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2);


        delete []dataX1;
        delete []dataX2;
        delete []dataY1;
        delete []dataY2;

        Html+=HQt_EndHtml();
        HQt_SaveFile(Html, path+"temp.html");
        ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
}
