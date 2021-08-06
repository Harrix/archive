#ifndef HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
#define HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
#include <math.h>

//ПЕРЕМЕННЫЕ ПЕРЕЧИСЛЯЕМОГО ТИПА
enum TypeOfTestFunction { TestFunction_Ackley, TestFunction_ParaboloidOfRevolution, TestFunction_Rastrigin, TestFunction_Rosenbrock, TestFunction_SumVector, TestFunction_AdditivePotential, TestFunction_MultiplicativePotential, TestFunction_ReverseGriewank, TestFunction_HyperEllipsoid, TestFunction_RotatedHyperEllipsoid, TestFunction_Wave, TestFunction_Multiextremal, TestFunction_Multiextremal2, TestFunction_Sombrero, TestFunction_Himmelblau, TestFunction_Katnikov, TestFunction_Multiextremal3, TestFunction_Multiextremal4, TestFunction_StepFunction, TestFunction_Rana, TestFunction_ShekelsFoxholes, TestFunction_EggHolder, TestFunction_RastriginWithChange, TestFunction_RastriginWithTurning, TestFunction_Schwefel, TestFunction_Griewangk, TestFunction_InvertedRosenbrock, TestFunction_GaussianQuartic, TestFunction_RastriginNovgorod, TestFunction_Bosom };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Для тестовых функций
int HML_ClassOfTestFunction(TypeOfTestFunction Type);
int HML_CountOfFitnessOfTestFunction_Binary(int Dimension);
int HML_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type);
int HML_CountOfFitnessOfTestFunction_Real(int Dimension);
int HML_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type);
void HML_DefineTestFunction(TypeOfTestFunction Type);
int HML_DimensionTestFunction_Binary(int i);
int HML_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type);
int HML_DimensionTestFunction_Real(int i);
int HML_DimensionTestFunction_Real(int i, TypeOfTestFunction Type);
double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N);
double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N);
double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);
double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N);
double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N, TypeOfTestFunction Type);
double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N);
double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N, TypeOfTestFunction Type);
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N);
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
double HML_ErrorROfTestFunction_Real(double *x, int VHML_N);
double HML_ErrorROfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N);
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N, TypeOfTestFunction Type);
double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N);
double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N, TypeOfTestFunction Type);
int HML_GetCountOfFitness();
int HML_GetCountOfSubProblems_Binary();
int HML_GetCountOfSubProblems_Binary(TypeOfTestFunction Type);
int HML_GetCountOfSubProblems_Real();
int HML_GetCountOfSubProblems_Real(TypeOfTestFunction Type);
void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VHML_N);
void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VHML_N, TypeOfTestFunction Type);
double HML_MaximumOrMinimumOfTestFunction_Binary();
double HML_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type);
double HML_MaximumOrMinimumOfTestFunction_Real();
double HML_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type);
double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N);
double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N, TypeOfTestFunction Type);
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N);
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N, TypeOfTestFunction Type);
double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N);
double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N, TypeOfTestFunction Type);
double HML_PrecisionOfCalculationsOfTestFunction_Real();
double HML_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type);
void HML_SetToZeroCountOfFitness();
double HML_TestFunction_Binary(int *x, int VHML_N);
double HML_TestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
double HML_TestFunction_Real(double *x, int VHML_N);
double HML_TestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);

#endif // HARRIXMATHLIBRARYFORTESTFUNCTIONS_H
