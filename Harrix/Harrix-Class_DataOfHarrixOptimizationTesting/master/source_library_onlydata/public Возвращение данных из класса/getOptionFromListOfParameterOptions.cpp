QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getOptionFromListOfParameterOptions(int Number_Of_Parameter, int Number_Of_Option)
{
    /*
    Получение названия вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
     Number_Of_Option - номер считываемой опции у параметра алгоритма оптимизации.
    Возвращаемое значение:
     Название вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    return ListOfParameterOptions[Number_Of_Parameter].at(Number_Of_Option);
}