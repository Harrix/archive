QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexAnalysis()
{
    /*
     Получение текста переменной LatexAnalysis - отображение данных первоначального анализа данных.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexInfo + LatexAboutParameters + LatexListOfVectorParameterOptions + LatexAnalysis + getLatexEnd();
}