void HarrixClass_OnlyDataOfHarrixOptimizationTesting::addListOfVectorParameterOptions(QString Option)
{
    /*
    Добавление строки параметров эксперимента из списка вектора названий вариантов параметров алгоритма оптимизации - это сборник строк из MatrixOfNameParameters, где объединены столбцы.
    Входные параметры:
     Option - добавляемая строка.
    Возвращаемое значение:
     Отсутствует.
     */
    ListOfVectorParameterOptions<<Option;
}