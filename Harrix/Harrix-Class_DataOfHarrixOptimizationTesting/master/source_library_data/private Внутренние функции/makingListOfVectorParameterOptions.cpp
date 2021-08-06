void HarrixClass_DataOfHarrixOptimizationTesting::makingListOfVectorParameterOptions()
{
    /*
    Заполняет список вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell2.clear();

        //получим значения параметров алгоритма
        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +". ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +".  ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +". ";
        }

        //получим значения критерий

        Data.addListOfVectorParameterOptions(Cell2);

        NumberOfListOfVectorParameterOptions[i]=i+1;
    }
}