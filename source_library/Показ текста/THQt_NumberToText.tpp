template <class T> QString THQt_NumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result="<b><font class=\"number\">"+QString::number(VMHL_X)+"</font></b>";
    return VMHL_Result;
}