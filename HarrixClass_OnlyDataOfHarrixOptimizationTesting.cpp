//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.19
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixMathLibrary.h"
#include "HarrixClass_OnlyDataOfHarrixOptimizationTesting.h"

////////////////////////////////////////////////////////////////////////////
/////////// HarrixClass_OnlyDataOfHarrixOptimizationTesting ////////////////
////////////////////////////////////////////////////////////////////////////

//Класс, который только содержит сырые данные исследований, которые считываются
//классом HarrixClass_DataOfHarrixOptimizationTesting. В данном классе нет ни проверки
//корректности ввоод информации и др. Это служебный класс.

HarrixClass_OnlyDataOfHarrixOptimizationTesting::HarrixClass_OnlyDataOfHarrixOptimizationTesting()
{
    /*
    Конструктор. Создает пустой экзмепляр.
    Входные параметры:
     Отсутствуют.
 */
    initializationOfVariables();
}
//--------------------------------------------------------------------------

HarrixClass_OnlyDataOfHarrixOptimizationTesting::~HarrixClass_OnlyDataOfHarrixOptimizationTesting()
{
    /*
     Деконструктор класса.
     */
    memoryDeallocation();
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B)
{
    //Вначале учничтожим все массивы если они были.
    memoryDeallocation();
    //B обнулим переменные
    initializationOfVariables();

    XML_Author = B.XML_Author;
    XML_Date = B.XML_Date;
    XML_Email = B.XML_Email;
    XML_Name_Algorithm = B.XML_Name_Algorithm;
    XML_Full_Name_Algorithm = B.XML_Full_Name_Algorithm;//Полное название алгоритма оптимизации
    XML_Name_Test_Function = B.XML_Name_Test_Function;//Название тестовой функции
    XML_Full_Name_Test_Function = B.XML_Full_Name_Test_Function;//Полное название тестовой функции
    XML_DimensionTestFunction = B.XML_DimensionTestFunction;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring = B.XML_Number_Of_Measuring;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs = B.XML_Number_Of_Runs;//Количество прогонов, по которому делается усреднение для эксперимента
    XML_Max_Count_Of_Fitness = B.XML_Max_Count_Of_Fitness;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters = B.XML_Number_Of_Parameters;//Количество проверяемых параметров алгоритма оптимизации
    XML_Number_Of_Experiments = B.XML_Number_Of_Experiments;//Количество комбинаций вариантов настроек
    XML_Link_Test_Function = B.XML_Link_Test_Function;//Ссылка на описание тестовой функции
    XML_Link_Algorithm = B.XML_Link_Algorithm;//Ссылка на описание алгоритма оптимизации
    XML_Format = B.XML_Format;//Что за формат файла
    XML_Version = B.XML_Version;//Какая версия формата файла
    XML_Link = B.XML_Link;//Ссылка на описание формата файла
    XML_All_Combinations = B.XML_All_Combinations;//Все ли рассмотрены функции

    SuccessReading=B.SuccessReading;

    memoryAllocation();

    if (SuccessReading)
    {
        for (int i=0;i<XML_Number_Of_Experiments;i++)
            for (int j=0;j<XML_Number_Of_Measuring;j++)
            {
                MatrixOfEx[i][j]=B.MatrixOfEx[i][j];
                MatrixOfEy[i][j]=B.MatrixOfEy[i][j];
                MatrixOfR [i][j]=B.MatrixOfR [i][j];
            }
    }
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::memoryAllocation()
{
    /*
    Выделяет память под необходимые массивы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //Матрица значений ошибок Ex алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEx=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEx[i]=new double[XML_Number_Of_Measuring];
    TMHL_FillMatrix(MatrixOfEx, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEy=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEy[i]=new double[XML_Number_Of_Measuring];
    TMHL_FillMatrix(MatrixOfEy, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений ошибок R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfR=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfR[i]=new double[XML_Number_Of_Measuring];
    TMHL_FillMatrix(MatrixOfR, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    //MatrixOfParameters=new int*[XML_Number_Of_Experiments];
    //for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfParameters[i]=new int[XML_Number_Of_Parameters];

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружений новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в ListOfParameterOptions
    //находится под номером соответствующим.
    //ListOfParameterOptions=new QStringList[XML_Number_Of_Parameters];

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    //MatrixOfNameParameters=new QStringList[XML_Number_Of_Experiments];

    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до XML_Number_Of_Experiments
    //NumberOfListOfVectorParameterOptions=new double[XML_Number_Of_Experiments];
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::memoryDeallocation()
{
    /*
    Удаляет память из-под массивов. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (!SuccessReading)
    {
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEx[i];
        delete [] MatrixOfEx;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEy[i];
        delete [] MatrixOfEy;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfR[i];
        delete [] MatrixOfR;
        //for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfParameters[i];
        //delete [] MatrixOfParameters;
        //delete [] ListOfParameterOptions;
        //delete [] NumberOfListOfVectorParameterOptions;
    }
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::initializationOfVariables()
{
    /*
    Обнуление пемеренных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    SuccessReading=false;
    XML_DimensionTestFunction=-1;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring=-1;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs=-1;//Количество прогонов, по которому делается усреднение для эксперимента
    XML_Max_Count_Of_Fitness=-1;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters=-1;//Количество проверяемых параметров алгоритма оптимизации
    //Zero_Number_Of_Parameters=false;//пока ничего не известно
    XML_Number_Of_Experiments=-1;//Количество комбинаций вариантов настроек
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getAuthor()
{
    /*
     Получение текста переменной XML_Author - Автор документа
     */
    return XML_Author;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setAuthor(QString Author)
{
    /*
     Задание текста переменной XML_Author - Автор документа
     */
    XML_Author = Author;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getDate()
{
    /*
     Получение текста переменной  XML_Date - Дата создания документа
     */
    return XML_Date;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setDate(QString Date)
{
    /*
     Задание текста переменной  XML_Date - Дата создания документа
     */
    XML_Date = Date;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getEmail()
{
    /*
     Получение текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться
     */
    return XML_Email;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setEmail(QString Email)
{
    /*
     Задание текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться
     */
    XML_Email = Email;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
     */
    return XML_Name_Algorithm;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNameAlgorithm(QString NameAlgorithm)
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
     */
    XML_Name_Algorithm = NameAlgorithm;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFullNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
     */
    return XML_Full_Name_Algorithm;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFullNameAlgorithm(QString FullNameAlgorithm)
{
    /*
     Задание текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
     */
    XML_Full_Name_Algorithm = FullNameAlgorithm;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameTestFunction()
{
    /*
     Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
     */
    return XML_Name_Test_Function;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNameTestFunction(QString NameTestFunction)
{
    /*
     Задание текста переменной  XML_Name_Test_Function - Название тестовой функции
     */
    XML_Name_Test_Function = NameTestFunction;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFullNameTestFunction()
{
    /*
     Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
     */
    return XML_Full_Name_Test_Function;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFullNameTestFunction(QString FullNameTestFunction)
{
    /*
     Задание текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
     */
    XML_Full_Name_Test_Function = FullNameTestFunction;
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getDimensionTestFunction()
{
    /*
     Получение текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи
     */
    return XML_DimensionTestFunction;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setDimensionTestFunction(qint64 DimensionTestFunction)
{
    /*
     Задание текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи
     */
    XML_DimensionTestFunction = DimensionTestFunction;
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfMeasuring()
{
    /*
     Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
     */
    return XML_Number_Of_Measuring;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfMeasuring(qint64 NumberOfMeasuring)
{
    /*
     Задание текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
     */
    XML_Number_Of_Measuring = NumberOfMeasuring;
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfRuns()
{
    /*
     Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
     */
    return XML_Number_Of_Runs;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfRuns(qint64 NumberOfRuns)
{
    /*
     Задание текста переменной  XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
     */
    XML_Number_Of_Runs = NumberOfRuns;
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMaxCountOfFitness()
{
    /*
     Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
     */
    return XML_Max_Count_Of_Fitness;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMaxCountOfFitness(qint64 MaxCountOfFitness)
{
    /*
     Задание текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
     */
    XML_Max_Count_Of_Fitness = MaxCountOfFitness;
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
     */
    //if (Zero_Number_Of_Parameters) return 0; /*ПОСМОТРЕТЬ*/
    return XML_Number_Of_Parameters;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfParameters(qint64 NumberOfParameters)
{
    /*
     Задание текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
     */
    XML_Number_Of_Parameters = NumberOfParameters;/*ПОСМОТРЕТЬ*/
}
//--------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfExperiments()
{
    /*
     Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
     */
    return XML_Number_Of_Experiments;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfExperiments(qint64 NumberOfExperiments)
{
    /*
     Задание текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
     */
    XML_Number_Of_Experiments = NumberOfExperiments;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLinkTestFunction()
{
    /*
     Получение текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции
     */
    return XML_Link_Test_Function;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLinkTestFunction(QString LinkTestFunction)
{
    /*
     Задание текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции
     */
    XML_Link_Test_Function = LinkTestFunction;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLinkAlgorithm()
{
    /*
     Получение текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации
     */
    return XML_Link_Algorithm;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLinkAlgorithm(QString LinkAlgorithm)
{
    /*
     Задание текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации
     */
    XML_Link_Algorithm = LinkAlgorithm;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFormat()
{
    /*
    Получение переменной XML_Format, то есть возвращает название формата документа.
    */
    return XML_Format;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFormat(QString Format)
{
    /*
    Задание переменной XML_Format, то есть возвращает название формата документа.
    */
    XML_Format = Format;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVersion()
{
    /*
    Получение переменной XML_Version, то есть возвращает версию формата документа.
     */
    return XML_Version;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVersion(QString Version)
{
    /*
    Задание переменной XML_Version, то есть возвращает версию формата документа.
     */
    XML_Version = Version;
}
//--------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLink()
{
    /*
    Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.
     */
    return XML_Link;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLink(QString Link)
{
    /*
    Задание переменной XML_Link, то есть возвращает ссылку на описание формата файла.
     */
    XML_Link = Link;
}
//--------------------------------------------------------------------------

bool HarrixClass_OnlyDataOfHarrixOptimizationTesting::getCheckAllCombinations()
{
    /*
     Получение текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1
     */
    return bool(XML_All_Combinations);
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setCheckAllCombinations(bool AllCombinations)
{
    /*
     Задание текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1
     */
    XML_All_Combinations=int(AllCombinations);
}
//--------------------------------------------------------------------------

bool HarrixClass_OnlyDataOfHarrixOptimizationTesting::getSuccessReading()
{
    /*
     Получение текста переменной SuccessReading - Успешно ли прошло считывание
     */
    return SuccessReading;
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setSuccessReading(bool Success)
{
    /*
     Задание текста переменной SuccessReading - Успешно ли прошло считывание
     */
    SuccessReading = Success;
}
//--------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения ошибки Ex.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfEx[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения ошибки Ex.
    Входные параметры:
     ErrorEx - задаваниемое значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfEx[Number_Of_Experiment][Number_Of_Measuring] = ErrorEx;
}
//--------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения ошибки Ey.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfEy[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorEy(double ErrorEy,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения ошибки Ey.
    Входные параметры:
     ErrorEy - задаваниемое значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfEy[Number_Of_Experiment][Number_Of_Measuring] = ErrorEy;
}
//--------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getErrorR(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения надежности R.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfR[Number_Of_Experiment][Number_Of_Measuring];
}
//--------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorR(double ErrorR,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения надежности R.
    Входные параметры:
     ErrorR - задаваниемое значение надежности;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfR[Number_Of_Experiment][Number_Of_Measuring] = ErrorR;
}
//--------------------------------------------------------------------------
