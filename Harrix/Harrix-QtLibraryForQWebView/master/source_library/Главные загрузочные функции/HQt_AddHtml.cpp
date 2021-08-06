void HQt_AddHtml(QString Html)
{
    /*
    Функция добавляет код html к существующему и сохраняет его в temp.html.
    Входные параметры:
     Html - добавляемый текст.
    Возвращаемое значение:
     Отсутствует.
    */
    VHQt_HTML+=Html;
    HQt_SaveFile(VHQt_HTML, VHQt_Path+"temp.html");
}