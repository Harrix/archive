void HarrixClass_DataOfHarrixOptimizationTesting::zeroArray()
{
    /*
    Обнуляет массивы, в котрые записывается информация о данных из файла. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //"Обнулим" матрицы
    TMHL_ZeroVector(NumberOfListOfVectorParameterOptions,Data.getNumberOfExperiments());
}