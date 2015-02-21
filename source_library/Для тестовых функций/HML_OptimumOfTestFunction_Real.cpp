double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N)
{
    /*
    Функция определяет значение оптимума для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
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

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0.954452;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=-0.993263;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	// один из 4 оптимумов
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
        Optimum[0]=3;
		Optimum[1]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
        Optimum[0]=-488.6326;
		Optimum[1]=512;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=-32;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
        Optimum[0]=512;
		Optimum[1]=404.2319;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=420.968746;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
        Optimum[0]=0.00990099;
		Optimum[1]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
	// один из 2 оптимумов
        for (i=0;i<VHML_N;i++) Optimum[i]=0;
        Optimum[0]=4;
		Optimum[1]=4;
    }

    VHML_Result = HML_FitnessOfOptimumOfTestFunction_Real(VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение оптимума для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
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

    VHML_Result = HML_OptimumOfTestFunction_Real(Optimum, VHML_N);

    return VHML_Result;
}