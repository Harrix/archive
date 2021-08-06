void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setErrorEx(double ErrorEx,int Number_Of_Experiment, int Number_Of_Measuring)
{
    /*
    Задание значения ошибки Ex.
    Входные параметры:
     ErrorEx - задаваемое значение ошибки;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Measuring - номер измерения варианта настроек.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Measuring<0) Number_Of_Measuring=0;
    if (Number_Of_Measuring>XML_Number_Of_Measuring-1) Number_Of_Measuring=XML_Number_Of_Measuring-1;

    MatrixOfEx[Number_Of_Experiment][Number_Of_Measuring] = ErrorEx;
}