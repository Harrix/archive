/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixSettings - настройки компонентов.
*/

pragma Singleton
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.0

QtObject {
    // Глобальные настройки экрана
    readonly property var dir: ["mdpi", "hdpi", "xhdpi", "xxhdpi", "xxxhdpi", "xxxxhdpi"]
    readonly property var ppiScales: [16/2, 16/3, 16/4, 16/6, 16/8, 16/16]
    readonly property int ppi: Screen.pixelDensity * 25.4
    readonly property int ppiRange: {
        if (ppi >= 540) 5
        else if (ppi >= 360) 4
        else if (ppi >= 270) 3
        else if (ppi >= 180) 2
        else if (ppi >= 135) 1
        else 0
    }
    readonly property real dp: 8 / ppiScales[ppiRange]
    readonly property real sp: dp

    //Общие настройки оформления
    readonly property color colorBackground: "#fff"
    readonly property color colorBorder: "#ccc"
    readonly property int marginCommon: 10*dp
    readonly property int widthBorder: 1*dp

    //Настройки шрифтов
    readonly property int fontSize: 12*sp
    readonly property int fontSizeExtraHuge: 32*sp
    readonly property int fontSizeHuge: 25*sp
    readonly property int fontSizeLarge: 20*sp
    readonly property int fontSizeMore: 15*sp
    readonly property int fontSizeSmall: 10*sp
    readonly property color fontColor: "#000"
    readonly property var renderType: Text.NativeRendering//Text.QtRendering Text.NativeRendering
    readonly property string fontName: "Raleway"
    readonly property string fontNameHeader: "Raleway"
    readonly property string fontNameCode: "Consalas"

    //Размеры
    readonly property int sizeExtraHuge: 32*dp
    readonly property int sizeHuge: 25*dp
    readonly property int sizeLarge: 20*dp
    readonly property int sizeDefault: 15*dp
    readonly property int sizeSmall: 12*dp
    readonly property int sizeExtraSmall: 10*dp

    //Пути
    readonly property url pathImages: "qrc:/images/HarrixQML/images/"

    //Параметры по умолчанию у компонентов
    readonly property int heightToolBar: 32*dp
    readonly property int minimumHeightWindow: 50*dp
    readonly property int minimumWidthWindow: 100*dp
    readonly property int defaultHeightWindow: 300*dp
    readonly property int defaultWidthWindow: 200*dp
    readonly property int minimumHeightMainWindow: 50*dp
    readonly property int minimumWidthMainWindow: 100*dp
    readonly property int defaultHeightMainWindow: 300*dp
    readonly property int defaultWidthMainWindow: 200*dp
}
