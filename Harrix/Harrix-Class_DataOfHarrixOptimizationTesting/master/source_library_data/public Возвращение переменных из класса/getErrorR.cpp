double HarrixClass_DataOfHarrixOptimizationTesting::getErrorR(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения надежности R.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения надежности R.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>Data.getNumberOfExperiments()-1) Number_Of_Experiment=Data.getNumberOfExperiments()-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>Data.getNumberOfMeasuring()-1) Number_Of_Measuring=Data.getNumberOfMeasuring()-1;

    return Data.getErrorR(Number_Of_Experiment,Number_Of_Measuring);
}