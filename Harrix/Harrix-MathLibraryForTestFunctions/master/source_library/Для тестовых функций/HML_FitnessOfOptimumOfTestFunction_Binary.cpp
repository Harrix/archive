double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        VHML_Result = VHML_N;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N, TypeOfTestFunction Type)
{
    /*
	Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_FitnessOfOptimumOfTestFunction_Binary(VHML_N);

    return VHML_Result;
}