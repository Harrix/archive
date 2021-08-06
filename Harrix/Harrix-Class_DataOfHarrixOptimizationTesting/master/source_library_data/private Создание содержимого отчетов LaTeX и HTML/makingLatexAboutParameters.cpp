void HarrixClass_DataOfHarrixOptimizationTesting::makingLatexAboutParameters()
{
    /*
    Создает текст LaTeX для отображения данных о обнаруженных параметрах алгоритма и какие они бывают.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Отсутствует. Значение возвращается в переменную LatexTableEx, которую можно вызвать getLatexAboutParameters.
     */
    LatexAboutParameters+="\\subsection {Параметры алгоритма оптимизации}\n\n";
    if ((Data.getNumberOfParameters()==1)&&(Data.getNameOption(0)=="NULL"))
    {
        LatexAboutParameters+="В данном исследуемом алгоритме оптимизации нет настраиваемых параметров. Поэтому в таблице ниже приведены даные только одного эксперимента.";
    }
    else
    {
        LatexAboutParameters+="Исследуемый алгоритм оптимизации проверялся по эффективности по некоторому конечному множеству возможных настроек алгоритма. ";
        LatexAboutParameters+="Как написано выше, всего возможных параметров алгоритма было "+QString::number(Data.getNumberOfParameters())+" штук. ";
        LatexAboutParameters+="В формуле \\ref{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":Parameters} показано множество проверяемых параметров алгоритма.\n\n";
        LatexAboutParameters+="\\begin{equation}\n";
        LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":Parameters}\n";
        LatexAboutParameters+="Parameters = \\left( \\begin{array}{c} ";
        if (HQt_MaxCountOfQStringList(Data.getNamesOfParameters())>57)
            Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
        else
            Parbox="";
        for (int i=0;i<Data.getNamesOfParameters().count();i++)
        {
            LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(Data.getNameOption(i))+"}} ";
            if (i!=Data.getNamesOfParameters().count()-1) LatexAboutParameters+="\\\\ ";
        }
        LatexAboutParameters+="\\end{array}\\right). ";
        LatexAboutParameters+="\\end{equation}\n\n";
        LatexAboutParameters+="Теперь рассмотрим, какие значения может принимать каждый из параметров.";

        for (int j=0;j<Data.getNumberOfParameters();j++)
        {
            LatexAboutParameters+="\\begin{equation}\n";
            LatexAboutParameters+="\\label{"+Un+":"+HQt_StringToLabelForLaTeX(Data.getNameAlgorithm())+":parameter_"+QString::number(j+1)+"}\n";
            LatexAboutParameters+="Parameters^{"+QString::number(j+1)+"} \\in \\left\\lbrace  \\begin{array}{c} ";
            if (HQt_MaxCountOfQStringList(Data.getListOfParameterOptions(j))>57)
                Parbox="\\parbox{\\dimexpr \\linewidth-3in}";
            else
                Parbox="";
            for (int i=0;i<Data.getListOfParameterOptions(j).count();i++)
            {
                LatexAboutParameters+=Parbox+"{\\centering\\textit{"+HQt_StringForLaTeX(Data.getOptionFromListOfParameterOptions(j,i))+"}} ";
                if (i!=Data.getListOfParameterOptions(j).count()-1) LatexAboutParameters+="\\\\ ";
            }
            LatexAboutParameters+="\\end{array}\\right\\rbrace . ";
            LatexAboutParameters+="\\end{equation}\n\n";
        }
    }
}