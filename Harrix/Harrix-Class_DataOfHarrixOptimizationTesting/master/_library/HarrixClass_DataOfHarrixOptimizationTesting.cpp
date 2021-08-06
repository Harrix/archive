//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.26
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include <QVector>

#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixMathLibrary.h"
#include "HarrixClass_DataOfHarrixOptimizationTesting.h"
#include "HarrixClass_OnlyDataOfHarrixOptimizationTesting.h"
#include "Functions_For_HarrixClass_DataOfHarrixOptimizationTesting.h"

//*****************************************************************
//_Конструкторы и деструкторы
//*****************************************************************
HarrixClass_DataOfHarrixOptimizationTesting::HarrixClass_DataOfHarrixOptimizationTesting(QString filename)
{
    /*
    Конструктор. Функция считывает данные о тестировании алгоритма оптимизации
    из файла формата HarrixOptimizationTesting.
    Входные параметры:
     filename - полное имя считываемого файла.
 */
    initializationOfVariables();

    if (!HQt_FileExists(filename))
    {
        if (filename.isEmpty())
            HtmlMessageOfError+=HQt_ShowAlert("Это пустой экземпляр класса");
        else
            HtmlMessageOfError+=HQt_ShowAlert("Файл "+HQt_GetFilenameFromFullFilename(filename)+" не открывается");
        Error=true;
    }
    else
    {
        Html+=HQt_ShowText("Файл <font color=\"#00b400\">"+HQt_GetFilenameFromFullFilename(filename)+"</font> загружен");

        //Первоначальные действия
        try
        {
            FileXML=HQt_ReadFile(filename);
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Файл не был прочитан.");
            Error=true;
        }

        try
        {
            Rxml.addData(FileXML);
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Не смогли добавить содержимое в экземпляр QXmlStreamReader.");
            Error=true;
        }

        try
        {
            readXml();//считывание XML файла и все остальные анализы запускаются в этой функцииcatch (...)
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Считывание XML файла прошло с ошибками.");
            Error=true;
        }
    }
}
//--------------------------------------------------------------------------
HarrixClass_DataOfHarrixOptimizationTesting::HarrixClass_DataOfHarrixOptimizationTesting()
{
    /*
    Конструктор. Создает пустой экземпляр.
    Входные параметры:
     Отсутствуют.
 */
    HarrixClass_DataOfHarrixOptimizationTesting("");
}
//---------------------------------------------------------------------------

HarrixClass_DataOfHarrixOptimizationTesting::~HarrixClass_DataOfHarrixOptimizationTesting()
{
    /*
     Деструктор класса.
     */
    memoryDeallocation();
}
//---------------------------------------------------------------------------


//*****************************************************************
//Возвращение HTML данных из класса
//*****************************************************************
QString HarrixClass_DataOfHarrixOptimizationTesting::getHtml()
{
    /*
     Получение текста переменной Html. Это итоговый Html документ.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return Html;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getHtmlMessageOfError()
{
    /*
     Получение текста переменной HtmlMessageOfError. Это часть html документа в виде кода о сообщениях ошибок.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return HtmlMessageOfError;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getHtmlReport()
{
    /*
     Получение текста переменной HtmlReport. Это часть html документа в виде отчета о проделанной работе.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return HtmlReport;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Возвращение LaTeX данных из класса
//*****************************************************************
QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatex()
{
    /*
     Получение текста переменной Latex в полном составе с началом и концовкой в Latex файле.
     Здесь собран полный файл анализа данных из считываемого xml файла.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + Latex + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexAboutParameters()
{
    /*
     Получение текста переменной LatexAboutParameters - отображение данных о обнаруженных параметрах алгоритма и какие они бывают с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexAboutParameters + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexAnalysis()
{
    /*
     Получение текста переменной LatexAnalysis - отображение данных первоначального анализа данных.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexInfo + LatexAboutParameters + LatexListOfVectorParameterOptions + LatexAnalysis + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexInfo()
{
    /*
     Получение текста переменной LatexInfo - отображение информации о исследовании с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexInfo + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTable()
{
    /*
     Получение текста переменной LatexTable в полном составе с началом и концовкой в Latex файле.
     Здесь собран полный файл первичных данных из считываемого xml файла (без анализа).
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTable + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTableEx()
{
    /*
     Получение текста переменной LatexTableEx - отображение сырых данных таблицы данных о ошибке Ex с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTableEx + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTableEy()
{
    /*
     Получение текста переменной LatexTableEy - отображение сырых данных таблицы данных о ошибке Ey с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTableEy + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTableR()
{
    /*
     Получение текста переменной LatexTableR - отображение сырых данных по надежности в виде полной таблицы с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTableR + getLatexEnd();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatex()
{
    /*
     Получение текста переменной Latex.
     Здесь собран полный файл анализа данных из считываемого xml файла.
     Помните, что это не полноценный Latex код. Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return Latex;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexAboutParameters()
{
    /*
     Получение текста переменной LatexAboutParameters - отображение данных о обнаруженных параметрах алгоритма и какие они бывают.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexAboutParameters;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexAnalysis()
{
    /*
     Получение текста переменной LatexAnalysis - отображение первоначального анализа данных.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexAboutParameters+LatexListOfVectorParameterOptions+LatexAnalysis;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexInfo()
{
    /*
     Получение текста переменной LatexInfo - отображение информации о исследовании.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexInfo;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexTable()
{
    /*
     Получение текста переменной LatexTable.
     Здесь собран полный файл первичных данных из считываемого xml файла (без анализа).
     Помните, что это не полноценный Latex код. Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTable;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexTableEx()
{
    /*
     Получение текста переменной LatexTableEx - отображение сырых данных таблицы данных о ошибке Ex.
     Помните, что это не полноценный Latex код. Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableEx;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexTableEy()
{
    /*
     Получение текста переменной LatexTableEy - отображение сырых данных ошибки по значениям целевой функции в виде полной таблицы.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableEy;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexTableR()
{
    /*
     Получение текста переменной LatexTableR - отображение сырых данных по надежности в виде полной таблицы.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableR;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Возвращение переменных из класса
//*****************************************************************
QString HarrixClass_DataOfHarrixOptimizationTesting::getAuthor()
{
    /*
     Получение текста переменной XML_Author - Автор документа.
     */
    return Data.getAuthor();
}
//---------------------------------------------------------------------------

bool HarrixClass_DataOfHarrixOptimizationTesting::getCheckAllCombinations()
{
    /*
     Получение текста переменной  XML_All_Combinations - Все ли комбинации вариантов настроек просмотрены: 0 или 1.
     */
    return bool(Data.getCheckAllCombinations());
}
//---------------------------------------------------------------------------

HarrixClass_OnlyDataOfHarrixOptimizationTesting& HarrixClass_DataOfHarrixOptimizationTesting::getData()
{
    /*
     Возвращает содержимое исследований в виде экземпляра класса.
     */
    return Data;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getDate()
{
    /*
     Получение текста переменной  XML_Date - Дата создания документа.
     */
    return Data.getDate();
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getDimensionTestFunction()
{
    /*
     Получение текста переменной  XML_DimensionTestFunction - Размерность тестовой задачи.
     */
    return Data.getDimensionTestFunction();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getEmail()
{
    /*
     Получение текста переменной  XML_Email - Email автора, чтобы можно было с ним связаться.
     */
    return Data.getEmail();
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring)
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
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>Data.getNumberOfMeasuring()-1) Number_Of_Measuring=Data.getNumberOfMeasuring()-1;

    return Data.getErrorEx(Number_Of_Experiment,Number_Of_Measuring);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring)
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
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>Data.getNumberOfMeasuring()-1) Number_Of_Measuring=Data.getNumberOfMeasuring()-1;

    return Data.getErrorEy(Number_Of_Experiment,Number_Of_Measuring);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getErrorR(int Number_Of_Experiment, int Number_Of_Measuring)
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
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>Data.getNumberOfMeasuring()-1) Number_Of_Measuring=Data.getNumberOfMeasuring()-1;

    return Data.getErrorR(Number_Of_Experiment,Number_Of_Measuring);
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFormat()
{
    /*
    Получение переменной XML_Format, то есть возвращает название формата документа.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "Harrix Optimization Testing".
     */

    return Data.getFormat();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации.
     */
    return Data.getFullNameAlgorithm();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getFullNameTestFunction()
{
    /*
     Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции.
     */
    return Data.getFullNameTestFunction();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLink()
{
    /*
    Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "https://github.com/Harrix/HarrixFileFormats".
     */

    return Data.getLink();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLinkAlgorithm()
{
    /*
     Получение текста переменной  XML_Link_Algorithm - Ссылка на описание алгоритма оптимизации.
     */
    return Data.getLinkAlgorithm();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLinkTestFunction()
{
    /*
     Получение текста переменной  XML_Link_Test_Function - Ссылка на описание тестовой функции.
     */
    return Data.getLinkTestFunction();
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getMaxCountOfFitness()
{
    /*
     Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
     */
    return Data.getMaxCountOfFitness();
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getMeanEx(int Number_Of_Experiment)
{
    /*
    Получение среднего значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getMeanEx(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getMeanEy(int Number_Of_Experiment)
{
    /*
    Получение среднего значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getMeanEy(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getMeanR(int Number_Of_Experiment)
{
    /*
    Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getMeanR(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации.
     */
    return Data.getNameAlgorithm();
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter)
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
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>Data.getNumberOfParameters()-1) Number_Of_Parameter=Data.getNumberOfParameters()-1;

    return Data.getNameParameter(Number_Of_Experiment,Number_Of_Parameter);
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getNameTestFunction()
{
    /*
     Получение текста переменной  XML_Name_Test_Function - Название тестовой функции.
     */
    return Data.getNameTestFunction();
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfExperiments()
{
    /*
     Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек.
     */
    return Data.getNumberOfExperiments();
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfMeasuring()
{
    /*
     Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения).
     */
    return Data.getNumberOfMeasuring();
}
//---------------------------------------------------------------------------

int HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfOption(QString NameOption)
{
    /*
    Получение номера параметра алгоритма по его имени.
    Входные параметры:
     NameOption - имя параметра.
    Возвращаемое значение:
     Значения параметра в виде номера (если не найдено, то возвращается -1.
     */
    int VHML_Result=-1;

    VHML_Result = HQt_SearchQStringInQStringList (Data.getNamesOfParameters(), NameOption);

    return VHML_Result;
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации.
     */
    if (Zero_Number_Of_Parameters) return 0;
    return Data.getNumberOfParameters();
}
//---------------------------------------------------------------------------

qint64 HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfRuns()
{
    /*
     Получение текста переменной  XML_Number_Of_Runs - Количество прогонов, по которому делается усреднение для эксперимента.
     */
    return Data.getNumberOfRuns();
}
//---------------------------------------------------------------------------

int HarrixClass_DataOfHarrixOptimizationTesting::getParameter(int Number_Of_Experiment, int Number_Of_Parameter)
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
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>Data.getNumberOfParameters()-1) Number_Of_Parameter=Data.getNumberOfParameters()-1;

    return Data.getParameter(Number_Of_Experiment,Number_Of_Parameter);
}
//---------------------------------------------------------------------------

bool HarrixClass_DataOfHarrixOptimizationTesting::getSuccessReading()
{
    /*
    Получение значения переменной SuccessReading о удачности или не удачности считывания файла.
     */
    return Data.getSuccessReading();
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getVarianceOfEx(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения Ex.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getVarianceOfEx(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getVarianceOfEy(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ey по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getVarianceOfEy(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

double HarrixClass_DataOfHarrixOptimizationTesting::getVarianceOfR(int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения дисперсии значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    return Data.getVarianceOfR(Number_Of_Experiment);
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getVersion()
{
    /*
    Получение переменной XML_Version, то есть возвращает версию формата документа.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "1.0".
     */

    return Data.getVersion();
}
//---------------------------------------------------------------------------


//*****************************************************************
//Операторы
//*****************************************************************
void HarrixClass_DataOfHarrixOptimizationTesting::operator = (HarrixClass_DataOfHarrixOptimizationTesting& B)
{
    //Вначале уничтожим все массивы если они были.
    memoryDeallocation();

    initializationOfVariables();

    FileXML=B.FileXML;

    if (FileXML.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Это пустой экземпляр класса");
        Error=true;
    }
    else
    {
        Rxml.addData(FileXML);

        readXml();//считывание XML файла и все остальные анализы запускаются в этой функции

        Html+=HQt_ShowText("Экземпляр скопирован");
    }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Специализированные функции
//*****************************************************************
QString HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTable2D(QString Title, QStringList InfoForEveryExperiment)
{
    /*
    Создает текст LaTeX в виде таблицы 2D для всех экспериментов для отображения какой-нибудь информации.
    Входные параметры:
     Title - заголовок таблицы;
     InfoForEvryExperiment - информация выдаваемая в таблицу.
    Возвращаемое значение:
     Итоговая таблица в виде кода Latex.
     */
    QString Table;

    ////////////////////////////////////////////////////////
    //// ОПРЕДЕЛИМ В КАКОМ ПОРЯДКЕ И ГДЕ БУДУТ ИДТИ СТОЛБЦЫ
    ////////////////////////////////////////////////////////
    //Сколько у нас вообще параметров
    int NumberOfParametersTemp = getNumberOfParameters();

    if (NumberOfParametersTemp>0)
    {
        //массив для числа каждого параметры
        int *CountOfParametersTemp = new int [NumberOfParametersTemp];
        for (int i=0;i<NumberOfParametersTemp; i++)
            CountOfParametersTemp[i]=Data.getListOfParameterOptions(i).count();
        //в каком порядке будем располагать
        int *Order = new int [NumberOfParametersTemp];

        //Определим сколько параметров пойдет на столбцы, а сколько на строки
        int Limit=10;//сколько максимум столбцов с данными
        //сколько параметров будет в виде столбов
        int ForColsN = HML_SeparateVectorLimitOnProductElementsTwo(CountOfParametersTemp, Order, Limit, NumberOfParametersTemp);
        if (ForColsN==-1)
        {
            //Если слишком много элементов в каждом варианте, то берем самый маленький и только один
            //Пусть коряво будет, но хоть что-то будет
            HML_ReverseVector(Order,NumberOfParametersTemp);
            ForColsN = 1;
        }
        //А если все параметры решились по верхней части разместиться? Хотя бы один сместим на вертикальную часть
        if (ForColsN==NumberOfParametersTemp)
        {
            ForColsN--;
        }


        //Во второй части массива Order элементы расположим по длине текста
        int *CountForSubOrder = new int[NumberOfParametersTemp-ForColsN];
        int *SubOrder = new int[NumberOfParametersTemp-ForColsN];
        for (int i=0;i<NumberOfParametersTemp-ForColsN;i++)
        {
            SubOrder[i] = Order[i+ForColsN];
            CountForSubOrder[i] = Data.getOptionFromListOfParameterOptionsForTable(Order[i+ForColsN],0).length();
            for (int j=0;j<CountOfParametersTemp[Order[i+ForColsN]];j++)
            {
                QString Temp = Data.getOptionFromListOfParameterOptionsForTable(Order[i+ForColsN],j);
                if (Temp.length()>CountForSubOrder[i]) CountForSubOrder[i] = Temp.length();
            }
        }
        HML_BubbleSortWithConjugateVector(CountForSubOrder, SubOrder, NumberOfParametersTemp-ForColsN);
        for (int i=0;i<NumberOfParametersTemp-ForColsN;i++)
        {
            Order[i+ForColsN]=SubOrder[i];
        }
        delete [] CountForSubOrder;
        delete [] SubOrder;

        //Число столбов для контента
        int ColsForContent=1;
        for (int i=0;i<ForColsN;i++)
            ColsForContent*=Data.getListOfParameterOptions(Order[i]).count();

        //Число строк для контента
        int RowsForContent=1;
        for (int i=ForColsN;i<NumberOfParametersTemp;i++)
            RowsForContent*=Data.getListOfParameterOptions(Order[i]).count();

        //Число столбов для заголовков (слева)
        int ColsForHeader=NumberOfParametersTemp-ForColsN;
        //Число строк для заголовков (наверху)
        int RowsForHeader=ForColsN;

        ////////////////////////////////////////////////////////
        //// РИСУЕМ ВЕРХНИЕ ЗАГОЛОВКИ
        ////////////////////////////////////////////////////////
        //Начинаем отрисовывать таблицу
        Table+="\\begin{center}\n";
        Table+="{\n";
        Table+="\\renewcommand{\\arraystretch}{2}\n";

        double WidthCol=1./double(ColsForHeader+ColsForContent);

        Table+="\\tiny\n\\begin{longtable}[H]{";
        for (int i=0;i<ColsForHeader;i++)
        {
            QString Type="p";
            //if (i==ColsForHeader-1) Type="m";
            Table+="|"+Type+"{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}";
        }
        for (int i=0;i<ColsForContent;i++)
            Table+="|p{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}";
        Table+="|}\n";

        Table+="\\caption{"+Title+"}\n";

        int TempC=Data.getListOfParameterOptions(Order[0]).count();
        for (int j=0;j<RowsForHeader;j++)
        {
            Table+="\\tabularnewline\\cline{"+QString::number(ColsForHeader+1)+"-"+QString::number(ColsForContent+ColsForHeader)+"}\n";
            Table+="\\multicolumn{"+QString::number(ColsForHeader)+"}{c|} {\\centering \\textbf{ }} & ";

            for (int i=0;i<TempC;i++)
            {
                QString Amper;
                if (i!=TempC-1)
                    Amper=" & ";

                //Получим название настройки алгоритма оптимизации
                QString Text=HQt_ForcedWordWrap(Data.getOptionFromListOfParameterOptionsForTable(Order[j],i%(Data.getListOfParameterOptions(Order[j]).count())));

                if (j!=RowsForHeader-1)
                    Table+="\\multicolumn{"+QString::number(ColsForContent/TempC)+"}{c|} {\\centering \\textbf{"+Text+"}}"+Amper;
                else
                    Table+="\\multicolumn{"+QString::number(ColsForContent/TempC)+"}{p{\\dimexpr"+QString::number(WidthCol)+"\\linewidth-2\\tabcolsep}|} {\\centering \\textbf{"+Text+"}}"+Amper;
            }
            Table+="\n";
            TempC*=Data.getListOfParameterOptions(Order[j+1]).count();
        }

        Table+="\\tabularnewline\\hline\n";
        Table+="\\endhead\n";

        ////////////////////////////////////////////////////////
        //// ПОБОЧНЫЕ ДЕЙСТВИЯ С ТАБЛИЦЕЙ
        ////////////////////////////////////////////////////////

        //Оформляем «Продолжение следует», если не всё впорядке пойдет.
        Table+="\\hline\n\\multicolumn{"+QString::number(ColsForHeader+ColsForContent)+"}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
        Table+="\\endlastfoot\n";

        ////////////////////////////////////////////////////////
        //// ОСНОВОЕ ТЕЛО ТАБЛИЦЫ
        ////////////////////////////////////////////////////////

        int *WhatOptionInRow = new int [ColsForHeader];
        HML_FillVector(WhatOptionInRow,ColsForHeader,-1);

        int *WhatOptionInCol = new int [RowsForHeader];

        //Основное тело таблицы
        for (int j=0;j<RowsForContent;j++)
        {
            QString Row;
            //Заголовки слева

            ////////////////////////////////////////////////////////
            //// ЗАГОЛОВКИ СЛЕВА
            ////////////////////////////////////////////////////////

            //получим число всех вариантов настроек, отображаемых слева
            TempC=1;
            for (int i=0;i<ColsForHeader;i++)
                TempC*=Data.getListOfParameterOptions(Order[ForColsN+i]).count();

            int k=-1;//C какого номера на данной ячеейке начинать рисовать горизонтальную линию
            bool kDo=false;//значит, что еще не решали будет линия или нет
            for (int i=0;i<ColsForHeader;i++)
            {
                int uc=Data.getListOfParameterOptions(Order[ForColsN+i]).count();
                TempC = TempC/uc;
                int OO=j%TempC;
                if (OO==0)
                {
                    WhatOptionInRow[i]++;
                    if (WhatOptionInRow[i]==Data.getListOfParameterOptions(Order[ForColsN+i]).count())
                    {
                        WhatOptionInRow[i]=0;
                    }

                    QString Text=HQt_ForcedWordWrap(Data.getOptionFromListOfParameterOptionsForTable(Order[ForColsN+i],WhatOptionInRow[i]));

                    int dt;
                    dt=7.75*TempC;
                    if (i==ColsForHeader-1) dt=12.5*TempC;
                    //["+QString::number(dt)+"pt]

                    Row+="\\centering \\textbf{"+Text+"} & ";

                    //                if (TempC!=1)
                    //                    Row+="\\multirow{"+QString::number(TempC)+"}{\\linewidth}{\\centering \\textbf{"+Text+"}} & ";
                    //                else
                    //                    Row+="\\centering \\textbf{"+Text+"} & ";
                }
                else
                {
                    Row+=" & ";
                    if (OO==TempC-1)
                    {
                        if (kDo==false)
                        {
                            k=i+1;
                            kDo=true;
                        }
                    }
                }
            }
            if (k==-1) k=ColsForHeader;


            ////////////////////////////////////////////////////////
            //// ОСНОВНЫЕ ЯЧЕЙКИ
            ////////////////////////////////////////////////////////

            //Основное содержание
            HML_FillVector(WhatOptionInCol,RowsForHeader,-1);
            for (int i=0;i<ColsForContent;i++)
            {
                // i - номер столбца
                // j - номер строки
                //WhatOptionInRow[i] - номер i параметра по столбцам слева

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЯЕМ КАКИЕ ПАРАМЕТРЫ ПО СТОЛБЦАМ ИДУТ
                ////////////////////////////////////////////////////////
                {//Определяем какие параметры по столбцам идут
                    int TempC=Data.getListOfParameterOptions(Order[0]).count();
                    for (int k=0;k<RowsForHeader;k++)
                    {
                        int ii=0;
                        int wo;
                        for (int p=0;p<TempC;p++)
                        {
                            wo=p%(Data.getListOfParameterOptions(Order[k]).count());

                            for (int h=0;h<ColsForContent/TempC;h++)
                            {
                                if (ii==i)
                                {
                                    WhatOptionInCol[k]=wo;
                                }
                                ii++;
                            }
                        }
                        TempC*=Data.getListOfParameterOptions(Order[k+1]).count();
                    }
                }//Определяем какие параметры по столбцам идут

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА
                ////////////////////////////////////////////////////////
                int NumberExperimentInCell=-1;
                {//ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА
                    // i - номер столбца
                    // j - номер строки

                    for (int p=0;p<Data.getNumberOfExperiments();p++)
                    {
                        bool find=true;
                        for (int k=0;k<ForColsN;k++)
                        {
                            if (WhatOptionInCol[k]!=Data.getParameter(p,Order[k]))
                                find=false;
                        }
                        for (int k=ForColsN;k<Data.getNumberOfParameters();k++)
                        {
                            if (WhatOptionInRow[k-ForColsN]!=Data.getParameter(p,Order[k]))
                                find=false;
                        }
                        if (find)
                        {
                            NumberExperimentInCell=p;
                        }
                    }

                    // NumberExperimentInCell -  теперь тут номер хранится
                }//ОПРЕДЕЛЕНИЕ НОМЕРА ЭКПЕРИМЕНТА

                ////////////////////////////////////////////////////////
                //// ОПРЕДЕЛЕНИЕ СОДЕРЖИМОГО ЯЧЕЙКИ
                ////////////////////////////////////////////////////////

                QString Content;

                Content = "\\centering " + InfoForEveryExperiment.at(NumberExperimentInCell);

                //Добавляем разделитель между ячейками
                QString Amper;
                if (i!=ColsForContent-1)
                    Amper=" & ";
                Row+=Content+Amper;

            }

            Row+="\\tabularnewline \\cline{"+QString::number(k)+"-"+QString::number(ColsForContent+ColsForHeader)+"}\n";
            Table+=Row;
        }

        Table+="\\end{longtable}\n";
        Table+="}\n";
        Table+="\\end{center}\n\n";


        delete [] CountOfParametersTemp;
        delete [] Order;
        delete [] WhatOptionInRow;
        delete [] WhatOptionInCol;
    }
    else
    {
    //Настраиваемых парметров у алгоритма нет, так что и ничего добавлять в таблицу
    }

    return Table;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Внутренние функции
//*****************************************************************
void HarrixClass_DataOfHarrixOptimizationTesting::checkXmlLeafTags()
{
    /*
    Проверяет наличие тэгов и правильное их выполнение. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Data.getFormat()!="Harrix Optimization Testing")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный формат данных. Это не Harrix Optimization Testing.");
        Error=true;
    }
    if (Data.getLink()!="https://github.com/Harrix/HarrixFileFormats")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный сайт в описании. Должен быть https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if (Data.getVersion()!="1.0")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильная версия формата Harrix Optimization Testing. Данная функция обрабатывает версию 1.0.");
        Error=true;
    }
    if (Data.getNumberOfParameters()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_parameters.");
        Error=true;
    }
    if (Data.getNumberOfParameters()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Минимальное число параметров 1. Подробности в описании формата данных на https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if ((Data.getNumberOfParameters()<0)&&(Data.getNumberOfParameters()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfExperiments()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_experiments.");
        Error=true;
    }
    if (Data.getNumberOfExperiments()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Минимальное число экспериментов 1.");
        Error=true;
    }
    if ((Data.getNumberOfExperiments()<0)&&(Data.getNumberOfExperiments()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (Data.getMaxCountOfFitness()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга max_count_of_fitness.");
        Error=true;
    }
    if (Data.getMaxCountOfFitness()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Минимальное число вычислений целевой функции 1, и то это очень мало.");
        Error=true;
    }
    if ((Data.getMaxCountOfFitness()<0)&&(Data.getMaxCountOfFitness()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Число вычислений целевой функции не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfRuns()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_runs.");
        Error=true;
    }
    if (Data.getNumberOfRuns()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Минимальное число запусков алгоритма для усреднения 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getNumberOfRuns()<0)&&(Data.getNumberOfRuns()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Число запусков алгоритма для усреднения не может быть отрицательным.");
        Error=true;
    }
    if (Data.getNumberOfMeasuring()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_measuring.");
        Error=true;
    }
    if (Data.getNumberOfMeasuring()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Минимальное число измерений для настройки алгоритма 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getNumberOfMeasuring()<0)&&(Data.getNumberOfMeasuring()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Число измерений для настройки алгоритма не может быть отрицательным.");
        Error=true;
    }
    if (Data.getDimensionTestFunction()==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о размерности тестовой задачи dimension_test_function.");
        Error=true;
    }
    if (Data.getDimensionTestFunction()==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге dimension_test_function. Минимальная длина хромосомы 1 (желательно от 10).");
        Error=true;
    }
    if ((Data.getDimensionTestFunction()<0)&&(Data.getDimensionTestFunction()!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге dimension_test_function. Длина хромосомы не может быть отрицательной.");
        Error=true;
    }
    if (Data.getFullNameTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии тестовой функции full_name_test_function.");
        Error=true;
    }
    if (Data.getNameTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о названии тестовой функции name_test_function.");
        Error=true;
    }
    if (Data.getNameTestFunction().contains(" "))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Идентификатор тестовой функции должен быть одним словом. Пробелы не допускаются.");
        Error=true;
    }
    if (Data.getFullNameAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии алгоритма full_name_algorithm.");
        Error=true;
    }
    if (Data.getNameAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об названии алгоритма name_algorithm.");
        Error=true;
    }
    if (Data.getNameAlgorithm().contains(" "))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Идентификатор алгоритма оптимизации должен быть одним словом. Пробелы не допускаются.");
        Error=true;
    }
    if (Data.getDate().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о дате создания документа date.");
        Error=true;
    }
    if (Data.getAuthor().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об авторе author");
        Error=true;
    }
    if (Data.getEmail().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об электронной почте email. Если не хотите давать свою почту, то вставьте NULL.");
        Error=true;
    }
    if (Data.getLinkAlgorithm().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание алгоритма link_algorithm.");
        Error=true;
    }
    if (Data.getLinkTestFunction().isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание тестовой функции link_test_function.");
        Error=true;
    }
    if (!((Data.getCheckAllCombinations()==0)||(Data.getCheckAllCombinations()==1)))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Тэг all_combinations может принимать значение 0 или 1.");
        Error=true;
    }

}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexBegin()
{
    /*
     Внутренняя функция. Возвращает начало для полноценного Latex файла.
     */
    QString VHML_Result;
    VHML_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VHML_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VHML_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VHML_Result+="\\usepgfplotslibrary{external}\n";
    VHML_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VHML_Result+="\\begin{document}\n\n";
    VHML_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VHML_Result;
}
//---------------------------------------------------------------------------

QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexEnd()
{
    /*
     Внутренняя функция. Возвращает концовку для полноценного Latex файла.
     */
    return "\n\n\\end{document}";
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::initializationOfVariables()
{
    /*
    Обнуление переменных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    Rxml.clear();
    Data.setSuccessReading(false);
    Data.setDimensionTestFunction(-1);//Размерность тестовой задачи (длина хромосомы решения)
    Data.setNumberOfMeasuring(-1);//Количество экспериментов для каждого набора параметров алгоритма
    Data.setNumberOfRuns(-1);//Количество прогонов, по которому делается усреднение для эксперимента
    Data.setMaxCountOfFitness(-1);//Максимальное допустимое число вычислений целевой функции для алгоритма
    Data.setNumberOfParameters(-1);//Количество проверяемых параметров алгоритма оптимизации
    Zero_Number_Of_Parameters=false;//пока ничего не известно
    Data.setNumberOfExperiments(-1);//Количество комбинаций вариантов настроек
    Error=false;//типа вначале нет ошибок в файле
    Un=HQt_RandomString(5);//уникальная строка для Latex
    //AllOptions=true;//вначале наивно предполагаем, что в файле все настройки рассмотрены
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingListOfVectorParameterOptions()
{
    /*
    Заполняет список вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell2.clear();

        //получим значения параметров алгоритма
        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +". ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +".  ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +". ";
        }

        //получим значения критерий

        Data.addListOfVectorParameterOptions(Cell2);

        NumberOfListOfVectorParameterOptions[i]=i+1;
    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::memoryAllocation()
{
    /*
    Выделяет память под необходимые массивы. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до Data.getNumberOfExperiments()
    NumberOfListOfVectorParameterOptions=new double[Data.getNumberOfExperiments()];
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::memoryDeallocation()
{
    /*
    Удаляет память из-под массивов. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Data.getSuccessReading())
    {
        delete [] NumberOfListOfVectorParameterOptions;
    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::readXml()
{
    /*
     Считывание XML файла и осуществление всех остальных анализов и др.
     */
    if (!Error)
    {
        try
        {
            Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}//первый нормальный элемент
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Первый нормальный элемент не найден.");
            Error=true;
        }
    }

    if (!Error)
    {
        try
        {
            //Начнем анализ документа
            if (readXmlTreeTag("document"))
            {
                if (readXmlTreeTag("harrix_file_format"))
                {
                    //далее должны идти тэги format, version, site
                    for (int k=0;k<3;k++)
                        readXmlLeafTag();//считает тэг

                    if (readXmlTreeTag("about"))
                    {
                        //далее должны идти тэги author, date, email
                        for (int k=0;k<3;k++)
                            readXmlLeafTag();//считает тэг

                        if (readXmlTreeTag("about_data"))
                        {
                            //далее должны идти 13 тэгов по информации о данных
                            for (int k=0;k<13;k++)
                                readXmlLeafTag();//считает тэг

                            readXmlTreeTag("data");
                        }
                    }
                    checkXmlLeafTags();//проверим наличие всех тэгов
                }
            }
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Не смогли прочитать нужные тэги.");
            Error=true;
        }
    }

    if (!Error)
    {
        memoryAllocation();//выделение памяти под массивы
        Data.memoryAllocation();
        zeroArray();//обнулим массивы
        readXmlDataTags();//считаем данные непосредственно
    }
    if ((Rxml.hasError())||(Error))
    {
        HtmlMessageOfError+=HQt_ShowAlert("В процессе разбора файла обнаружены ошибки. Помните, что для этой функции обработки XML файла требуется правильный порядок следования тэгов.");
        Html+=HtmlMessageOfError;
        Data.setSuccessReading(false);
    }
    else
    {
        Data.setSuccessReading(true);
        makingAnalysis();//выполняем анализ данных

        //Обработка полученной информации Html
        makingHtmlReport();
        Html+=HtmlReport;

        //Обработка полученной информации Latex
        NameForHead="алгоритма оптимизации <<"+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getFullNameAlgorithm()))+">>на тестовой функции <<"+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getFullNameTestFunction()))+">> (размерность равна "+QString::number(Data.getDimensionTestFunction())+")";
        makingLatexInfo();
        makingLatexAboutParameters();
        makingLatexTableEx();//заполняем LatexTableEx
        makingLatexTableEy();//заполняем LatexTableEy
        makingLatexTableR();//заполняем LatexTableR
        makingListOfVectorParameterOptions();
        makingLatexListOfVectorParameterOptions2();
        makingLatexAnalysis();
        //Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;
        Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR+LatexListOfVectorParameterOptions+LatexAnalysis;
        LatexTable+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;

        Html+=HQt_ShowHr();
        Html+=HQt_ShowText("Обработка файла завершена. Ошибки не обнаружены");
    }

    Rxml.clear();//больше не будем использовать, так что удаляем
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::readXmlDataTags()
{
    /*
    Считывает и проверяет тэги данных. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */

    //Теперь должны пойти данные об экспериментах
    int i=0;//номер варианта настройки алгоритма
    bool bool_ex;
    bool bool_ey;
    bool bool_r;
    bool is_number;
    while(!Rxml.atEnd())
    {
        if(Rxml.isStartElement())
        {
            NameOfElement=Rxml.name().toString().toLower();

            if (NameOfElement=="experiment")
            {
                //если параметров нет, то имитируем один NULL парметр
                if (Zero_Number_Of_Parameters)
                {
                    Data.addNameOption("NULL");
                    Data.setParameter(0,0,0);
                    Data.addNameParameter("NULL",0);
                }
                else
                {
                    for (int k=0;k<Data.getNumberOfParameters();k++)
                    {
                        //считаем массив параметров алгоритма
                        NameOfAttr="parameters_of_algorithm_"+QString::number(k+1);
                        AttrOfElement = Rxml.attributes().value(NameOfAttr).toString();

                        //считывает названия параметров алгоритма
                        if (i==0) Data.addNameOption(HQt_TextBeforeEqualSign(AttrOfElement));

                        //теперь значения параметров алгоритма
                        Data.setListOfParameterOptions(HQt_AddUniqueQStringInQStringList (Data.getListOfParameterOptions(k), HQt_TextAfterEqualSign(AttrOfElement)),k);

                        Data.setParameter(HQt_SearchQStringInQStringList (Data.getListOfParameterOptions(k), HQt_TextAfterEqualSign(AttrOfElement)),i,k);

                        Data.addNameParameter(HQt_TextAfterEqualSign(AttrOfElement),i);
                    }
                }

                for (int k=0;k<Data.getNumberOfMeasuring();k++)
                {
                    Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                    NameOfElement=Rxml.name().toString().toLower();

                    if (NameOfElement=="measuring")
                    {
                        bool_ex = false;
                        bool_ey = false;
                        bool_r = false;

                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;
                        }

                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;
                        }

                        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
                        NameOfElement=Rxml.name().toString().toLower();
                        TextOfElement=Rxml.readElementText();
                        is_number=HQt_IsNumeric(TextOfElement);
                        if (!is_number)
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("Ошибка Ex не является числом. Вместо числа получили вот это: "+TextOfElement);
                            Error=true;
                        }

                        if (NameOfElement=="ex")
                        {
                            Data.setErrorEx(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            Data.setErrorEy(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            Data.setErrorR(HQt_QStringToNumber(TextOfElement),i,k);
                            bool_r=true;

                            if ((Data.getErrorR(i,k)<0)||(Data.getErrorR(i,k)>1))
                            {
                                HtmlMessageOfError+=HQt_ShowAlert("Сейчас просматривался тэг нажедности R. Надежность это величина от 0 до 1. У вас это не так.");
                                Error=true;
                            }
                        }

                        if (!((bool_ex)&&(bool_ey)&&(bool_r)))
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("В тэге measuring были не все три тэга ex, ey, r (или вообще не было).");
                            Error=true;
                        }
                    }
                    else
                    {
                        //должен быть тэг measuring, а его нет
                        HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга measuring. Что не так в структуре или данных файла.");
                        Error=true;
                    }
                }

            }
            else
            {
                //должен быть тэг experiment, а его нет
                HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга experiment. Что не так в структуре или данных файла.");
                Error=true;
            }

        }

        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
        i++;
    }

    if (i!=Data.getNumberOfExperiments())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Число экспериментов в тэге number_of_experiments не равно реальному числу экспериментов в xml файле.");
        Error=true;
    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::readXmlLeafTag()
{
    /*
    Считывает и проверяет тэг, который должен являться "листом", то есть самым глубоким. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    bool FindTag=false;
    NameOfElement.clear();

    //проверка тэга number_of_parameters
    if ((!Rxml.atEnd())&&(!Error))
    {
        NameOfElement=Rxml.name().toString().toLower();
        TextOfElement=Rxml.readElementText();
        if (NameOfElement=="number_of_parameters")
        {
            Data.setNumberOfParameters(TextOfElement.toInt());
            if (Data.getNumberOfParameters()==0)
            {
                //чтобы  в дальнейших вычислениях не было путаницы, но всё равно считаем,
                //что число параметров нулю
                Data.setNumberOfParameters(1);
                Zero_Number_Of_Parameters=true;
            }

            FindTag=true;
        }
        if (NameOfElement=="number_of_experiments")
        {
            Data.setNumberOfExperiments(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="max_count_of_fitness")
        {
            Data.setMaxCountOfFitness(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="number_of_runs")
        {
            Data.setNumberOfRuns(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="number_of_measuring")
        {
            Data.setNumberOfMeasuring(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="dimension_test_function")
        {
            Data.setDimensionTestFunction(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="full_name_test_function")
        {
            Data.setFullNameTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="name_test_function")
        {
            Data.setNameTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="full_name_algorithm")
        {
            Data.setFullNameAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="name_algorithm")
        {
            Data.setNameAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="date")
        {
            Data.setDate(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="author")
        {
            Data.setAuthor(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="email")
        {
            Data.setEmail(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link_test_function")
        {
            Data.setLinkTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link_algorithm")
        {
            Data.setLinkAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="format")
        {
            Data.setFormat(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="version")
        {
            Data.setVersion(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link")
        {
            Data.setLink(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="all_combinations")
        {
            Data.setCheckAllCombinations(TextOfElement.toInt());
            FindTag=true;
        }
    }

    if (FindTag)
    {
        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
    }
    else
    {
        if (NameOfElement.length()>0)
            HtmlMessageOfError+=HQt_ShowAlert("Попался какой-то непонятный тэг "+NameOfElement+". Программа в непонятках! О_о");
        else
            HtmlMessageOfError+=HQt_ShowAlert("Ждали-ждали тэг, а тут вообще ничего нет.");
        Error=true;
    }
}
//---------------------------------------------------------------------------

bool HarrixClass_DataOfHarrixOptimizationTesting::readXmlTreeTag(QString tag)
{
    /*
    Считывает и проверяет тэг, который содержит внутри себя другие тэги. Внутренняя функция.
    Входные параметры:
     tag - какой тэг мы ищем.
    Возвращаемое значение:
     true - текущий тэг это тот самый, что нам и нужен;
     false - иначе.
     */
    bool FindTag=false;

    NameOfElement.clear();

    //проверка тэга number_of_parameters
    if ((!Rxml.atEnd())&&(!Error))
    {
        NameOfElement=Rxml.name().toString().toLower();
        if (NameOfElement==tag)
        {
            FindTag=true;
        }
    }

    if (FindTag)
    {
        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
    }
    else
    {
        if (NameOfElement.length()>0)
            HtmlMessageOfError+=HQt_ShowAlert("Ожидался тэг "+tag+". Но этого не случилось, и получили этот "+NameOfElement+".");
        else
            HtmlMessageOfError+=HQt_ShowAlert("Ожидался тэг "+tag+". Но этого не случилось, и вообще никакого тэга не получили.");
        Error=true;
    }
    return FindTag;
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::zeroArray()
{
    /*
    Обнуляет массивы, в котрые записывается информация о данных из файла. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //"Обнулим" матрицы
    HML_ZeroVector(NumberOfListOfVectorParameterOptions,Data.getNumberOfExperiments());
}
//---------------------------------------------------------------------------


//*****************************************************************
//Создание содержимого отчетов LaTeX и HTML
//*****************************************************************
void HarrixClass_DataOfHarrixOptimizationTesting::makingHtmlReport()
{
    /*
    Создает текст Html для отображения отчета о считывании XML файла.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную HtmlReport, которую можно вызвать getHtmlReport.
     */
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о файле");
    HtmlReport+=HQt_ShowSimpleText("<b>Автор документа:</b> "+Data.getAuthor()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Дата создания документа:</b> "+Data.getDate()+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о собранных данных");
    HtmlReport+=HQt_ShowSimpleText("<b>Обозначение алгоритма:</b> "+Data.getNameAlgorithm()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название алгоритма:</b> "+Data.getFullNameAlgorithm()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Название тестовой функции:</b> "+Data.getNameTestFunction()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название тестовой функции:</b> "+Data.getFullNameTestFunction()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Размерность задачи оптимизации:</b> "+QString::number(Data.getDimensionTestFunction())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество измерений для каждого варианта настроек алгоритма:</b> "+QString::number(Data.getNumberOfMeasuring())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество запусков алгоритма в каждом из экспериментов:</b> "+QString::number(Data.getNumberOfRuns())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Максимальное допустимое число вычислений целевой функции:</b> "+QString::number(Data.getMaxCountOfFitness())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество проверяемых параметров алгоритма оптимизации:</b> "+QString::number(getNumberOfParameters())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество комбинаций вариантов настроек:</b> "+QString::number(Data.getNumberOfExperiments())+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Собранные данные");

    double **MOfEx;
    MOfEx=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfEx[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfEx[i][j] = Data.getErrorEx(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfEx,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Ошибки по входным параметрам","Ex");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfEx[i];
    delete [] MOfEx;

    double **MOfEy;
    MOfEy=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfEy[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfEy[i][j] = Data.getErrorEy(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfEy,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Ошибки по значениям целевой функции","Ey");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfEy[i];
    delete [] MOfEy;

    double **MOfR;
    MOfR=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfR[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfR[i][j] = Data.getErrorR(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfR,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Надежности","R");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfR[i];
    delete [] MOfR;

    if (!Zero_Number_Of_Parameters)
    {
        HtmlReport+=THQt_ShowVector(Data.getNamesOfParameters(),"Вектора названий параметров алгоритма","NamesOfParameters");
        for (int j=0;j<Data.getNumberOfParameters();j++)
            HtmlReport+=THQt_ShowVector(Data.getListOfParameterOptions(j),Data.getNameOption(j) + "(возможные принимаемые значения)","ParameterOptions");

        double **MOfP;
        MOfP=new double*[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOfP[i]=new double[Data.getNumberOfParameters()];
        for (int i=0;i<Data.getNumberOfExperiments();i++)
            for (int j=0;j<Data.getNumberOfParameters();j++)
                MOfP[i][j] = Data.getParameter(i,j);
        HtmlReport+=THQt_ShowMatrix(MOfP,Data.getNumberOfExperiments(),Data.getNumberOfParameters(),"Матрица параметров по номерам","MatrixOfParameters");
        for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfP[i];
        delete [] MOfP;
    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexAboutParameters()
{
    /*
    Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexAboutParameters.
     */
    LatexAboutParameters+="\\subsection {Параметры алгоритма оптимизации}\n\n";
    if ((Data.getNumberOfParameters()==1)&&(Data.getNameOption(0)=="NULL"))
    {
        LatexAboutParameters+="В данном исследуемом алгоритме оптимизации нет настраиваемых параметров. Поэтому в таблице ниже приведены даные только одного эксперимента.";
    }
    else
    {
        LatexAboutParameters+="Исследуемый алгоритм оптимизации проверялся по эффективности по некоторому конечному множеству возможных настроек алгоритма. ";
        LatexAboutParameters+="Как написано выше, всего возможных параметров алгоритма было "+QString::number(Data.getNumberOfParameters())+" штук. ";
        LatexAboutParameters+="В формуле \\ref{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":Parameters} показано множество проверяемых параметров алгоритма.\n\n";
        LatexAboutParameters+="\\begin{equation}\n";
        LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":Parameters}\n";
        LatexAboutParameters+="Parameters = \\left( \\begin{array}{c} ";
        if (HQt_MaxCountOfQStringList(Data.getNamesOfParameters())>57)
            Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
        else
            Parbox="";
        for (int i=0;i<Data.getNamesOfParameters().count();i++)
        {
            LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(Data.getNameOption(i))+"}} ";
            if (i!=Data.getNamesOfParameters().count()-1) LatexAboutParameters+="\\\\ ";
        }
        LatexAboutParameters+="\\end{array}\\right). ";
        LatexAboutParameters+="\\end{equation}\n\n";
        LatexAboutParameters+="Теперь рассмотрим, какие значения может принимать каждый из параметров.";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            LatexAboutParameters+="\\begin{equation}\n";
            LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":parameter_"+QString::number(j+1)+"}\n";
            LatexAboutParameters+="Parameters^{"+QString::number(j+1)+"} \\in \\left\\lbrace  \\begin{array}{c} ";
            if (HQt_MaxCountOfQStringList(Data.getListOfParameterOptions(j))>57)
                Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
            else
                Parbox="";
            for (int i=0;i<Data.getListOfParameterOptions(j).count();i++)
            {
                LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(Data.getOptionFromListOfParameterOptions(j,i))+"}} ";
                if (i!=Data.getListOfParameterOptions(j).count()-1) LatexAboutParameters+="\\\\ ";
            }
            LatexAboutParameters+="\\end{array}\\right\\rbrace . ";
            LatexAboutParameters+="\\end{equation}\n\n";
        }
    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexAnalysis()
{
    /*
    Создает текст LaTeX для отображения первоначального анализа данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexAnalysis, которую можно вызвать getLatexAnalysis.
     */
    LatexAnalysis+="\\subsection {Первоначальный анализ данных}\n\n";
    LatexAnalysis+="В данном разделе представлен первоначальный анализ данных исследования эффективности алгоритма оптимизации <<"+Data.getFullNameAlgorithm()+">> на рассматриваемой тестовой функции <<"+Data.getFullNameTestFunction()+">> (размерность "+QString::number(Data.getDimensionTestFunction())+"). ";
    if (Data.getNumberOfExperiments()==1)
    {
        //Алгоритм имеет только один эксперимент

        if (Data.getCheckAllCombinations()==true)
        {
            LatexAnalysis+="Исследуемый алгоритм оптимизации относится к алгоритмам множества варьируемых параметров самого алгоритма. Поэтому при исследовании алгоритма на тестовой функции надо было провести <<эксперимент>> только один раз (многократно его повторяя). Мы можем сделать полный анализ работы алгоритма в рассматриваемых условиях.\n\n";
        }
        else
        {
            LatexAnalysis+="Данное исследование является частичным, так как рассмотрено не всё множество возможных настроек алгоритма. Поэтому ниже будут представлены неполные выводы, так как при нерассмотренных настройках алгоритм мог показать себя лучше или хуже.\n\n";
        }
    }
    else
    {
        if (Data.getCheckAllCombinations()==true)
        {
            LatexAnalysis+="При данном исследовании было рассмотрено всё множество возможных настроек алгоритма. Поэтому можно сделать полный анализ работы алгоритма в рассматриваемых условиях.\n\n";
        }
        else
        {
            LatexAnalysis+="Данное исследование является частичным, так как рассмотрено не всё множество возможных настроек алгоритма. Поэтому ниже будут представлены неполные выводы, так как при нерассмотренных настройках алгоритм мог показать себя лучше или хуже.\n\n";
        }

        LatexAnalysis+="В таблице ниже приведены значения характеристик эффективности алгоритма оптимизации на множестве всех проведенных экспериментов. На основании их можно ценить среднюю эффективность алгоритма.\n\n";

        QStringList Col1, Col2, Col3;
        Col1 << "Ошибка по входным параметрам, $E_x$";
        Col2 << QString::number(Data.getMeanOfAllEx());
        Col3 << QString::number(Data.getVarianceOfAllEx());

        Col1 << "Ошибка по значениям целевой функции, $E_y$";
        Col2 << QString::number(Data.getMeanOfAllEy());
        Col3 << QString::number(Data.getVarianceOfAllEy());

        Col1 << "Надёжность, $R$";
        Col2 << QString::number(Data.getMeanOfAllR());
        Col3 << QString::number(Data.getVarianceOfAllR());

        LatexAnalysis+=HQt_LatexShowTable (Col1, Col2, Col3, "Измеряемая характеристика", "Выборочное среднее", "Выборочная дисперсия", 60,20, "Значения характеристик эффективности алгоритма оптимизации на множестве всех проведенных экспериментов");

        LatexAnalysis+="Построим теперь графики характеристик эффективности алгоритма по выборочным средним для каждой комбинации настроек алгоритма оптимизации.\n\n";

        double *MOEx=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOEx[i]=Data.getMeanEx(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOEx, Data.getNumberOfExperiments(), "Ошибка по входным параметрам по порядку номеров комбинаций", "N, Номер комбинации настроек", "E_x", "Ошибка по входным параметрам", "MeanOfEx"+HQt_RandomString(5), true, true, false, true, false , true);

        double *MOEy=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOEy[i]=Data.getMeanEy(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOEy, Data.getNumberOfExperiments(), "Ошибка по значениям целевой функции по порядку номеров комбинаций", "N, Номер комбинации настроек", "E_y", "Ошибка по значениям целевой функции", "MeanOfEy"+HQt_RandomString(5), true, true, false, true, false , true);

        double *MOR=new double[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOR[i]=Data.getMeanR(i);
        LatexAnalysis += THQt_LatexShowChartOfLine (NumberOfListOfVectorParameterOptions, MOR, Data.getNumberOfExperiments(), "Надёжность по порядку номеров комбинаций", "N, Номер комбинации настроек", "R", "Надёжность", "MeanOfR"+HQt_RandomString(5), true, true, false, true, false , true);

        int Temp;
        double Q;
        Q=0.2;

        int iBestEx = HML_NumberOfMinimumOfVector(MOEx,Data.getNumberOfExperiments());
        LatexAnalysis += "На основании этих графиков можно выделить оптимальные комбинации настроек алгоритмов.\n\n";
        LatexAnalysis += "В нашем случае относительно ошибки по входным параметра наименьшее значение наблюдается у комбинации настройки под номером "+QString::number(iBestEx+1)+", а именно: <<\\textbf{"+Data.getListOfVectorParameterOptions(iBestEx).trimmed()+"}>>. ";
        //Найдем те экмперименты, которые по критерию Вилкоксона не хуже, чем лучшее.
        double *BestExperimentEx = new double [Data.getNumberOfMeasuring()];
        double *TempExperimentEx = new double [Data.getNumberOfMeasuring()];
        int *NumbersBestEx= new int[Data.getNumberOfExperiments()];
        //Как минимум один эксперимент у нас уже есть
        NumbersBestEx[0] = iBestEx;
        int NumberOfBest=1;

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            BestExperimentEx[j] = Data.getErrorEx(iBestEx,j);

        for (int i=0;i<Data.getNumberOfExperiments();i++)
        {
            if (i!=iBestEx)
            {
                for (int j=0;j<Data.getNumberOfMeasuring();j++)
                    TempExperimentEx[j] = Data.getErrorEx(i,j);
                Temp = HML_WilcoxonW(BestExperimentEx, TempExperimentEx, Data.getNumberOfMeasuring(), Data.getNumberOfMeasuring(), Q);
                if (Temp==1)
                {
                    NumbersBestEx[NumberOfBest] = i;
                    NumberOfBest++;
                }
            }
        }

        if (NumberOfBest>1)
        {
            LatexAnalysis += "При критерию Вилкосона при $Q="+QString::number(Q)+"$ есть другие комбинации настроек алгоритма, которые бы статистически не отличались от наилучшей комбинации, рассмотренной выше, в количестве "+QString::number(NumberOfBest-1)+" штук. ";
        }
        else
        {
            LatexAnalysis += "При критерию Вилкосона при $Q="+QString::number(Q)+"$ нет других комбинаций настроек алгоритма, которые бы статистически не отличались от наилучшей комбинации, рассмотренной выше. ";
        }

        LatexAnalysis += "В таблице ниже представлено множество лучших комбинаций настроек алгоритма по $Ex$.\n\n";

        Col1.clear();
        Col2.clear();

        for (int j=0;j<NumberOfBest;j++)
        {
            Col1 << QString::number(NumbersBestEx[j]);
            Col2 << Data.getListOfVectorParameterOptions(NumbersBestEx[j]).trimmed();
        }

        LatexAnalysis+=HQt_LatexShowTable (Col1, Col2, "№ эксперимента", "Комбинация настроек",20, "Множество лучших комбинаций настроек алгоритма по $Ex$");


        QStringList InfoForEveryExperiment;
        for (int i=0;i<Data.getNumberOfExperiments();i++)
        {
//            if (HML_SearchElementInVector (NumbersBestEx, i, NumberOfBest)!=-1)
//                InfoForEveryExperiment <<HQt_LatexGreenText("\\checkmark");
//            else
//                InfoForEveryExperiment <<"-";
            InfoForEveryExperiment <<QString::number(Data.getMeanEx(i));
        }
        LatexAnalysis+=makingLatexTable2D("Ошибка по Ex",InfoForEveryExperiment);



        delete [] BestExperimentEx;
        delete [] TempExperimentEx;
        delete [] NumbersBestEx;


        delete [] MOEx;
        delete [] MOEy;
        delete [] MOR;

    }
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexInfo()
{
    /*
    Создает текст LaTeX для отображения информации о исследовании.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexInfo.
     */
    LatexInfo+="\\section{Исследование эффективности "+NameForHead+"}\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":Name_Algorithm}\n\n";
    LatexInfo+="В данной работе, автором проведено исследование алгоритма <<"+HQt_StringForLaTeX(Data.getFullNameAlgorithm())+">>. Ниже приведена информация об этом исследовании.\n\n";
    LatexInfo+="\\subsection {Информация об исследовании}\n\n";
    LatexInfo+="\\begin{tabularwide}\n";
    LatexInfo+="\\textbf{Автор исследования}: & "+HQt_StringForLaTeX(Data.getAuthor())+". \\\\ \n";
    if (Data.getEmail()!="NULL")
        LatexInfo+="\\textbf{Дата создания исследования}: & "+HQt_StringForLaTeX(Data.getDate())+". \\\\ \n";
    LatexInfo+="\\textbf{Дата создания исследования}: & "+HQt_StringForLaTeX(Data.getDate())+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор алгоритма}: & "+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getNameAlgorithm()))+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название алгоритма}: & "+HQt_StringForLaTeX(Data.getFullNameAlgorithm())+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор исследуемой тестовой функции}: & "+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getNameTestFunction()))+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название тестовой функции}: & "+HQt_StringForLaTeX(Data.getFullNameTestFunction())+". \\\\ \n";
    LatexInfo+="\\end{tabularwide}\n\n";
    LatexInfo+="\\begin{tabularwide08}\n";
    LatexInfo+="\\textbf{Размерность тестовой функции:} & "+QString::number(Data.getDimensionTestFunction())+" \\\\ \n";
    LatexInfo+="\\textbf{Количество измерений для каждого варианта настроек алгоритма}: & "+QString::number(Data.getNumberOfMeasuring())+" \\\\ \n";
    LatexInfo+="\\textbf{Количество запусков алгоритма в каждом из экспериментов}: & "+QString::number(Data.getNumberOfRuns())+" \\\\ \n";
    LatexInfo+="\\textbf{Максимальное допустимое число вычислений целевой функции}: & "+QString::number(Data.getMaxCountOfFitness())+" \\\\ \n";

    if ((Data.getNumberOfParameters()==1)&&(Data.getNameOption(0)=="NULL"))
    {
        LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & Отсутствуют \\\\ \n";
    }
    else
    {
        LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & "+QString::number(Data.getNumberOfParameters())+" \\\\ \n";
    }

    LatexInfo+="\\textbf{Количество комбинаций вариантов настроек}: & "+QString::number(Data.getNumberOfExperiments())+" \\\\ \n";
    qint64 Number=Data.getNumberOfExperiments()*Data.getMaxCountOfFitness()*Data.getNumberOfMeasuring()*Data.getNumberOfRuns();
    LatexInfo+="\\textbf{Общий объем максимального числа вычислений целевой функции во всем исследовании}: & "+QString::number(Number)+" \\\\ \n";
    LatexInfo+="\\end{tabularwide08}\n\n";
    LatexInfo+="Информацию о исследуемой функции можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}\n\n";
    LatexInfo+="Информацию о исследуемом алгоритме оптимизации можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixOptimizationAlgorithms}{https://github.com/Harrix/HarrixOptimizationAlgorithms}\n\n";
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexListOfVectorParameterOptions()
{
    /*
    Создает текст LaTeX для отображения списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */
    LatexListOfVectorParameterOptions="\\subsection {Список вектора названий вариантов параметров алгоритма оптимизации}\n\n";
    LatexListOfVectorParameterOptions+="Ниже представлена таблица, в которой представлен нумерованный список вариантов  параметров алгоритма оптимизации. ";
    LatexListOfVectorParameterOptions+="\\begin{center}\n";
    LatexListOfVectorParameterOptions+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexListOfVectorParameterOptions+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{0.9\\linewidth}|}\n";
    LatexListOfVectorParameterOptions+="\\caption{Список вектора названий вариантов параметров "+NameForHead+"}\n";
    LatexListOfVectorParameterOptions+="\\tabularnewline\\hline\n";
    LatexListOfVectorParameterOptions+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма} \\centering \\tabularnewline \\hline \\endhead\n";
    LatexListOfVectorParameterOptions+="\\multicolumn{2}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexListOfVectorParameterOptions+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        //получим номер
        Cell1=QString::number(NumberOfListOfVectorParameterOptions[i]);
        Cell1="\\centering \\footnotesize "+Cell1;

        Cell2="\\footnotesize "+  Data.getListOfVectorParameterOptions(i);

        //получим значения критерий

        LatexListOfVectorParameterOptions+=Cell1+" & "+Cell2+"\\tabularnewline \\hline\n";
    }

    LatexListOfVectorParameterOptions+="\n\\end{longtable}\n";
    LatexListOfVectorParameterOptions+="}\n";
    LatexListOfVectorParameterOptions+="\\end{center}\n\n";
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexListOfVectorParameterOptions2()
{
    /*
    Создает текст LaTeX для отображения списка номеров вариантов настроек параметров алгоритма оптимизации в виде 2D таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */
    LatexListOfVectorParameterOptions="\\subsection {Список номеров вариантов настроек параметров алгоритма оптимизации}\n\n";
    LatexListOfVectorParameterOptions+="Ниже представлена таблица, в которой представлены номера вариантов  параметров алгоритма оптимизации. Данные номера будут использованы в дальнейшем анализе.";

    QStringList List;
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        List <<QString::number(i+1);
    LatexListOfVectorParameterOptions+=makingLatexTable2D("Номера вариантов параметров "+NameForHead+"",List);
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTableEx()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexTableEx.
     */
    //////////////////Сырые данные по Ex ///////////
    LatexTableEx+="\\subsection {Ошибка по входным параметрам $E_x$}\n\n";
    LatexTableEx+="Одним из критериев, по которому происходит сравнение алгоритмов оптимизации является ошибка по входным параметрам $E_x$. ";
    LatexTableEx+="В результате проделанных экспериментов были получены следующие данные, представленные ниже в таблице. ";
    LatexTableEx+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.\n";
    LatexTableEx+="\\begin{center}\n";
    LatexTableEx+="{\\renewcommand{\\arraystretch}{1.5}\n";
    //LatexTableEx+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":TableEx}\n";
    LatexTableEx+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2.1in}|m{0.2\\linewidth}|m{0.17\\linewidth}|m{0.17\\linewidth}|}\n";
    LatexTableEx+="\\caption{Значения ошибки по выходным параметрам $E_x$ "+NameForHead+"}\n";
    LatexTableEx+="\\tabularnewline\\hline\n";
    LatexTableEx+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_x$} & \\centering \\textbf{Выборочное среднее} & \\centering \\textbf{Выборочная дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEx+="\\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEx+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +" \\\\ ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Cell3+=QString::number(Data.getErrorEx(i,j))+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(Data.getMeanEx(i));

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(Data.getVarianceOfEx(i));

        Cell5="\\centering "+Cell5;

        LatexTableEx+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEx+="\n\\end{longtable}\n";
    LatexTableEx+="}\n";
    LatexTableEx+="\\end{center}\n\n";
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTableEy()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по значениям целевой функции в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEy, которую можно вызвать getLatexTableEy.
     */
    //////////////////Сырые данные по Ey ///////////
    LatexTableEy+="\\subsection {Ошибка по значениям целевой функции $E_y$}\n\n";
    LatexTableEy+="Другим критерием, по которому происходит сравнение алгоритмов оптимизации является ошибка по значениям целевой функции $E_y$. ";
    LatexTableEy+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableEy+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.\n";
    LatexTableEy+="\\begin{center}\n";
    LatexTableEy+="{\\renewcommand{\\arraystretch}{1.5}\n";
    //LatexTableEy+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":TableEy}\n";
    LatexTableEy+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2.1in}|m{0.2\\linewidth}|m{0.17\\linewidth}|m{0.17\\linewidth}|}\n";
    LatexTableEy+="\\caption{Значения ошибки по значениям целевой функции $E_y$ "+NameForHead+"}\n";
    LatexTableEy+="\\tabularnewline\\hline\n";
    LatexTableEy+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_y$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEy+="\\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEy+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +" \\\\ ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Cell3+=QString::number(Data.getErrorEy(i,j))+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(Data.getMeanEy(i));

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(Data.getVarianceOfEy(i));

        Cell5="\\centering "+Cell5;

        LatexTableEy+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEy+="\n\\end{longtable}\n";
    LatexTableEy+="}\n";
    LatexTableEy+="\\end{center}\n\n";
}
//---------------------------------------------------------------------------

void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTableR()
{
    /*
    Создает текст LaTeX для отображения сырых данных по надежности в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableR, которую можно вызвать getLatexTableR.
     */
    //////////////////Сырые данные по R ///////////
    LatexTableR+="\\subsection {Надёжность $R$}\n\n";
    LatexTableR+="Третьим критерием, по которому происходит сравнение алгоритмов оптимизации является надёжность $R$. ";
    LatexTableR+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableR+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.\n";
    LatexTableR+="\\begin{center}\n";
    LatexTableR+="{\\renewcommand{\\arraystretch}{1.5}\n";
    //LatexTableR+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":TableR}\n";
    LatexTableR+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2.1in}|m{0.2\\linewidth}|m{0.17\\linewidth}|m{0.17\\linewidth}|}\n";
    LatexTableR+="\\caption{Значения надёжности $R$ "+NameForHead+"}\n";
    LatexTableR+="\\tabularnewline\\hline\n";
    LatexTableR+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $R$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableR+="\\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableR+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +" \\\\ ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Cell3+=QString::number(Data.getErrorR(i,j))+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(Data.getMeanR(i));

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(Data.getVarianceOfR(i));

        Cell5="\\centering "+Cell5;

        LatexTableR+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableR+="\n\\end{longtable}\n";
    LatexTableR+="}\n";
    LatexTableR+="\\end{center}\n\n";
}
//---------------------------------------------------------------------------


//*****************************************************************
//Функции анализа данных
//*****************************************************************
void HarrixClass_DataOfHarrixOptimizationTesting::makingAnalysis()
{
    /*
    Выполняет анализ считанных данных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        //заполним значениями вектор средних значений критериев и дисперсий
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Data.setMeanEx(Data.getMeanEx(i)+Data.getErrorEx(i,j),i);
            Data.setMeanEy(Data.getMeanEy(i)+Data.getErrorEy(i,j),i);
            Data.setMeanR (Data.getMeanR (i)+Data.getErrorR (i,j),i);

            //для общих дисперсий
            Data.setMeanOfAllEx(Data.getMeanOfAllEx()+Data.getErrorEx(i,j));
            Data.setMeanOfAllEy(Data.getMeanOfAllEy()+Data.getErrorEy(i,j));
            Data.setMeanOfAllR (Data.getMeanOfAllR ()+Data.getErrorR (i,j));
        }
        Data.setMeanEx(Data.getMeanEx(i)/double(Data.getNumberOfMeasuring()),i);
        Data.setMeanEy(Data.getMeanEy(i)/double(Data.getNumberOfMeasuring()),i);
        Data.setMeanR (Data.getMeanR (i)/double(Data.getNumberOfMeasuring()),i);

        Data.setVarianceOfEx(0,i);
        Data.setVarianceOfEy(0,i);
        Data.setVarianceOfR (0,i);
        double sd;
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            sd=(Data.getErrorEx(i,j)-Data.getMeanEx(i))*(Data.getErrorEx(i,j)-Data.getMeanEx(i));
            Data.setVarianceOfEx(Data.getVarianceOfEx(i)+sd,i);
            sd=(Data.getErrorEy(i,j)-Data.getMeanEy(i))*(Data.getErrorEy(i,j)-Data.getMeanEy(i));
            Data.setVarianceOfEy(Data.getVarianceOfEy(i)+sd,i);
            sd=(Data.getErrorR(i,j) -Data.getMeanR (i))*(Data.getErrorR(i,j) -Data.getMeanR (i));
            Data.setVarianceOfR(Data.getVarianceOfR(i)+sd,i);
        }
        Data.setVarianceOfEx(Data.getVarianceOfEx(i)/double(Data.getNumberOfMeasuring()-1),i);
        Data.setVarianceOfEy(Data.getVarianceOfEy(i)/double(Data.getNumberOfMeasuring()-1),i);
        Data.setVarianceOfR (Data.getVarianceOfR (i)/double(Data.getNumberOfMeasuring()-1),i);
    }

    //посчитаем общие средние значения
    Data.setMeanOfAllEx(Data.getMeanOfAllEx()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));
    Data.setMeanOfAllEy(Data.getMeanOfAllEy()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));
    Data.setMeanOfAllR (Data.getMeanOfAllR ()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()));

    double sd;
    //посчитаем дисперсии
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            sd=(Data.getErrorEx(i,j)-Data.getMeanOfAllEx())*(Data.getErrorEx(i,j)-Data.getMeanOfAllEx());
            Data.setVarianceOfAllEx(Data.getVarianceOfAllEx()+sd);
            sd=(Data.getErrorEy(i,j)-Data.getMeanOfAllEy())*(Data.getErrorEy(i,j)-Data.getMeanOfAllEy());
            Data.setVarianceOfAllEy(Data.getVarianceOfAllEy()+sd);
            sd=(Data.getErrorR(i,j) -Data.getMeanOfAllR() )*(Data.getErrorR(i,j) -Data.getMeanOfAllR() );
            Data.setVarianceOfAllR (Data.getVarianceOfAllR ()+sd);
        }
    Data.setVarianceOfAllEx(Data.getVarianceOfAllEx()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
    Data.setVarianceOfAllEy(Data.getVarianceOfAllEy()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
    Data.setVarianceOfAllR (Data.getVarianceOfAllR ()/double(Data.getNumberOfMeasuring()*Data.getNumberOfExperiments()-1));
}
//---------------------------------------------------------------------------