//HarrixClass_EvaluateFunction
//Версия 1.0
//Класс для вычисления значений функции с помощью QtScript.
//https://github.com/Harrix/HarrixClass_EvaluateFunction
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include <QtScript/QScriptEngine>
#include <QElapsedTimer>
#include "math.h"
#include "HarrixClass_EvaluateFunction.h"

HarrixClass_EvaluateFunction::HarrixClass_EvaluateFunction()
{
/*
    Конструктор.
*/
    Type = EvaluateFunctionOneVariable;//по умолчанию одномерная функция

    setCodeFunction ("RESULT = x");//по умолчанию функция имеет вид fun(x)=x
}
//---------------------------------------------------------------------------

HarrixClass_EvaluateFunction::~HarrixClass_EvaluateFunction()
{

}
//---------------------------------------------------------------------------

void HarrixClass_EvaluateFunction::initialization ()
{
/*
    Инициализация движка QtScript. Внутренная функция
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствуют.
*/
    engine.evaluate(getBeginFunction() + CodeFunction + getEndFunction ());
    scriptFun = engine.globalObject().property("fun");
}
//---------------------------------------------------------------------------

QString HarrixClass_EvaluateFunction::getBeginFunction ()
{
/*
    Получить начало кода функции в QtScript. Внутренная функция
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Начало кода функции в QtScript.
*/
    QString BeginFunction;

    if (Type==EvaluateFunctionOneVariable)
    {
      BeginFunction = "function fun(x)\n {\n var RESULT=0;\n";
    }

    if (Type==EvaluateFunctionTwoVariables)
    {
      BeginFunction = "function fun(x,y)\n {\n var RESULT=0;\n";
    }

    return BeginFunction;
}
//---------------------------------------------------------------------------

QString HarrixClass_EvaluateFunction::getEndFunction ()
{
/*
    Получить конец кода функции в QtScript. Внутренная функция
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Конец кода функции в QtScript.
*/
    QString EndFunction;

    if ((Type==EvaluateFunctionOneVariable)||(Type==EvaluateFunctionTwoVariables))
    {
      EndFunction = "\n return RESULT;\n}\n";
    }

    return EndFunction;
}
//---------------------------------------------------------------------------

void HarrixClass_EvaluateFunction::setCodeFunction (QString Code)
{
/*
    Задать код функции в QtScript.
    Входные параметры:
     Code - код функции в QtScript.
    Возвращаемое значение:
     Отсутствует.
*/
    CodeFunction = Code;

    initialization ();
}
//---------------------------------------------------------------------------

void HarrixClass_EvaluateFunction::setTypeFunction (TypeOfEvaluateFunction T)
{
/*
    Задать тип функции в QtScript.
    Входные параметры:
     T - тип вычисляемой функции.
    Возвращаемое значение:
     Отсутствует.
*/
    Type = T;

    initialization ();
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x)
{
/*
    Получить значение функции в точке x.
    Входные параметры:
     x - входной параметр в одномерной функции.
    Возвращаемое значение:
     Значение функции в точке.
*/
    Result = 0;

    if (Type==EvaluateFunctionOneVariable)
    {
      Result = scriptFun.call(QScriptValue(), QScriptValueList() << x).toNumber();
    }

    if (Type==EvaluateFunctionTwoVariables)
    {
      Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << 0).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x, double y)
{
/*
    Получить значение функции в точке (x,y).
    Входные параметры:
     x - первый входной параметр в двумерной функции.
     y - второй входной параметр в двумерной функции.
    Возвращаемое значение:
     Значение функции в точке.
*/
    Result = 0;

    if (Type==EvaluateFunctionOneVariable)
    {
      Result = scriptFun.call(QScriptValue(), QScriptValueList() << x).toNumber();
    }

    if (Type==EvaluateFunctionTwoVariables)
    {
      Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------
