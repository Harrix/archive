int HCDOHOT_CompareOfDataByWilcoxonW (HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data1, HarrixClass_OnlyDataOfHarrixOptimizationTesting *Data2, double Q)
{
    /*
    Проверяет по критерию Вилкосона два исследования алгоритмов.
    Входные параметры:
     Data1 - первое исследование;
     Data2 - второе исследование;
     Q - уровень значимости. Может принимать значения:
       0.002;
       0.01;
       0.02;
       0.05;
       0.1;
       0.2.
    Возвращаемое значение:
     -2 - уровень значимости выбран неправильно (не из допустимого множества);
     -1 - объемы выборок не позволяют провести проверку при данном уровне значимости (или они не положительные);
     0 - выборки не однородны  при данном уровне значимости;
     1 - выборки однородны  при данном уровне значимости;
     */
    int VMHL_Result=1;

    int i,j;

    int N1 = (*Data1).getNumberOfExperiments()*(*Data1).getNumberOfMeasuring();
    int N2 = (*Data2).getNumberOfExperiments()*(*Data2).getNumberOfMeasuring();

    double *Vector1 = new double [N1];
    double *Vector2 = new double [N2];

    for (i=0;i<N1;i++) Vector1[i]=0;
    for (i=0;i<N2;i++) Vector2[i]=0;

    for (i=0;i<(*Data1).getNumberOfExperiments();i++)
        for (j=0;j<(*Data1).getNumberOfMeasuring();j++)
        {
            Vector1[i*(*Data1).getNumberOfMeasuring()+j]=(*Data1).getErrorEx(i,j);
        }

    for (i=0;i<(*Data2).getNumberOfExperiments();i++)
        for (j=0;j<(*Data2).getNumberOfMeasuring();j++)
        {
            Vector2[i*(*Data2).getNumberOfMeasuring()+j]=(*Data2).getErrorEx(i,j);
        }

    VMHL_Result = MHL_WilcoxonW(Vector1, Vector2, N1, N2, Q);

    delete [] Vector1;
    delete [] Vector2;

    return VMHL_Result;
}