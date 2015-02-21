void HQt_BeginHtml(QString Path)
{
    /*
    Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.
    Входные параметры:
     Path - путь к папке, в которой надо будет сохранять html код. В этой папке должен содержаться файл index.html
    Возвращаемое значение:
     Отсутствует.
    */
    VHQt_HTML="";
    VHQt_Path=QDir::toNativeSeparators(Path);
    if (VHQt_Path.at(VHQt_Path.length()-1)!='\\') VHQt_Path+="\\";
    HQt_SaveFile(VHQt_HTML, VHQt_Path+"temp.html");//сохраняем пустую пока переменную в temp.html
}