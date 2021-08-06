double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N)
{
    /*
    Функция определяет значение надежности найденного решения
	в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VHML_Result_R = 1;
    int i;

    int *Optimum=new int[VHML_N];

    HML_OptimumOfTestFunction_Binary(Optimum, VHML_N);

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VHML_N;i++)
        {
            if (x[i]!=Optimum[i]) VHML_Result_R=0;
        }
    }

    delete [] Optimum;

    return VHML_Result_R;
}
//---------------------------------------------------------------------------
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorROfTestFunction_Binary(x, VHML_N);

    return VHML_Result;
}