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