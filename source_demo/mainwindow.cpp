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

    //MHL_SeedRandom();//Инициализация датчика случайных чисел

    model = new QStandardItemModel(this);
    model->setObjectName(QString::fromUtf8("model"));

    QStandardItem *item;//элемент списка

    //добавление новых элементов

    //Сюда нужно добавить код

   item = new QStandardItem(QString("MHL_DefineTestFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_OptimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_FitnessOfOptimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorExOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorEyOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorROfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GetCountOfFitness"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SetToZeroCountOfFitness"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ClassOfTestFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_OptimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_FitnessOfOptimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NumberOfPartsOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_PrecisionOfCalculationsOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorROfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorExOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ErrorEyOfTestFunction_Real"));
    model->appendRow(item);

   item = new QStandardItem(QString("MHL_LeftAndRightBorderOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MaximumOrMinimumOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MaximumOrMinimumOfTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GetCountOfSubProblems_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GetCountOfSubProblems_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DimensionTestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DimensionTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CountOfFitnessOfTestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CountOfFitnessOfTestFunction_Binary"));
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

void MainWindow::MHL_ShowText (QString TitleX)
{
    /*
    Функция выводит число строку в textEdit.
    Входные параметры:
     TitleX - непосредственно строка сама.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=HQt_ShowText (TitleX);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> void MainWindow::MHL_ShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция выводит число VMHL_X в textEdit.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowNumber (VMHL_X, TitleX, NameX);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> QString MainWindow::MHL_NumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_NumberToText (VMHL_X);
    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVector (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit в траснпонированном виде
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVectorT (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowMatrix (T **VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция выводит матрицу VMHL_Matrix в textEdit
    Входные параметры:
     VMHL_Matrix - указатель на указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowMatrix (VMHL_Matrix, VMHL_N ,VMHL_M, TitleMatrix, NameMatrix);// из HarrixQtLibrary.h
    Html=VMHL_Result;
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

    if (NameFunction=="MHL_DefineTestFunction")
    {
        //Вызов функции
        MHL_DefineTestFunction(TestFunction_SumVector);

        //Использование результата
        int N=5;
        int *x=new int[N];
        TMHL_RandomBinaryVector(x,N);
        double f=MHL_TestFunction_Binary(x,N);

        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	0

        MHL_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=4
    }

    if (NameFunction=="MHL_TestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        TMHL_RandomBinaryVector(x,N);

        //Вызов функции
        double f=MHL_TestFunction_Binary(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	0

        MHL_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=4
    }

    if (NameFunction=="MHL_OptimumOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];

        //Вызов функции
        double f=MHL_OptimumOfTestFunction_Binary(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Оптимальное решение тестовой функции TestFunction_SumVector","x");
        //Оптимальное решение тестовой функции TestFunction_SumVector:
        //x =
        //1	1	1	1	1

        MHL_ShowNumber(f,"Значение целевой функции оптимального решения","f");
        //Значение целевой функции оптимального решения:
        //f=5
    }

    if (NameFunction=="MHL_FitnessOfOptimumOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;

        //Вызов функции
        double f=MHL_FitnessOfOptimumOfTestFunction_Binary(N);

        //Использование результата
        MHL_ShowNumber(f,"Значение целевой функции оптимального решения функции TestFunction_SumVector","f");
        //Значение целевой функции оптимального решения функции TestFunction_SumVector:
        //f=5
    }

    if (NameFunction=="MHL_ErrorExOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        TMHL_RandomBinaryVector(x,N);

        //Вызов функции
        double Ex=MHL_ErrorExOfTestFunction_Binary(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	0	1	1	1

        MHL_ShowNumber(Ex,"Значение ошибки по входным параметрам","E<sub>x</sub>");
        //Значение ошибки по входным параметрам:
        //Ex=1
    }

    if (NameFunction=="MHL_ErrorEyOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        TMHL_RandomBinaryVector(x,N);
        double f=MHL_TestFunction_Binary(x,N);

        //Вызов функции
        double Ey=MHL_ErrorEyOfTestFunction_Binary(f,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //0	1	1	0	1

        MHL_ShowNumber(Ey,"Значение ошибки по значениям целевой функции","E<sub>y</sub>");
        //Значение ошибки по значениям целевой функции:
        //Ey=2
    }

    if (NameFunction=="MHL_ErrorROfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int N=5;
        int *x=new int[N];
        TMHL_RandomBinaryVector(x,N);

        //Вызов функции
        double R=MHL_ErrorROfTestFunction_Binary(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //1	1	1	1	1

        MHL_ShowNumber(R,"Значение надежности","R");
        //Значение надежности:
        //R=1
    }

    if (NameFunction=="MHL_GetCountOfFitness")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        MHL_SetToZeroCountOfFitness();

        int N=5;
        double f=0;
        int *x=new int[N];

        for (int i=0;i<10;i++)
        {
            TMHL_RandomBinaryVector(x,N);
            f+=MHL_TestFunction_Binary(x,N);
        }

        f/=double(10.);

        //Вызов функции
        int M=MHL_GetCountOfFitness();

        //Использование результата
        MHL_ShowNumber(M,"Количество вызовов целевой функции","M");
        //Количество вызовов целевой функции:
        //M=10

        MHL_ShowNumber(f,"Среднее значение целевой функции","f");
        //Среднее значение целевой функции:
        //f=2.6
    }

    if (NameFunction=="MHL_SetToZeroCountOfFitness")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        MHL_SetToZeroCountOfFitness();

        //Использование результата
        int N=5;
        double f=0;
        int *x=new int[N];

        for (int i=0;i<10;i++)
        {
            TMHL_RandomBinaryVector(x,N);
            f+=MHL_TestFunction_Binary(x,N);
        }

        f/=double(10.);

        int M=MHL_GetCountOfFitness();
        MHL_ShowNumber(M,"Количество вызовов целевой функции","M");
        //Количество вызовов целевой функции:
        //M=10

        MHL_ShowNumber(f,"Среднее значение целевой функции","f");
        //Среднее значение целевой функции:
        //f=2.6
    }

    if (NameFunction=="MHL_ClassOfTestFunction")
    {
        TypeOfTestFunction Type=TestFunction_Ackley;

        //Вызов функции
        int ClassOfTestFunction=MHL_ClassOfTestFunction(Type);

        //используем результат
        if (ClassOfTestFunction==1)
            MHL_ShowText("Это задача бинарной оптимизации");
        if (ClassOfTestFunction==2)
            MHL_ShowText("Это задача вещественной оптимизации");
        //Это задача вещественной оптимизации.
    }

    if (NameFunction=="MHL_TestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        MHL_RandomRealVector(x,-1,1,N);

        //Вызов функции
        double f=MHL_TestFunction_Real(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.391724	0.347656	0.259155	-0.544617	0.116516

        MHL_ShowNumber(f,"Значение целевой функции","f");
        //Значение целевой функции:
        //f=3.38932
    }

    if (NameFunction=="MHL_OptimumOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];

        //Вызов функции
        double f=MHL_OptimumOfTestFunction_Real(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Оптимальное решение тестовой функции TestFunction_Ackley","x");
        //Оптимальное решение тестовой функции TestFunction_Ackley:
        //x =
        //0	0	0	0	0

        MHL_ShowNumber(f,"Значение целевой функции оптимального решения","f");
        //Значение целевой функции оптимального решения:
        //f=0
    }

    if (NameFunction=="MHL_FitnessOfOptimumOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;

        //Вызов функции
        double f=MHL_FitnessOfOptimumOfTestFunction_Binary(N);

        //Использование результата
        MHL_ShowNumber(f,"Значение целевой функции оптимального решения функции TestFunction_Ackley","f");
        //Значение целевой функции оптимального решения функции TestFunction_Ackley:
        //f=0
    }

    if (NameFunction=="MHL_NumberOfPartsOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        int *NumberOfParts=new int[N];

        //Вызов функции
        double e=MHL_NumberOfPartsOfTestFunction_Real(NumberOfParts,N);

        //Использование результата
        MHL_ShowVectorT(NumberOfParts,N,"На сколько частей нужно делить каждую координату функции TestFunction_Ackley","NumberOfParts");
        //На сколько частей нужно делить каждую координату функции TestFunction_Ackley:
        //NumberOfParts =
        //4095	4095	4095	4095	4095

        MHL_ShowNumber(e,"Точность вычислений.","e");
        //Точность вычислений.:
        //e=0.025
    }

    if (NameFunction=="MHL_PrecisionOfCalculationsOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double e=MHL_PrecisionOfCalculationsOfTestFunction_Real();

        //Использование результата
        MHL_ShowNumber(e,"Точность вычислений","e");
        //Точность вычислений:
        //e=0.025
    }

    if (NameFunction=="MHL_ErrorROfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        MHL_RandomRealVector(x,0.01,0.02,N);

        //Вызов функции
        double R=MHL_ErrorROfTestFunction_Real(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //0.0118939	0.0177618	0.0115656	0.0181937	0.0124084

        MHL_ShowNumber(R,"Значение надежности","R");
        //Значение надежности:
        //R=1
    }

    if (NameFunction=="MHL_ErrorExOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        MHL_RandomRealVector(x,-0.5,0.05,N);

        //Вызов функции
        double Ex=MHL_ErrorExOfTestFunction_Real(x,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.43694	-0.458693	-0.0266388	0.0117142	-0.136948


        MHL_ShowNumber(Ex,"Значение ошибки по входным параметрам","E<sub>x</sub>");
        //Значение ошибки по входным параметрам:
        //Ex=0.129756
    }

    if (NameFunction=="MHL_ErrorEyOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *x=new double[N];
        MHL_RandomRealVector(x,-0.5,0.05,N);
        double f=MHL_TestFunction_Real(x,N);

        //Вызов функции
        double Ey=MHL_ErrorEyOfTestFunction_Real(f,N);

        //Использование результата
        MHL_ShowVectorT(x,N,"Решение","x");
        //Решение:
        //x =
        //-0.0963959	-0.183693	-0.0485428	-0.185757	0.0321075

        MHL_ShowNumber(Ey,"Значение ошибки по значениям целевой функции","E<sub>y</sub>");
        //Значение ошибки по значениям целевой функции:
        //Ey=1.18549
    }

    if (NameFunction=="MHL_LeftAndRightBorderOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int N=5;
        double *Left=new double[N];
        double *Right=new double[N];

        //Вызов функции
        MHL_LeftAndRightBorderOfTestFunction_Real(Left,Right,N);

        //Использование результата
        MHL_ShowVectorT(Left,N,"Левые границы допустимой области функции TestFunction_Ackley","Left");
        //Левые границы допустимой области функции TestFunction_Ackley:
        //Left =
        //-5	-5	-5	-5	-5

        MHL_ShowVectorT(Right,N,"Правые границы допустимой области функции TestFunction_Ackley","Right");
        //Правые границы допустимой области функции TestFunction_Ackley:
        //Right =
        //5	5	5	5	5
    }

    if (NameFunction=="MHL_MaximumOrMinimumOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double MorM=MHL_MaximumOrMinimumOfTestFunction_Real();

        //Использование результата
        MHL_ShowNumber(MorM,"Максимум или минимум функции находим у TestFunction_Ackley","MorM");
        //Максимум или минимум функции находим у TestFunction_Ackley:
        //MorM=-1
    }

    if (NameFunction=="MHL_MaximumOrMinimumOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double MorM=MHL_MaximumOrMinimumOfTestFunction_Binary();

        //Использование результата
        MHL_ShowNumber(MorM,"Максимум или минимум функции находим у TestFunction_SumVector","MorM");
        //Максимум или минимум функции находим у TestFunction_SumVector:
        //MorM=1
    }


    if (NameFunction=="MHL_GetCountOfSubProblems_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double N=MHL_GetCountOfSubProblems_Binary();

        //Использование результата
        MHL_ShowNumber(N,"Число подзадач (включая основную задачу) для TestFunction_SumVector","N");
        //Число подзадач (включая основную задачу) для TestFunction_SumVector:
        //N=10
    }

    if (NameFunction=="MHL_GetCountOfSubProblems_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double N=MHL_GetCountOfSubProblems_Real();

        //Использование результата
        MHL_ShowNumber(N,"Число подзадач (включая основную задачу) для TestFunction_Ackley","N");
        //Число подзадач (включая основную задачу) для TestFunction_Ackley:
        //N=7
    }

    if (NameFunction=="MHL_DimensionTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        //Вызов функции
        double N=MHL_DimensionTestFunction_Binary(0);

        //Использование результата
        MHL_ShowNumber(N,"Размерность тестовой задачи для TestFunction_SumVector при i=0","N");
        //Размерность тестовой задачи для TestFunction_SumVector при i=0:
        //N=20
    }

    if (NameFunction=="MHL_DimensionTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        //Вызов функции
        double N=MHL_DimensionTestFunction_Real(0);

        //Использование результата
        MHL_ShowNumber(N,"Размерность тестовой задачи для TestFunction_Ackley при i=0","N");
        //Размерность тестовой задачи для TestFunction_Ackley при i=0:
        //N=2
    }

    if (NameFunction=="MHL_CountOfFitnessOfTestFunction_Real")
    {
        MHL_DefineTestFunction(TestFunction_Ackley);

        int Dimension = 3;

        //Вызов функции
        int  N=MHL_CountOfFitnessOfTestFunction_Real(Dimension);

        //Использование результата
        MHL_ShowNumber(N,"Количество вычислений целевой функции для TestFunction_Ackley при размерности 3","N");
        //Количество вычислений целевой функции для TestFunction_Ackley при размерности 3:
        //N=729
    }

    if (NameFunction=="MHL_CountOfFitnessOfTestFunction_Binary")
    {
        MHL_DefineTestFunction(TestFunction_SumVector);

        int Dimension = 30;

        //Вызов функции
        int  N=MHL_CountOfFitnessOfTestFunction_Binary(Dimension);

        //Использование результата
        MHL_ShowNumber(N,"Количество вычислений целевой функции для TestFunction_SumVector при размерности 30","N");
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
