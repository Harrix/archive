void HarrixClass_DataOfHarrixOptimizationTesting::memoryAllocation()
{
    /*
    Выделяет память под необходимые массивы. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до Data.getNumberOfExperiments()
    NumberOfListOfVectorParameterOptions=new double[Data.getNumberOfExperiments()];
}