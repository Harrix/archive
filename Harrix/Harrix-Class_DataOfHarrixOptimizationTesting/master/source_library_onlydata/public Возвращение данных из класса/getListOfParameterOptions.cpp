QStringList HarrixClass_OnlyDataOfHarrixOptimizationTesting::getListOfParameterOptions(int Number_Of_Parameter)
{
    /*
    Получение списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Список вектора названий вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return ListOfParameterOptions[Number_Of_Parameter];
}