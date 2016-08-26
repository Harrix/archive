import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

MenuItem {
    id: control

    //Common properties which can be changed if necessary
    property string fontName: SettingsHarrixQML.fontName
    property color colorFont: SettingsHarrixQML.colorFont
    property int fontSize: SettingsHarrixQML.fontSize
    property int fontRenderType: SettingsHarrixQML.fontRenderType

    contentItem: Text {
        leftPadding: control.checkable && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.checkable && control.mirrored ? control.indicator.width + control.spacing : 0

        //wrapMode: Text.Wrap
        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        //color: colorFont

        text: control.text
        //font: control.font
        color: control.enabled ? "#000" : "red"
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

}
