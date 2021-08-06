double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VHML_Result_Ex = 0;
    int i;

    double *Optimum=new double[VHML_N];

    HML_OptimumOfTestFunction_Real(Optimum, VHML_N);

    if ((VHML_TypeOfTestFunction==TestFunction_Ackley)||(VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VHML_TypeOfTestFunction==TestFunction_Rastrigin)||(VHML_TypeOfTestFunction==TestFunction_Rosenbrock)||(VHML_TypeOfTestFunction==TestFunction_AdditivePotential)||(VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_Wave)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal2)||(VHML_TypeOfTestFunction==TestFunction_Sombrero)||(VHML_TypeOfTestFunction==TestFunction_Katnikov)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal3)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal4)||(VHML_TypeOfTestFunction==TestFunction_StepFunction)||(VHML_TypeOfTestFunction==TestFunction_Rana)||(VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VHML_TypeOfTestFunction==TestFunction_EggHolder)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VHML_TypeOfTestFunction==TestFunction_Schwefel)||(VHML_TypeOfTestFunction==TestFunction_Griewangk)||(VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VHML_N;i++)
            VHML_Result_Ex+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
        VHML_Result_Ex=sqrt(VHML_Result_Ex)/double(VHML_N);
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	double *Ex = new double[4];
	for (i=0;i<VHML_N;i++) Ex[i]=0;
	
	Optimum[0]=( 3.0     ); Optimum[1]=( 2.0     );
	for (i=0;i<VHML_N;i++)
        Ex[0]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[0]=sqrt(Ex[0])/double(VHML_N);
	
	Optimum[0]=(-2.805118); Optimum[1]=( 3.131312);
	for (i=0;i<VHML_N;i++)
        Ex[1]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[1]=sqrt(Ex[1])/double(VHML_N);
	
	Optimum[0]=(-3.779310); Optimum[1]=(-3.283186);
	for (i=0;i<VHML_N;i++)
        Ex[2]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[2]=sqrt(Ex[2])/double(VHML_N);
	
	Optimum[0]=( 3.584428); Optimum[1]=(-1.848126);
	for (i=0;i<VHML_N;i++)
        Ex[3]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[3]=sqrt(Ex[3])/double(VHML_N);	
	
	VHML_Result_Ex = HML_MinimumOfVector(Ex,4);
	
	delete [] Ex;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
	double *Ex = new double[2];
	for (i=0;i<VHML_N;i++) Ex[i]=0;
	
	Optimum[0]=( 4.0); Optimum[1]=(4.0);
	for (i=0;i<VHML_N;i++)
        Ex[0]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[0]=sqrt(Ex[0])/double(VHML_N);
	
	Optimum[0]=(-4.0); Optimum[1]=(-4.0);
	for (i=0;i<VHML_N;i++)
        Ex[1]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[1]=sqrt(Ex[1])/double(VHML_N);
	
	VHML_Result_Ex = HML_MinimumOfVector(Ex,2);
	
	delete [] Ex;
    }

    delete [] Optimum;

    return VHML_Result_Ex;
}
//---------------------------------------------------------------------------
double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorExOfTestFunction_Real(x, VHML_N);

    return VHML_Result;
}