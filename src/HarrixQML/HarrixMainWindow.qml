/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixMainWindow - главное окно для приложения.
*/

import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1

import "."

HarrixBasicWindow {
    id:window
    objectName: "window"

    width: HarrixSettings.defaultHeightMainWindow
    height: HarrixSettings.defaultWidthMainWindow
    minimumHeight: HarrixSettings.minimumHeightMainWindow
    minimumWidth: HarrixSettings.minimumWidthMainWindow

    visible:true

    //Оно должно отображатся на панели задач и сварачиваться
    flags: Qt.FramelessWindowHint | Qt.WindowSystemMenuHint| Qt.WindowMinimizeButtonHint| Qt.Window

    //При двойном клике на верхнюю панель инструментов
    //окно разворачивается
    titleBarMouseArea.onDoubleClicked: {
        if (window.visibility==Window.FullScreen) {
        showNormal();
        }
        else {
            if (window.visibility==Window.Maximized) {
                showNormal();
            }
            else {
                showMaximized();
            }
        }
    }

    //размещаем иконки свернуть, развернуть, закрыть
    titleBarIcons: RowLayout {
        id: windowButtonSystem

        //Кнопка сворачивания прилолажения
        HarrixIcon {
            id: minimizeButton
            defaultIcon: "Minimize.png";
            hoverIcon: "MinimizeHover.png";
            onClicked : showMinimized();
        }

        //Кнопка разварачивания приложения
        HarrixIcon {
            id: maximizeButton
            defaultIcon: "Restore.png";
            hoverIcon: "RestoreHover.png";
            onClicked : {
                if (window.visibility==Window.Maximized) {
                    showNormal()
                    defaultIcon = "Restore.png"
                    hoverIcon = "RestoreHover.png"

                }
                else {
                    showMaximized()
                    defaultIcon = "Maximize.png"
                    hoverIcon = "MaximizeHover.png"
                }
                iconSource: HarrixSettings.pathImages+defaultIcon
            }
        }

        //Кнопка закрытия приложения
        HarrixIcon {
            id: closeButton
            defaultIcon: "Close.png";
            hoverIcon: "CloseHover.png";
            onClicked : close();
        }
        focus:true
    }
}
