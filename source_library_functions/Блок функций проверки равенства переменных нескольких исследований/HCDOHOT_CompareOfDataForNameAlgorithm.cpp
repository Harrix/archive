bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getNameAlgorithm()!=(*Data2).getNameAlgorithm()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VMHL_Result=true;

    QString Info=SeveralData[0].getNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameAlgorithm() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNameAlgorithm (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство идентификаторов алгоритмов оптимизации: в данных содержится один и тот же алгоритм или же нет.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если имена алгоритмов одинаковы.
     false - если разные.
     */
    bool VMHL_Result=true;

    QString Info=SeveralData[0].getNameAlgorithm();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNameAlgorithm() ) VMHL_Result=false;
    }

    return VMHL_Result;
}