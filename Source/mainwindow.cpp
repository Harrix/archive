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

#include "HarrixQtLibrary.h"
#include "HarrixMathLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixClass_HarrixData.h"

MainWindow::MainWindow(QWidget *parent,QString FileNameFromArgv) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    if (Path.contains(QDir::separator())) DS=QDir::separator();
    if (Path.contains("\\")) DS="\\";
    if (Path.contains("/")) DS="/";
    Path+=DS;

    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)

    if (FileNameFromArgv.length()>0)
    {
        QString Html;
        HQt_BeginHtml (Path);

        HarrixClass_HarrixData H(FileNameFromArgv);
        Html += H.getChartHtmlCode();

        HQt_AddHtml(Html);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString Html;
    HQt_BeginHtml (Path);

    QString filename;
    filename=QFileDialog::getOpenFileName(this, tr("Открыть файл с данными графика"),"",tr("Harrix Data 1.1 (*.hdata)"));

    if (filename.length()>0)
    {
        HarrixClass_HarrixData H(filename);
        Html += H.getChartHtmlCode();
    HQt_AddHtml(Html);
    }
}

void MainWindow::on_action_LaTeX_triggered()
{
    HQt_BeginHtml (Path);
    QString Latex;

    Latex+=HQt_LatexBegin();

    QString filename;
    filename=QFileDialog::getOpenFileName(this, tr("Открыть файл с данными графика"),"",tr("Harrix Data 1.0 (*.hdata)"));

    if (filename.length()>0)
    {
        HarrixClass_HarrixData H(filename);
    Latex += H.getChartLatexCode();
    }

    Latex+=HQt_LatexEnd();
    HQt_SaveFile(Latex, Path+DS+"Generated LaTeX file"+DS+"Chart.tex");
    Latex+="<p>О компиляции файлов LaTeX: <a href=\"https://github.com/Harrix/HarrixLaTeXDocumentTemplate\">https://github.com/Harrix/HarrixLaTeXDocumentTemplate</a>.</p>";
    HQt_AddHtml( Latex);

    //открытие папки с собранными файлами
    QDesktopServices::openUrl(QUrl::fromLocalFile(Path+DS+"Generated LaTeX file"));
}
