void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexTableEx()
{
    /*
    Создает текст LaTeX для отображения сырых данных ошибки по входным параметрам в виде полной таблицы.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexTableEx.
     */
    //////////////////Сырые данные по Ex ///////////
    LatexTableEx+="\\subsection {Ошибка по входным параметрам $E_x$}\n\n";
    LatexTableEx+="Одним из критериев, по которому происходит сравнение алгоритмов оптимизации является ошибка по входным параметрам $E_x$. ";
    LatexTableEx+="В результате проделанных экспериментов были получены следующие данные, представленные ниже в таблице. ";
    LatexTableEx+="\\href{https://github.com/Harrix/HarrixTestFunctions}{https://github.com/Harrix/HarrixTestFunctions}.\n";
    LatexTableEx+="\\begin{center}\n";
    LatexTableEx+="{\\renewcommand{\\arraystretch}{1.5}\n";
    //LatexTableEx+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":TableEx}\n";
    LatexTableEx+="\\footnotesize\\begin{longtable}[H]{|m{0.03\\linewidth}|m{2.1in}|m{0.2\\linewidth}|m{0.17\\linewidth}|m{0.17\\linewidth}|}\n";
    LatexTableEx+="\\caption{Значения ошибки по выходным параметрам $E_x$ "+NameForHead+"}\n";
    LatexTableEx+="\\tabularnewline\\hline\n";
    LatexTableEx+="\\centering \\textbf{№} & \\centering \\textbf{Настройки алгоритма}    & \\centering \\textbf{Значения ошибки $E_x$} & \\centering \\textbf{Выборочное среднее} & \\centering \\textbf{Выборочная дисперсия}  \\centering \\tabularnewline \\hline \\endhead\n";
    LatexTableEx+="\\multicolumn{5}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    LatexTableEx+="\\endlastfoot\n";

    for (int i=0;i<Data.getNumberOfExperiments();i++)
    {
        Cell1.clear();
        Cell2.clear();
        Cell3.clear();
        Cell4.clear();
        Cell5.clear();
        //получим номер
        Cell1=QString::number(i+1);
        Cell1="\\centering "+Cell1;

        //получим значения параметров алгоритма
        Cell2="\\specialcelltwoin{";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            if (Data.getNameParameter(i,j)=="NULL")
                Cell2+="Отсутствует \\\\ ";
            else
                if (!HQt_IsNumeric(Data.getNameParameter(i,j)))
                    if (Data.getNameParameter(i,j).length()>=5)
                        Cell2+=Data.getNameParameter(i,j) +" \\\\ ";
                    else
                        Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
                else
                    Cell2+=Data.getNameOption(j) + " = " + Data.getNameParameter(i,j) +" \\\\ ";
        }

        Cell2+="}";
        Cell2="\\centering "+Cell2;

        //получим значения критерий
        Cell3="\\specialcell{";

        for (int j=0;j<Data.getNumberOfMeasuring();j++)
        {
            Cell3+=QString::number(Data.getErrorEx(i,j))+" \\\\ ";
        }

        Cell3+="}";

        Cell3="\\centering "+Cell3;

        //получим средние значения критерия
        Cell4=QString::number(Data.getMeanEx(i));

        Cell4="\\centering "+Cell4;

        //получим значения дисперсии
        Cell5=QString::number(Data.getVarianceOfEx(i));

        Cell5="\\centering "+Cell5;

        LatexTableEx+=Cell1+" & "+Cell2+" & "+Cell3+" & "+Cell4+" & "+Cell5+"\\tabularnewline \\hline\n";
    }

    LatexTableEx+="\n\\end{longtable}\n";
    LatexTableEx+="}\n";
    LatexTableEx+="\\end{center}\n\n";
}