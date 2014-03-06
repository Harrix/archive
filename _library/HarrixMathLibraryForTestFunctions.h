#ifndef HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
#define HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
#include <math.h>

//ПЕРЕМЕННЫЕ ПЕРЕЧИСЛЯЕМОГО ТИПА
enum TypeOfTestFunction { TestFunction_Ackley, TestFunction_ParaboloidOfRevolution, TestFunction_Rastrigin, TestFunction_Rosenbrock, TestFunction_SumVector, TestFunction_AdditivePotential, TestFunction_MultiplicativePotential, TestFunction_ReverseGriewank, TestFunction_HyperEllipsoid, TestFunction_RotatedHyperEllipsoid, TestFunction_Wave, TestFunction_Multiextremal, TestFunction_Multiextremal2, TestFunction_Sombrero, TestFunction_Himmelblau, TestFunction_Katnikov, TestFunction_Multiextremal3, TestFunction_Multiextremal4, TestFunction_StepFunction, TestFunction_Rana, TestFunction_ShekelsFoxholes, TestFunction_EggHolder, TestFunction_RastriginWithChange, TestFunction_RastriginWithTurning, TestFunction_Schwefel, TestFunction_Griewangk, TestFunction_InvertedRosenbrock, TestFunction_GaussianQuartic, TestFunction_RastriginNovgorod, TestFunction_Bosom };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Для тестовых функций
int MHL_ClassOfTestFunction(TypeOfTestFunction Type);
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension);
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type);
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension);
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type);
void MHL_DefineTestFunction(TypeOfTestFunction Type);
int MHL_DimensionTestFunction_Binary(int i);
int MHL_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type);
int MHL_DimensionTestFunction_Real(int i);
int MHL_DimensionTestFunction_Real(int i, TypeOfTestFunction Type);
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N);
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N);
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N);
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N);
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N);
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N);
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N);
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N, TypeOfTestFunction Type);
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N);
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N, TypeOfTestFunction Type);
int MHL_GetCountOfFitness();
int MHL_GetCountOfSubProblems_Binary();
int MHL_GetCountOfSubProblems_Binary(TypeOfTestFunction Type);
int MHL_GetCountOfSubProblems_Real();
int MHL_GetCountOfSubProblems_Real(TypeOfTestFunction Type);
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VMHL_N);
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VMHL_N, TypeOfTestFunction Type);
double MHL_MaximumOrMinimumOfTestFunction_Binary();
double MHL_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type);
double MHL_MaximumOrMinimumOfTestFunction_Real();
double MHL_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type);
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N);
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N, TypeOfTestFunction Type);
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N);
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N, TypeOfTestFunction Type);
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N);
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N, TypeOfTestFunction Type);
double MHL_PrecisionOfCalculationsOfTestFunction_Real();
double MHL_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type);
void MHL_SetToZeroCountOfFitness();
double MHL_TestFunction_Binary(int *x, int VMHL_N);
double MHL_TestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_TestFunction_Real(double *x, int VMHL_N);
double MHL_TestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Для тестовых функций
//*****************************************************************


#endif // HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
