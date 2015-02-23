QString HarrixClass_DataOfHarrixOptimizationTesting::getLatexBegin()
{
    /*
     Внутренняя функция. Возвращает начало для полноценного Latex файла.
     */
    QString VHML_Result;
    VHML_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VHML_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VHML_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VHML_Result+="\\usepgfplotslibrary{external}\n";
    VHML_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VHML_Result+="\\begin{document}\n\n";
    VHML_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VHML_Result;
}