import QtQuick 2.7
import "."

Text {
    property string symbol: FontAwesome.Icon.fa_glass
    property string fontSize: Settings.fontSize
    property var fontRenderType: Settings.fontRenderType
    property string colorFont: Settings.colorFontButton

    font.pointSize: fontSize
    renderType: fontRenderType
    color: colorFont
    font.family: "FontAwesome"
    text: symbol
}
