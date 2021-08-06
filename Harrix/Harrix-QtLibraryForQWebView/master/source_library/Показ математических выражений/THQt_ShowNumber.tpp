template <class T> QString THQt_ShowNumber (T VHQt_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p><b>"+TitleX+":</b><br>";

    VHQt_Result+=NameX+"=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VHQt_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p>"+NameX+"=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VHQt_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p>x=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}