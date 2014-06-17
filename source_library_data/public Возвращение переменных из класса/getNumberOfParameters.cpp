qint64 HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfParameters()
{
    /*
     Получение текста переменной  XML_Number_Of_Parameters - Количество проверяемых параметров алгоритма оптимизации.
     */
    if (Zero_Number_Of_Parameters) return 0;
    return Data.getNumberOfParameters();
}