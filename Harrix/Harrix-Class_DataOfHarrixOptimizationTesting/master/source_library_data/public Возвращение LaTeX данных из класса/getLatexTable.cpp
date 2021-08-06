QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexTable()
{
    /*
     Получение текста переменной LatexTable.
     Здесь собран полный файл первичных данных из считываемого xml файла (без анализа).
     Помните, что это не полноценный Latex код. Его нужно применять внутри файла из макета:
     https://github.com/Harrix/Harrix-Document-Template-LaTeX
     */
    return LatexTable;
}