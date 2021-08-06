bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getFormat()!=(*Data2).getFormat()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFormat();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFormat() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForFormat (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство форматов файлов в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    QString Info=SeveralData[0].getFormat();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getFormat() ) VHML_Result=false;
    }

    return VHML_Result;
}