bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getCheckAllCombinations()!=(*Data2).getCheckAllCombinations()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    int Info=SeveralData[0].getCheckAllCombinations();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getCheckAllCombinations() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForCheckAllCombinations (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство переменной, которая говорит все ли рассмотрены функции в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    int Info=SeveralData[0].getCheckAllCombinations();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getCheckAllCombinations() ) VHML_Result=false;
    }

    return VHML_Result;
}