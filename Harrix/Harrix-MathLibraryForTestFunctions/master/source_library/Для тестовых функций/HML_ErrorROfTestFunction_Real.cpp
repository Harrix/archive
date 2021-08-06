double HML_ErrorROfTestFunction_Real(double *x, int VHML_N)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
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

    double *Optimum=new double[VHML_N];

    HML_OptimumOfTestFunction_Real(Optimum, VHML_N);

    if ((VHML_TypeOfTestFunction==TestFunction_Ackley)||(VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VHML_TypeOfTestFunction==TestFunction_Rastrigin)||(VHML_TypeOfTestFunction==TestFunction_Rosenbrock)||(VHML_TypeOfTestFunction==TestFunction_AdditivePotential)||(VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_Wave)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal2)||(VHML_TypeOfTestFunction==TestFunction_Sombrero)||(VHML_TypeOfTestFunction==TestFunction_Katnikov)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal3)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal4)||(VHML_TypeOfTestFunction==TestFunction_StepFunction)||(VHML_TypeOfTestFunction==TestFunction_Rana)||(VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VHML_TypeOfTestFunction==TestFunction_EggHolder)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VHML_TypeOfTestFunction==TestFunction_Schwefel)||(VHML_TypeOfTestFunction==TestFunction_Griewangk)||(VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VHML_N;i++)
        {
            if (fabs(x[i]-Optimum[i])>=HML_PrecisionOfCalculationsOfTestFunction_Real()) VHML_Result_R=0;
        }
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
	VHML_Result_R = 0;
	double p=HML_PrecisionOfCalculationsOfTestFunction_Real();
	
	if ( (fabs(x[0]-( 4.0))<p) && (fabs(x[1]-( 4.0))<p)) VHML_Result_R = 1;
	if ( (fabs(x[0]-(-4.0))<p) && (fabs(x[1]-(-4.0))<p)) VHML_Result_R = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	VHML_Result_R = 0;
	double p=HML_PrecisionOfCalculationsOfTestFunction_Real();
	
	if ( (fabs(x[0]-( 3.0     ))<p) && (fabs(x[1]-( 2.0     ))<p)  ) VHML_Result_R = 1;
	if ( (fabs(x[0]-(-2.805118))<p) && (fabs(x[1]-( 3.131312))<p)  ) VHML_Result_R = 1;
	if ( (fabs(x[0]-(-3.779310))<p) && (fabs(x[1]-(-3.283186))<p)  ) VHML_Result_R = 1;
	if ( (fabs(x[0]-( 3.584428))<p) && (fabs(x[1]-(-1.848126))<p)  ) VHML_Result_R = 1;
    }

    delete [] Optimum;

    return VHML_Result_R;
}
//---------------------------------------------------------------------------
double HML_ErrorROfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorROfTestFunction_Real(x, VHML_N);

    return VHML_Result;
}