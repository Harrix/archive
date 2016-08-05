import QtQuick 2.7

pragma Singleton

QtObject {
    //Colors
    readonly property color colorBackground: "#fff"
    readonly property color colorFont: "#5f5f5f"
    readonly property color colorFontButton: "#fff"

    //Fonts
    readonly property string fontName: "Open Sans"
    readonly property string fontNameCode: "PT Mono"
    readonly property int fontSize: 14
    readonly property var fontRenderType: Text.NativeRendering
}
