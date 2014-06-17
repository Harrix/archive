QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexInfo()
{
    /*
     Получение текста переменной LatexInfo - отображение информации о исследовании с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexInfo + getLatexEnd();
}