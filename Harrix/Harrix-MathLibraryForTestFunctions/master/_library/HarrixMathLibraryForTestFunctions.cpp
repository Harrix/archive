//HarrixMathLibraryForTestFunctions
//Версия 1.2
//Сборник различных математических функций и шаблонов с открытым кодом на языке C++.
//https://github.com/Harrix/HarrixMathLibraryForTestFunctions
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixMathLibraryForTestFunctions.h"
#include "HarrixMathLibrary.h"

TypeOfTestFunction VHML_TypeOfTestFunction;//для функций по работе с тестовыми функциями для анализа эффективности алгоритмов
int CountOfFitness;//количество вызовов тестовой функции при запуске алгоритма оптимизации

//*****************************************************************
//Для тестовых функций
//*****************************************************************
int HML_ClassOfTestFunction(TypeOfTestFunction Type)
{
    /*
    Функция выдает принадлежность тестовой функции к классу функций: бинарной, вещественной или иной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Класс тестовой функции:
      1 - бинарной оптимизации;
      2 - вещественной оптимизации.
    */
    int VHML_Result=0;

    if (Type==TestFunction_SumVector)
        return 1;

    if (Type==TestFunction_Ackley)
        return 2;
		
	if (Type==TestFunction_AdditivePotential)
        return 2;
		
    if (Type==TestFunction_MultiplicativePotential)
        return 2;
		
	if (Type==TestFunction_ReverseGriewank)
        return 2;

    if (Type==TestFunction_ParaboloidOfRevolution)
        return 2;

    if (Type==TestFunction_Rastrigin)
        return 2;

    if (Type==TestFunction_Rosenbrock)
        return 2;
		
	if (Type==TestFunction_HyperEllipsoid)
        return 2;
		
	if (Type==TestFunction_RotatedHyperEllipsoid)
        return 2;
		
	if (Type==TestFunction_Wave)
        return 2;
		
	if (Type==TestFunction_Multiextremal)
        return 2;
		
	if (Type==TestFunction_Multiextremal2)
        return 2;
		
	if (Type==TestFunction_Sombrero)
        return 2;
		
	if (Type==TestFunction_Himmelblau)
        return 2;
		
	if (Type==TestFunction_Katnikov)
        return 2;
		
	if (Type==TestFunction_Multiextremal3)
        return 2;
		
	if (Type==TestFunction_Multiextremal4)
        return 2;
		
	if (Type==TestFunction_StepFunction)
        return 2;
		
	if (Type==TestFunction_Rana)
        return 2;
		
	if (Type==TestFunction_ShekelsFoxholes)
        return 2;
		
	if (Type==TestFunction_EggHolder)
        return 2;
		
	if (Type==TestFunction_RastriginWithChange)
        return 2;
		
	if (Type==TestFunction_RastriginWithTurning)
        return 2;
		
	if (Type==TestFunction_Schwefel)
        return 2;
		
	if (Type==TestFunction_Griewangk)
        return 2;
		
	if (Type==TestFunction_InvertedRosenbrock)
        return 2;
		
	if (Type==TestFunction_GaussianQuartic)
        return 2;
		
	if (Type==TestFunction_RastriginNovgorod)
        return 2;
		
	if (Type==TestFunction_Bosom)
        return 2;

    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_CountOfFitnessOfTestFunction_Binary(int Dimension)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Для тестовых функций бинарного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 20; 30; 40; 50; 60; 70; 80; 90; 100; 200.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        if (Dimension==20)  VHML_Result = 225;
        if (Dimension==30)  VHML_Result = 400;
        if (Dimension==40)  VHML_Result = 576;
        if (Dimension==50)  VHML_Result = 784;
        if (Dimension==60)  VHML_Result = 1024;
        if (Dimension==70)  VHML_Result = 1296;
        if (Dimension==80)  VHML_Result = 1521;
        if (Dimension==90)  VHML_Result = 1764;
        if (Dimension==100) VHML_Result = 2025;
        if (Dimension==200) VHML_Result = 4761;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Для тестовых функций бинарного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_CountOfFitnessOfTestFunction_Binary(Dimension);

    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_CountOfFitnessOfTestFunction_Real(int Dimension)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (Dimension==2)  VHML_Result = 324;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        if (Dimension==1)  VHML_Result = 64;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (Dimension==1)  VHML_Result = 64;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (Dimension==1)  VHML_Result = 64;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        if (Dimension==2)  VHML_Result = 324;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        if (Dimension==2)  VHML_Result = 324;
        if (Dimension==3)  VHML_Result = 729;
        if (Dimension==4)  VHML_Result = 1225;
        if (Dimension==5)  VHML_Result = 1849;
        if (Dimension==10) VHML_Result = 5776;
        if (Dimension==20) VHML_Result = 15876;
        if (Dimension==30) VHML_Result = 28224;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        if (Dimension==2)  VHML_Result = 324;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_CountOfFitnessOfTestFunction_Real(Dimension);

    return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_DefineTestFunction(TypeOfTestFunction Type)
{
    /*
    Служебная функция определяет тестовую функцию для других функций по работе с тестовыми функциями.
	Вызывать всегда, когда хотите вызвать функции по работе с тестовыми функциями (из одноименного раздела).
    Ответ представляет собой два действительных числа.
    Входные параметры:
     Type - обозначение тестовой функции, которую вызываем.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Отсутствует.
    */
    VHML_TypeOfTestFunction=Type;
}
//---------------------------------------------------------------------------

int HML_DimensionTestFunction_Binary(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VHML_Result = 0;

    //проверка
    if (i<0) i=0;
    //if (i>=HML_GetCountOfSubProblems_Binary()) i=HML_GetCountOfSubProblems_Binary()-1;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        if (i==0) VHML_Result = 20;
        if (i==1) VHML_Result = 30;
        if (i==2) VHML_Result = 40;
        if (i==3) VHML_Result = 50;
        if (i==4) VHML_Result = 60;
        if (i==5) VHML_Result = 70;
        if (i==6) VHML_Result = 80;
        if (i==7) VHML_Result = 90;
        if (i==8) VHML_Result = 100;
        if (i==9) VHML_Result = 200;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_DimensionTestFunction_Binary(i);

    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_DimensionTestFunction_Real(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VHML_Result = 0;

    //проверка
    if (i<0) i=0;
    //if (i>=HML_GetCountOfSubProblems_Real()) i=HML_GetCountOfSubProblems_Real()-1;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (i==0) VHML_Result = 2;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        if (i==0) VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (i==0) VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (i==0) VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        if (i==0) VHML_Result = 2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        if (i==0) VHML_Result = 2;
        if (i==1) VHML_Result = 3;
        if (i==2) VHML_Result = 4;
        if (i==3) VHML_Result = 5;
        if (i==4) VHML_Result = 10;
        if (i==5) VHML_Result = 20;
        if (i==6) VHML_Result = 30;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        if (i==0) VHML_Result = 2;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_DimensionTestFunction_Real(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_DimensionTestFunction_Real(i);

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
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

    int *Optimum=new int[VHML_N];

    HML_OptimumOfTestFunction_Binary(Optimum, VHML_N);


    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VHML_N;i++)
            VHML_Result_Ex+=abs(x[i]-Optimum[i]);
    }

    delete [] Optimum;

    return VHML_Result_Ex/double(VHML_N);
}
//---------------------------------------------------------------------------
double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorExOfTestFunction_Binary(x, VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VHML_Result_Ey = 0;

    double FitnessOfOptimum=HML_FitnessOfOptimumOfTestFunction_Binary(VHML_N);

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        VHML_Result_Ey=fabs(HML_MaximumOrMinimumOfTestFunction_Binary()*FitnessOfx-FitnessOfOptimum);
		VHML_Result_Ey/=double(VHML_N);
    }

    return VHML_Result_Ey;
}
//---------------------------------------------------------------------------
double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorEyOfTestFunction_Binary(FitnessOfx, VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N)
{
    /*
    Функция определяет значение надежности найденного решения
	в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
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

    int *Optimum=new int[VHML_N];

    HML_OptimumOfTestFunction_Binary(Optimum, VHML_N);

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VHML_N;i++)
        {
            if (x[i]!=Optimum[i]) VHML_Result_R=0;
        }
    }

    delete [] Optimum;

    return VHML_Result_R;
}
//---------------------------------------------------------------------------
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_ErrorROfTestFunction_Binary(x, VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        VHML_Result = VHML_N;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N, TypeOfTestFunction Type)
{
    /*
	Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     VHML_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_FitnessOfOptimumOfTestFunction_Binary(VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

int HML_GetCountOfFitness()
{
    /*
    Функция выдает количество вызовов целевой функции.
    Вызывать после вызова алгорита оптимизации.
    Обязательно вызвать HML_SetToZeroCountOfFitness один раз перед вызовом алгоритмов оптимизации
    при исследовании эффективности алгоритмов оптимизации, где требуется контроль числа вызовов целевой функции.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество вызовов целевой функции.
    */
    return CountOfFitness;
}
//---------------------------------------------------------------------------

int HML_GetCountOfSubProblems_Binary()
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        VHML_Result = 10;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_GetCountOfSubProblems_Binary(TypeOfTestFunction Type)
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_GetCountOfSubProblems_Binary();

    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_GetCountOfSubProblems_Real()
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VHML_Result = 1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VHML_Result = 7;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VHML_Result = 7;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VHML_Result = 1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VHML_Result = 7;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        VHML_Result = 1;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_GetCountOfSubProblems_Real(TypeOfTestFunction Type)
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_GetCountOfSubProblems_Real();

    return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VHML_N)
{
    /*
    Функция определяет левые и правые границы допустимой области для тестовой функции вещественной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Left - указатель на массив, куда будет записываться результат левых границ допустимой области;
     Right - указатель на массив, куда будет записываться результат левых границ допустимой области;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Отсутствует.
    */
    int i;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        for (i=0;i<VHML_N;i++) Left[i]=0;
        for (i=0;i<VHML_N;i++) Right[i]=4;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        for (i=0;i<VHML_N;i++) Left[i]=0;
        for (i=0;i<VHML_N;i++) Right[i]=4;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-10;
        for (i=0;i<VHML_N;i++) Right[i]=10;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-10;
        for (i=0;i<VHML_N;i++) Right[i]=10;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        for (i=0;i<VHML_N;i++) Left[i]=0;
        for (i=0;i<VHML_N;i++) Right[i]=4;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-512;
        for (i=0;i<VHML_N;i++) Right[i]=512;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-50;
        for (i=0;i<VHML_N;i++) Right[i]=50;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-512;
        for (i=0;i<VHML_N;i++) Right[i]=512;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-16;
        for (i=0;i<VHML_N;i++) Right[i]=16;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-16;
        for (i=0;i<VHML_N;i++) Right[i]=16;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-500;
        for (i=0;i<VHML_N;i++) Right[i]=500;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-16;
        for (i=0;i<VHML_N;i++) Right[i]=16;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-5;
        for (i=0;i<VHML_N;i++) Right[i]=5;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-2;
        for (i=0;i<VHML_N;i++) Right[i]=2;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        for (i=0;i<VHML_N;i++) Left[i]=-12;
        for (i=0;i<VHML_N;i++) Right[i]=12;
    }
}
//---------------------------------------------------------------------------
void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет левые и правые границы допустимой области для тестовой функции вещественной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VHML_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    VHML_TypeOfTestFunction = Type;

    HML_LeftAndRightBorderOfTestFunction_Real(Left, Right, VHML_N);
}
//---------------------------------------------------------------------------

double HML_MaximumOrMinimumOfTestFunction_Binary()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции бинарной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        VHML_Result=1;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type)
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции бинарной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_MaximumOrMinimumOfTestFunction_Binary();

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_MaximumOrMinimumOfTestFunction_Real()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_Ackley)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VHML_Result=1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VHML_Result=-1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VHML_Result=-1;
    }

    if (VHML_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Wave)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VHML_Result=1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Rana)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VHML_Result=-1;
    }
	
	if (VHML_TypeOfTestFunction==TestFunction_Bosom)
    {
        VHML_Result=1;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type)
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VHML_Result = 0;

    VHML_TypeOfTestFunction = Type;

    VHML_Result = HML_MaximumOrMinimumOfTestFunction_Real();

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N)
{
    /*
	Функция определяет значение оптимума для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
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

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VHML_N;i++)
            Optimum[i]=1;
        VHML_Result = HML_FitnessOfOptimumOfTestFunction_Binary(VHML_N);
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение оптимума для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
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

    VHML_Result = HML_TestFunction_Binary(Optimum, VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------

void HML_SetToZeroCountOfFitness()
{
    /*
    Функция обнуляет количество вызовов целевой функции.
    Обязательно вызвать один раз перед вызовом алгоритмов оптимизации при исследовании эффективности
    алгоритмов оптимизации, где требуется контроль числа вызовов целевой функции.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
    */
    CountOfFitness=0;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Binary(int *x, int VHML_N)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию HML_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VHML_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VHML_Result = 0;

    if (VHML_TypeOfTestFunction==TestFunction_SumVector)
        VHML_Result = HML_MaximumOrMinimumOfTestFunction_Binary()*HML_TestFunction_SumVector(x, VHML_N);
    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VHML_Result;
}
//---------------------------------------------------------------------------
double HML_TestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
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

    VHML_Result = HML_TestFunction_Binary(x, VHML_N);

    return VHML_Result;
}
//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------