/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixButton - кнопка.
*/

import QtQuick 2.5

import "."

/*ПОЛНОСТЬЮ БУДЕТ ПЕРЕПИСАНО*/

//Кнопка
Rectangle {
    //Размеры кнопки
    width: 100
    height: 30

    //Цвет кнопки
    color: "#0066ff"

    //Текст кнопки
    Text {
        id: buttonLabel
        text: "Сложить"
        color: "#ffffff";
        anchors.centerIn: parent;
        renderType: HarrixSettings.renderType
        font.family: fonts.fontRaleway.name
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Bold
    }
}

