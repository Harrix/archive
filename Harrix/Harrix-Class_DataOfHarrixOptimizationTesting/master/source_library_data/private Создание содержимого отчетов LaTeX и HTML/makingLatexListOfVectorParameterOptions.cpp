void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexListOfVectorParameterOptions()
{
    /*
    Создает текст LaTeX для отображения списка вектора названий вариантов параметров алгоритма оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexListOfParameterOptions.
     */
    LatexListOfVectorParameterOptions="\\subsection {Список вектора названий вариантов параметров алгоритма оптимизации}\n\n";
    LatexListOfVectorParameterOptions+="Ниже представлена таблица, в которой представлен нумерованный список вариантов  параметров алгоритма оптимизации. ";
    LatexListOfVectorParameterOptions+="\\begin{center}\n";
    LatexListOfVectorParameterOptions+="{\\renewcommand{\\arraystretch}{1.5}\n";
    LatexListOfVectorParameterOptions+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{0.9\\linewidth}|}\n";
    LatexListOfVectorParameterOptions+="\\caption{Список вектора названий вариантов параметров "+NameForHead+"}\n";
    LatexListOfVectorParameterOptions+="\\tabularnewline\\hline\n";
    LatexListOfVectorParameterOptions+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма} \\centering \\tabularnewline \\hline \\endhead\n";
    LatexListOfVectorParameterOptions+="\\multicolumn{2}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexListOfVectorParameterOptions+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        //получим номер
        Cell1=QString::number(NumberOfListOfVectorParameterOptions[i]);
        Cell1="\\centering \\footnotesize "+Cell1;

        Cell2="\\footnotesize "+  Data.getListOfVectorParameterOptions(i);

        //получим значения критерий

        LatexListOfVectorParameterOptions+=Cell1+" & "+Cell2+"\\tabularnewline \\hline\n";
    }

    LatexListOfVectorParameterOptions+="\n\\end{longtable}\n";
    LatexListOfVectorParameterOptions+="}\n";
    LatexListOfVectorParameterOptions+="\\end{center}\n\n";
}