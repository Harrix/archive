int HCDOHOT_NumberFilesInDir(QString path)
{
    /*
    Подсчитывает число HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
    Возвращаемое значение:
     Число файлов HarrixClass_DataOfHarrixOptimizationTesting файлов в папке.
     */
    int Result=0;

    path = QDir::toNativeSeparators(path);

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
                //HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                Result++;
            }
            QGuiApplication::processEvents();
        }
    }

    return Result;
}