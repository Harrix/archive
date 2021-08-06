int HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfOption(QString NameOption)
{
    /*
    Получение номера параметра алгоритма по его имени.
    Входные параметры:
     NameOption - имя параметра.
    Возвращаемое значение:
     Значения параметра в виде номера (если не найдено, то возвращается -1.
     */
    int VHML_Result=-1;

    VHML_Result = HQt_SearchQStringInQStringList (Data.getNamesOfParameters(), NameOption);

    return VHML_Result;
}