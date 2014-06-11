void HQt_AddHtml(QString Html)
{
    /*
    Функция добавляет код html к существующему и сохраняет его в temp.html.
    Входные параметры:
     Html - добавляемый текст.
    Возвращаемое значение:
     Отсутствует.
    */
    VMHL_HTML+=Html;
    HQt_SaveFile(VMHL_HTML, VMHL_Path+"temp.html");
}