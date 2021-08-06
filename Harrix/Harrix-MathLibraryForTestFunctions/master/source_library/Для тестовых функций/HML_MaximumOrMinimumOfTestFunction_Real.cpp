double HML_MaximumOrMinimumOfTestFunction_Real()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VHML_Result=1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VHML_Result=-1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VHML_Result=-1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        VHML_Result=1;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type)
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real();

    return VHML_Result;
}