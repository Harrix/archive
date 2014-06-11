template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="<p><b>"+TitleX+":</b><br>";

    VMHL_Result+=NameX+"=<b><font class=\"number\">"+QString::number(VMHL_X)+"</font></b></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VMHL_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="<p>"+NameX+"=<b><font class=\"number\">"+QString::number(VMHL_X)+"</font></b></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VMHL_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="<p>x=<b><font class=\"number\">"+QString::number(VMHL_X)+"</font></b></p>\n";

    return VMHL_Result;
}