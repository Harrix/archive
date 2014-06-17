void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setVarianceOfEx(double Variance, int Number_Of_Experiment)
{
    /*
    Получение дисперсии значения ошибки Ex по измерениям для настройки (сколько точек было по столько и усредняем).
    Входные параметры:
	 Variance - значение заносимой дисперсии;
     Number_Of_Experiment - номер комбинации вариантов настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    VarianceOfEx[Number_Of_Experiment] = Variance;
}