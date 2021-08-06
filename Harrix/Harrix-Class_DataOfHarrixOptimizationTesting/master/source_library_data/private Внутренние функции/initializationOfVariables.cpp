void HarrixClass_DataOfHarrixOptimizationTesting::initializationOfVariables()
{
    /*
    Обнуление переменных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    Rxml.clear();
    Data.setSuccessReading(false);
    Data.setDimensionTestFunction(-1);//Размерность тестовой задачи (длина хромосомы решения)
    Data.setNumberOfMeasuring(-1);//Количество экспериментов для каждого набора параметров алгоритма
    Data.setNumberOfRuns(-1);//Количество прогонов, по которому делается усреднение для эксперимента
    Data.setMaxCountOfFitness(-1);//Максимальное допустимое число вычислений целевой функции для алгоритма
    Data.setNumberOfParameters(-1);//Количество проверяемых параметров алгоритма оптимизации
    Zero_Number_Of_Parameters=false;//пока ничего не известно
    Data.setNumberOfExperiments(-1);//Количество комбинаций вариантов настроек
    Error=false;//типа вначале нет ошибок в файле
    Un=HQt_RandomString(5);//уникальная строка для Latex
    //AllOptions=true;//вначале наивно предполагаем, что в файле все настройки рассмотрены
}