bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getNumberOfExperiments()!=(*Data2).getNumberOfExperiments()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getNumberOfExperiments();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfExperiments() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfExperiments (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества комбинаций вариантов настроек в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    qint64 Info=SeveralData[0].getNumberOfExperiments();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfExperiments() ) VMHL_Result=false;
    }

    return VMHL_Result;
}