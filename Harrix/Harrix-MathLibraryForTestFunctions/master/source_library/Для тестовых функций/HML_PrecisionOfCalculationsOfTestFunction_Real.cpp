double HML_PrecisionOfCalculationsOfTestFunction_Real()
{
    /*
    Функция определяет точность для подсчета надежности в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result_E = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VHML_Result_E=0.05;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VHML_Result_E=0.01;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VHML_Result_E=0.025;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VHML_Result_E=0.05;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result_E=2.5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result_E=0.25;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VHML_Result_E=2.5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VHML_Result_E=0.08;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VHML_Result_E=0.08;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VHML_Result_E=2.5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VHML_Result_E=0.08;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VHML_Result_E=0.025;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VHML_Result_E=0.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VHML_Result_E=0.01;
    }

    return VHML_Result_E;
}
//---------------------------------------------------------------------------
double HML_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type)
{
    /*
    Функция определяет точность для подсчета надежности в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_PrecisionOfCalculationsOfTestFunction_Real();

    return VHML_Result;
}