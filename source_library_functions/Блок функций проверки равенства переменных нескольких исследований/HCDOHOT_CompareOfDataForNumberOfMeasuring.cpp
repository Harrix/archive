bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *Data1, HarrixClass_DataOfHarrixOptimizationTesting *Data2)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    if ((*Data1).getNumberOfMeasuring()!=(*Data2).getNumberOfMeasuring()) VHML_Result=false;

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_DataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfMeasuring();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfMeasuring() ) VHML_Result=false;
    }

    return VHML_Result;
}
//--------------------------------------------------------------------------
bool HCDOHOT_CompareOfDataForNumberOfMeasuring (HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, int N)
{
    /*
    Проверяет равенство количества экспериментов для каждого набора параметров алгоритма в исследованиях.
    Входные параметры:
     SeveralData - массив исследований;
     N - количество исследований в массиве.
    Возвращаемое значение:
     true - если исследуемый параметр алгоритмов одинаков.
     false - если разные.
     */
    bool VHML_Result=true;

    qint64 Info=SeveralData[0].getNumberOfMeasuring();

    for (int i=1;i<N;i++)
    {
        if ( Info!=SeveralData[i].getNumberOfMeasuring() ) VHML_Result=false;
    }

    return VHML_Result;
}