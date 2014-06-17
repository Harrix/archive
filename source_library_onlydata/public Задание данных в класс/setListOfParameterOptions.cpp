void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setListOfParameterOptions(QStringList List, int Number_Of_Parameter)
{
    /*
    Задание списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     List - список названий параметров, которым будем заменять текущий список.
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Значения параметра в виде наименования.
     */
    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    ListOfParameterOptions[Number_Of_Parameter] = List;
}