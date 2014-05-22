//HarrixClass_EvaluateFunction
//Версия 1.4
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

    if (Type==EvaluateFunctionThreeVariables)
    {
        BeginFunction = "function fun(x,y,z)\n {\n var RESULT=0;\n";
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        BeginFunction = "function fun(x,y,z,k)\n {\n var RESULT=0;\n";
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        BeginFunction = "function fun(x1,x2,x3,x4,x5)\n {\n var RESULT=0;\n";
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        BeginFunction = "function fun(x1,x2,x3,x4,x5,x6)\n {\n var RESULT=0;\n";
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

    EndFunction = "\n return RESULT;\n}\n";

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

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << 0 << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << 0 << 0 << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << 0 << 0 << 0 << 0 << 0).toNumber();
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

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << 0).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << 0 << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << 0 << 0 << 0 << 0).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x, double y, double z)
{
    /*
    Получить значение функции в точке (x,y,z).
    Входные параметры:
     x - первый входной параметр в трехмерной функции.
     y - второй входной параметр в трехмерной функции.
     z - третий входной параметр в трехмерной функции.
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

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << 0).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << 0 << 0).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << 0 << 0 << 0).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x, double y, double z, double k)
{
    /*
    Получить значение функции в точке (x,y,z,k).
    Входные параметры:
     x - первый входной параметр в четырехмерной функции.
     y - второй входной параметр в четырехмерной функции.
     z - третий входной параметр в четырехмерной функции.
     k - четвертый входной параметр в четырехмерной функции.
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

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << k).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << k << 0).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x << y << z << k << 0 << 0).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x1, double x2, double x3, double x4, double x5)
{
    /*
    Получить значение функции в точке (x1,x2,x3,x4,x5).
    Входные параметры:
     x1 - первый входной параметр в пятимерной функции.
     x2 - второй входной параметр в пятимерной функции.
     x3 - третий входной параметр в пятимерной функции.
     x4 - четвертый входной параметр в пятимерной функции.
     x5 - пятый входной параметр в пятимерной функции.
    Возвращаемое значение:
     Значение функции в точке.
*/
    Result = 0;

    if (Type==EvaluateFunctionOneVariable)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1).toNumber();
    }

    if (Type==EvaluateFunctionTwoVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2).toNumber();
    }

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4 << x5).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4 << x5 << 0).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------

double HarrixClass_EvaluateFunction::getEvaluateFunction (double x1, double x2, double x3, double x4, double x5, double x6)
{
    /*
    Получить значение функции в точке (x1,x2,x3,x4,x5,x6).
    Входные параметры:
     x1 - первый входной параметр в шестимерной функции.
     x2 - второй входной параметр в шестимерной функции.
     x3 - третий входной параметр в шестимерной функции.
     x4 - четвертый входной параметр в шестимерной функции.
     x5 - пятый входной параметр в шестимерной функции.
     x6 - шестой входной параметр в шестимерной функции.
    Возвращаемое значение:
     Значение функции в точке.
*/
    Result = 0;

    if (Type==EvaluateFunctionOneVariable)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1).toNumber();
    }

    if (Type==EvaluateFunctionTwoVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2).toNumber();
    }

    if (Type==EvaluateFunctionThreeVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3).toNumber();
    }

    if (Type==EvaluateFunctionFourVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4).toNumber();
    }

    if (Type==EvaluateFunctionFiveVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4 << x5).toNumber();
    }

    if (Type==EvaluateFunctionSixVariables)
    {
        Result = scriptFun.call(QScriptValue(), QScriptValueList() << x1 << x2 << x3 << x4 << x5 << x6).toNumber();
    }

    return Result;
}
//---------------------------------------------------------------------------
