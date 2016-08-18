import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    id:head
    objectName: "head"

    anchors.horizontalCenter: parent.horizontalCenter
    height: 84
    //width: 1140
    //anchors.fill: parent

    Image {
        source: "qrc:/images/logo-harrix.svg"
        height: 60
        fillMode: Image.PreserveAspectFit
        smooth: true
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        anchors.right: parent.right
        height: menu.height
        width: menu.width
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 50

        Row {
            id: menu
            spacing: 15

            Label {
                text: qsTr("File")
                font.pixelSize: SettingsApp.fontSize
            }

            Label {
                text: qsTr("Edit")
                font.pixelSize: SettingsApp.fontSize
            }

            Label {
                text: qsTr("Options")
                font.pixelSize: SettingsApp.fontSize
            }

            Label {
                text: qsTr("About")
                font.pixelSize: SettingsApp.fontSize
            }
        }
    }
}
