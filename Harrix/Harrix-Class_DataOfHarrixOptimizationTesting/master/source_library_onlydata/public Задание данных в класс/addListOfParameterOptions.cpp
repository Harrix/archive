void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addListOfParameterOptions(QString Option, int Number_Of_Parameter)
{
    /*
    Добавление списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Option - добавляемое название варианта параметра алгоритма.
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    ListOfParameterOptions[Number_Of_Parameter]<<Option;
}