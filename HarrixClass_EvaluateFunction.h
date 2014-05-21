#ifndef HarrixClass_EvaluateFunction_H
#define HarrixClass_EvaluateFunction_H

#include <QtScript/QScriptEngine>
#include <QElapsedTimer>

//Тип вычисляемой функции
enum TypeOfEvaluateFunction {EvaluateFunctionOneVariable, EvaluateFunctionTwoVariables, EvaluateFunctionThreeVariables,
                            EvaluateFunctionFourVariables};

class HarrixClass_EvaluateFunction
{
public:
    HarrixClass_EvaluateFunction();
    ~HarrixClass_EvaluateFunction();

    void setTypeFunction (TypeOfEvaluateFunction T);//Задать тип функции в QtScript.
    void setCodeFunction (QString Code);//Задать код функции в QtScript.ss
    double getEvaluateFunction (double x);//Получить значение функции в точке x.
    double getEvaluateFunction (double x, double y);//Получить значение функции в точке (x,y).
    double getEvaluateFunction (double x, double y, double z);//Получить значение функции в точке (x,y,z).
    double getEvaluateFunction (double x, double y, double z, double k);//Получить значение функции в точке (x,y,z,k).

private:
    void initialization ();//Инициализация движка QtScript
    QString getBeginFunction ();//Получить начало кода функции в QtScript
    QString getEndFunction ();// Получить конец кода функции в QtScript

    //Основные переменные для работы с QtScript
    QScriptEngine engine;
    QScriptValue scriptFun;

    TypeOfEvaluateFunction Type;//Тип вычисляемой функции (EvaluateFunctionOneVariable по умолчанию)
    double Result;//Сюда возвращается значение функции, которую мы вычисляем
    QString CodeFunction; //код функции на QtScript
};

#endif // HarrixClass_EvaluateFunction_H
