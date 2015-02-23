bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getDate()!=(*Data2).getDate()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForDate (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getDate();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDate() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForDate (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство дат исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getDate();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getDate() ) VHML_Result=false;
    }

    return VHML_Result;
}