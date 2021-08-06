double HML_TestFunction_Real(double *x, int VHML_N)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Ackley(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_AdditivePotential(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_MultiplicativePotential(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_ReverseGriewank(x[0], x[1]);

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_ParaboloidOfRevolution(x, VHML_N);

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Rastrigin(x, VHML_N);

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Rosenbrock(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_HyperEllipsoid(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_RotatedHyperEllipsoid(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Wave(x[0]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Multiextremal(x[0]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Multiextremal2(x[0]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Sombrero(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Himmelblau(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Katnikov(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Multiextremal3(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Multiextremal4(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_StepFunction(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Rana(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_ShekelsFoxholes(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_EggHolder(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_RastriginWithChange(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_RastriginWithTurning(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Schwefel(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Griewangk(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_InvertedRosenbrock(x[0], x[1]);
		
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_GaussianQuartic(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_RastriginNovgorod(x, VHML_N);
		
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real()*HML_TestFunction_Bosom(x[0], x[1]);

    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_TestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
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

    VHML_Result = HML_TestFunction_Real(x, VHML_N);

    return VHML_Result;
}