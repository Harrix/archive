bool HCDOHOT_CompareOfDataForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getDimensionTestFunction()!=(*Data2).getDimensionTestFunction()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getDimensionTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDimensionTestFunction() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForForDimensionTestFunction (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство размерностей тестовой задачи (длина хромосомы решения) в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getDimensionTestFunction();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDimensionTestFunction() ) VMHL_Result=false;
    }

    return VMHL_Result;
}