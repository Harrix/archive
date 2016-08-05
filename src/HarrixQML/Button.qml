import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property alias icon: loaderIcon.sourceComponent

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
            font.family: Settings.fontName
            font.pixelSize: Settings.fontSize
            font.weight: Font.Bold
            font.capitalization: Font.AllUppercase
            color: Settings.colorFontButton
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            renderType: Settings.fontRenderType
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
                console.log("111");
                control.clicked()
            }
        }

        Behavior on color {
            ColorAnimation { duration: 200 }
        }

        /*ServiceRipple {
            mouseArea: mousearea
        }*/
    }
}
