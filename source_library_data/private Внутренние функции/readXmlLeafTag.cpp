void HarrixClass_DataOfHarrixOptimizationTesting::readXmlLeafTag()
{
    /*
    Считывает и проверяет тэг, который должен являться "листом", то есть самым глубоким. Внутренняя функция.
    Учитывает все "листовые" тэги кроме тэгов данных.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует.
     */
    bool FindTag=false;
    NameOfElement.clear();

    //проверка тэга number_of_parameters
    if ((!Rxml.atEnd())&&(!Error))
    {
        NameOfElement=Rxml.name().toString().toLower();
        TextOfElement=Rxml.readElementText();
        if (NameOfElement=="number_of_parameters")
        {
            Data.setNumberOfParameters(TextOfElement.toInt());
            if (Data.getNumberOfParameters()==0)
            {
                //чтобы  в дальнейших вычислениях не было путаницы, но всё равно считаем,
                //что число параметров нулю
                Data.setNumberOfParameters(1);
                Zero_Number_Of_Parameters=true;
            }

            FindTag=true;
        }
        if (NameOfElement=="number_of_experiments")
        {
            Data.setNumberOfExperiments(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="max_count_of_fitness")
        {
            Data.setMaxCountOfFitness(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="number_of_runs")
        {
            Data.setNumberOfRuns(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="number_of_measuring")
        {
            Data.setNumberOfMeasuring(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="dimension_test_function")
        {
            Data.setDimensionTestFunction(TextOfElement.toInt());
            FindTag=true;
        }
        if (NameOfElement=="full_name_test_function")
        {
            Data.setFullNameTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="name_test_function")
        {
            Data.setNameTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="full_name_algorithm")
        {
            Data.setFullNameAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="name_algorithm")
        {
            Data.setNameAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="date")
        {
            Data.setDate(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="author")
        {
            Data.setAuthor(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="email")
        {
            Data.setEmail(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link_test_function")
        {
            Data.setLinkTestFunction(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link_algorithm")
        {
            Data.setLinkAlgorithm(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="format")
        {
            Data.setFormat(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="version")
        {
            Data.setVersion(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="link")
        {
            Data.setLink(TextOfElement);
            FindTag=true;
        }
        if (NameOfElement=="all_combinations")
        {
            Data.setCheckAllCombinations(TextOfElement.toInt());
            FindTag=true;
        }
    }

    if (FindTag)
    {
        Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}
    }
    else
    {
        if (NameOfElement.length()>0)
            HtmlMessageOfError+=HQt_ShowAlert("Попался какой-то непонятный тэг "+NameOfElement+". Программа в непонятках! О_о");
        else
            HtmlMessageOfError+=HQt_ShowAlert("Ждали-ждали тэг, а тут вообще ничего нет.");
        Error=true;
    }
}