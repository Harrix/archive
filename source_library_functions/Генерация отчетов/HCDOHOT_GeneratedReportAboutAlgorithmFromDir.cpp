void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave, QString pathForTempHtml)
{
    /*
    Генерирует отчет Latex по алгоритму по файлам *.hdata алгоритма, просматривая все файлы в папке.
    То, чтобы в папке были файлы только одного алгоритма, вы берете на себя.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Для отчета в виде html берется проект:
    https://github.com/Harrix/HarrixHtmlForQWebView
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
     pathForTempHtml - путь к папке куда сохраняем во время работы функции отчет в виде temp.html.
    Возвращаемое значение:
     Отсутствует.
     */
    path = QDir::toNativeSeparators(path);
    pathForSave = QDir::toNativeSeparators(pathForSave);
    if (!pathForTempHtml.isEmpty()) pathForTempHtml = QDir::toNativeSeparators(pathForTempHtml);

    //if (!pathForTempHtml.isEmpty()) HQt_BeginHtml (pathForTempHtml);

    if (path.length()>0)
    {
        QString Html;//сюда записывается код  HTML по анализу файла данных
        QString Latex;//сюда записывается код  Latex для добавления в https://github.com/Harrix/HarrixLaTeXDocumentTemplate
        QString LatexInclude;//сюда записываются отдельные исследования, которые сохраняются в отдельные файлы
        QString filename;
        QString namealg;

        //Вытащим название папки, из которой всё считываем
        QStringList dirs = path.split( "\\", QString::SkipEmptyParts );
        namealg = dirs.at(dirs.count()-1);
        QString namealgNameForSave=namealg;
        if (namealg.at(0)=='_') namealg = namealg.mid(1);

        Html=path;
        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

        QStringList Files = HQt_ListFilesInDirQStringList(path);

        Files = HQt_NaturalSortingQStringList(Files);//сортируем правильно список файлов

        Latex+=HQt_LatexBeginArticle();//Начало LaTeX файла

        for (int i=0;i<Files.count();i++)
        {
            filename=Files.at(i);
            if (HQt_GetExpFromFilename(filename)=="xml")
            {
                Html=HQt_ShowSimpleText(filename);
                if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

                HarrixClass_DataOfHarrixOptimizationTesting Data(path+"\\"+filename);

                if (Data.getSuccessReading())
                {
                    if (i==0)
                    {
                        Latex+="\\title{Исследование алгоритма оптимизации "+HQt_ForcedWordWrap(HQt_TextToTextForLatex(namealg))+"}\n";
                        //namealg=Data.getNameAlgorithm();

                        Latex+="\\author{"+HQt_TextToTextForLatex(Data.getAuthor())+"}\n";
                        Latex+="\\date{\\today}\n";
                        Latex+="\\maketitle\n\n";
                        Latex+="\\tableofcontents\n";
                        Latex+="\\newpage\n\n";
                        Latex+="\\section{Вводная информация}\n\n";
                        Latex+="Данный файл и другие исследования располагаются по адресу:\n\n \\href {https://github.com/Harrix/HarrixPDFDataOfOptimizationTesting} {https://github.com/Harrix/HarrixPDFDataOfOptimizationTesting}.\n\n";
                        Latex+="Анализ данных исследований можно посмотреть по адресу:\n\n \\href {https://github.com/Harrix/HarrixAnalysisPDFDataOfOptimizationTesting} {https://github.com/Harrix/HarrixAnalysisPDFDataOfOptimizationTesting}.\n\n";

                        Latex+="Данные исследований взяты из базы исследований алгоритмов оптимизации:\n\n \\href {https://github.com/Harrix/HarrixDataOfOptimizationTesting} {https://github.com/Harrix/HarrixDataOfOptimizationTesting}.\n\n";
                        Latex+="О методологии проведения исследований можно прочитать в описании формата данных <<Harrix Optimization Testing>> в главе <<Идея проведения исследований эффективности алгоритмов>> по адресу:\n\n \\href {https://github.com/Harrix/HarrixFileFormats} {https://github.com/Harrix/HarrixFileFormats}.\n\n";
                        Latex+="Описание алгоритма оптимизации можно найти по адресу:\n\n \\href {https://github.com/Harrix/HarrixOptimizationAlgorithms} {https://github.com/Harrix/HarrixOptimizationAlgorithms}.\n\n";
                        Latex+="Описание тестовых функций можно найти по адресу:\n\n \\href {https://github.com/Harrix/HarrixTestFunctions} {https://github.com/Harrix/HarrixTestFunctions}.\n\n";
                        Latex+="С автором можно связаться по адресу \\href {mailto:sergienkoanton@mail.ru} {sergienkoanton@mail.ru} или  \\href {http://vk.com/harrix} {http://vk.com/harrix}. Сайт автора, где публикуются последние новости: \\href {http://blog.harrix.org} {http://blog.harrix.org}, а проекты располагаются по адресу \\href {http://harrix.org} {http://harrix.org}.\n\n";
                    }

                    LatexInclude=Data.getLatexTable();
                    HQt_SaveFile(LatexInclude, pathForSave+"\\"+(HQt_GetNameFromFilename(filename)).replace("_","").replace(" ", "")+".tex");
                    Latex += "\\input{"+(HQt_GetNameFromFilename(filename)).replace("_","").replace(" ", "")+"}\n";
                }
                else
                {
                    //выводим ошибку
                    Html=Data.getHtml();
                    if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);
                }

            }
            QGuiApplication::processEvents();
        }

        Latex+=HQt_LatexEnd();
        HQt_SaveFile(Latex, pathForSave+"\\"+namealgNameForSave+".tex");

        Html=HQt_ShowSimpleText("Сохранили");
        if (!pathForTempHtml.isEmpty()) HQt_AddHtml(Html);

    }
}
//--------------------------------------------------------------------------
void HCDOHOT_GeneratedReportAboutAlgorithmFromDir(QString path, QString pathForSave)
{
    /*
    Генерирует отчет Latex по алгоритму по файлам *.hdata алгоритма, просматривая все файлы в папке без сохранения отчета в HTML.
    То, чтобы в папке были файлы только одного алгоритма, вы берете на себя.
    В папке сохранения должны быть находиться файлы names.tex, packages.tex, styles.tex из проекта
    https://github.com/Harrix/HarrixLaTeXDocumentTemplate
    Входные параметры:
     path - путь к папке, из которой считаем файлы.
     pathForSave - путь к папке, куда сохраняем Latex файлы.
    Возвращаемое значение:
     Отсутствует.
     */
    HCDOHOT_GeneratedReportAboutAlgorithmFromDir(path, pathForSave, "");
}