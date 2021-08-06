QStringList HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfVectorParameterOptions()
{
    /*
    Получение списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Список параметров алгоритма.
     */

    return ListOfVectorParameterOptions;
}
//--------------------------------------------------------------------------
QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfVectorParameterOptions(int Number_Of_Experiment)
{
    /*
    Получение строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Number_Of_Experiment - номер эксперимента.
    Возвращаемое значение:
     Значения строки параметров эксперимента.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    return ListOfVectorParameterOptions.at(Number_Of_Experiment);
}