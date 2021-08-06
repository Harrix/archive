QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatexTable()
{
    /*
     Получение текста переменной LatexTable в полном составе с началом и концовкой в Latex файле.
     Здесь собран полный файл первичных данных из считываемого xml файла (без анализа).
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + LatexTable + getLatexEnd();
}