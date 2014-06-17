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