double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VHML_Result = -15.606060606060606;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VHML_Result = -60.8872819100091;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VHML_Result = 1.;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VHML_Result = 0;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VHML_Result = 0;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        VHML_Result = 1.01;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VHML_Result = 0.000103742;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VHML_Result = 1.93374;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VHML_Result = 1.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VHML_Result = 0.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VHML_Result = 0.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VHML_Result = 0.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VHML_Result = 0.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result = -1.;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        VHML_Result = -511.7328819;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VHML_Result = 0.99800384;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
		VHML_Result = -959.64067;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
		VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
		VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
		VHML_Result = 0;
        double *x;
        x=new double[int(VHML_N)];
		for (int i=0;i<VHML_N;i++) x[i]=420.968746;
		VHML_Result=HML_TestFunction_Schwefel(x,VHML_N);
		delete [] x;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
		VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
		VHML_Result = -0.99019608;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
		VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
		VHML_Result = 0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
		VHML_Result = 1.150000077;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_FitnessOfOptimumOfTestFunction_Real(VHML_N);

    return VHML_Result;
}