import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias drawer: navigationDrawer.drawer
    property alias content: contentLoader.sourceComponent
    property alias head: headLoader.sourceComponent

    property alias navigationDrawer: navigationDrawer
    property int marginCommon: SettingsApp.marginCommon

    id: mainWindow
    objectName: "mainWindow"

    visibility: "Maximized"
    title: qsTr("Harrix-QMLComponents - Demo")

    Column {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: headerPanel
            width: parent.width
            height: 84
            z: 30

            Loader {
                id: headLoader
                anchors.fill: parent
                anchors.margins: marginCommon
                clip: true
            }
        }

        Rectangle {
            id: mainRow
            width: parent.width
            height: parent.height - headerPanel.height

            NavigationDrawer {
                id: navigationDrawer
                drawer: drawer
            }

            Rectangle {
                id: paneRight
                height: parent.height
                width: widthPaneRight ()
                z: 10
                y: 0
                anchors.margins: 0
                anchors.left: navigationDrawer.right
                anchors.rightMargin: marginCommon

                Rectangle {
                    anchors.fill: parent
                    color:"yellow"
                }

                Loader {
                    id: contentLoader
                    anchors.fill: parent
                    anchors.margins: marginCommon
                    anchors.leftMargin: 0
                    clip: true
                }
            }
        }
    }

    onWidthChanged: navigationDrawer.defineTypeNavigationDrawerSelf ()

    onHeightChanged: navigationDrawer.defineTypeNavigationDrawerSelf ()

    function widthPaneRight () {
        if (navigationDrawer.type == "fix")
          return mainRow.width - navigationDrawer.width
        if (navigationDrawer.type == "drawer")
            return mainRow.width - SettingsApp.startDragDistance
    }
}
