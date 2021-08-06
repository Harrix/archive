void HarrixClass_OnlyDataOfHarrixOptimizationTesting::memoryAllocation()
{
    /*
    Выделяет память под необходимые массивы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    //Матрица значений ошибок Ex алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEx=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEx[i]=new double[XML_Number_Of_Measuring];
    HML_FillMatrix(MatrixOfEx, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений ошибок Ey алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfEy=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfEy[i]=new double[XML_Number_Of_Measuring];
    HML_FillMatrix(MatrixOfEy, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений надежностей R алгоритма оптимизации.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу измерений для каждого варианта настроек алгоритма.
    MatrixOfR=new double*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfR[i]=new double[XML_Number_Of_Measuring];
    HML_FillMatrix(MatrixOfR, XML_Number_Of_Experiments, XML_Number_Of_Measuring, -1.);

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfParameters=new int*[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfParameters[i]=new int[XML_Number_Of_Parameters];
    HML_FillMatrix(MatrixOfParameters, XML_Number_Of_Experiments, XML_Number_Of_Parameters, -1);

    //Вектор названий вариантов параметров алгоритма оптимизации.
    //Число элементов равно числу проверяемых параметров алгоритма оптимизации.
    //Элементы будут заноситься по мере обнаружения новых вариантов алгоритма.
    //Номера вариантов параметров алгоритма в конкретном списке QStringList будет совпадать
    //с номерами из MatrixOfParameters. То есть, что записано в MatrixOfParameters в ListOfParameterOptions
    //находится под номером соответствующим.
    ListOfParameterOptions=new QStringList[XML_Number_Of_Parameters];
    for (int i=0;i<XML_Number_Of_Parameters;i++) ListOfParameterOptions[i].clear();

    //Матрица значений параметров для каждой комбинации вариантов настроек.
    //Элементы не в виде чисел, а в виде наименований этих параметров.
    //Число строк равно числу комбинаций вариантов настроек.
    //Число столбцов равно числу проверяемых параметров алгоритма оптимизации.
    MatrixOfNameParameters=new QStringList[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MatrixOfNameParameters[i].clear();

    //Номера комбинаций вариантов настроек
    //Содержит номера от 1 до XML_Number_Of_Experiments
    NumberOfListOfVectorParameterOptions=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++)
        NumberOfListOfVectorParameterOptions[i]=i+1;

    //Вектор средних значений ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEx=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEx[i]=0;

    //Вектор средних ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfEy=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEy[i]=0;

    //Вектор средних надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    MeanOfR=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfR[i]=0;

    //Вектор дисперсий ошибок Ex алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEx=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEx[i]=0;

    //Вектор дисперсий ошибок Ey алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfEy=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEy[i]=0;

    //Вектор дисперсий надежностей R алгоритма оптимизации по измерениям для каждой настройки.
    //Число элементов равно числу комбинаций вариантов настроек.
    VarianceOfR=new double[XML_Number_Of_Experiments];
    for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfR[i]=0;
}