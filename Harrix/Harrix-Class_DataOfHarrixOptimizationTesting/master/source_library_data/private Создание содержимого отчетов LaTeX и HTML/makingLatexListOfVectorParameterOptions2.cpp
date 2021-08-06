void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexListOfVectorParameterOptions2()
{
    /*
    Создает текст LaTeX для отображения списка номеров вариантов настроек параметров алгоритма оптимизации в виде 2D таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */
    LatexListOfVectorParameterOptions="\\subsection {Список номеров вариантов настроек параметров алгоритма оптимизации}\n\n";
    LatexListOfVectorParameterOptions+="Ниже представлена таблица, в которой представлены номера вариантов  параметров алгоритма оптимизации. Данные номера будут использованы в дальнейшем анализе.";

    QStringList List;
    for (int i=0;i<Data.getNumberOfExperiments();i++)
        List <<QString::number(i+1);
    LatexListOfVectorParameterOptions+=makingLatexTable2D("Номера вариантов параметров "+NameForHead+"",List);
}