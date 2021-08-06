//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.27
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibraryForLaTeX.h"
#include "HarrixMathLibrary.h"
#include "HarrixClass_DataOfHarrixOptimizationTesting.h"
#include "HarrixClass_OnlyDataOfHarrixOptimizationTesting.h"
#include "Functions_For_HarrixClass_DataOfHarrixOptimizationTesting.h"

//*****************************************************************
//Блок функций проверки равенства переменных нескольких исследований
//*****************************************************************
int HCDOHOT_CompareOfDataByWilcoxonW (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2, double Q)
{
    /*
    Проверяет по критерию Вилкосона два исследования алгоритмов.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование;
     Q - уровень значимости. Может принимать значения:
       0.002;
       0.01;
       0.02;
       0.05;
       0.1;
       0.2.
    Возвращаемое значение:
     -2 - уровень значимости выбран неправильно (не из допустимого множества);
     -1 - объемы выборок не позволяют провести проверку при данном уровне значимости (или они не положительные);
     0 - выборки не однородны  при данном уровне значимости;
     1 - выборки однородны  при данном уровне значимости;
     */
    int VHML_Result=1;

    int i,j;

    int N1 = (*Data1).getNumberOfExperiments()*(*Data1).getNumberOfMeasuring();
    int N2 = (*Data2).getNumberOfExperiments()*(*Data2).getNumberOfMeasuring();

    double *Vector1 = new double [N1];
    double *Vector2 = new double [N2];

    for (i=0;i<N1;i++) Vector1[i]=0;
    for (i=0;i<N2;i++) Vector2[i]=0;

    for (i=0;i<(*Data1).getNumberOfExperiments();i++)
        for (j=0;j<(*Data1).getNumberOfMeasuring();j++)
        {
            Vector1[i*(*Data1).getNumberOfMeasuring()+j]=(*Data1).getErrorEx(i,j);
        }

    for (i=0;i<(*Data2).getNumberOfExperiments();i++)
        for (j=0;j<(*Data2).getNumberOfMeasuring();j++)
        {
            Vector2[i*(*Data2).getNumberOfMeasuring()+j]=(*Data2).getErrorEx(i,j);
        }

    VHML_Result = HML_WilcoxonW(Vector1, Vector2, N1, N2, Q);

    delete [] Vector1;
    delete [] Vector2;

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство авторов исследований.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getAuthor()!=(*Data2).getAuthor()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getAuthor();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getAuthor() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getAuthor();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getAuthor() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getCheckAllCombinations()!=(*Data2).getCheckAllCombinations()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    int Info=SeveralData[0].getCheckAllCombinations();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getCheckAllCombinations() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    int Info=SeveralData[0].getCheckAllCombinations();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getCheckAllCombinations() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getDate()!=(*Data2).getDate()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getDate();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDate() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForDate (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getDate();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDate() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getDimensionTestFunction()!=(*Data2).getDimensionTestFunction()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getDimensionTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDimensionTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getDimensionTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDimensionTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getEmail()!=(*Data2).getEmail()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getEmail();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getEmail() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getEmail();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getEmail() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getFormat()!=(*Data2).getFormat()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFormat();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFormat() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFormat();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFormat() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство полных названий алгоритмов в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getFullNameAlgorithm()!=(*Data2).getFullNameAlgorithm()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство полных названий алгоритмов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFullNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFullNameAlgorithm() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство полных названий алгоритмов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFullNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFullNameAlgorithm() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство полных названий тестовых функций в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getFullNameTestFunction()!=(*Data2).getFullNameTestFunction()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство полных названий тестовых функций в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFullNameTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFullNameTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForFullNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство полных названий тестовых функций в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFullNameTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFullNameTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство ссылок на описание версий формата файла в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getLink()!=(*Data2).getLink()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство ссылок на описание версий формата файла в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getLink();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getLink() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForLink (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство ссылок на описание версий формата файла в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getLink();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getLink() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getMaxCountOfFitness()!=(*Data2).getMaxCountOfFitness()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getMaxCountOfFitness();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getMaxCountOfFitness() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getMaxCountOfFitness();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getMaxCountOfFitness() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNameAlgorithm()!=(*Data2).getNameAlgorithm()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameAlgorithm() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameAlgorithm() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство идентификаторов тестовых функций в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNameTestFunction()!=(*Data2).getNameTestFunction()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов тестовых функций в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getNameTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов тестовых функций в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getNameTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameTestFunction() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNumberOfExperiments()!=(*Data2).getNumberOfExperiments()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfExperiments();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfExperiments() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfExperiments();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfExperiments() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNumberOfMeasuring()!=(*Data2).getNumberOfMeasuring()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfMeasuring();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfMeasuring() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfMeasuring();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfMeasuring() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества проверяемых параметров алгоритма оптимизации в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNumberOfParameters()!=(*Data2).getNumberOfParameters()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества проверяемых параметров алгоритма оптимизации в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfParameters();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfParameters() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества проверяемых параметров алгоритма оптимизации в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfParameters();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfParameters() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNumberOfRuns()!=(*Data2).getNumberOfRuns()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfRuns();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfRuns() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfRuns();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfRuns() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство версий формата файла в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getVersion()!=(*Data2).getVersion()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство версий формата файла в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getVersion();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getVersion() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство версий формата файла в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getVersion();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getVersion() ) VHML_Result=false;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Генерация отчетов
//*****************************************************************
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml)
{
    /*
    Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    filename = QDir::toNativeSeparators(filename);
    pathForSave = QDir::toNativeSeparators(pathForSave);
    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);

    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    if (filename.length()>0)
    {
        QString Html;//сюда записывается код  HTML по анализу файла данных
        QString Latex;//сюда записывается код  Latex для добавления в https://github.com/Harrix/HarrixLaTeXDocumentTemplate

        HarrixClass_DataOfHarrixOptimizationTesting Data(filename);

        if (Data.getSuccessReading())
        {
            Html=Data.getHtml();

            Latex=Data.getFullLatexAnalysis();

            HQt_SaveFile(Latex, pathForSave+"\\Report.tex");

            if (!pathForTempHtml.isEmpty())
            {
                HQt_AddHtml(Html);
            }
        }
        else
        {
            //выводим ошибку
            Html=Data.getHtml();
            if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
        }

    }
}
//--------------------------------------------------------------------------
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave)
{
    /*
    Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata без генерации Html отчета.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    HCDOHOT_GeneratedAnalysisReportFromFile(filename, pathForSave, "");
}
//---------------------------------------------------------------------------

void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml)
{
    /*
    Генерирует отчет Latex по алгоритму по файлам *.hdata алгоритма, просматривая все файлы в папке.
    То, чтобы в папке были файлы только одного алгоритма, вы берете на себя.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    path = QDir::toNativeSeparators(path);
    pathForSave = QDir::toNativeSeparators(pathForSave);
    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);

    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    if (path.length()>0)
    {
        QString Html;//сюда записывается код  HTML по анализу файла данных
        QString Latex;//сюда записывается код  Latex для добавления в https://github.com/Harrix/HarrixLaTeXDocumentTemplate
        QString LatexInclude;//сюда записываются отдельные исследования, которые сохраняются в отдельные файлы
        QString filename;
        QString namealg;

        //Вытащим название папки, из которой всё считываем
        QStringList dirs = path.split( "\\", QString::SkipEmptyParts );
        namealg = dirs.at(dirs.count()-1);
        QString namealgNameForSave=namealg;
        if (namealg.at(0)=='_') namealg = namealg.mid(1);

        Html=path;
        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        Latex+=HQt_LatexBeginArticle();//Начало LaTeX файла

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                Html=HQt_ShowSimpleText(filename);
                if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

                HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                if (Data.getSuccessReading())
                {
                    if (i==0)
                    {
                        Latex+="\\title{Исследование алгоритма оптимизации "+HQt_ForcedWordWrap(HQt_TextToTextForLatex(namealg))+"}\n";
                        //namealg=Data.getNameAlgorithm();

                        Latex+="\\author{"+HQt_TextToTextForLatex(Data.getAuthor())+"}\n";
                        Latex+="\\date{\\today}\n";
                        Latex+="\\maketitle\n\n";
                        Latex+="\\tableofcontents\n";
                        Latex+="\\newpage\n\n";
                        Latex+="\\section{Вводная информация}\n\n";
                        Latex+="Данный файл и другие исследования располагаются по адресу:\n\n \\href {https://github.com/Harrix/HarrixPDFDataOfOptimizationTesting} {https://github.com/Harrix/HarrixPDFDataOfOptimizationTesting}.\n\n";
                        Latex+="Анализ данных исследований можно посмотреть по адресу:\n\n \\href {https://github.com/Harrix/HarrixAnalysisPDFDataOfOptimizationTesting} {https://github.com/Harrix/HarrixAnalysisPDFDataOfOptimizationTesting}.\n\n";

                        Latex+="Данные исследований взяты из базы исследований алгоритмов оптимизации:\n\n \\href {https://github.com/Harrix/HarrixDataOfOptimizationTesting} {https://github.com/Harrix/HarrixDataOfOptimizationTesting}.\n\n";
                        Latex+="О методологии проведения исследований можно прочитать в описании формата данных <<Harrix Optimization Testing>> в главе <<Идея проведения исследований эффективности алгоритмов>> по адресу:\n\n \\href {https://github.com/Harrix/HarrixFileFormats} {https://github.com/Harrix/HarrixFileFormats}.\n\n";
                        Latex+="Описание алгоритма оптимизации можно найти по адресу:\n\n \\href {https://github.com/Harrix/HarrixOptimizationAlgorithms} {https://github.com/Harrix/HarrixOptimizationAlgorithms}.\n\n";
                        Latex+="Описание тестовых функций можно найти по адресу:\n\n \\href {https://github.com/Harrix/HarrixTestFunctions} {https://github.com/Harrix/HarrixTestFunctions}.\n\n";
                        Latex+="С автором можно связаться по адресу \\href {mailto:sergienkoanton@mail.ru} {sergienkoanton@mail.ru} или  \\href {http://vk.com/harrix} {http://vk.com/harrix}. Сайт автора, где публикуются последние новости: \\href {http://blog.harrix.org} {http://blog.harrix.org}, а проекты располагаются по адресу \\href {http://harrix.org} {http://harrix.org}.\n\n";
                    }

                    LatexInclude=Data.getLatexTable();
                    HQt_SaveFile(LatexInclude, pathForSave+"\\"+(HQt_GetNameFromFilename(filename)).replace("_","").replace(" ", "")+".tex");
                    Latex += "\\input{"+(HQt_GetNameFromFilename(filename)).replace("_","").replace(" ", "")+"}\n";
                }
                else
                {
                    //выводим ошибку
                    Html=Data.getHtml();
                    if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                }

            }
            QGuiApplication::processEvents();
        }

        Latex+=HQt_LatexEnd();
        HQt_SaveFile(Latex, pathForSave+"\\"+namealgNameForSave+".tex");

        Html=HQt_ShowSimpleText("Сохранили");
        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

    }
}
//--------------------------------------------------------------------------
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave)
{
    /*
    Генерирует отчет Latex по алгоритму по файлам *.hdata алгоритма, просматривая все файлы в папке без сохранения отчета в HTML.
    То, чтобы в папке были файлы только одного алгоритма, вы берете на себя.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
    Возвращаемое значение:
     Отсутствует.
     */
    HCDOHOT_GeneratedReportAboutAlgorithmFromDir(path, pathForSave, "");
}
//---------------------------------------------------------------------------

void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml)
{
    /*
    Генерирует простой отчет Latex по алгоритму по файлу *.hdata.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    filename = QDir::toNativeSeparators(filename);
    pathForSave = QDir::toNativeSeparators(pathForSave);
    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);

    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    if (filename.length()>0)
    {
        QString Html;//сюда записывается код  HTML по анализу файла данных
        QString Latex;//сюда записывается код  Latex для добавления в https://github.com/Harrix/HarrixLaTeXDocumentTemplate

        HarrixClass_DataOfHarrixOptimizationTesting Data(filename);

        if (Data.getSuccessReading())
        {
            Html=Data.getHtml();

            Latex=Data.getFullLatexTable();

            HQt_SaveFile(Latex, pathForSave+"\\Report.tex");

            if (!pathForTempHtml.isEmpty())
            {
                HQt_AddHtml(Html);
            }
        }
        else
        {
            //выводим ошибку
            Html=Data.getHtml();
            if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
        }

    }
}
//--------------------------------------------------------------------------
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave)
{
    /*
    Генерирует простой отчет Latex по алгоритму по файлу *.hdata без вывода в HTML.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
    Возвращаемое значение:
     Отсутствует.
     */
    HCDOHOT_GeneratedSimpleReportFromFile(filename, pathForSave, "");
}
//---------------------------------------------------------------------------


//*****************************************************************
//Функции по работе с классом
//*****************************************************************
int HCDOHOT_NumberFilesInDir(QString path)
{
    /*
    Подсчитывает число HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
     */
    int Result=0;

    path = QDir::toNativeSeparators(path);

    if (path.length()>0)
    {
        QString filename;

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                //HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                Result++;
            }
            QGuiApplication::processEvents();
        }
    }

    return Result;
}
//---------------------------------------------------------------------------

int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml)
{
    /*
    Заполняет массив SeveralData данными из всех файлов *.hdata из папки.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=0;

    path = QDir::toNativeSeparators(path);

    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);
    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    QString Html;

    if (path.length()>0)
    {
        QString filename;

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                SeveralData[i]=Data;

                if (!pathForTempHtml.isEmpty())
                {
                    if (Data.getSuccessReading())
                    {
                        Html=HQt_ShowSimpleText(filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                    else
                    {
                        Html=HQt_ShowAlert("Ошибка при считывании файла "+ filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                }

                Result++;
            }
            QGuiApplication::processEvents();
        }
    }

    return Result;
}
//--------------------------------------------------------------------------
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path)
{
    /*
    Заполняет массив SeveralData данными из всех файлов *.hdata из папки без генерации отчета в HTML.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=HCDOHOT_ReadFilesInDir(SeveralData, path, "");

    return Result;
}
//---------------------------------------------------------------------------

int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml)
{
    /*
    Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=0;

    path = QDir::toNativeSeparators(path);

    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);
    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    QString Html;

    if (path.length()>0)
    {
        QString filename;

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                SeveralData[i]=Data.getData();

                if (!pathForTempHtml.isEmpty())
                {
                    if (Data.getSuccessReading())
                    {
                        Html=HQt_ShowSimpleText(filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                    else
                    {
                        Html=HQt_ShowAlert("Ошибка при считывании файла "+ filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                }

                Result++;
            }
            QGuiApplication::processEvents();
        }
    }

    return Result;
}
//--------------------------------------------------------------------------
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path)
{
    /*
    Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки. Без создания html отчета.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=0;

    Result = HCDOHOT_ReadFilesOnlyDataInDir(SeveralData, path, "");

    return Result;
}
//---------------------------------------------------------------------------