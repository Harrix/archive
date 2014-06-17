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