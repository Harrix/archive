import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property alias icon: loaderIcon.sourceComponent
    property string fontName: SettingsApp.fontName
    property int fontSize: SettingsApp.fontSize
    property string colorButton: SettingsApp.colorRed
    property string colorButtonHover: SettingsApp.colorRedLight
    property string colorFontButton: SettingsApp.colorFontButton
    property int fontRenderType: SettingsApp.fontRenderType
    property int durationAnimation: SettingsApp.durationAnimation
    property real opacityNotEnabled: SettingsApp.opacityNotEnabled

    id: control

    padding: 8
    leftPadding: 24
    rightPadding: 24

    contentItem: Row {
        id: contentItem
        spacing: 6
        anchors.centerIn: parent

        Loader {
            id: loaderIcon
            width: loaderIcon.status ? text.height : 0
            height: text.height
        }

        Text {
            id: text
            text: control.text
            font.family: fontName
            font.pixelSize: fontSize
            font.weight: Font.Bold
            font.capitalization: Font.AllUppercase
            color: colorFontButton
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            renderType: fontRenderType
        }
    }

    background: Rectangle {
        opacity: enabled ? 1 : opacityNotEnabled
        color: control.down ? colorButtonHover : colorButton
        border.width: 0
        radius: 0

        MouseAreaRipple {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = colorButtonHover
            onExited: parent.color = colorButton
            onClicked: control.clicked()
        }

        Behavior on color {
            ColorAnimation { duration: durationAnimation }
        }
    }
}
