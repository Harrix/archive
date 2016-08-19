import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias content: contentLoader.sourceComponent
    property alias head: head
    property alias navigationDrawer: navigationDrawer

    property int marginCommon: SettingsApp.marginCommon

    id: mainWindow
    objectName: "mainWindow"

    signal changeSizeWindow()

    visibility: "Maximized"

    NavigationDrawer {
        id: navigationDrawer
        drawer: drawer
        window: mainWindow
    }

    Column {
        id: mainColumn
        height: parent.height
        width: widthPaneRight ()
        y: 0
        z: navigationDrawer.zNavigationDrawer-1
        anchors.margins: 0
        anchors.left: navigationDrawer.right
        spacing: 0

        Head {
            id: head
            window: mainWindow
        }

        Rectangle {
            id: contentPanel
            height: parent.height - head.height
            width: parent.width
            y: 0
            anchors.margins: 0

            Loader {
                id: contentLoader
                anchors.fill: parent
                anchors.margins: 0
                clip: true
            }
        }
    }

    onWidthChanged: changeSizeWindow()
    onHeightChanged: changeSizeWindow()

    function widthPaneRight () {
        if (navigationDrawer.fixNavigationDrawer === true)
            return mainWindow.width - navigationDrawer.width
        else
            return mainWindow.width - navigationDrawer.startDragDistance / 2
    }
}
