//HarrixMathLibraryForTestFunctions
//Версия 1.0
//Сборник различных математических функций и шаблонов с открытым кодом на языке C++.
//https://github.com/Harrix/HarrixMathLibraryForTestFunctions
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixMathLibraryForTestFunctions.h"
#include "HarrixMathLibrary.h"

TypeOfTestFunction VMHL_TypeOfTestFunction;//для функций по работе с тестовыми функциями для анализа эффективности алгоритмов
int CountOfFitness;//количество вызовов тестовой функции при запуске алгоритма оптимизации

//*****************************************************************
//Для тестовых функций
//*****************************************************************
int MHL_ClassOfTestFunction(TypeOfTestFunction Type)
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
    int VMHL_Result=0;

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

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Для тестовых функций бинарного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 20; 30; 40; 50; 60; 70; 80; 90; 100; 200.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        if (Dimension==20)  VMHL_Result = 225;
        if (Dimension==30)  VMHL_Result = 400;
        if (Dimension==40)  VMHL_Result = 576;
        if (Dimension==50)  VMHL_Result = 784;
        if (Dimension==60)  VMHL_Result = 1024;
        if (Dimension==70)  VMHL_Result = 1296;
        if (Dimension==80)  VMHL_Result = 1521;
        if (Dimension==90)  VMHL_Result = 1764;
        if (Dimension==100) VMHL_Result = 2025;
        if (Dimension==200) VMHL_Result = 4761;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Для тестовых функций бинарного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_CountOfFitnessOfTestFunction_Binary(Dimension);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_CountOfFitnessOfTestFunction_Real(Dimension);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
void MHL_DefineTestFunction(TypeOfTestFunction Type)
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
    VMHL_TypeOfTestFunction=Type;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Binary(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VMHL_Result = 0;

    //проверка
    if (i<0) i=0;
    //if (i>=MHL_GetCountOfSubProblems_Binary()) i=MHL_GetCountOfSubProblems_Binary()-1;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        if (i==0) VMHL_Result = 20;
        if (i==1) VMHL_Result = 30;
        if (i==2) VMHL_Result = 40;
        if (i==3) VMHL_Result = 50;
        if (i==4) VMHL_Result = 60;
        if (i==5) VMHL_Result = 70;
        if (i==6) VMHL_Result = 80;
        if (i==7) VMHL_Result = 90;
        if (i==8) VMHL_Result = 100;
        if (i==9) VMHL_Result = 200;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_DimensionTestFunction_Binary(i);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Real(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VMHL_Result = 0;

    //проверка
    if (i<0) i=0;
    //if (i>=MHL_GetCountOfSubProblems_Real()) i=MHL_GetCountOfSubProblems_Real()-1;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (i==0) VMHL_Result = 2;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Real(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_DimensionTestFunction_Real(i);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result_Ex = 0;
    int i;

    int *Optimum=new int[VMHL_N];

    MHL_OptimumOfTestFunction_Binary(Optimum, VMHL_N);


    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VMHL_N;i++)
            VMHL_Result_Ex+=abs(x[i]-Optimum[i]);
    }

    delete [] Optimum;

    return VMHL_Result_Ex/double(VMHL_N);
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorExOfTestFunction_Binary(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result_Ex = 0;
    int i;

    double *Optimum=new double[VMHL_N];

    MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VMHL_N;i++)
            VMHL_Result_Ex+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
        VMHL_Result_Ex=sqrt(VMHL_Result_Ex)/double(VMHL_N);
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	double *Ex = new double[4];
	for (i=0;i<VMHL_N;i++) Ex[i]=0;
	
	Optimum[0]=( 3.0     ); Optimum[1]=( 2.0     );
	for (i=0;i<VMHL_N;i++)
        Ex[0]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[0]=sqrt(Ex[0])/double(VMHL_N);
	
	Optimum[0]=(-2.805118); Optimum[1]=( 3.131312);
	for (i=0;i<VMHL_N;i++)
        Ex[1]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[1]=sqrt(Ex[1])/double(VMHL_N);
	
	Optimum[0]=(-3.779310); Optimum[1]=(-3.283186);
	for (i=0;i<VMHL_N;i++)
        Ex[2]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[2]=sqrt(Ex[2])/double(VMHL_N);
	
	Optimum[0]=( 3.584428); Optimum[1]=(-1.848126);
	for (i=0;i<VMHL_N;i++)
        Ex[3]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[3]=sqrt(Ex[3])/double(VMHL_N);	
	
	VMHL_Result_Ex = TMHL_MinimumOfVector(Ex,4);
	
	delete [] Ex;
    }

    delete [] Optimum;

    return VMHL_Result_Ex;
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorExOfTestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result_Ey = 0;

    double FitnessOfOptimum=MHL_FitnessOfOptimumOfTestFunction_Binary(VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Binary()*FitnessOfx-FitnessOfOptimum);
		VMHL_Result_Ey/=double(VMHL_N);
    }

    return VMHL_Result_Ey;
}
//---------------------------------------------------------------------------
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorEyOfTestFunction_Binary(FitnessOfx, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result_Ey = 0;

    double FitnessOfOptimum=MHL_FitnessOfOptimumOfTestFunction_Real(VMHL_N);

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Himmelblau)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    return VMHL_Result_Ey;
}
//---------------------------------------------------------------------------
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorEyOfTestFunction_Real(FitnessOfx, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N)
{
    /*
    Функция определяет значение надежности найденного решения
	в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result_R = 1;
    int i;

    int *Optimum=new int[VMHL_N];

    MHL_OptimumOfTestFunction_Binary(Optimum, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (x[i]!=Optimum[i]) VMHL_Result_R=0;
        }
    }

    delete [] Optimum;

    return VMHL_Result_R;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorROfTestFunction_Binary(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result_R = 1;
    int i;

    double *Optimum=new double[VMHL_N];

    MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])>=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	VMHL_Result_R = 0;
	double p=MHL_PrecisionOfCalculationsOfTestFunction_Real();
	
	if ( (fabs(x[0]-( 3.0     ))<p) && (fabs(x[1]-( 2.0     ))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-(-2.805118))<p) && (fabs(x[1]-( 3.131312))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-(-3.779310))<p) && (fabs(x[1]-(-3.283186))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-( 3.584428))<p) && (fabs(x[1]-(-1.848126))<p)  ) VMHL_Result_R = 1;
    }

    delete [] Optimum;

    return VMHL_Result_R;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorROfTestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        VMHL_Result = VMHL_N;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N, TypeOfTestFunction Type)
{
    /*
	Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Binary(VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result = -15.606060606060606;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result = -60.8872819100091;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result = 1.;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result = 0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result = 0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result = 1.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result = 0.000103742;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result = 1.93374;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result = 1.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result = -1.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        VMHL_Result = -511.7328819;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VMHL_Result = 0.99800384;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
		VMHL_Result = -959.64067;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
		VMHL_Result = 0;
        double *x;
        x=new double[int(VMHL_N)];
		for (int i=0;i<VMHL_N;i++) x[i]=420.968746;
		VMHL_Result=MHL_TestFunction_Schwefel(x,VMHL_N);
		delete [] x;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
		VMHL_Result = -0.99019608;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
		VMHL_Result = 0;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Real(VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfFitness()
{
    /*
    Функция выдает количество вызовов целевой функции.
    Вызывать после вызова алгорита оптимизации.
    Обязательно вызвать MHL_SetToZeroCountOfFitness один раз перед вызовом алгоритмов оптимизации
    при исследовании эффективности алгоритмов оптимизации, где требуется контроль числа вызовов целевой функции.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Количество вызовов целевой функции.
    */
    return CountOfFitness;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfSubProblems_Binary()
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        VMHL_Result = 10;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfSubProblems_Binary(TypeOfTestFunction Type)
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции бинарной оптимизации.
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_GetCountOfSubProblems_Binary();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfSubProblems_Real()
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result = 1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result = 7;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result = 7;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VMHL_Result = 7;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfSubProblems_Real(TypeOfTestFunction Type)
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_GetCountOfSubProblems_Real();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VMHL_N)
{
    /*
    Функция определяет левые и правые границы допустимой области для тестовой функции вещественной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Left - указатель на массив, куда будет записываться результат левых границ допустимой области;
     Right - указатель на массив, куда будет записываться результат левых границ допустимой области;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Отсутствует.
    */
    int i;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=0;
        for (i=0;i<VMHL_N;i++) Right[i]=4;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=0;
        for (i=0;i<VMHL_N;i++) Right[i]=4;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-10;
        for (i=0;i<VMHL_N;i++) Right[i]=10;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-10;
        for (i=0;i<VMHL_N;i++) Right[i]=10;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=0;
        for (i=0;i<VMHL_N;i++) Right[i]=4;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-512;
        for (i=0;i<VMHL_N;i++) Right[i]=512;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-50;
        for (i=0;i<VMHL_N;i++) Right[i]=50;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-512;
        for (i=0;i<VMHL_N;i++) Right[i]=512;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-16;
        for (i=0;i<VMHL_N;i++) Right[i]=16;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-16;
        for (i=0;i<VMHL_N;i++) Right[i]=16;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-500;
        for (i=0;i<VMHL_N;i++) Right[i]=500;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-16;
        for (i=0;i<VMHL_N;i++) Right[i]=16;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-5;
        for (i=0;i<VMHL_N;i++) Right[i]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        for (i=0;i<VMHL_N;i++) Left[i]=-2;
        for (i=0;i<VMHL_N;i++) Right[i]=2;
    }
}
//---------------------------------------------------------------------------
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет левые и правые границы допустимой области для тестовой функции вещественной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    VMHL_TypeOfTestFunction = Type;

    MHL_LeftAndRightBorderOfTestFunction_Real(Left, Right, VMHL_N);
}
//---------------------------------------------------------------------------
double MHL_MaximumOrMinimumOfTestFunction_Binary()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции бинарной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        VMHL_Result=1;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type)
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
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Binary();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_MaximumOrMinimumOfTestFunction_Real()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result=1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result=-1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result=-1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result=1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result=1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result=1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VMHL_Result=-1;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type)
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
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result_E = 0;
    int i;

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Himmelblau)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VMHL_N;i++) NumberOfParts[i]=4095;
    }

    VMHL_Result_E=MHL_PrecisionOfCalculationsOfTestFunction_Real();

    return VMHL_Result_E;
}
//---------------------------------------------------------------------------
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_NumberOfPartsOfTestFunction_Real(NumberOfParts, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N)
{
    /*
	Функция определяет значение оптимума для тестовой функции бинарной оптимизации.
	Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;
    int i;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VMHL_N;i++)
            Optimum[i]=1;
        VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Binary(VMHL_N);
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение оптимума для тестовой функции бинарной оптимизации. 
	Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_TestFunction_Binary(Optimum, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N)
{
    /*
    Функция определяет значение оптимума для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;
    int i;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0.954452;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=-0.993263;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	// один из 4 оптимумов
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
        Optimum[0]=3;
		Optimum[1]=2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
        Optimum[0]=-488.6326;
		Optimum[1]=512;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=-32;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
        Optimum[0]=512;
		Optimum[1]=404.2319;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=420.968746;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
        Optimum[0]=0.00990099;
		Optimum[1]=5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        for (i=0;i<VMHL_N;i++) Optimum[i]=0;
    }

    VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Real(VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение оптимума для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Optimum - указатель на исходный массив, куда будет записываться результат;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_PrecisionOfCalculationsOfTestFunction_Real()
{
    /*
    Функция определяет точность для подсчета надежности в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result_E = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result_E=0.05;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result_E=0.01;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result_E=0.025;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result_E=0.05;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result_E=2.5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result_E=0.25;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VMHL_Result_E=2.5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VMHL_Result_E=0.08;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VMHL_Result_E=0.08;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VMHL_Result_E=2.5;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VMHL_Result_E=0.08;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
    {
        VMHL_Result_E=0.01;
    }

    return VMHL_Result_E;
}
//---------------------------------------------------------------------------
double MHL_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type)
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
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_PrecisionOfCalculationsOfTestFunction_Real();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
void MHL_SetToZeroCountOfFitness()
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
double MHL_TestFunction_Binary(int *x, int VMHL_N)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Binary()*MHL_TestFunction_SumVector(x, VMHL_N);
    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_TestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач бинарной оптимизации. Включает в себя все тестовые функции.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x,
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_TestFunction_Binary(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_TestFunction_Real(double *x, int VMHL_N)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Ackley(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_AdditivePotential(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_MultiplicativePotential(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ReverseGriewank(x[0], x[1]);

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ParaboloidOfRevolution(x, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rastrigin(x, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rosenbrock(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_HyperEllipsoid(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RotatedHyperEllipsoid(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Wave(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal2(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Sombrero(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Himmelblau(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Katnikov(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal3(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal4(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_StepFunction(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rana(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ShekelsFoxholes(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_EggHolder(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginWithChange(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginWithTurning(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Schwefel(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Griewangk(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_InvertedRosenbrock(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_GaussianQuartic(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginNovgorod(x, VMHL_N);

    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_TestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x,
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_TestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

