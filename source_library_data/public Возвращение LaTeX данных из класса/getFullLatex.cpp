QString HarrixClass_DataOfHarrixOptimizationTesting::getFullLatex()
{
    /*
     Получение текста переменной Latex в полном составе с началом и концовкой в Latex файле.
     Здесь собран полный файл анализа данных из считываемого xml файла.
     Это полноценный Latex код. Его нужно применять с файлами из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return getLatexBegin() + Latex + getLatexEnd();
}