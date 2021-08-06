//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.27
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
#define HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H

#include "HarrixClass_OnlyDataOfHarrixOptimizationTesting.h"
#include <QXmlStreamReader>

class HarrixClass_DataOfHarrixOptimizationTesting
{
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

public:
//_Конструкторы и деструкторы
HarrixClass_DataOfHarrixOptimizationTesting(QString filename);
HarrixClass_DataOfHarrixOptimizationTesting();
~HarrixClass_DataOfHarrixOptimizationTesting();

//Возвращение HTML данных из класса
QString getHtml();
QString getHtmlMessageOfError();
QString getHtmlReport();

//Возвращение LaTeX данных из класса
QString getFullLatex();
QString getFullLatexAboutParameters();
QString getFullLatexAnalysis();
QString getFullLatexInfo();
QString getFullLatexTable();
QString getFullLatexTableEx();
QString getFullLatexTableEy();
QString getFullLatexTableR();
QString getLatex();
QString getLatexAboutParameters();
QString getLatexAnalysis();
QString getLatexInfo();
QString getLatexTable();
QString getLatexTableEx();
QString getLatexTableEy();
QString getLatexTableR();

//Возвращение переменных из класса
QString getAuthor();
bool getCheckAllCombinations();
HarrixClass_OnlyDataOfHarrixOptimizationTesting& getData();
QString getDate();
qint64 getDimensionTestFunction();
QString getEmail();
double getErrorEx(int Number_Of_Experiment, int Number_Of_Measuring);
double getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring);
double getErrorR(int Number_Of_Experiment, int Number_Of_Measuring);
QString getFormat();
QString getFullNameAlgorithm();
QString getFullNameTestFunction();
QString getLink();
QString getLinkAlgorithm();
QString getLinkTestFunction();
qint64 getMaxCountOfFitness();
double getMeanEx(int Number_Of_Experiment);
double getMeanEy(int Number_Of_Experiment);
double getMeanR(int Number_Of_Experiment);
QString getNameAlgorithm();
QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
QString getNameTestFunction();
qint64 getNumberOfExperiments();
qint64 getNumberOfMeasuring();
int getNumberOfOption(QString NameOption);
qint64 getNumberOfParameters();
qint64 getNumberOfRuns();
int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
bool getSuccessReading();
double getVarianceOfEx(int Number_Of_Experiment);
double getVarianceOfEy(int Number_Of_Experiment);
double getVarianceOfR(int Number_Of_Experiment);
QString getVersion();

//Операторы
void operator = (HarrixClass_DataOfHarrixOptimizationTesting& B);

//Специализированные функции
QString makingLatexTable2D(QString Title, QStringList InfoForEveryExperiment);

private:
//Внутренние функции
void checkXmlLeafTags();
QString getLatexBegin();
QString getLatexEnd();
void initializationOfVariables();
void makingListOfVectorParameterOptions();
void memoryAllocation();
void memoryDeallocation();
void readXml();
void readXmlDataTags();
void readXmlLeafTag();
bool readXmlTreeTag(QString tag);
void zeroArray();

//Создание содержимого отчетов LaTeX и HTML
void makingHtmlReport();
void makingLatexAboutParameters();
void makingLatexAnalysis();
void makingLatexInfo();
void makingLatexListOfVectorParameterOptions();
void makingLatexListOfVectorParameterOptions2();
void makingLatexTableEx();
void makingLatexTableEy();
void makingLatexTableR();

//Функции анализа данных
void makingAnalysis();

//ПЕРЕМЕННЫЕ
//Главные переменные
HarrixClass_OnlyDataOfHarrixOptimizationTesting Data;//сырые данные исследований, считываемые из FileXML
QString FileXML;//сохраняем на всякий случай содержимое файла	
QXmlStreamReader Rxml;//непосредственно анализируемый XML файл

//Строка с возвращаемым HTML кодом
QString Html;
//далее идет набор переменных для кусков Html кодов
QString HtmlMessageOfError;// сюда записывается код о сообщениях ошибок
QString HtmlReport;//текст Html для отображения отчета о считывании XML файла.

//Строка с возвращаемым кодом  Latex для добавления в https://github.com/Harrix/Harrix-Document-Template-LaTeX
QString Latex;
QString LatexTable;//Первичная информация плюс таблицы. Без анализа
//далее идет набор переменных для кусков Latex кодов
QString LatexTableEx;//для отображения таблицы данных о ошибке Ex
QString LatexTableEy;//для отображения таблицы данных о ошибке Ey
QString LatexTableR; //для отображения таблицы данных о надежности R
QString LatexInfo;//Для отображения информации о исследовании
QString LatexAboutParameters;//Для отображения данных о обнаруженных параметрах алгоритма и какие они бывают
QString LatexAnalysis;//Для отображения первоначального анализа данных.
QString LatexListOfVectorParameterOptions;//Для отображения списка вектора параметров алгоритма

//Номера комбинаций вариантов настроек
//Содержит номера от 1 до XML_Number_Of_Experiments
//Дополнительный вектор, чтобы понимать, какой номер у
//эксперимента с настройками из ListOfVectorParameterOptions
double *NumberOfListOfVectorParameterOptions;

//далее идут внутренние служебные переменные
QString Un;//уникальная строка для использования ссылок в Latex
QString NameForHead;//тот кусок, который будет вставляться в таблицы, заголовки: какой-то алгоритм оптимизации на такой-то тестовой функции такой-то размерности.
QString Cell1,Cell2,Cell3,Cell4,Cell5;//для записи ячеек в полные таблицы
QString Parbox;//нужно или не нужно делать в формулах фиксированную ячейку для длинного текста
QString NameOfElement;//имя тэга
QString TextOfElement;//содержимое тэга
QString AttrOfElement;//содержимое атрибута тэга
QString NameOfAttr;//название атрибута тэга
bool Error;//есть ли ошибка при анализе XML файла
bool Zero_Number_Of_Parameters;//Число параметров равно нулю или нет
};
#endif // HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
