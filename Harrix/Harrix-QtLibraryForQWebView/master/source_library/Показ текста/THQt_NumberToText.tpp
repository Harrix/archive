template <class T> QString THQt_NumberToText (T VHQt_X)
{
    /*
    Функция выводит число VHQt_X в строку.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHQt_Result;
    VHQt_Result="<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b>";
    return VHQt_Result;
}