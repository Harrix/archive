import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property alias icon: loaderIcon.sourceComponent
    property string fontName: Settings.fontName
    property int fontSize: Settings.fontSize
    property string colorFontButton: Settings.colorFontButton
    property int fontRenderType: Settings.fontRenderType

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
        opacity: enabled ? 1 : 0.3
        color: control.down ? "#f54d4c" : "#de2b26"
        border.width: 0
        radius: 0

        MouseAreaRipple {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#f54d4c"
            onExited: parent.color = "#de2b26"
            onClicked: {
                control.clicked()
            }
        }

        Behavior on color {
            ColorAnimation { duration: 200 }
        }
    }
}
