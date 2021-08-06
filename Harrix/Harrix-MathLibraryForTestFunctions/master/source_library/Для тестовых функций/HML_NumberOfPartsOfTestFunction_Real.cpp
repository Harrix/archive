double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result_E = 0;
    int i;

    if ((VHML_TypeOfTestFunction==TestFunction_Ackley)||(VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VHML_TypeOfTestFunction==TestFunction_Rastrigin)||(VHML_TypeOfTestFunction==TestFunction_Rosenbrock)||(VHML_TypeOfTestFunction==TestFunction_AdditivePotential)||(VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VHML_TypeOfTestFunction==TestFunction_Wave)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal2)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal2)||(VHML_TypeOfTestFunction==TestFunction_Sombrero)||(VHML_TypeOfTestFunction==TestFunction_Himmelblau)||(VHML_TypeOfTestFunction==TestFunction_Katnikov)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal3)||(VHML_TypeOfTestFunction==TestFunction_Multiextremal4)||(VHML_TypeOfTestFunction==TestFunction_StepFunction)||(VHML_TypeOfTestFunction==TestFunction_Rana)||(VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VHML_TypeOfTestFunction==TestFunction_EggHolder)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VHML_TypeOfTestFunction==TestFunction_Schwefel)||(VHML_TypeOfTestFunction==TestFunction_Griewangk)||(VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)||(VHML_TypeOfTestFunction==TestFunction_Bosom))
    {
        for (i=0;i<VHML_N;i++) NumberOfParts[i]=4095;
    }

    VHML_Result_E=HML_PrecisionOfCalculationsOfTestFunction_Real();

    return VHML_Result_E;
}
//---------------------------------------------------------------------------
double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_NumberOfPartsOfTestFunction_Real(NumberOfParts, VHML_N);

    return VHML_Result;
}