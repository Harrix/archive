QString HQt_ShowH1 (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<h1>"+String+"</h1>\n";

    return VMHL_Result;
}