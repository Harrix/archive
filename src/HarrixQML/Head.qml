import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    property alias logo: logo
    property alias centerMobileElement: centerMobileElement.sourceComponent
    property alias window: connectionsChangeSizeWindow.target

    property int marginCommon: SettingsApp.marginCommon
    property int widthTransitionInMobileMode: SettingsApp.widthTransitionInMobileMode
    property int heightHead: 84
    property int heightLogo: 60
    property int heightIcons: 22

    id:head
    objectName: "head"

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon
    anchors.horizontalCenter: parent.horizontalCenter
    clip: true

    Image {
        id: hamburger
        source: "qrc:/HarrixQML/images/drawer.svg"
        height: heightIcons
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
        visible: false
        enabled: false
    }

    Image {
        id: logo
        height: heightLogo
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Loader {
        id: centerMobileElement
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
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

            Image {
                id: ellipsis
                source: "qrc:/HarrixQML/images/menu.svg"
                height: heightIcons
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    Connections {
        id: connectionsChangeSizeWindow

        onChangeSizeWindow: {
            if ((window.width <= widthTransitionInMobileMode)
                    ||(window.width < window.height)) {
              console.log ('Mobile mode');
            }
        }
    }
}
