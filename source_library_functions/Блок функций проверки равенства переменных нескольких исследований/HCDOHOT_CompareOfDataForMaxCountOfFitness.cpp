bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getMaxCountOfFitness()!=(*Data2).getMaxCountOfFitness()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getMaxCountOfFitness();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getMaxCountOfFitness() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForMaxCountOfFitness (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство максимальных допустимых чисел вычислений целевой функции для алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getMaxCountOfFitness();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getMaxCountOfFitness() ) VMHL_Result=false;
    }

    return VMHL_Result;
}