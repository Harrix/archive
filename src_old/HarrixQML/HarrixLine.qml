/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixLine - линия, может использоваться как разделитель.
*/

import QtQuick 2.5

import "."

Rectangle {
    property int orientation : Qt.Vertical // или Qt.Horizontal
    property int length : 100; //длину лучше задавать в экземпляре
    property int separatorWidth : HarrixSettings.widthBorder //толщина линии

    onOrientationChanged: correction();
    onLengthChanged: correction();
    onSeparatorWidthChanged: correction();
    Component.onCompleted: correction();

    //Растыгиваем и вытыгиваем нашу линию, когда попросят
    function correction(){
        switch(orientation){
        case Qt.Vertical:
            height = length;
            width = separatorWidth;
            break;
        case Qt.Horizontal:
            width = length;
            height = separatorWidth;
            break;
        default:
            height = length;
            width = separatorWidth;
            break;
        }
    }   
}
