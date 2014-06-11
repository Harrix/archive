QString HQt_ShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<p><b>"+TitleX+".</b></p>\n";

    return VMHL_Result;
}