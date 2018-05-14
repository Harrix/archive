/*
If the setting can be used somewhere else, then it prescribes in this file.
If the setting is used qml only one file, the file it is prescribed.
*/

import QtQuick 2.7

pragma Singleton

QtObject {
    //Constants properties

    //Colors
    readonly property color colorBackground: "#fff"
    readonly property color colorFont: "#5f5f5f"
    readonly property color colorDarkElement: "#25292c"
    readonly property color colorDarkElementHover: colorBlue
    readonly property color colorLightElement: "#fff"
    readonly property color colorLightElementHover: "#eee"
    readonly property color colorNotEnabled: "#d0d0d0"
    readonly property color colorBorder: "#dbdbdb"
    readonly property color colorBackgroundMenu: "#f5f5f5"
    readonly property color colorRippleInWhite: "#cecece"
    readonly property color colorFontPlaceholder: "#939393"

    //Common colors
    readonly property color colorRed: "#de2b26"
    readonly property color colorRedLight: "#f54d4c"
    readonly property color colorRedDark: "#8d130f"
    readonly property color colorBlue: "#19a5a5"
    readonly property color colorBlueLight: "#71c2c2"
    readonly property color colorGreen: "#4abf60"
    readonly property color colorGreenLight: "#77cb87"

    //Fonts
    readonly property string fontName: "Roboto"
    readonly property string fontNameCode: "Roboto Mono"
    readonly property int fontSize: 14
    readonly property int fontSizeText: fontSize + 2
    readonly property int fontSizeFontAwesome: fontSize + 5
    readonly property int fontRenderType: Text.QtRendering//Text.NativeRendering
    readonly property real fontLineHeight: 1.1

    //Indents
    readonly property int marginCommon: 10
    readonly property int spacingCommon: 12
    readonly property int marginIcons: 18

    //Sizes
    readonly property int sizeIcons: 26

    //Durations
    readonly property int durationAnimation: 300

    //Cursors
    readonly property int cursorHover: Qt.PointingHandCursor
}
