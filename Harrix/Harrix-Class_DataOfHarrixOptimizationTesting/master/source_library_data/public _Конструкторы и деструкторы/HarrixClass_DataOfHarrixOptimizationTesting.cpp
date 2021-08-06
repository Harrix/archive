HarrixClass_DataOfHarrixOptimizationTesting::HarrixClass_DataOfHarrixOptimizationTesting(QString filename)
{
    /*
    Конструктор. Функция считывает данные о тестировании алгоритма оптимизации
    из файла формата HarrixOptimizationTesting.
    Входные параметры:
     filename - полное имя считываемого файла.
 */
    initializationOfVariables();

    if (!HQt_FileExists(filename))
    {
        if (filename.isEmpty())
            HtmlMessageOfError+=HQt_ShowAlert("Это пустой экземпляр класса");
        else
            HtmlMessageOfError+=HQt_ShowAlert("Файл "+HQt_GetFilenameFromFullFilename(filename)+" не открывается");
        Error=true;
    }
    else
    {
        Html+=HQt_ShowText("Файл <font color=\"#00b400\">"+HQt_GetFilenameFromFullFilename(filename)+"</font> загружен");

        //Первоначальные действия
        try
        {
            FileXML=HQt_ReadFile(filename);
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Файл не был прочитан.");
            Error=true;
        }

        try
        {
            Rxml.addData(FileXML);
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Не смогли добавить содержимое в экземпляр QXmlStreamReader.");
            Error=true;
        }

        try
        {
            readXml();//считывание XML файла и все остальные анализы запускаются в этой функцииcatch (...)
        }
        catch (...)
        {
            HtmlMessageOfError+=HQt_ShowAlert("Считывание XML файла прошло с ошибками.");
            Error=true;
        }
    }
}
//--------------------------------------------------------------------------
HarrixClass_DataOfHarrixOptimizationTesting::HarrixClass_DataOfHarrixOptimizationTesting()
{
    /*
    Конструктор. Создает пустой экземпляр.
    Входные параметры:
     Отсутствуют.
 */
    HarrixClass_DataOfHarrixOptimizationTesting("");
}