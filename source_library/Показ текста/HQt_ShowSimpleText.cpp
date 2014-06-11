QString HQt_ShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишества. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<p>"+String+"</p>\n";

    return VMHL_Result;
}