//HarrixClass_DataOfHarrixOptimizationTesting
//Версия 1.26
//Класс для считывания информации формата данных Harrix Optimization Testing на C++ для Qt.
//https://github.com/Harrix/HarrixClass_DataOfHarrixOptimizationTesting
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#ifndef FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
#define FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Блок функций проверки равенства переменных нескольких исследований
int HCDOHOT_CompareOfDataByWilcoxonW (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2, double Q);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForAuthor (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDate (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForFullNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForLink (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNameTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfParameters (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N);
bool HCDOHOT_CompareOfDataForVersion (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N);

//Генерация отчетов
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave);
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave);
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml);
void HCDOHOT_GeneratedSimpleReportFromFile(QString filename, QString pathForSave);

//Функции по работе с классом
int HCDOHOT_NumberFilesInDir(QString path);
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesInDir(HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, QString path);
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml);
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Блок функций проверки равенства переменных нескольких исследований
//*****************************************************************
//*****************************************************************
//Генерация отчетов
//*****************************************************************
//*****************************************************************
//Функции по работе с классом
//*****************************************************************

#endif // FUNCTIONS_FOR_HARRIXCLASS_DATAOFHARRIXOPTIMIZATIONTESTING_H
