void HarrixClass_OnlyDataOfHarrixOptimizationTesting::operator = (HarrixClass_OnlyDataOfHarrixOptimizationTesting& B)
{
    //Вначале уничтожим все массивы если они были.
    memoryDeallocation();
    //B обнулим переменные
    initializationOfVariables();

    XML_Author = B.XML_Author;
    XML_Date = B.XML_Date;
    XML_Email = B.XML_Email;
    XML_Name_Algorithm = B.XML_Name_Algorithm;
    XML_Full_Name_Algorithm = B.XML_Full_Name_Algorithm;//Полное название алгоритма оптимизации
    XML_Name_Test_Function = B.XML_Name_Test_Function;//Название тестовой функции
    XML_Full_Name_Test_Function = B.XML_Full_Name_Test_Function;//Полное название тестовой функции
    XML_DimensionTestFunction = B.XML_DimensionTestFunction;//Размерность тестовой задачи (длина хромосомы решения)
    XML_Number_Of_Measuring = B.XML_Number_Of_Measuring;//Количество экспериментов для каждого набора параметров алгоритма
    XML_Number_Of_Runs = B.XML_Number_Of_Runs;//Количество прогонов, по которому делается усреднение для эксперимента
    XML_Max_Count_Of_Fitness = B.XML_Max_Count_Of_Fitness;//Максимальное допустимое число вычислений целевой функции для алгоритма
    XML_Number_Of_Parameters = B.XML_Number_Of_Parameters;//Количество проверяемых параметров алгоритма оптимизации
    XML_Number_Of_Experiments = B.XML_Number_Of_Experiments;//Количество комбинаций вариантов настроек
    XML_Link_Test_Function = B.XML_Link_Test_Function;//Ссылка на описание тестовой функции
    XML_Link_Algorithm = B.XML_Link_Algorithm;//Ссылка на описание алгоритма оптимизации
    XML_Format = B.XML_Format;//Что за формат файла
    XML_Version = B.XML_Version;//Какая версия формата файла
    XML_Link = B.XML_Link;//Ссылка на описание формата файла
    XML_All_Combinations = B.XML_All_Combinations;//Все ли рассмотрены функции

    SuccessReading=B.SuccessReading;

    memoryAllocation();

    if (SuccessReading)
    {
        for (int i=0;i<XML_Number_Of_Experiments;i++)
            for (int j=0;j<XML_Number_Of_Measuring;j++)
            {
                MatrixOfEx[i][j]=B.MatrixOfEx[i][j];
                MatrixOfEy[i][j]=B.MatrixOfEy[i][j];
                MatrixOfR [i][j]=B.MatrixOfR [i][j];
            }

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            for (int j=0;j<XML_Number_Of_Parameters;j++)
            {
                MatrixOfParameters[i][j]=B.MatrixOfParameters[i][j];
            }

        NamesOfParameters=B.NamesOfParameters;

        for (int i=0;i<XML_Number_Of_Parameters;i++)
            ListOfParameterOptions[i]= B.ListOfParameterOptions[i];

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            NumberOfListOfVectorParameterOptions[i]= B.NumberOfListOfVectorParameterOptions[i];

        for (int i=0;i<XML_Number_Of_Experiments;i++)
            MatrixOfNameParameters[i]= B.MatrixOfNameParameters[i];

        ListOfVectorParameterOptions = B.ListOfVectorParameterOptions;

        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEx[i]=B.MeanOfEx[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfEy[i]=B.MeanOfEy[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) MeanOfR [i]=B.MeanOfR [i];

        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEx[i]=B.VarianceOfEx[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfEy[i]=B.VarianceOfEy[i];
        for (int i=0;i<XML_Number_Of_Experiments;i++) VarianceOfR [i]=B.VarianceOfR [i];

        MeanOfAllEx=B.MeanOfAllEx;
        MeanOfAllEy=B.MeanOfAllEy;
        MeanOfAllR=B.MeanOfAllR;
        VarianceOfAllR=B.VarianceOfAllR;
        VarianceOfAllEx=B.VarianceOfAllEx;
        VarianceOfAllEy=B.VarianceOfAllEy;
    }
}