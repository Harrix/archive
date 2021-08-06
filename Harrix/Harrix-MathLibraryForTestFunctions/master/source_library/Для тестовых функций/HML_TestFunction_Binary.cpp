double HML_TestFunction_Binary(int *x, int VHML_N)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Binary()*HML_TestFunction_SumVector(x, VHML_N);
    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_TestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
    Входные параметры:
     x - указатель на исходный массив;
     VHML_N - размер массива x,
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_TestFunction_Binary(x, VHML_N);

    return VHML_Result;
}