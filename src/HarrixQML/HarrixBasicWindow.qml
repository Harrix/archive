/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixBasicWindow - базовое окно без стандартных элементов управления из ОС.
*/

import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "."

ApplicationWindow {    
    id:window

    property alias content: mContentLoader.sourceComponent //Где содержится главное содержимое окна
    property alias contentLoader: mContentLoader //Загрузчик контента
    property alias titleBarMouseArea: mTitleBarMouseArea //MouseArea верхней панели инструментов
    property alias titleBarIcons: mIconLoader.sourceComponent //Панель иконов в верхней парнели инструментов
    property alias fonts: fonts //Шрифты

    readonly property int heightToolBar: HarrixSettings.heightToolBar

    flags: Qt.FramelessWindowHint //Окно без обрамления и границ

    width: HarrixSettings.defaultHeightWindow
    height: HarrixSettings.defaultWidthWindow
    minimumHeight: HarrixSettings.minimumHeightWindow
    minimumWidth: HarrixSettings.minimumWidthWindow

    HarrixBasicFonts { id: fonts } //Загрузка шрифтов

    //Внешний вид обрамления окна и его фон
    style: ApplicationWindowStyle {
        background: Rectangle {
            color:HarrixSettings.colorBackground
            border.width: HarrixSettings.widthBorder
            border.color: HarrixSettings.colorBorder
        }
    }

    //Через данный загрузчик подгружается основной контент окна
    //Делается через content: в экземпляре
    Loader {
        id: mContentLoader
        anchors.fill: parent
        anchors.margins: HarrixSettings.marginCommon
    }

    //верхняя панель приложения
    toolBar: Rectangle {
        id: titleBar;
        width: window.width
        height: HarrixSettings.heightToolBar

        //toolBar стирает границы, заданные в ApplicationWindowStyle
        //Поэтому для данного компонента рисуем три границы (кроме нижней)
        HarrixLine { orientation: Qt.Horizontal; length: titleBar.width; color:HarrixSettings.colorBorder; }
        HarrixLine { orientation: Qt.Vertical; length: titleBar.height; color:HarrixSettings.colorBorder; anchors.right: titleBar.right; }
        HarrixLine { orientation: Qt.Vertical; length: titleBar.height; color:HarrixSettings.colorBorder; anchors.left: titleBar.left; }

        //За панель инструментов мы можем перетаскивать окно
        MouseArea {
            id: mTitleBarMouseArea;
            anchors.fill: titleBar
            property point previousPosition
            onPressed:  previousPosition = Qt.point(mouseX, mouseY);
            onPositionChanged: {
                if (pressedButtons == Qt.LeftButton) {
                    var dx = mouseX - previousPosition.x;
                    var dy = mouseY - previousPosition.y;
                    window.x = window.x + dx;
                    window.y = window.y + dy;
                }
            }
        }

        //Заголовок окна
        Text {
            id: textTitle
            anchors.left: titleBar.left
            anchors.verticalCenter: titleBar.verticalCenter
            anchors.leftMargin: HarrixSettings.marginCommon
            text:window.title
            font.pixelSize: HarrixSettings.fontSize
            color: HarrixSettings.fontColor
            font.family: fonts.fontRaleway.name
            font.weight:Font.DemiBold
            renderType: HarrixSettings.renderType
        }

        //В панель инструментов загружаем иконки
        //Делается через titleBarIcons:
        Loader {
            id:mIconLoader
            anchors.right: titleBar.right
            anchors.rightMargin: HarrixSettings.marginCommon
            anchors.verticalCenter: titleBar.verticalCenter
            focus:true
        }
    }
}
