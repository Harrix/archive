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
#include <QFileDialog>

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

    Html+=HQt_ReadHdataToHtmlChart (QFileDialog::getOpenFileName(this, tr("Открыть файл с данными графика"),"",tr("Harrix Data 1.0 (*.hdata)")));

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
}

void MainWindow::on_action_triggered()
{
    QString Html;
    Html=HQt_BeginHtml ();

    Html+=HQt_ReadHdataToHtmlChart (QFileDialog::getOpenFileName(this, tr("Открыть файл с данными графика"),"",tr("Harrix Data 1.0 (*.hdata)")));

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
}
