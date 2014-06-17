bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getNumberOfRuns()!=(*Data2).getNumberOfRuns()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getNumberOfRuns();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfRuns() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfRuns (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества прогонов, по которому делается усреднение для эксперимента в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getNumberOfRuns();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfRuns() ) VMHL_Result=false;
    }

    return VMHL_Result;
}