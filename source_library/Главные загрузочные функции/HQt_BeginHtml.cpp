void HQt_BeginHtml(QString Path)
{
    /*
    Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.
    Входные параметры:
     Path - путь к папке, в которой надо будет сохранять html код. В этой папке должен содержаться файл index.html
    Возвращаемое значение:
     Отсутствует.
    */
    VMHL_HTML="";
    VMHL_Path=QDir::toNativeSeparators(Path);
    if (VMHL_Path.at(VMHL_Path.length()-1)!='\\') VMHL_Path+="\\";
    HQt_SaveFile(VMHL_HTML, VMHL_Path+"temp.html");//сохраняем пустую пока переменную в temp.html
}