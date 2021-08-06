void HarrixClass_DataOfHarrixOptimizationTesting::operator = (HarrixClass_DataOfHarrixOptimizationTesting& B)
{
    //Вначале уничтожим все массивы если они были.
    memoryDeallocation();

    initializationOfVariables();

    FileXML=B.FileXML;

    if (FileXML.isEmpty())
    {
        HtmlMessageOfError+=HQt_ShowAlert("Это пустой экземпляр класса");
        Error=true;
    }
    else
    {
        Rxml.addData(FileXML);

        readXml();//считывание XML файла и все остальные анализы запускаются в этой функции

        Html+=HQt_ShowText("Экземпляр скопирован");
    }
}