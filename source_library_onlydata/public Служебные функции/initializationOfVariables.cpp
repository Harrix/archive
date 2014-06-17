void HarrixClass_OnlyDataOfHarrixOptimizationTesting::initializationOfVariables()
{
    /*
    Обнуление переменных. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    SuccessReading=false;
    XML_DimensionTestFunction=-1;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring=-1;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs=-1;//Количество прогонов, по которому делается усреднение для эксперимента
    XML_Max_Count_Of_Fitness=-1;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters=-1;//Количество проверяемых параметров алгоритма оптимизации
    //Zero_Number_Of_Parameters=false;//пока ничего не известно
    XML_Number_Of_Experiments=-1;//Количество комбинаций вариантов настроек
    NamesOfParameters.clear();
    ListOfVectorParameterOptions.clear();

    MeanOfAllEx=0;
    MeanOfAllEy=0;
    MeanOfAllR=0;
    VarianceOfAllR=0;
    VarianceOfAllEx=0;
    VarianceOfAllEy=0;
}