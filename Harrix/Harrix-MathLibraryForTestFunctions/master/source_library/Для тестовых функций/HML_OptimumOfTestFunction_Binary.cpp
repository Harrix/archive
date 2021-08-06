double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N)
{
    /*
	Функция определяет значение оптимума для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;
    int i;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VHML_N;i++)
            Optimum[i]=1;
        VHML_Result = HML_FitnessOfOptimumOfTestFunction_Binary(VHML_N);
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение оптимума для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VHML_N - размер массива x;
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_TestFunction_Binary(Optimum, VHML_N);

    return VHML_Result;
}