import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias drawer: navigationDrawer.drawer
    property alias content: contentLoader.sourceComponent

    property int marginCommon: SettingsApp.marginCommon

    id: mainWindow
    objectName: "mainWindow"

    visibility: "Maximized"
    title: qsTr("Harrix-QMLComponents - Demo")

    Column {
        anchors.fill: parent
        spacing: 0

        Pane {
            id: header
            width: parent.width
            padding: 0
            height: 84
            ButtonBlue{
                text: qsTr("Open Drawer")
                onClicked:  navigationDrawer.toogleNavigationDrawer ()
            }
            z:4
        }


        Pane {
            width: parent.width
            height: parent.height - header.height
            padding: 0

            NavigationDrawer {
                id: navigationDrawer
                drawer: drawer
            }

            Frame {
                id: paneRight
                height: parent.height
                width: parent.width - navigationDrawer.width - navigationDrawer.x
                z: 1
                y:0
                anchors.margins: 0
                anchors.left: navigationDrawer.right
                anchors.rightMargin: marginCommon
                padding: 0

                Rectangle {
                    anchors.fill: parent
                    color:"yellow"
                }

                Loader {
                    id: contentLoader
                    anchors.fill: parent
                    anchors.margins: SettingsApp.marginCommon
                    anchors.leftMargin: 0
                }
            }
        }
    }

    onWidthChanged: console.log(width)


}
