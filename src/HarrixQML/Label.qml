import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Label {
    id: label

    //Common properties which can be changed if necessary
    property string fontName: SettingsHarrixQML.fontName
    property color colorFont: SettingsHarrixQML.colorFont
    property int fontSize: SettingsHarrixQML.fontSizeText
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property real fontLineHeight: SettingsHarrixQML.fontLineHeight

    wrapMode: Text.Wrap
    renderType: fontRenderType
    font.pixelSize: fontSize
    font.family: fontName
    color: colorFont
    lineHeight: fontLineHeight
    horizontalAlignment: Text.AlignJustify
}
