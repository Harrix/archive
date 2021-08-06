#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "HarrixMathLibraryForTestFunctions.h"
#include "HarrixMathLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)

    //HML_SeedRandom();//Инициализация датчика случайных чисел

    model = new QStandardItemModel(this);
    model->setObjectName(QString::fromUtf8("model"));

    QStandardItem *item;//элемент списка

    //добавление новых элементов

    //Сюда нужно добавить код

   item = new QStandardItem(QString("HML_DefineTestFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_OptimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FitnessOfOptimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorExOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorEyOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorROfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GetCountOfFitness"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SetToZeroCountOfFitness"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ClassOfTestFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_OptimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FitnessOfOptimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfPartsOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_PrecisionOfCalculationsOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorROfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorExOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ErrorEyOfTestFunction_Real"));
    model->appendRow(item);

   item = new QStandardItem(QString("HML_LeftAndRightBorderOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MaximumOrMinimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MaximumOrMinimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GetCountOfSubProblems_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GetCountOfSubProblems_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DimensionTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DimensionTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CountOfFitnessOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CountOfFitnessOfTestFunction_Binary"));
    model->appendRow(item);

   model->sort(0);

    //соединение модели списка с конкретным списком

    proxyModelView = new QSortFilterProxyModel(this);
    proxyModelView->setSourceModel(model);
    proxyModelView->setObjectName(QString::fromUtf8("proxyModelView"));

    ui->listView->setModel(proxyModelView);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//---------------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------------------------------------------

void MainWindow::HML_ShowText (QString TitleX)
{
    /*
    Функция выводит число строку в textEdit.
    Входные параметры:
     TitleX - непосредственно строка сама.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=HQt_ShowText (TitleX);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> void MainWindow::HML_ShowNumber (T VHML_X, QString TitleX, QString NameX)
{
    /*
    Функция выводит число VHML_X в textEdit.
    Входные параметры:
     VHML_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowNumber (VHML_X, TitleX, NameX);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> QString MainWindow::HML_NumberToText (T VHML_X)
{
    /*
    Функция выводит число VHML_X в строку.
    Входные параметры:
     VHML_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHML_Result;
    VHML_Result=THQt_NumberToText (VHML_X);
    return VHML_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowVector (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VHML_Vector в textEdit
    Входные параметры:
     VHML_Vector - указатель на выводимый вектор;
     VHML_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowVector (VHML_Vector,VHML_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowVectorT (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VHML_Vector в textEdit в траснпонированном виде
    Входные параметры:
     VHML_Vector - указатель на выводимый вектор;
     VHML_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowVectorT (VHML_Vector,VHML_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowMatrix (T **VHML_Matrix, int VHML_N, int VHML_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция выводит матрицу VHML_Matrix в textEdit
    Входные параметры:
     VHML_Matrix - указатель на указатель на выводимую матрицу;
     VHML_N - количество строк в матрице;
     VHML_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowMatrix (VHML_Matrix, VHML_N ,VHML_M, TitleMatrix, NameMatrix);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    HQt_BeginHtml (Path);

    QString NameFunction;//Какая функция вызывается

    //выдергиваем текст
    NameFunction=index.data(Qt::DisplayRole).toString();

    //Сюда нужно добавить код

    if (NameFunction=="HML_DefineTestFunction")
    {
        //Вызов функции
        HML_DefineTestFunction(TestFunction_SumVector);

        //Использование результата
        int N=5;
        int *x=new int[N];
        HML_RandomBinaryVector(x,N);
        double f=HML_TestFunction_Binary(x,N);

        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	0

        HML_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=4
    }

    if (NameFunction=="HML_TestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        HML_RandomBinaryVector(x,N);

        //Вызов функции
        double f=HML_TestFunction_Binary(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	0

        HML_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=4
    }

    if (NameFunction=="HML_OptimumOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];

        //Вызов функции
        double f=HML_OptimumOfTestFunction_Binary(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Оптимальное решение тестовой функции TestFunction_SumVector","x");
        //Оптимальное решение тестовой функции TestFunction_SumVector:
        //x =
        //1	1	1	1	1

        HML_ShowNumber(f,"Значение целевой функции оптимального решения","f");
        //Значение целевой функции оптимального решения:
        //f=5
    }

    if (NameFunction=="HML_FitnessOfOptimumOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;

        //Вызов функции
        double f=HML_FitnessOfOptimumOfTestFunction_Binary(N);

        //Использование результата
        HML_ShowNumber(f,"Значение целевой функции оптимального решения функции TestFunction_SumVector","f");
        //Значение целевой функции оптимального решения функции TestFunction_SumVector:
        //f=5
    }

    if (NameFunction=="HML_ErrorExOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        HML_RandomBinaryVector(x,N);

        //Вызов функции
        double Ex=HML_ErrorExOfTestFunction_Binary(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	0	1	1	1

        HML_ShowNumber(Ex,"Значение ошибки по входным параметрам","E<sub>x</sub>");
        //Значение ошибки по входным параметрам:
        //Ex=1
    }

    if (NameFunction=="HML_ErrorEyOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        HML_RandomBinaryVector(x,N);
        double f=HML_TestFunction_Binary(x,N);

        //Вызов функции
        double Ey=HML_ErrorEyOfTestFunction_Binary(f,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //0	1	1	0	1

        HML_ShowNumber(Ey,"Значение ошибки по значениям целевой функции","E<sub>y</sub>");
        //Значение ошибки по значениям целевой функции:
        //Ey=2
    }

    if (NameFunction=="HML_ErrorROfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        HML_RandomBinaryVector(x,N);

        //Вызов функции
        double R=HML_ErrorROfTestFunction_Binary(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	1

        HML_ShowNumber(R,"Значение надежности","R");
        //Значение надежности:
        //R=1
    }

    if (NameFunction=="HML_GetCountOfFitness")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        HML_SetToZeroCountOfFitness();

        int N=5;
        double f=0;
        int *x=new int[N];

        for (int i=0;i<10;i++)
        {
            HML_RandomBinaryVector(x,N);
            f+=HML_TestFunction_Binary(x,N);
        }

        f/=double(10.);

        //Вызов функции
        int M=HML_GetCountOfFitness();

        //Использование результата
        HML_ShowNumber(M,"Количество вызовов целевой функции","M");
        //Количество вызовов целевой функции:
        //M=10

        HML_ShowNumber(f,"Среднее значение целевой функции","f");
        //Среднее значение целевой функции:
        //f=2.6
    }

    if (NameFunction=="HML_SetToZeroCountOfFitness")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        HML_SetToZeroCountOfFitness();

        //Использование результата
        int N=5;
        double f=0;
        int *x=new int[N];

        for (int i=0;i<10;i++)
        {
            HML_RandomBinaryVector(x,N);
            f+=HML_TestFunction_Binary(x,N);
        }

        f/=double(10.);

        int M=HML_GetCountOfFitness();
        HML_ShowNumber(M,"Количество вызовов целевой функции","M");
        //Количество вызовов целевой функции:
        //M=10

        HML_ShowNumber(f,"Среднее значение целевой функции","f");
        //Среднее значение целевой функции:
        //f=2.6
    }

    if (NameFunction=="HML_ClassOfTestFunction")
    {
        TypeOfTestFunction Type=TestFunction_Ackley;

        //Вызов функции
        int ClassOfTestFunction=HML_ClassOfTestFunction(Type);

        //используем результат
        if (ClassOfTestFunction==1)
            HML_ShowText("Это задача бинарной оптимизации");
        if (ClassOfTestFunction==2)
            HML_ShowText("Это задача вещественной оптимизации");
        //Это задача вещественной оптимизации.
    }

    if (NameFunction=="HML_TestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        HML_RandomRealVector(x,-1,1,N);

        //Вызов функции
        double f=HML_TestFunction_Real(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.391724	0.347656	0.259155	-0.544617	0.116516

        HML_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=3.38932
    }

    if (NameFunction=="HML_OptimumOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];

        //Вызов функции
        double f=HML_OptimumOfTestFunction_Real(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Оптимальное решение тестовой функции TestFunction_Ackley","x");
        //Оптимальное решение тестовой функции TestFunction_Ackley:
        //x =
        //0	0	0	0	0

        HML_ShowNumber(f,"Значение целевой функции оптимального решения","f");
        //Значение целевой функции оптимального решения:
        //f=0
    }

    if (NameFunction=="HML_FitnessOfOptimumOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;

        //Вызов функции
        double f=HML_FitnessOfOptimumOfTestFunction_Binary(N);

        //Использование результата
        HML_ShowNumber(f,"Значение целевой функции оптимального решения функции TestFunction_Ackley","f");
        //Значение целевой функции оптимального решения функции TestFunction_Ackley:
        //f=0
    }

    if (NameFunction=="HML_NumberOfPartsOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        int *NumberOfParts=new int[N];

        //Вызов функции
        double e=HML_NumberOfPartsOfTestFunction_Real(NumberOfParts,N);

        //Использование результата
        HML_ShowVectorT(NumberOfParts,N,"На сколько частей нужно делить каждую координату функции TestFunction_Ackley","NumberOfParts");
        //На сколько частей нужно делить каждую координату функции TestFunction_Ackley:
        //NumberOfParts =
        //4095	4095	4095	4095	4095

        HML_ShowNumber(e,"Точность вычислений.","e");
        //Точность вычислений.:
        //e=0.025
    }

    if (NameFunction=="HML_PrecisionOfCalculationsOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double e=HML_PrecisionOfCalculationsOfTestFunction_Real();

        //Использование результата
        HML_ShowNumber(e,"Точность вычислений","e");
        //Точность вычислений:
        //e=0.025
    }

    if (NameFunction=="HML_ErrorROfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        HML_RandomRealVector(x,0.01,0.02,N);

        //Вызов функции
        double R=HML_ErrorROfTestFunction_Real(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //0.0118939	0.0177618	0.0115656	0.0181937	0.0124084

        HML_ShowNumber(R,"Значение надежности","R");
        //Значение надежности:
        //R=1
    }

    if (NameFunction=="HML_ErrorExOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        HML_RandomRealVector(x,-0.5,0.05,N);

        //Вызов функции
        double Ex=HML_ErrorExOfTestFunction_Real(x,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.43694	-0.458693	-0.0266388	0.0117142	-0.136948


        HML_ShowNumber(Ex,"Значение ошибки по входным параметрам","E<sub>x</sub>");
        //Значение ошибки по входным параметрам:
        //Ex=0.129756
    }

    if (NameFunction=="HML_ErrorEyOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        HML_RandomRealVector(x,-0.5,0.05,N);
        double f=HML_TestFunction_Real(x,N);

        //Вызов функции
        double Ey=HML_ErrorEyOfTestFunction_Real(f,N);

        //Использование результата
        HML_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.0963959	-0.183693	-0.0485428	-0.185757	0.0321075

        HML_ShowNumber(Ey,"Значение ошибки по значениям целевой функции","E<sub>y</sub>");
        //Значение ошибки по значениям целевой функции:
        //Ey=1.18549
    }

    if (NameFunction=="HML_LeftAndRightBorderOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *Left=new double[N];
        double *Right=new double[N];

        //Вызов функции
        HML_LeftAndRightBorderOfTestFunction_Real(Left,Right,N);

        //Использование результата
        HML_ShowVectorT(Left,N,"Левые границы допустимой области функции TestFunction_Ackley","Left");
        //Левые границы допустимой области функции TestFunction_Ackley:
        //Left =
        //-5	-5	-5	-5	-5

        HML_ShowVectorT(Right,N,"Правые границы допустимой области функции TestFunction_Ackley","Right");
        //Правые границы допустимой области функции TestFunction_Ackley:
        //Right =
        //5	5	5	5	5
    }

    if (NameFunction=="HML_MaximumOrMinimumOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double MorM=HML_MaximumOrMinimumOfTestFunction_Real();

        //Использование результата
        HML_ShowNumber(MorM,"Максимум или минимум функции находим у TestFunction_Ackley","MorM");
        //Максимум или минимум функции находим у TestFunction_Ackley:
        //MorM=-1
    }

    if (NameFunction=="HML_MaximumOrMinimumOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double MorM=HML_MaximumOrMinimumOfTestFunction_Binary();

        //Использование результата
        HML_ShowNumber(MorM,"Максимум или минимум функции находим у TestFunction_SumVector","MorM");
        //Максимум или минимум функции находим у TestFunction_SumVector:
        //MorM=1
    }


    if (NameFunction=="HML_GetCountOfSubProblems_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double N=HML_GetCountOfSubProblems_Binary();

        //Использование результата
        HML_ShowNumber(N,"Число подзадач (включая основную задачу) для TestFunction_SumVector","N");
        //Число подзадач (включая основную задачу) для TestFunction_SumVector:
        //N=10
    }

    if (NameFunction=="HML_GetCountOfSubProblems_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double N=HML_GetCountOfSubProblems_Real();

        //Использование результата
        HML_ShowNumber(N,"Число подзадач (включая основную задачу) для TestFunction_Ackley","N");
        //Число подзадач (включая основную задачу) для TestFunction_Ackley:
        //N=7
    }

    if (NameFunction=="HML_DimensionTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double N=HML_DimensionTestFunction_Binary(0);

        //Использование результата
        HML_ShowNumber(N,"Размерность тестовой задачи для TestFunction_SumVector при i=0","N");
        //Размерность тестовой задачи для TestFunction_SumVector при i=0:
        //N=20
    }

    if (NameFunction=="HML_DimensionTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double N=HML_DimensionTestFunction_Real(0);

        //Использование результата
        HML_ShowNumber(N,"Размерность тестовой задачи для TestFunction_Ackley при i=0","N");
        //Размерность тестовой задачи для TestFunction_Ackley при i=0:
        //N=2
    }

    if (NameFunction=="HML_CountOfFitnessOfTestFunction_Real")
    {
        HML_DefineTestFunction(TestFunction_Ackley);

        int Dimension = 3;

        //Вызов функции
        int  N=HML_CountOfFitnessOfTestFunction_Real(Dimension);

        //Использование результата
        HML_ShowNumber(N,"Количество вычислений целевой функции для TestFunction_Ackley при размерности 3","N");
        //Количество вычислений целевой функции для TestFunction_Ackley при размерности 3:
        //N=729
    }

    if (NameFunction=="HML_CountOfFitnessOfTestFunction_Binary")
    {
        HML_DefineTestFunction(TestFunction_SumVector);

        int Dimension = 30;

        //Вызов функции
        int  N=HML_CountOfFitnessOfTestFunction_Binary(Dimension);

        //Использование результата
        HML_ShowNumber(N,"Количество вычислений целевой функции для TestFunction_SumVector при размерности 30","N");
        //Количество вычислений целевой функции для TestFunction_SumVector при размерности 30:
        //N=400
    }
}
//---------------------------------------------------------------------------

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QRegExp regExp(QString("*%1*").arg(arg1), Qt::CaseInsensitive,
                   QRegExp::Wildcard);
    proxyModelView->setFilterRegExp(regExp);
}
