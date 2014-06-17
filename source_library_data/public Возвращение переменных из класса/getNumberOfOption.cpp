int HarrixClass_DataOfHarrixOptimizationTesting::getNumberOfOption(QString NameOption)
{
    /*
    Получение номера параметра алгоритма по его имени.
    Входные параметры:
     NameOption - имя параметра.
    Возвращаемое значение:
     Значения параметра в виде номера (если не найдено, то возвращается -1.
     */
    int VMHL_Result=-1;

    VMHL_Result = HQt_SearchQStringInQStringList (Data.getNamesOfParameters(), NameOption);

    return VMHL_Result;
}