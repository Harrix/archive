QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexAnalysis()
{
    /*
     Получение текста переменной LatexAnalysis - отображение первоначального анализа данных.
     Помните, что это не полноценный Latex код.Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexAboutParameters+LatexListOfVectorParameterOptions+LatexAnalysis;
}