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

QtObject {
    //Общие настройки оформления
    readonly property color colorBackground: "#fff"
    readonly property color colorBorder: "#ccc"    
    readonly property int marginCommon: 10
    readonly property int widthBorder: 1

    //Настройки шрифтов
    readonly property int fontSize: 12
    readonly property color fontColor: "#000"
    readonly property var renderType: Text.NativeRendering//Text.QtRendering Text.NativeRendering
    readonly property string fontName: "Raleway"
    readonly property string fontNameHeader: "Raleway"
    readonly property string fontNameCode: "Consalas"

    //Размеры
    readonly property int sizeExtraHuge: 32
    readonly property int sizeHuge: 25
    readonly property int sizeLarge: 20
    readonly property int sizeDefault: 15
    readonly property int sizeSmall: 12
    readonly property int sizeExtraSmall: 10

    //Пути
    readonly property url pathImages: "qrc:/images/HarrixQML/images/"

    //Параметры по умолчанию у компонентов
    readonly property int heightToolBar: 32
    readonly property int minimumHeightWindow: 50
    readonly property int minimumWidthWindow: 100
    readonly property int defaultHeightWindow: 300
    readonly property int defaultWidthWindow: 200
    readonly property int minimumHeightMainWindow: 50
    readonly property int minimumWidthMainWindow: 100
    readonly property int defaultHeightMainWindow: 300
    readonly property int defaultWidthMainWindow: 200
}
