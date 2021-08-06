void HarrixClass_DataOfHarrixOptimizationTesting::makingHtmlReport()
{
    /*
    Создает текст Html для отображения отчета о считывании XML файла.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную HtmlReport, которую можно вызвать getHtmlReport.
     */
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о файле");
    HtmlReport+=HQt_ShowSimpleText("<b>Автор документа:</b> "+Data.getAuthor()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Дата создания документа:</b> "+Data.getDate()+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Данные о собранных данных");
    HtmlReport+=HQt_ShowSimpleText("<b>Обозначение алгоритма:</b> "+Data.getNameAlgorithm()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название алгоритма:</b> "+Data.getFullNameAlgorithm()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Название тестовой функции:</b> "+Data.getNameTestFunction()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Полное название тестовой функции:</b> "+Data.getFullNameTestFunction()+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Размерность задачи оптимизации:</b> "+QString::number(Data.getDimensionTestFunction())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество измерений для каждого варианта настроек алгоритма:</b> "+QString::number(Data.getNumberOfMeasuring())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество запусков алгоритма в каждом из экспериментов:</b> "+QString::number(Data.getNumberOfRuns())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Максимальное допустимое число вычислений целевой функции:</b> "+QString::number(Data.getMaxCountOfFitness())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество проверяемых параметров алгоритма оптимизации:</b> "+QString::number(getNumberOfParameters())+".");
    HtmlReport+=HQt_ShowSimpleText("<b>Количество комбинаций вариантов настроек:</b> "+QString::number(Data.getNumberOfExperiments())+".");
    HtmlReport+=HQt_ShowHr();
    HtmlReport+=HQt_ShowH1("Собранные данные");

    double **MOfEx;
    MOfEx=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfEx[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfEx[i][j] = Data.getErrorEx(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfEx,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Ошибки по входным параметрам","Ex");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfEx[i];
    delete [] MOfEx;

    double **MOfEy;
    MOfEy=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfEy[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfEy[i][j] = Data.getErrorEy(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfEy,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Ошибки по значениям целевой функции","Ey");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfEy[i];
    delete [] MOfEy;

    double **MOfR;
    MOfR=new double*[Data.getNumberOfExperiments()];
    for (int i=0;i<Data.getNumberOfExperiments();i++) MOfR[i]=new double[Data.getNumberOfMeasuring()];
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        for (int j=0;j<Data.getNumberOfMeasuring();j++)
            MOfR[i][j] = Data.getErrorR(i,j);
    HtmlReport+=THQt_ShowMatrix(MOfR,Data.getNumberOfExperiments(),Data.getNumberOfMeasuring(),"Надежности","R");
    for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfR[i];
    delete [] MOfR;

    if (!Zero_Number_Of_Parameters)
    {
        HtmlReport+=THQt_ShowVector(Data.getNamesOfParameters(),"Вектора названий параметров алгоритма","NamesOfParameters");
        for (int j=0;j<Data.getNumberOfParameters();j++)
            HtmlReport+=THQt_ShowVector(Data.getListOfParameterOptions(j),Data.getNameOption(j) + "(возможные принимаемые значения)","ParameterOptions");

        double **MOfP;
        MOfP=new double*[Data.getNumberOfExperiments()];
        for (int i=0;i<Data.getNumberOfExperiments();i++) MOfP[i]=new double[Data.getNumberOfParameters()];
        for (int i=0;i<Data.getNumberOfExperiments();i++)
            for (int j=0;j<Data.getNumberOfParameters();j++)
                MOfP[i][j] = Data.getParameter(i,j);
        HtmlReport+=THQt_ShowMatrix(MOfP,Data.getNumberOfExperiments(),Data.getNumberOfParameters(),"Матрица параметров по номерам","MatrixOfParameters");
        for (int i=0;i<Data.getNumberOfExperiments();i++) delete [] MOfP[i];
        delete [] MOfP;
    }
}