int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path, QString pathForTempHtml)
{
    /*
    Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=0;

    path = QDir::toNativeSeparators(path);

    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);
    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    QString Html;

    if (path.length()>0)
    {
        QString filename;

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                SeveralData[i]=Data.getData();

                if (!pathForTempHtml.isEmpty())
                {
                    if (Data.getSuccessReading())
                    {
                        Html=HQt_ShowSimpleText(filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                    else
                    {
                        Html=HQt_ShowAlert("Ошибка при считывании файла "+ filename);
                        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                    }
                }

                Result++;
            }
            QGuiApplication::processEvents();
        }
    }

    return Result;
}
//--------------------------------------------------------------------------
int HCDOHOT_ReadFilesOnlyDataInDir(HarrixClass_OnlyDataOfHarrixOptimizationTesting *SeveralData, QString path)
{
    /*
    Заполняет массив SeveralData данными (только исследования) из всех файлов *.hdata из папки. Без создания html отчета.
    Входные параметры:
     SeveralData - массив, в который записываем данные.
     path - путь к папке, из которой считаем файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Примечание.
     Подсчитать число файлов в папке до вызова этой функции можно функцией HCDOHOT_NumberFilesInDir.
     */
    int Result=0;

    Result = HCDOHOT_ReadFilesOnlyDataInDir(SeveralData, path, "");

    return Result;
}