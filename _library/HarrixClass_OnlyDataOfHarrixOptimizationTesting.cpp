//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.26
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixMathLibrary.h"
#include "HarrixClass_OnlyDataOfHarrixOptimizationTesting.h"

//*****************************************************************
//_Конструкторы и деструкторы
//*****************************************************************
HarrixClass_OnlyDataOfHarrixOptimizationTesting::HarrixClass_OnlyDataOfHarrixOptimizationTesting()
{
    /*
    Конструктор. Создает пустой экземпляр.
    Входные параметры:
     Отсутствуют.
 */
    initializationOfVariables();
}
//---------------------------------------------------------------------------

HarrixClass_OnlyDataOfHarrixOptimizationTesting::~HarrixClass_OnlyDataOfHarrixOptimizationTesting()
{
    /*
     Деструктор класса.
     */
    memoryDeallocation();
}
//---------------------------------------------------------------------------


//*****************************************************************
//Возвращение данных из класса
//*****************************************************************
QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getAuthor()
{
    /*
     Получение текста переменной XML_Author - Автор документа.
     */
    return XML_Author;
}
//---------------------------------------------------------------------------

bool HarrixClass_OnlyDataOfHarrixOptimizationTesting::getCheckAllCombinations()
{
    /*
     Получение текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1.
     */
    return bool(XML_All_Combinations);
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getDate()
{
    /*
     Получение текста переменной  XML_Date - Дата создания документа.
     */
    return XML_Date;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getDimensionTestFunction()
{
    /*
     Получение текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи.
     */
    return XML_DimensionTestFunction;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getEmail()
{
    /*
     Получение текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться.
     */
    return XML_Email;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFormat()
{
    /*
    Получение переменной XML_Format, то есть возвращает название формата документа.
    */
    return XML_Format;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFullNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации.
     */
    return XML_Full_Name_Algorithm;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getFullNameTestFunction()
{
    /*
     Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции.
     */
    return XML_Full_Name_Test_Function;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLink()
{
    /*
    Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.
     */
    return XML_Link;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLinkAlgorithm()
{
    /*
     Получение текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации.
     */
    return XML_Link_Algorithm;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getLinkTestFunction()
{
    /*
     Получение текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции.
     */
    return XML_Link_Test_Function;
}
//---------------------------------------------------------------------------

QStringList HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfParameterOptions(int Number_Of_Parameter)
{
    /*
    Получение списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Список вектора названий вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return ListOfParameterOptions[Number_Of_Parameter];
}
//---------------------------------------------------------------------------

QStringList HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfVectorParameterOptions()
{
    /*
    Получение списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Список параметров алгоритма.
     */

    return ListOfVectorParameterOptions;
}
//--------------------------------------------------------------------------
QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfVectorParameterOptions(int Number_Of_Experiment)
{
    /*
    Получение строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Number_Of_Experiment - номер эксперимента.
    Возвращаемое значение:
     Значения строки параметров эксперимента.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return ListOfVectorParameterOptions.at(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMaxCountOfFitness()
{
    /*
     Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма.
     */
    return XML_Max_Count_Of_Fitness;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanEx(int Number_Of_Experiment)
{
    /*
    Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return MeanOfEx[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanEy(int Number_Of_Experiment)
{
    /*
    Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return MeanOfEy[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanOfAllEx()
{
    /*
     Получение значения переменной MeanOfAllEx - среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return MeanOfAllEx;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanOfAllEy()
{
    /*
     Получение значения переменной MeanOfAllEy - среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return MeanOfAllEy;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanOfAllR()
{
    /*
     Получение значения переменной MeanOfAllR - среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return MeanOfAllR;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getMeanR(int Number_Of_Experiment)
{
    /*
    Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return MeanOfR[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации.
     */
    return XML_Name_Algorithm;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameOption(int Number_Of_Parameter)
{
    /*
    Получение имени параметра алгоритма по его номеру.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return NamesOfParameters.at(Number_Of_Parameter);
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Получение значения параметра настройки какой-то в виде полного наименования.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return MatrixOfNameParameters[Number_Of_Experiment].at(Number_Of_Parameter);
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNameTestFunction()
{
    /*
     Получение текста переменной  XML_Name_Test_Function - Название тестовой функции.
     */
    return XML_Name_Test_Function;
}
//---------------------------------------------------------------------------

QStringList HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNamesOfParameters()
{
    /*
    Получение списка параметров алгоритма (тип селекции, тип скрещивания).
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Список параметров алгоритма.
     */
    return NamesOfParameters;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfExperiments()
{
    /*
     Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек.
     */
    return XML_Number_Of_Experiments;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfMeasuring()
{
    /*
     Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения).
     */
    return XML_Number_Of_Measuring;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации.
     */
    //if (Zero_Number_Of_Parameters) return 0; /*ПОСМОТРЕТЬ*/
    return XML_Number_Of_Parameters;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_OnlyDataOfHarrixOptimizationTesting::getNumberOfRuns()
{
    /*
     Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента.
     */
    return XML_Number_Of_Runs;
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option)
{
    /*
    Получение названия вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
     Number_Of_Option - номер считываемой опции у параметра алгоритма оптимизации.
    Возвращаемое значение:
     Название вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return ListOfParameterOptions[Number_Of_Parameter].at(Number_Of_Option);
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getOptionFromListOfParameterOptionsForTable(int Number_Of_Parameter, int Number_Of_Option)
{
    /*
    Получение названия вариантов параметров алгоритма оптимизации. Но старается где-то сокращать, а где-то добавлять строки.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
     Number_Of_Option - номер считываемой опции у параметра алгоритма оптимизации.
    Возвращаемое значение:
     Название вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    QString Result=ListOfParameterOptions[Number_Of_Parameter].at(Number_Of_Option);

    if (!HQt_IsNumeric(Result))
    {
        if (Result.length()>=5)
            Result = HQt_TryingReduceString(Result,40);
        else
        {
            Result = HQt_TryingReduceString(Result,40);

            QString NameOption = getNameOption(Number_Of_Parameter);
            NameOption = HQt_TryingReduceString(NameOption,40-3-Result.length());
            Result=NameOption + " = " + Result;
        }
    }
    else
    {
        QString NameOption = getNameOption(Number_Of_Parameter);
        NameOption = HQt_TryingReduceString(NameOption,40-3-Result.length());
        Result=NameOption + " = " + Result;
    }

    return Result;
}
//---------------------------------------------------------------------------

int HarrixClass_OnlyDataOfHarrixOptimizationTesting::getParameter(int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Получение значения параметра настройки какой-то.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде числа (соответствие находим в ListOfParameterOptions).
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return MatrixOfParameters[Number_Of_Experiment][Number_Of_Parameter];
}
//---------------------------------------------------------------------------

bool HarrixClass_OnlyDataOfHarrixOptimizationTesting::getSuccessReading()
{
    /*
     Получение текста переменной SuccessReading - Успешно ли прошло считывание.
     */
    return SuccessReading;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfAllEx()
{
    /*
     Получение значения переменной VarianceOfAllEx - дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return VarianceOfAllEx;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfAllEy()
{
    /*
     Получение значения переменной VarianceOfAllEy - дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return VarianceOfAllEy;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfAllR()
{
    /*
     Получение значения переменной VarianceOfAllR - дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    return VarianceOfAllR;
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfEx(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return VarianceOfEx[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfEy(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return VarianceOfEy[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVarianceOfR(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return VarianceOfR[Number_Of_Experiment];
}
//---------------------------------------------------------------------------

QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getVersion()
{
    /*
    Получение переменной XML_Version, то есть возвращает версию формата документа.
     */
    return XML_Version;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Задание данных в класс
//*****************************************************************
void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addListOfParameterOptions(QString Option, int Number_Of_Parameter)
{
    /*
    Добавление списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Option - добавляемое название варианта параметра алгоритма.
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    ListOfParameterOptions[Number_Of_Parameter]<<Option;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addListOfVectorParameterOptions(QString Option)
{
    /*
    Добавление строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Option - добавляемая строка.
    Возвращаемое значение:
     Отсутствует.
     */
    ListOfVectorParameterOptions<<Option;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addNameOption(QString Option)
{
    /*
    Добавление имени параметра алгоритма.
    Входные параметры:
     Option - имени параметра алгоритма.
    Возвращаемое значение:
     Отсутствует.
     */
    NamesOfParameters<<Option;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addNameParameter(QString Name, int Number_Of_Experiment)
{
    /*
    Получение значения параметра настройки какой-то в виде полного наименования.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    MatrixOfNameParameters[Number_Of_Experiment] <<Name;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setAuthor(QString Author)
{
    /*
     Задание текста переменной XML_Author - Автор документа.
     */
    XML_Author = Author;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setCheckAllCombinations(bool AllCombinations)
{
    /*
     Задание текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1.
     */
    XML_All_Combinations=int(AllCombinations);
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setDate(QString Date)
{
    /*
     Задание текста переменной  XML_Date - Дата создания документа.
     */
    XML_Date = Date;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setDimensionTestFunction(qint64 DimensionTestFunction)
{
    /*
     Задание текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи.
     */
    XML_DimensionTestFunction = DimensionTestFunction;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setEmail(QString Email)
{
    /*
     Задание текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться.
     */
    XML_Email = Email;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения ошибки Ex.
    Входные параметры:
     ErrorEx - задаваемое значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfEx[Number_Of_Experiment][Number_Of_Measuring] = ErrorEx;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorEy(double ErrorEy,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения ошибки Ey.
    Входные параметры:
     ErrorEy - задаваемое значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfEy[Number_Of_Experiment][Number_Of_Measuring] = ErrorEy;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorR(double ErrorR,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения надежности R.
    Входные параметры:
     ErrorR - задаваемое значение надежности;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfR[Number_Of_Experiment][Number_Of_Measuring] = ErrorR;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFormat(QString Format)
{
    /*
	Задание переменной XML_Format - название формата документа.
    */
    XML_Format = Format;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFullNameAlgorithm(QString FullNameAlgorithm)
{
    /*
     Задание текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации.
     */
    XML_Full_Name_Algorithm = FullNameAlgorithm;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setFullNameTestFunction(QString FullNameTestFunction)
{
    /*
     Задание текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции.
     */
    XML_Full_Name_Test_Function = FullNameTestFunction;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLink(QString Link)
{
    /*
	Задание переменной XML_Link - ссылка на описание формата файла.
     */
    XML_Link = Link;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLinkAlgorithm(QString LinkAlgorithm)
{
    /*
     Задание текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации.
     */
    XML_Link_Algorithm = LinkAlgorithm;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setLinkTestFunction(QString LinkTestFunction)
{
    /*
     Задание текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции.
     */
    XML_Link_Test_Function = LinkTestFunction;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setListOfParameterOptions(QStringList List, int Number_Of_Parameter)
{
    /*
    Задание списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     List - список названий параметров, которым будем заменять текущий список.
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    ListOfParameterOptions[Number_Of_Parameter] = List;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMaxCountOfFitness(qint64 MaxCountOfFitness)
{
    /*
     Задание текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма.
     */
    XML_Max_Count_Of_Fitness = MaxCountOfFitness;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanEx(double MeanEx, int Number_Of_Experiment)
{
    /*
    Задание среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     MeanEx - значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    MeanOfEx[Number_Of_Experiment] = MeanEx;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanEy(double MeanEy, int Number_Of_Experiment)
{
    /*
    Задание среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     MeanEy - значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    MeanOfEy[Number_Of_Experiment] = MeanEy;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanOfAllEx(double Mean)
{
    /*
     Задание значения переменной MeanOfAllEx - среднее значение ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    MeanOfAllEx = Mean;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanOfAllEy(double Mean)
{
    /*
     Задание значения переменной MeanOfAllEy - среднее значение ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    MeanOfAllEy = Mean;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanOfAllR(double Mean)
{
    /*
     Задание значения переменной MeanOfAllR - среднее значение надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    MeanOfAllR = Mean;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setMeanR(double MeanR, int Number_Of_Experiment)
{
    /*
    Задание среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     MeanR - значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    MeanOfR[Number_Of_Experiment] = MeanR;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNameAlgorithm(QString NameAlgorithm)
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации.
     */
    XML_Name_Algorithm = NameAlgorithm;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNameTestFunction(QString NameTestFunction)
{
    /*
     Задание текста переменной  XML_Name_Test_Function - Название тестовой функции.
     */
    XML_Name_Test_Function = NameTestFunction;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfExperiments(qint64 NumberOfExperiments)
{
    /*
     Задание текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек.
     */
    XML_Number_Of_Experiments = NumberOfExperiments;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfListOfVectorParameterOptions(double Num,int Number)
{
    /*
    Задание значения элемента массива NumberOfListOfVectorParameterOptions.
	Входные параметры:
     Num - значение элемента;
     Number - номер элемента.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    NumberOfListOfVectorParameterOptions[Number] = Num;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfMeasuring(qint64 NumberOfMeasuring)
{
    /*
     Задание текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения).
     */
    XML_Number_Of_Measuring = NumberOfMeasuring;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfParameters(qint64 NumberOfParameters)
{
    /*
     Задание текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации.
     */
    XML_Number_Of_Parameters = NumberOfParameters;/*ПОСМОТРЕТЬ*/
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setNumberOfRuns(qint64 NumberOfRuns)
{
    /*
     Задание текста переменной  XML_Number_Of_Runs - Количество прогонов по которому делается усреднение для эксперимента.
     */
    XML_Number_Of_Runs = NumberOfRuns;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Задание значения параметра настройки какой-то.
    Входные параметры:
	 Parameter - значение параметра в виде числа;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    MatrixOfParameters[Number_Of_Experiment][Number_Of_Parameter] = Parameter;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setSuccessReading(bool Success)
{
    /*
     Задание текста переменной SuccessReading - Успешно ли прошло считывание.
     */
    SuccessReading = Success;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfAllEx(double Variance)
{
    /*
     Задание значения переменной VarianceOfAllEx - дисперсия ошибок Ex алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    VarianceOfAllEx = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfAllEy(double Variance)
{
    /*
     Задание значения переменной VarianceOfAllEy - дисперсия ошибок Ey алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    VarianceOfAllEy = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfAllR(double Variance)
{
    /*
     Задание значения переменной VarianceOfAllR - дисперсия надежностей R алгоритма оптимизации по измерениям по всем измерениям вообще.
     */
    VarianceOfAllR = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfEx(double Variance, int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
	 Variance - значение заносимой дисперсии;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    VarianceOfEx[Number_Of_Experiment] = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfEy(double Variance, int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
	 Variance - значение заносимой дисперсии;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    VarianceOfEy[Number_Of_Experiment] = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfR(double Variance, int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
	 Variance - значение заносимой дисперсии;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    VarianceOfR[Number_Of_Experiment] = Variance;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVersion(QString Version)
{
    /*
	Задание переменной XML_Version --- версия формата документа.
     */
    XML_Version = Version;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Операторы
//*****************************************************************
void HarrixClass_OnlyDataOfHarrixOptimizationTesting::operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B)
{
    //Вначале уничтожим все массивы если они были.
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

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            for (int j=0;j<XML_Number_Of_Parameters;j++)
            {
                MatrixOfParameters[i][j]=B.MatrixOfParameters[i][j];
            }

        NamesOfParameters=B.NamesOfParameters;

        for (int i=0;i<XML_Number_Of_Parameters;i++)
            ListOfParameterOptions[i]= B.ListOfParameterOptions[i];

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            NumberOfListOfVectorParameterOptions[i]= B.NumberOfListOfVectorParameterOptions[i];

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            MatrixOfNameParameters[i]= B.MatrixOfNameParameters[i];

        ListOfVectorParameterOptions = B.ListOfVectorParameterOptions;

        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEx[i]=B.MeanOfEx[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEy[i]=B.MeanOfEy[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfR [i]=B.MeanOfR [i];

        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEx[i]=B.VarianceOfEx[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEy[i]=B.VarianceOfEy[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfR [i]=B.VarianceOfR [i];

        MeanOfAllEx=B.MeanOfAllEx;
        MeanOfAllEy=B.MeanOfAllEy;
        MeanOfAllR=B.MeanOfAllR;
        VarianceOfAllR=B.VarianceOfAllR;
        VarianceOfAllEx=B.VarianceOfAllEx;
        VarianceOfAllEy=B.VarianceOfAllEy;
    }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Служебные функции
//*****************************************************************
void HarrixClass_OnlyDataOfHarrixOptimizationTesting::initializationOfVariables()
{
    /*
    Обнуление переменных. Внутренняя функция.
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
    NamesOfParameters.clear();
    ListOfVectorParameterOptions.clear();

    MeanOfAllEx=0;
    MeanOfAllEy=0;
    MeanOfAllR=0;
    VarianceOfAllR=0;
    VarianceOfAllEx=0;
    VarianceOfAllEy=0;
}
//---------------------------------------------------------------------------

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
    HML_FillMatrix(MatrixOfEx, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEy=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEy[i]=new double[XML_Number_Of_Measuring];
    HML_FillMatrix(MatrixOfEy, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений надежностей R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfR=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfR[i]=new double[XML_Number_Of_Measuring];
    HML_FillMatrix(MatrixOfR, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfParameters=new int*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfParameters[i]=new int[XML_Number_Of_Parameters];
    HML_FillMatrix(MatrixOfParameters, XML_Number_Of_Experiments, XML_Number_Of_Parameters, -1);

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружения новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в ListOfParameterOptions
    //находится под номером соответствующим.
    ListOfParameterOptions=new QStringList[XML_Number_Of_Parameters];
    for (int i=0;i<XML_Number_Of_Parameters;i++) ListOfParameterOptions[i].clear();

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfNameParameters=new QStringList[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfNameParameters[i].clear();

    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до XML_Number_Of_Experiments
    NumberOfListOfVectorParameterOptions=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++)
        NumberOfListOfVectorParameterOptions[i]=i+1;

    //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEx=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEx[i]=0;

    //Вектор средних ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEy=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEy[i]=0;

    //Вектор средних надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfR=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfR[i]=0;

    //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEx=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEx[i]=0;

    //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEy=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEy[i]=0;

    //Вектор дисперсий надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfR=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfR[i]=0;
}
//---------------------------------------------------------------------------

void HarrixClass_OnlyDataOfHarrixOptimizationTesting::memoryDeallocation()
{
    /*
    Удаляет память из-под массивов. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (SuccessReading)
    {
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEx[i];
        delete [] MatrixOfEx;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEy[i];
        delete [] MatrixOfEy;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfR[i];
        delete [] MatrixOfR;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfParameters[i];
        delete [] MatrixOfParameters;
        delete [] ListOfParameterOptions;
        delete [] NumberOfListOfVectorParameterOptions;
        delete [] MatrixOfNameParameters;
        delete [] MeanOfEx;
        delete [] MeanOfEy;
        delete [] MeanOfR;
        delete [] VarianceOfEx;
        delete [] VarianceOfEy;
        delete [] VarianceOfR;
    }
}
//---------------------------------------------------------------------------