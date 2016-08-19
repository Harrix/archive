import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Label {
    property string symbol: FontAwesome.Icon.fa_glass

    property int fontSize: SettingsApp.fontSizeFontAwesome
    property int fontRenderType: SettingsApp.fontRenderType
    property string colorFont: SettingsApp.colorFontInColorRectangle

    id: iconFontAwesome

    font.pixelSize: fontSize
    renderType: fontRenderType
    color: colorFont
    font.family: "FontAwesome"
    text: symbol
}
