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