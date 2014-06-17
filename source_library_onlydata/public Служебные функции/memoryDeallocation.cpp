void HarrixClass_OnlyDataOfHarrixOptimizationTesting::memoryDeallocation()
{
    /*
    Удаляет память из-под массивов. Внутренняя функция.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    if (SuccessReading)
    {
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEx[i];
        delete [] MatrixOfEx;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfEy[i];
        delete [] MatrixOfEy;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfR[i];
        delete [] MatrixOfR;
        for (int i=0;i<XML_Number_Of_Experiments;i++) delete [] MatrixOfParameters[i];
        delete [] MatrixOfParameters;
        delete [] ListOfParameterOptions;
        delete [] NumberOfListOfVectorParameterOptions;
        delete [] MatrixOfNameParameters;
        delete [] MeanOfEx;
        delete [] MeanOfEy;
        delete [] MeanOfR;
        delete [] VarianceOfEx;
        delete [] VarianceOfEy;
        delete [] VarianceOfR;
    }
}