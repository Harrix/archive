double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VHML_Result_Ey = 0;

    double FitnessOfOptimum=HML_FitnessOfOptimumOfTestFunction_Real(VHML_N);

    if ((VHML_TypeOfTestFunction==TestFunction_Ackley)||(VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VHML_TypeOfTestFunction==TestFunction_Rastrigin)||(VHML_TypeOfTestFunction==TestFunction_Rosenbrock)||(VHML_TypeOfTestFunction==TestFunction_AdditivePotential)||(VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_Wave)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal2)||(VHML_TypeOfTestFunction==TestFunction_Sombrero)||(VHML_TypeOfTestFunction==TestFunction_Himmelblau)||(VHML_TypeOfTestFunction==TestFunction_Katnikov)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal3)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal4)||(VHML_TypeOfTestFunction==TestFunction_StepFunction)||(VHML_TypeOfTestFunction==TestFunction_Rana)||(VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VHML_TypeOfTestFunction==TestFunction_EggHolder)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VHML_TypeOfTestFunction==TestFunction_Schwefel)||(VHML_TypeOfTestFunction==TestFunction_Griewangk)||(VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)||(VHML_TypeOfTestFunction==TestFunction_Bosom))
    {
        VHML_Result_Ey=fabs(HML_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    return VHML_Result_Ey;
}
//---------------------------------------------------------------------------
double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorEyOfTestFunction_Real(FitnessOfx, VHML_N);

    return VHML_Result;
}