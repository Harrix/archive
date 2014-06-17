bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    if ((*Data1).getEmail()!=(*Data2).getEmail()) VMHL_Result=false;

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    QString Info=SeveralData[0].getEmail();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getEmail() ) VMHL_Result=false;
    }

    return VMHL_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForEmail (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство email авторов исследований.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VMHL_Result=true;

    QString Info=SeveralData[0].getEmail();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getEmail() ) VMHL_Result=false;
    }

    return VMHL_Result;
}