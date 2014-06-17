double HarrixClass_OnlyDataOfHarrixOptimizationTesting::getErrorEy(int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Получение значения ошибки Ey.
    Входные параметры:
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Значения ошибки Ey.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    return MatrixOfEy[Number_Of_Experiment][Number_Of_Measuring];
}