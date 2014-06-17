void HarrixClass_DataOfHarrixOptimizationTesting::readXml()
{
    /*
     Считывание XML файла и осуществление всех остальных анализов и др.
     */

    Rxml.readNext();while((!Rxml.isStartElement())&&(!Rxml.atEnd())){Rxml.readNext();}//первый нормальный элемент

    //Начнем анализ документа
    if (readXmlTreeTag("document"))
    {
        if (readXmlTreeTag("harrix_file_format"))
        {
            //далее должны идти тэги format, version, site
            for (int k=0;k<3;k++)
                readXmlLeafTag();//считает тэг

            if (readXmlTreeTag("about"))
            {
                //далее должны идти тэги author, date, email
                for (int k=0;k<3;k++)
                    readXmlLeafTag();//считает тэг

                if (readXmlTreeTag("about_data"))
                {
                    //далее должны идти 13 тэгов по информации о данных
                    for (int k=0;k<13;k++)
                        readXmlLeafTag();//считает тэг

                    readXmlTreeTag("data");
                }
            }
            checkXmlLeafTags();//проверим наличие всех тэгов
        }
    }

    if (!Error)
    {
        memoryAllocation();//выделение памяти под массивы
        Data.memoryAllocation();
        zeroArray();//обнулим массивы
        readXmlDataTags();//считаем данные непосредственно
    }
    if ((Rxml.hasError())||(Error))
    {
        HtmlMessageOfError+=HQt_ShowAlert("В процессе разбора файла обнаружены ошибки. Помните, что для этой функции обработки XML файла требуется правильный порядок следования тэгов.");
        Html+=HtmlMessageOfError;
        Data.setSuccessReading(false);
    }
    else
    {
        Data.setSuccessReading(true);
        makingAnalysis();//выполняем анализ данных

        //Обработка полученной информации Html
        makingHtmlReport();
        Html+=HtmlReport;

        //Обработка полученной информации Latex
        NameForHead="алгоритма оптимизации <<"+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getFullNameAlgorithm()))+">>на тестовой функции <<"+HQt_ForcedWordWrap(HQt_StringForLaTeX(Data.getFullNameTestFunction()))+">> (размерность равна "+QString::number(Data.getDimensionTestFunction())+")";
        makingLatexInfo();
        makingLatexAboutParameters();
        makingLatexTableEx();//заполняем LatexTableEx
        makingLatexTableEy();//заполняем LatexTableEy
        makingLatexTableR();//заполняем LatexTableR
        makingListOfVectorParameterOptions();
        makingLatexListOfVectorParameterOptions();
        makingLatexAnalysis();//заполняем LatexTableR
        //Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;
        Latex+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR+LatexListOfVectorParameterOptions+LatexAnalysis;
        LatexTable+=LatexInfo+LatexAboutParameters+LatexTableEx+LatexTableEy+LatexTableR;

        Html+=HQt_ShowHr();
        Html+=HQt_ShowText("Обработка файла завершена. Ошибки не обнаружены");
    }
	
    Rxml.clear();//больше не будем использовать, так что удаляем
}