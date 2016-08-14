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

    header: ToolBar {
        ButtonBlue{
            text: qsTr("Open Drawer")
            onClicked:  navigationDrawer.toogleDrawer ()
        }
        z:4
    }

    footer: ToolBar {
        ButtonBlue{
            text: qsTr("Footer")
        }
        z:3
    }

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

    onWidthChanged: console.log(width)


}
