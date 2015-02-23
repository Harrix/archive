//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.26
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
#define HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H

//Класс, который только содержит сырые данные исследований, которые считываются
//классом HarrixClass_DataOfHarrixOptimizationTesting. В данном классе нет ни проверки
//корректности ввода информации и др. Это служебный класс.
class HarrixClass_OnlyDataOfHarrixOptimizationTesting
{
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

public:
//_Конструкторы и деструкторы
HarrixClass_OnlyDataOfHarrixOptimizationTesting();
~HarrixClass_OnlyDataOfHarrixOptimizationTesting();

//Возвращение данных из класса
QString getAuthor();
bool getCheckAllCombinations();
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
QStringList getListOfParameterOptions(int Number_Of_Parameter);
QStringList getListOfVectorParameterOptions();
QString getListOfVectorParameterOptions(int Number_Of_Experiment);
qint64 getMaxCountOfFitness();
double getMeanEx(int Number_Of_Experiment);
double getMeanEy(int Number_Of_Experiment);
double getMeanOfAllEx();
double getMeanOfAllEy();
double getMeanOfAllR();
double getMeanR(int Number_Of_Experiment);
QString getNameAlgorithm();
QString getNameOption(int Number_Of_Parameter);
QString getNameParameter(int Number_Of_Experiment, int Number_Of_Parameter);
QString getNameTestFunction();
QStringList getNamesOfParameters();
qint64 getNumberOfExperiments();
qint64 getNumberOfMeasuring();
qint64 getNumberOfParameters();
qint64 getNumberOfRuns();
QString getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option);
QString getOptionFromListOfParameterOptionsForTable(int Number_Of_Parameter, int Number_Of_Option);
int getParameter(int Number_Of_Experiment, int Number_Of_Parameter);
bool getSuccessReading();
double getVarianceOfAllEx();
double getVarianceOfAllEy();
double getVarianceOfAllR();
double getVarianceOfEx(int Number_Of_Experiment);
double getVarianceOfEy(int Number_Of_Experiment);
double getVarianceOfR(int Number_Of_Experiment);
QString getVersion();

//Задание данных в класс
void addListOfParameterOptions(QString Option, int Number_Of_Parameter);
void addListOfVectorParameterOptions(QString Option);
void addNameOption(QString Option);
void addNameParameter(QString Name, int Number_Of_Experiment);
void setAuthor(QString Author);
void setCheckAllCombinations(bool AllCombinations);
void setDate(QString Date);
void setDimensionTestFunction(qint64 DimensionTestFunction);
void setEmail(QString Email);
void setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring);
void setErrorEy(double ErrorEy,int Number_Of_Experiment, int Number_Of_Measuring);
void setErrorR(double ErrorR,int Number_Of_Experiment, int Number_Of_Measuring);
void setFormat(QString Format);
void setFullNameAlgorithm(QString FullNameAlgorithm);
void setFullNameTestFunction(QString FullNameTestFunction);
void setLink(QString Link);
void setLinkAlgorithm(QString LinkAlgorithm);
void setLinkTestFunction(QString LinkTestFunction);
void setListOfParameterOptions(QStringList List, int Number_Of_Parameter);
void setMaxCountOfFitness(qint64 MaxCountOfFitness);
void setMeanEx(double MeanEx, int Number_Of_Experiment);
void setMeanEy(double MeanEy, int Number_Of_Experiment);
void setMeanOfAllEx(double Mean);
void setMeanOfAllEy(double Mean);
void setMeanOfAllR(double Mean);
void setMeanR(double MeanR, int Number_Of_Experiment);
void setNameAlgorithm(QString NameAlgorithm);
void setNameTestFunction(QString NameTestFunction);
void setNumberOfExperiments(qint64 NumberOfExperiments);
void setNumberOfListOfVectorParameterOptions(double Num,int Number);
void setNumberOfMeasuring(qint64 NumberOfMeasuring);
void setNumberOfParameters(qint64 NumberOfParameters);
void setNumberOfRuns(qint64 NumberOfRuns);
void setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter);
void setSuccessReading(bool Success);
void setVarianceOfAllEx(double Variance);
void setVarianceOfAllEy(double Variance);
void setVarianceOfAllR(double Variance);
void setVarianceOfEx(double Variance, int Number_Of_Experiment);
void setVarianceOfEy(double Variance, int Number_Of_Experiment);
void setVarianceOfR(double Variance, int Number_Of_Experiment);
void setVersion(QString Version);

//Операторы
void operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B);

//Служебные функции
void initializationOfVariables();
void memoryAllocation();
void memoryDeallocation();
};

#endif // HARRIXCLASS_ONLYDATAOFHARRIXOPTIMIZATIONTESTING_H
