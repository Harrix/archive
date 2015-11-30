/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixIcon - иконка.
*/

import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "."

Button {
    id: icon
    property int size: HarrixSettings.sizeDefault // размер кнопки
    property string defaultIcon // ссылка на картинку для обычного вида кнопки
    property string hoverIcon // ссылка на картинку для вида кнопки при наведении

    //Кнопка будет квадратной
    implicitHeight: size
    implicitWidth: size

    //Первоначально иконка берется из картинки по умолчанию
    iconSource: HarrixSettings.pathImages+defaultIcon

    //Стиль кнопки
    style: ButtonStyle{
        background: Rectangle {
            color: "transparent"
        }
    }

    //при наведении на иконку меняем картинку
    MouseArea{
        anchors.fill: icon
        hoverEnabled: true
        onClicked: icon.clicked();
        onEntered: iconSource = HarrixSettings.pathImages+hoverIcon;
        onExited: iconSource = HarrixSettings.pathImages+defaultIcon;
    }

    onDefaultIconChanged: {
        iconSource = HarrixSettings.pathImages+defaultIcon;
    }
}
