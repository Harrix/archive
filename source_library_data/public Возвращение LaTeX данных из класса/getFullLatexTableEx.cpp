QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTableEx()
{
    /*
     Получение текста переменной LatexTableEx - отображение сырых данных таблицы данных о ошибке Ex с началом и концовкой в Latex файле.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTableEx + getLatexEnd();
}