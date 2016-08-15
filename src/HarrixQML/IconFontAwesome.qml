import QtQuick 2.7
import "."

Text {
    property string symbol: FontAwesome.Icon.fa_glass

    property int fontSize: SettingsApp.fontSize
    property int fontRenderType: SettingsApp.fontRenderType
    property string colorFont: SettingsApp.colorFontButton

    font.pointSize: defindeFontSize ()
    renderType: fontRenderType
    color: colorFont
    font.family: "FontAwesome"
    text: symbol

    function defindeFontSize () {
        if (Qt.platform.os === "android")
            return fontSize + 4;
        else
            return fontSize;
    }
}
