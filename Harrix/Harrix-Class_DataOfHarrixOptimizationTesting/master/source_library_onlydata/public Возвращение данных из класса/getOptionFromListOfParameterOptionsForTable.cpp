QString HarrixClass_OnlyDataOfHarrixOptimizationTesting::getOptionFromListOfParameterOptionsForTable(int Number_Of_Parameter, int Number_Of_Option)
{
    /*
    Получение названия вариантов параметров алгоритма оптимизации. Но старается где-то сокращать, а где-то добавлять строки.
    Входные параметры:
     Number_Of_Parameter - номер параметра.
     Number_Of_Option - номер считываемой опции у параметра алгоритма оптимизации.
    Возвращаемое значение:
     Название вариантов параметров алгоритма оптимизации.
     */

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    QString Result=ListOfParameterOptions[Number_Of_Parameter].at(Number_Of_Option);

    if (!HQt_IsNumeric(Result))
    {
        if (Result.length()>=5)
            Result = HQt_TryingReduceString(Result,40);
        else
        {
            Result = HQt_TryingReduceString(Result,40);

            QString NameOption = getNameOption(Number_Of_Parameter);
            NameOption = HQt_TryingReduceString(NameOption,40-3-Result.length());
            Result=NameOption + " = " + Result;
        }
    }
    else
    {
        QString NameOption = getNameOption(Number_Of_Parameter);
        NameOption = HQt_TryingReduceString(NameOption,40-3-Result.length());
        Result=NameOption + " = " + Result;
    }

    return Result;
}