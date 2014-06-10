//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.24
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
#define FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H

////////////////////////////////////////////////////////////////////////////
////////////////////// ФУНКЦИИ ПО РАБОТЕ С КЛАССОМ /////////////////////////
////////////////////////////////////////////////////////////////////////////

//Подсчитывает число HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
int HCDOHOT_NumberFilesInDir(QString path);

//Заполняет массив SeveralData данными из всех файлов *.hdata из папки.
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path);

//Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки.
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path);


/////////////////////////// ГЕНЕРАЦИЯ ОТЧЕТОВ //////////////////////////////
////////////////////////////////////////////////////////////////////////////

//Генерирует отчет Latex по алгоритму по файлам *.hdata одного алгоритма, просматривая все файлы в папке.
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave);

//Генерирует простой отчет Latex по алгоритму по файлу *.hdata.
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave);

//Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata.
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave);

/// БЛОК ФУНКЦИЙ ПРОВЕРКИ РАВЕНСТВА ПЕРЕМННЫХ НЕСКОЛЬКИХ ИССЛЕДОВАНИЙ //////
////////////////////////////////////////////////////////////////////////////

//Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство авторов исследований.
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство дат исследований.
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство email авторов исследований.
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство полных названий алгоритмов в исследованиях
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство идентификаторов тестовых функций в исследованиях
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForForNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство полных названий тестовых функций в исследованиях
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForForFullNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство количества проверяемых параметров алгоритма оптимизации в исследованиях.
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство форматов файлов в исследованиях.
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство версий формата файла в исследованиях.
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство ссылок на описание версий формата файла в исследованиях.
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Проверяет по критерию Вилкосона два исследования алгоритмов.
int HCDOHOT_CompareOfDataByWilcoxonW (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2, double Q);

#endif // FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
