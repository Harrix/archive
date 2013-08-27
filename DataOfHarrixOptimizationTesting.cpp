//Класс DataOfHarrixOptimizationTesting для считывания информации формата данных Harrix Optimization Testing
//Версия 1.6

#include "QtHarrixLibrary.h"
#include "QtHarrixLibraryForQWebView.h"
#include "MathHarrixLibrary.h"
#include "DataOfHarrixOptimizationTesting.h"

DataOfHarrixOptimizationTesting::DataOfHarrixOptimizationTesting(QString filename)
{
    /*
    Конструктор. Функция считывает данные о тестировании алгоритма оптимизации
    из файла формата HarrixOptimizationTesting.
    Входные параметры:
     filename - полное имя считываемого файла;
 */
    SuccessReading=true;
    XML_Chromosome_Length=-1;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring=-1;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs=-1;//Количество прогонов по которому деляется усреднение для эксперимента
    XML_Max_Count_Of_Fitness=-1;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters=-1;//Количество проверяемых параметров алгоритма оптимизации
    XML_Number_Of_Experiments=-1;//Количество комбинаций вариантов настроек
    Error=false;//типа вначале нет ошибок в файле
    Un=HQt_RandomString(5);//уникальная строка для Latex

    QFile file(filename);//для открытия файла и запихивания его в Rxml

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Файл "+HQt_GetFilenameFromFullFilename(filename)+" не открывается");
        Error=true;
    }
    else
    {
        Html+=HQt_ShowText("Файл <font color=\"#00b400\">"+HQt_GetFilenameFromFullFilename(filename)+"</font> загружен");

        //Первоначальные действия
        Rxml.setDevice(&file);
        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}//первый нормальный элемент

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
                    //далее должны идти тэги author, date
                    for (int k=0;k<2;k++)
                        readXmlLeafTag();//считает тэг

                    if (readXmlTreeTag("about_data"))
                    {
                        //далее должны идти 12 тэгов по информации о данных
                        for (int k=0;k<12;k++)
                            readXmlLeafTag();//считает тэг

                        readXmlTreeTag("data");
                    }
                }
                checkXmlLeafTags();//проверим наличие всех тэгов
            }
        }

        if (!Error)
        {
            memoryAllocation();//выделение памяти под массивы
            zeroArray();//обнулим массивы
            readXmlDataTags();//считаем данные непосредственно
        }

        if ((Rxml.hasError())||(Error))
        {
            HtmlMessageOfError+=HQt_ShowAlert("В процессе разбора файла обнаружены ошибки. Помните, что для этой функции обработки XML файла требуется правильный порядок следования тэгов.");
            Html+=HtmlMessageOfError;
            SuccessReading=false;
        }
        else
        {
            makingAnalysis();//выполняем анализ данных

            //Обработка полученной информации Html
            makingHtmlReport();
            Html+=HtmlReport;

            //Обработка полученной информации Latex
            NameForHead="алгоритма оптимизации <<"+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+">>на тестовой функции <<"+HQt_StringForLaTeX(XML_Full_Name_Test_Function)+">> (размерность равна "+QString::number(XML_Chromosome_Length)+")";
            makingLatexInfo();
            makingLatexAboutParameters();
            makingLatexTableEx();//заполняем LatexTableEx
            makingLatexTableEy();//заполняем LatexTableEy
            makingLatexTableR();//заполняем LatexTableR
            Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;

            Html+=HQt_ShowHr();
            Html+=HQt_ShowText("Обработка файла завершена. Ошибки не обнаружены");
        }
    }

    file.close();
}
//--------------------------------------------------------------------------

DataOfHarrixOptimizationTesting::~DataOfHarrixOptimizationTesting()
{
    /*
     Деконструктор класса.
     */
    if (!Error)
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
        delete [] MeanOfEx;
        delete [] MeanOfEy;
        delete [] MeanOfR;
        delete [] VarianceOfEx;
        delete [] VarianceOfEy;
        delete [] VarianceOfR;
    }
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getHtml()
{
    /*
     Получение текста переменной Html. Это итоговый Html документ.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return Html;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getHtmlReport()
{
    /*
     Получение текста переменной HtmlReport. Это частm html документа в виде отчета о проделанной работе.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return HtmlReport;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getHtmlMessageOfError()
{
    /*
     Получение текста переменной HtmlMessageOfError. Это частm html документа в виде кода о сообщениях ошибок.
     Помните, что это не полноценный Html код. Его нужно применять в виде temp.html для макета:
     https://github.com/Harrix/QtHarrixLibraryForQWebView
     */
    return HtmlMessageOfError;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatex()
{
    /*
     Получение текста переменной Latex.
     Здесь собран полный файл анализа данных из считываемого xml файла.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return Latex;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexTableEx()
{
    /*
     Получение текста переменной LatexTableEx - отображение сырых данных таблицы данных о ошибке Ex.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableEx;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexTableEy()
{
    /*
     Получение текста переменной LatexTableEy - отображение сырых данных ошибки по значениям целевой функции в виде полной таблицы.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableEy;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexTableR()
{
    /*
     Получение текста переменной LatexTableR - отображение сырых данных по надедности в виде полной таблицы.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTableR;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexInfo()
{
    /*
     Получение текста переменной LatexInfo - отображение информации о исследовании.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexInfo;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexAboutParameters()
{
    /*
     Получение текста переменной LatexAboutParameters - отображение данных о обнаруженных параметрах алгоритма и какие они бывают.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexAboutParameters;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexBegin()
{
    /*
     Внутренная функция. Возвращает начало для полноценного Latex файла.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль перемиенования некоторых команд\n\n";

    return VMHL_Result;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLatexEnd()
{
    /*
     Внутренная функция. Возвращает концовку для полноценного Latex файла.
     */
    return "\n\n\\end{document}";
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getAuthor()
{
    /*
     Получение текста переменной XML_Author - Автор документа
     */
    return XML_Author;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getDate()
{
    /*
     Получение текста переменной  XML_Date - Дата создания документа
     */
    return XML_Date;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Name_Algorithm - Название алгоритма оптимизации
     */
    return XML_Name_Algorithm;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getFullNameAlgorithm()
{
    /*
     Получение текста переменной  XML_Full_Name_Algorithm - Полное название алгоритма оптимизации
     */
    return XML_Full_Name_Algorithm;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameTestFunction()
{
    /*
     Получение текста переменной  XML_Name_Test_Function - Название тестовой функции
     */
    return XML_Name_Test_Function;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getFullNameTestFunction()
{
    /*
     Получение текста переменной  XML_Full_Name_Test_Function - Полное название тестовой функции
     */
    return XML_Full_Name_Test_Function;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getChromosomeLength()
{
    /*
     Получение текста переменной  XML_Chromosome_Length - Размерность тестовой задачи (длина хромосомы решения)
     */
    return XML_Chromosome_Length;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfMeasuring()
{
    /*
     Получение текста переменной  XML_Number_Of_Measuring - Размерность тестовой задачи (длина хромосомы решения)
     */
    return XML_Number_Of_Measuring;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfRuns()
{
    /*
     Получение текста переменной  XML_Number_Of_Runs - Количество прогонов по которому деляется усреднение для эксперимента
     */
    return XML_Number_Of_Runs;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getMaxCountOfFitness()
{
    /*
     Получение текста переменной  Max_Count_Of_Fitness - Максимальное допустимое число вычислений целевой функции для алгоритма
     */
    return XML_Max_Count_Of_Fitness;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации
     */
    return XML_Number_Of_Parameters;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfExperiments()
{
    /*
     Получение текста переменной  XML_Number_Of_Experiments - Количество комбинаций вариантов настроек
     */
    return XML_Number_Of_Experiments;
}
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring)
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

double DataOfHarrixOptimizationTesting::getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring)
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

double DataOfHarrixOptimizationTesting::getErrorR(int Number_Of_Experiment, int Number_Of_Measuring)
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

double DataOfHarrixOptimizationTesting::getMeanEx(int Number_Of_Experiment)
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
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getMeanEy(int Number_Of_Experiment)
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
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getMeanR(int Number_Of_Experiment)
{
    /*
    Получение среднего значения надежности R по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Значения среднего значения Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return MeanOfR[Number_Of_Experiment];
}
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getVarianceOfEx(int Number_Of_Experiment)
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
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getVarianceOfEy(int Number_Of_Experiment)
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
//--------------------------------------------------------------------------

double DataOfHarrixOptimizationTesting::getVarianceOfR(int Number_Of_Experiment)
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
//--------------------------------------------------------------------------

bool DataOfHarrixOptimizationTesting::getSuccessReading()
{
    /*
    Получение значения переменной SuccessReading о удачности или неудачности прочитывания файла.
     */
    return SuccessReading;
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getParameter(int Number_Of_Experiment, int Number_Of_Parameter)
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
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter)
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

    return MatrixOfNameParameters[Number_Of_Experiment][Number_Of_Parameter];
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getNameOption(int Number_Of_Parameter)
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

    return NamesOfParameters[Number_Of_Parameter];
}
//--------------------------------------------------------------------------

int DataOfHarrixOptimizationTesting::getNumberOfOption(QString NameOption)
{
    /*
    Получение номера параметра алгоритма по его имени.
    Входные параметры:
     NameOption - имя параметра.
    Возвращаемое значение:
     Значения параметра в виде номера (если не найдено, то возвращается -1.
     */
    int VMHL_Result=-1;

    VMHL_Result = HQt_SearchQStringInQStringList (NamesOfParameters, NameOption);

    return VMHL_Result;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getFormat()
{
    /*
    Получение переменной XML_Format, то есть возвращает название формата документа.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "Harrix Optimization Testing".
     */

    return XML_Format;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getVersion()
{
    /*
    Получение переменной XML_Version, то есть возвращает версию формата документа.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "1.0".
     */

    return XML_Version;
}
//--------------------------------------------------------------------------

QString DataOfHarrixOptimizationTesting::getLink()
{
    /*
    Получение переменной XML_Link, то есть возвращает ссылку на описание формата файла.
    Входные параметры:
     Отсутствует.
    Возвращаемое значение:
     Если документ без ошибок в описании формата, то всегда должно возвращаться "https://github.com/Harrix/HarrixFileFormats".
     */

    return XML_Link;
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexTableR()
{
    /*
    Создает текст LaTeX для отображения сырых данных по надежности в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableR, которую можно вызвать getLatexTableR
     */
    //////////////////Сырые данные по R ///////////
    LatexTableR+="\\subsection {Надёжность $R$}\n\n";
    LatexTableR+="Третьим критерием, по которому происходит сравнение алгоритмов оптимизации является надёжность $R$. ";
    LatexTableR+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableR+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableR+="\\begin{center}\n";
    LatexTableR+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableR+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableR+="\\caption{Значения надёжности $R$ "+NameForHead+"}\n";
    LatexTableR+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableR}\n";
    LatexTableR+="\\tabularnewline\\hline\n";
    LatexTableR+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $R$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableR+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableR+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
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

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            if (MatrixOfNameParameters[i][j]=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(MatrixOfNameParameters[i][j]))
                    if (MatrixOfNameParameters[i][j].length()>=5)
                        Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
                    else
                        Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
                else
                    Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfR[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfR[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfR[i]);

        Cell5="\\centering "+Cell5;

        LatexTableR+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableR+="\\end{longtable}\n";
    LatexTableR+="}\n";
    LatexTableR+="\\end{center}\n\n";

}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexTableEy()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по значениям целевой функции в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEy, которую можно вызвать getLatexTableEy
     */
    //////////////////Сырые данные по Ey ///////////
    LatexTableEy+="\\subsection {Ошибка по значениям целевой функции $E_y$}\n\n";
    LatexTableEy+="Другим критерием, по которому происходит сравнение алгоритмов оптимизации является ошибка по значениям целевой функции $E_y$. ";
    LatexTableEy+="Конкретные формулы, по которым происходило подсчитывание критерия в виде ошибки по значениям целевой функции вы можете найти на сайте в описании конкретной тестовой функции: \n";
    LatexTableEy+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableEy+="\\begin{center}\n";
    LatexTableEy+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableEy+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableEy+="\\caption{Значения ошибки по значениям целевой функции $E_y$ "+NameForHead+"}\n";
    LatexTableEy+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableEy}\n";
    LatexTableEy+="\\tabularnewline\\hline\n";
    LatexTableEy+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_y$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEy+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEy+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
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

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            if (MatrixOfNameParameters[i][j]=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(MatrixOfNameParameters[i][j]))
                    if (MatrixOfNameParameters[i][j].length()>=5)
                        Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
                    else
                        Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
                else
                    Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfEy[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfEy[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfEy[i]);

        Cell5="\\centering "+Cell5;

        LatexTableEy+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEy+="\\end{longtable}\n";
    LatexTableEy+="}\n";
    LatexTableEy+="\\end{center}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexTableEx()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexTableEx
     */
    //////////////////Сырые данные по Ex ///////////
    LatexTableEx+="\\subsection {Ошибка по входным параметрам $E_x$}\n\n";
    LatexTableEx+="Одним из критериев, по которому происходит сравнение алгоритмов оптимизации является ошибка по входным параметрам $E_x$. ";
    LatexTableEx+="В результате проделанных экспериментов были получены следующие данные, представленные ниже в таблице. ";
    LatexTableEx+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.";
    LatexTableEx+="\\begin{center}\n";
    LatexTableEx+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexTableEx+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2in}|m{0.2\\linewidth}|m{0.18\\linewidth}|m{0.18\\linewidth}|}\n";
    LatexTableEx+="\\caption{Значения ошибки по выходным параметрам $E_x$ "+NameForHead+"}\n";
    LatexTableEx+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":TableEx}\n";
    LatexTableEx+="\\tabularnewline\\hline\n";
    LatexTableEx+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_x$} & \\centering \\textbf{Среднее значение} & \\centering \\textbf{Дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEx+="\\hline \\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEx+="\\hline \\endlastfoot";

    for (int i=0;i<XML_Number_Of_Experiments;i++)
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

        for (int j=0;j<XML_Number_Of_Parameters;j++)
        {
            if (MatrixOfNameParameters[i][j]=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(MatrixOfNameParameters[i][j]))
                    if (MatrixOfNameParameters[i][j].length()>=5)
                        Cell2+=MatrixOfNameParameters[i][j] +" \\\\ ";
                    else
                        Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
                else
                    Cell2+=NamesOfParameters[j] + " = " + MatrixOfNameParameters[i][j] +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            Cell3+=QString::number(MatrixOfEx[i][j])+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(MeanOfEx[i]);

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(VarianceOfEx[i]);

        Cell5="\\centering "+Cell5;

        LatexTableEx+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEx+="\\end{longtable}\n";
    LatexTableEx+="}\n";
    LatexTableEx+="\\end{center}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexInfo()
{
    /*
    Создает текст LaTeX для отображения информации о исследовании.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexInfo
     */
    LatexInfo+="\\section{Исследование эффективности "+NameForHead+"}\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Name_Algorithm}\n\n";
    LatexInfo+="В данной работе, автором проведено исследование алгоритма <<"+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+">>. Ниже приведена информация об этом исследовании.\n\n";
    LatexInfo+="\\subsection {Информация об исследовании}\n\n";
    LatexInfo+="\\begin{tabularwide}\n";
    LatexInfo+="\\textbf{Автор исследования}: & "+HQt_StringForLaTeX(XML_Author)+". \\\\ \n";
    LatexInfo+="\\textbf{Дата создания исследования}: & "+HQt_StringForLaTeX(XML_Date)+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор алгоритма}: & "+HQt_StringForLaTeX(XML_Name_Algorithm)+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название алгоритма}: & "+HQt_StringForLaTeX(XML_Full_Name_Algorithm)+". \\\\ \n";
    LatexInfo+="\\textbf{Идентификатор исследуемой тестовой функции}: & "+HQt_StringForLaTeX(XML_Name_Test_Function)+". \\\\ \n";
    LatexInfo+="\\textbf{Полное название тестовой функции}: & "+HQt_StringForLaTeX(XML_Full_Name_Test_Function)+". \\\\ \n";
    LatexInfo+="\\end{tabularwide}\n\n";
    LatexInfo+="\\begin{tabularwide08}\n";
    LatexInfo+="\\textbf{Размерность тестовой функции:} & "+QString::number(XML_Chromosome_Length)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество измерений для каждого варианта настроек алгоритма}: & "+QString::number(XML_Number_Of_Measuring)+" \\\\ \n";
    LatexInfo+="\\textbf{Количество запусков алгоритма в каждом из экспериментов}: & "+QString::number(XML_Number_Of_Runs)+" \\\\ \n";
    LatexInfo+="\\textbf{Максимальное допустимое число вычислений целевой функции}: & "+QString::number(XML_Max_Count_Of_Fitness)+" \\\\ \n";

    if ((XML_Number_Of_Parameters==1)&&(NamesOfParameters.at(0)=="NULL"))
    {
        LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & Отсутствуют \\\\ \n";
     }
      else
    {
        LatexInfo+="\\textbf{Количество проверяемых параметров алгоритма оптимизации}: & "+QString::number(XML_Number_Of_Parameters)+" \\\\ \n";
    }

    LatexInfo+="\\textbf{Количество комбинаций вариантов настроек}: & "+QString::number(XML_Number_Of_Experiments)+" \\\\ \n";
    LatexInfo+="\\textbf{Общий объем максимального числа вычислений целевой функции во всем исследовании}: & "+QString::number(XML_Number_Of_Experiments*XML_Max_Count_Of_Fitness*XML_Number_Of_Measuring*XML_Number_Of_Runs)+" \\\\ \n";
    LatexInfo+="\\end{tabularwide08}\n\n";
    LatexInfo+="Информацию о исследуемой функции можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}\n\n";
    LatexInfo+="Информацию о исследуемом алгоритме оптимизации можно найти по адресу:\n\n";
    LatexInfo+="\\href{https://github.com/Harrix/HarrixOptimizationAlgorithms}{https://github.com/Harrix/HarrixOptimizationAlgorithms}\n\n";
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingLatexAboutParameters()
{
    /*
    Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexAboutParameters
     */
    LatexAboutParameters+="\\subsection {Параметры алгоритма оптимизации}\n\n";
    if ((XML_Number_Of_Parameters==1)&&(NamesOfParameters.at(0)=="NULL"))
    {
        LatexAboutParameters+="В данном исследуемом алгоритме оптимизации нет настраеваемых параметров. Поэтому в таблице ниже приведены даные только одного эксперимента.";
    }
      else
    {
    LatexAboutParameters+="Исследуемый алгоритм оптимизации проверялся по эффективности по некоторому конечному множеству возможных настроек алгоритма. ";
    LatexAboutParameters+="Как написано выше, всего возможных параметров алгоритма было "+QString::number(XML_Number_Of_Parameters)+" штук. ";
    LatexAboutParameters+="В формуле \\ref{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Parameters} показано множество проверяемых параметров алгоритма.\n\n";
    LatexAboutParameters+="\\begin{equation}\n";
    LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":Parameters}\n";
    LatexAboutParameters+="Parameters = \\left( \\begin{array}{c} ";
    if (HQt_MaxCountOfQStringList(NamesOfParameters)>57)
        Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
    else
        Parbox="";
    for (int i=0;i<NamesOfParameters.count();i++)
    {
        LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(NamesOfParameters.at(i))+"}} ";
        if (i!=NamesOfParameters.count()-1) LatexAboutParameters+="\\\\ ";
    }
    LatexAboutParameters+="\\end{array}\\right). ";
    LatexAboutParameters+="\\end{equation}\n\n";
    LatexAboutParameters+="Теперь рассмотрим, какие значения может принимать каждый из параметров.";

    for (int j=0;j<XML_Number_Of_Parameters;j++)
    {
        LatexAboutParameters+="\\begin{equation}\n";
        LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(XML_Name_Algorithm)+":parameter_"+QString::number(j+1)+"}\n";
        LatexAboutParameters+="Parameters^{"+QString::number(j+1)+"} \\in \\left\\lbrace  \\begin{array}{c} ";
        if (HQt_MaxCountOfQStringList(ListOfParameterOptions[j])>57)
            Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
        else
            Parbox="";
        for (int i=0;i<ListOfParameterOptions[j].count();i++)
        {
            LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(ListOfParameterOptions[j].at(i))+"}} ";
            if (i!=ListOfParameterOptions[j].count()-1) LatexAboutParameters+="\\\\ ";
        }
        LatexAboutParameters+="\\end{array}\\right\\rbrace . ";
        LatexAboutParameters+="\\end{equation}\n\n";
    }
    }
}
//--------------------------------------------------------------------------
void DataOfHarrixOptimizationTesting::makingHtmlReport()
{
    /*
    Создает текст Html для отображения отчета о считывании XML файла.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную HtmlReport, которую можно вызвать getHtmlReport
     */
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о файле");
    HtmlReport+=HQt_ShowSimpleText("<b>Автор документа:</b> "+XML_Author+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Дата создания документа:</b> "+XML_Date+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о собранных данных");
    HtmlReport+=HQt_ShowSimpleText("<b>Обозначение алгоритма:</b> "+XML_Name_Algorithm+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название алгоритма:</b> "+XML_Full_Name_Algorithm+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Название тестовой функции:</b> "+XML_Name_Test_Function+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название тестовой функции:</b> "+XML_Full_Name_Test_Function+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Размерность задачи оптимизации:</b> "+QString::number(XML_Chromosome_Length)+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество измерений для каждого варианта настроек алгоритма:</b> "+QString::number(XML_Number_Of_Measuring)+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество запусков алгоритма в каждом из экспериментов:</b> "+QString::number(XML_Number_Of_Runs)+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Максимальное допустимое число вычислений целевой функции:</b> "+QString::number(XML_Max_Count_Of_Fitness)+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество проверяемых параметров алгоритма оптимизации:</b> "+QString::number(XML_Number_Of_Parameters)+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество комбинаций вариантов настроек:</b> "+QString::number(XML_Number_Of_Experiments)+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Собранные данные");
    HtmlReport+=THQt_ShowMatrix(MatrixOfEx,XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Ошибки по входным параметрам","Ex");
    HtmlReport+=THQt_ShowMatrix(MatrixOfEy,XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Ошибки по значениям целевой функции","Ey");
    HtmlReport+=THQt_ShowMatrix(MatrixOfR, XML_Number_Of_Experiments,XML_Number_Of_Measuring,"Надежности","R");
    HtmlReport+=THQt_ShowVector(NamesOfParameters,"Вектора названий параметров алгоримта","NamesOfParameters");
    for (int j=0;j<XML_Number_Of_Parameters;j++)
        HtmlReport+=THQt_ShowVector(ListOfParameterOptions[j],(NamesOfParameters).at(j) + "(возможные принимаемые значения)","ParameterOptions");
    HtmlReport+=THQt_ShowMatrix(MatrixOfParameters,XML_Number_Of_Experiments,XML_Number_Of_Parameters,"Матрица параметров по номерам","MatrixOfParameters");
    //HtmlReport+=THQt_ShowMatrix(MatrixOfNameParameters,XML_Number_Of_Experiments,"Матрица параметров по именам","MatrixOfParameters");
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::readXmlLeafTag()
{
    /*
    Считывает и проверяет тэг, который должен являться "листом", то есть самым глубоким. Внутренная функция.
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
            XML_Number_Of_Parameters=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="number_of_experiments")
        {
            XML_Number_Of_Experiments=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="max_count_of_fitness")
        {
            XML_Max_Count_Of_Fitness=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="number_of_runs")
        {
            XML_Number_Of_Runs=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="number_of_measuring")
        {
            XML_Number_Of_Measuring=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="chromosome_length")
        {
            XML_Chromosome_Length=TextOfElement.toInt();
            FindTag=true;
        }
        if (NameOfElement=="full_name_test_function")
        {
            XML_Full_Name_Test_Function=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="name_test_function")
        {
            XML_Name_Test_Function=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="full_name_algorithm")
        {
            XML_Full_Name_Algorithm=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="name_algorithm")
        {
            XML_Name_Algorithm=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="date")
        {
            XML_Date=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="author")
        {
            XML_Author=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="link_test_function")
        {
            XML_Link_Test_Function=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="link_algorithm")
        {
            XML_Link_Algorithm=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="format")
        {
            XML_Format=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="version")
        {
            XML_Version=TextOfElement;
            FindTag=true;
        }
        if (NameOfElement=="link")
        {
            XML_Link=TextOfElement;
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
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::checkXmlLeafTags()
{
    /*
    Проверяет наличие тэгов и правильное их выполнение. Внутренная функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (XML_Format!="Harrix Optimization Testing")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный формат данных. Это не Harrix Optimization Testing.");
        Error=true;
    }
    if (XML_Link!="https://github.com/Harrix/HarrixFileFormats")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильный сайт в описании. Должен быть https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if (XML_Version!="1.0")
    {
        HtmlMessageOfError+=HQt_ShowAlert("Неправильная версия формата Harrix Optimization Testing. Данная функция обрабатывает версию 1.0.");
        Error=true;
    }
    if (XML_Number_Of_Parameters==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_parameters.");
        Error=true;
    }
    if (XML_Number_Of_Parameters==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Минимальное число параметров 1. Подробности в описании формата данных на https://github.com/Harrix/HarrixFileFormats.");
        Error=true;
    }
    if ((XML_Number_Of_Parameters<0)&&(XML_Number_Of_Parameters!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_parameters. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (XML_Number_Of_Experiments==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_experiments.");
        Error=true;
    }
    if (XML_Number_Of_Experiments==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Минимальное число экспериментов 1.");
        Error=true;
    }
    if ((XML_Number_Of_Experiments<0)&&(XML_Number_Of_Experiments!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_experiments. Число параметров не может быть отрицательным.");
        Error=true;
    }
    if (XML_Max_Count_Of_Fitness==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга max_count_of_fitness.");
        Error=true;
    }
    if (XML_Max_Count_Of_Fitness==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Минимальное число вычислений целевой функции 1, и то это очень мало.");
        Error=true;
    }
    if ((XML_Max_Count_Of_Fitness<0)&&(XML_Max_Count_Of_Fitness!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге max_count_of_fitness. Число вычислений целевой функции не может быть отрицательным.");
        Error=true;
    }
    if (XML_Number_Of_Runs==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_runs.");
        Error=true;
    }
    if (XML_Number_Of_Runs==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Минимальное число запусков алгоритма для усреднения 1 (желательно от 10).");
        Error=true;
    }
    if ((XML_Number_Of_Runs<0)&&(XML_Number_Of_Runs!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_runs. Число запусков алгоритма для усреднения не может быть отрицательным.");
        Error=true;
    }
    if (XML_Number_Of_Measuring==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга number_of_measuring.");
        Error=true;
    }
    if (XML_Number_Of_Measuring==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Минимальное число измерений для настройки алгоритма 1 (желательно от 10).");
        Error=true;
    }
    if ((XML_Number_Of_Measuring<0)&&(XML_Number_Of_Measuring!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге number_of_measuring. Число измерений для настройки алгоритма не может быть отрицательным.");
        Error=true;
    }
    if (XML_Chromosome_Length==-1)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о размерности тестовой задачи chromosome_length.");
        Error=true;
    }
    if (XML_Chromosome_Length==0)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге chromosome_length. Минимальная длина хромосомы 1 (желательно от 10).");
        Error=true;
    }
    if ((XML_Chromosome_Length<0)&&(XML_Chromosome_Length!=-1))
    {
        HtmlMessageOfError+=HQt_ShowAlert("Ошибка в тэге chromosome_length. Длина хромосомы не может быть отрицательной.");
        Error=true;
    }
    if (XML_Full_Name_Test_Function.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии тестовой функции full_name_test_function.");
        Error=true;
    }
    if (XML_Name_Test_Function.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о названии тестовой функции name_test_function.");
        Error=true;
    }
    if (XML_Full_Name_Algorithm.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о полном названии алгоритма full_name_algorithm.");
        Error=true;
    }
    if (XML_Name_Algorithm.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об названии алгоритма name_algorithm.");
        Error=true;
    }
    if (XML_Date.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о дате создания документа date.");
        Error=true;
    }
    if (XML_Author.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга об авторе author");
        Error=true;
    }
    if (XML_Link_Algorithm.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание алгоритма link_algorithm.");
        Error=true;
    }
    if (XML_Link_Test_Function.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Нет тэга о ссылке на описание тестовой функции link_test_function.");
        Error=true;
    }
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::memoryAllocation()
{
    /*
    Выделяет память под необходимые массивы. Внутренная функция.
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

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEy=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEy[i]=new double[XML_Number_Of_Measuring];

    //Матрица значений ошибок R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfR=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfR[i]=new double[XML_Number_Of_Measuring];

    //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEx=new double[XML_Number_Of_Experiments];

    //Вектор средних ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEy=new double[XML_Number_Of_Experiments];

    //Вектор средних ошибок R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfR=new double[XML_Number_Of_Experiments];

    //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEx=new double[XML_Number_Of_Experiments];

    //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEy=new double[XML_Number_Of_Experiments];

    //Вектор дисперсий ошибок R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfR=new double[XML_Number_Of_Experiments];

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfParameters=new int*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfParameters[i]=new int[XML_Number_Of_Parameters];

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружений новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в ListOfParameterOptions
    //находится под номером соответствующим.
    ListOfParameterOptions=new QStringList[XML_Number_Of_Parameters];

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfNameParameters=new QStringList[XML_Number_Of_Experiments];
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::readXmlDataTags()
{
    /*
    Считывает и проверяет тэги данных. Внутренная функция.
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
                for (int k=0;k<XML_Number_Of_Parameters;k++)
                {
                    //считаем массив параметров алгоритма
                    NameOfAttr="parameters_of_algorithm_"+QString::number(k+1);
                    AttrOfElement = Rxml.attributes().value(NameOfAttr).toString();

                    //считываеv названия параметров алгорима
                    if (i==0) NamesOfParameters << HQt_TextBeforeEqualSign(AttrOfElement);

                    //теперь значения параметров алгоритма
                    ListOfParameterOptions[k] = HQt_AddUniqueQStringInQStringList (ListOfParameterOptions[k], HQt_TextAfterEqualSign(AttrOfElement));

                    MatrixOfParameters[i][k]=HQt_SearchQStringInQStringList (ListOfParameterOptions[k], HQt_TextAfterEqualSign(AttrOfElement));
                    MatrixOfNameParameters[i] << HQt_TextAfterEqualSign(AttrOfElement);
                }

                for (int k=0;k<XML_Number_Of_Measuring;k++)
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
                            MatrixOfEx[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            MatrixOfEy[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            MatrixOfR[i][k]=HQt_QStringToNumber(TextOfElement);
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
                            MatrixOfEx[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            MatrixOfEy[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            MatrixOfR[i][k]=HQt_QStringToNumber(TextOfElement);
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
                            MatrixOfEx[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ex=true;
                        }

                        if (NameOfElement=="ey")
                        {
                            MatrixOfEy[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_ey=true;
                        }

                        if (NameOfElement=="r")
                        {
                            MatrixOfR[i][k]=HQt_QStringToNumber(TextOfElement);
                            bool_r=true;

                            if ((MatrixOfR[i][k]<0)||(MatrixOfR[i][k]>1))
                            {
                                HtmlMessageOfError+=HQt_ShowAlert("Сейчас просматривался тэг нажедности R. Надежность это величина от 0 до 1. У вас это не так.");
                                Error=true;
                            }
                        }

                        if (!((bool_ex)&&(bool_ey)&&(bool_r)))
                        {
                            HtmlMessageOfError+=HQt_ShowAlert("В тэге measuring были не все три тэга ex, ee, r (или вообще не было).");
                            Error=true;
                        }
                    }
                    else
                    {
                        //должен быть тэг measuring, а его нет
                        HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга measuring. Что не так в струтуре или данных файла.");
                        Error=true;
                    }
                }

            }
            else
            {
                //должен быть тэг experiment, а его нет
                HtmlMessageOfError+=HQt_ShowAlert("Анализатор ожидал тэга experiment. Что не так в струтуре или данных файла.");
                Error=true;
            }

        }

        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
        i++;
    }

    if (i!=XML_Number_Of_Experiments)
    {
        HtmlMessageOfError+=HQt_ShowAlert("Число экспериментов в тэге number_of_experiments не равно реальному числу экспериментов в xml файле.");
        Error=true;
    }
}
//--------------------------------------------------------------------------
bool DataOfHarrixOptimizationTesting::readXmlTreeTag(QString tag)
{
    /*
    Считывает и проверяет тэг, который содержит внутри себя другие тэги. Внутренная функция.
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
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::zeroArray()
{
    /*
    Обнуляет массивы, в котрые записывается информация о данных из файла. Внутренная функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //"Обнулим" матрицы
    TMHL_FillMatrix(MatrixOfEx, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
    TMHL_FillMatrix(MatrixOfEy, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
    TMHL_FillMatrix(MatrixOfR,  XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);
    TMHL_FillMatrix(MatrixOfParameters,  XML_Number_Of_Experiments, XML_Number_Of_Parameters, -1);
    TMHL_ZeroVector(MeanOfEx,XML_Number_Of_Experiments);
    TMHL_ZeroVector(MeanOfEy,XML_Number_Of_Experiments);
    TMHL_ZeroVector(MeanOfR ,XML_Number_Of_Experiments);
    TMHL_ZeroVector(VarianceOfEx,XML_Number_Of_Experiments);
    TMHL_ZeroVector(VarianceOfEy,XML_Number_Of_Experiments);
    TMHL_ZeroVector(VarianceOfR ,XML_Number_Of_Experiments);
    for (int k=0;k<XML_Number_Of_Parameters;k++) ListOfParameterOptions[k].clear();
    (NamesOfParameters).clear();
}
//--------------------------------------------------------------------------

void DataOfHarrixOptimizationTesting::makingAnalysis()
{
    /*
    Выполняет анализ считанных данных. Внутренная функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    for (int i=0;i<XML_Number_Of_Experiments;i++)
    {
        //заполним значениями вектор средних значений критериев и дисперсий
        for (int j=0;j<XML_Number_Of_Measuring;j++)
        {
            MeanOfEx[i]+=MatrixOfEx[i][j];
            MeanOfEy[i]+=MatrixOfEy[i][j];
            MeanOfR[i] +=MatrixOfR[i][j];
        }

        MeanOfEx[i]/=double(XML_Number_Of_Measuring);
        MeanOfEy[i]/=double(XML_Number_Of_Measuring);
        MeanOfR[i] /=double(XML_Number_Of_Measuring);

        VarianceOfEx[i]+=TMHL_Variance(MatrixOfEx[i],XML_Number_Of_Measuring);
        VarianceOfEy[i]+=TMHL_Variance(MatrixOfEx[i],XML_Number_Of_Measuring);
        VarianceOfR [i]+=TMHL_Variance(MatrixOfR [i],XML_Number_Of_Measuring);
    }
}
//--------------------------------------------------------------------------
