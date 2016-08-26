import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

MenuItem {
    id: control

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property string fontName: SettingsHarrixQML.fontName
    property color colorFont: SettingsHarrixQML.colorFont
    property color colorNotEnabled: SettingsHarrixQML.colorNotEnabled
    property int fontSize: SettingsHarrixQML.fontSize
    property int fontRenderType: SettingsHarrixQML.fontRenderType

    contentItem: Text {
        leftPadding: marginCommon
        rightPadding: marginCommon
        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        text: control.text
        color: control.enabled ? colorFont : colorNotEnabled
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    /*background: Rectangle {
        implicitWidth: 200
        implicitHeight: 48
        visible: control.down || control.highlighted
        color: control.down ? control.Material.buttonPressColor : control.Material.listHighlightColor
    }*/

}
