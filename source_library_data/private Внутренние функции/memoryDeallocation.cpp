void HarrixClass_DataOfHarrixOptimizationTesting::memoryDeallocation()
{
    /*
    Удаляет память из-под массивов. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Data.getSuccessReading())
    {
        delete [] NumberOfListOfVectorParameterOptions;
    }
}