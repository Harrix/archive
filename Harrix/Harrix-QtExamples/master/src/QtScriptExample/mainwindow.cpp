#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtScript/QScriptEngine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Подготовка
    double x=2;//в какой точки ищем значение функции
    QString CodeFunction="RESULT = Math.sin(x);RESULT = RESULT + 1;";

    //Необходимые переменные
    double Result;
    QScriptEngine engine;
    QScriptValue scriptFun;

    //подготовка движка QtScript
    engine.evaluate("function fun(x)\n {\n var RESULT=0;\n"+CodeFunction+"\n return RESULT;\n}\n");
    scriptFun = engine.globalObject().property("fun");

    //Вычисление значения функции в точке
    Result = scriptFun.call(QScriptValue(), QScriptValueList() << x).toNumber();

    ui->textEdit->insertPlainText(QString::number(Result)+"\n");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString CodeFunction="2+2*2";

    QScriptEngine engine;

    double Result = engine.evaluate(CodeFunction).toNumber();

    ui->textEdit->insertPlainText(QString::number(Result)+"\n");
}

void MainWindow::on_pushButton_3_clicked()
{
    //Подготовка
    double x=2, y=3;//в какой точки ищем значение функции
    QString CodeFunction="RESULT = x+y;";

    //Необходимые переменные
    double Result;
    QScriptEngine engine;
    QScriptValue scriptFun;

    //подготовка движка QtScript
    engine.evaluate("function fun(x,y)\n {\n var RESULT=0;\n"+CodeFunction+"\n return RESULT;\n}\n");
    scriptFun = engine.globalObject().property("fun");

    //Вычисление значения функции в точке
    Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y).toNumber();

    ui->textEdit->insertPlainText(QString::number(Result)+"\n");
}
