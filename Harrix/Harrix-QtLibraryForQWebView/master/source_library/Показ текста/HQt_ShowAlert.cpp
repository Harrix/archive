QString HQt_ShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым предупреждением.
    */
    QString VHQt_Result;

    VHQt_Result="<div style=\"background: #ffdfdf url(images/box-alert.png) no-repeat 16px; border-color: #feabab;color: #c31b00;padding: 15px 20px 15px 55px;-webkit-border-radius: 5px;-moz-border-radius: 5px;border-radius: 5px;border: 1px solid;clear: both;margin: 15px 0;-webkit-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;-moz-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;text-align: justify; width:600px;\">"+String+"</div>\n";

    return VHQt_Result;
}