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