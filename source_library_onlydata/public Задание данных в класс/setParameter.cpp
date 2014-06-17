void HarrixClass_OnlyDataOfHarrixOptimizationTesting::setParameter(int Parameter, int Number_Of_Experiment, int Number_Of_Parameter)
{
    /*
    Задание значения параметра настройки какой-то.
    Входные параметры:
	 Parameter - значение параметра в виде числа;
     Number_Of_Experiment - номер комбинации вариантов настроек;
     Number_Of_Parameter - номер параметра.
    Возвращаемое значение:
     Отсутствует.
     */
    if (Number_Of_Experiment<0) Number_Of_Experiment=0;
    if (Number_Of_Experiment>XML_Number_Of_Experiments-1) Number_Of_Experiment=XML_Number_Of_Experiments-1;

    if (Number_Of_Parameter<0) Number_Of_Parameter=0;
    if (Number_Of_Parameter>XML_Number_Of_Parameters-1) Number_Of_Parameter=XML_Number_Of_Parameters-1;

    MatrixOfParameters[Number_Of_Experiment][Number_Of_Parameter] = Parameter;
}