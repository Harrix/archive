void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave, QString pathForTempHtml)
{
    /*
    Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    filename = QDir::toNativeSeparators(filename);
    pathForSave = QDir::toNativeSeparators(pathForSave);
    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);

    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    if (filename.length()>0)
    {
        QString Html;//сюда записывается код  HTML по анализу файла данных
        QString Latex;//сюда записывается код  Latex для добавления в https://github.com/Harrix/HarrixLaTeXDocumentTemplate

        HarrixClass_DataOfHarrixOptimizationTesting Data(filename);

        if (Data.getSuccessReading())
        {
            Html=Data.getHtml();

            Latex=Data.getFullLatexAnalysis();

            HQt_SaveFile(Latex, pathForSave+"\\Report.tex");

            if (!pathForTempHtml.isEmpty())
            {
                HQt_AddHtml(Html);
            }
        }
        else
        {
            //выводим ошибку
            Html=Data.getHtml();
            if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
        }

    }
}
//--------------------------------------------------------------------------
void HCDOHOT_GeneratedAnalysisReportFromFile(QString filename, QString pathForSave)
{
    /*
    Генерирует отчет-анализ Latex по алгоритму по файлу *.hdata без генерации Html отчета.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     filename - путь к файлу, из которого считываем данные.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    HCDOHOT_GeneratedAnalysisReportFromFile(filename, pathForSave, "");
}