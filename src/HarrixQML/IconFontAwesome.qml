import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Label {
    property string symbol: FontAwesome.Icon.fa_glass

    property int fontSize: SettingsHarrixQML.fontSizeFontAwesome
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property string colorFont: SettingsHarrixQML.colorFontInColorRectangle

    id: iconFontAwesome

    font.pixelSize: fontSize
    renderType: fontRenderType
    color: colorFont
    font.family: "FontAwesome"
    text: symbol
}
