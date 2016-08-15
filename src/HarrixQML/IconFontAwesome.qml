import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Label {
    property string symbol: FontAwesome.Icon.fa_glass

    property int fontSize: SettingsApp.fontSize + 5
    property int fontRenderType: SettingsApp.fontRenderType
    property string colorFont: SettingsApp.colorFontButton

    font.pixelSize: fontSize
    renderType: fontRenderType
    color: colorFont
    font.family: "FontAwesome"
    text: symbol
}
