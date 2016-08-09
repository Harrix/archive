import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property alias icon: loaderIcon.sourceComponent
    property string fontName: Settings.fontName
    property int fontSize: Settings.fontSize
    property string colorButton: Settings.colorRed
    property string colorButtonHover: Settings.colorRedLight
    property string colorFontButton: Settings.colorFontButton
    property int fontRenderType: Settings.fontRenderType
    property int durationAnimation: Settings.durationAnimation
    property real opacityNotEnabled: Settings.opacityNotEnabled

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
