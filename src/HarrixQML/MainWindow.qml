import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias leftPanel: leftPanelLoader.sourceComponent
    property alias content: contentLoader.sourceComponent
    property int marginCommon: SettingsApp.marginCommon

    id: mainWindow
    objectName: "mainWindow"

    visibility: "Maximized"
    title: qsTr("Harrix-QMLComponents - Demo")

    header: ToolBar {
        ButtonBlue{
            text: qsTr("Open Drawer")
            onClicked:  {
                if (paneLeft.x < 0)
                    paneLeft.x = 0;
                else
                    paneLeft.x = -paneLeft.width;
            }
        }
    }

    footer: ToolBar {
        ButtonBlue{
            text: qsTr("Footer")
        }
    }

    Pane {
        id: paneLeft
        height: parent.height
        width: Math.max( 0.25*parent.width, 250)
        z: 2
        anchors.leftMargin: marginCommon
        anchors.rightMargin: 0
        anchors.topMargin: 0
        y:0
        x:0

        Rectangle {
            anchors.fill: parent
            color:"blue"
        }

        Loader {
            id: leftPanelLoader
            anchors.fill: parent
        }

        Behavior on x {
            NumberAnimation { duration: SettingsApp.durationAnimation }
        }

    }

    Pane {
        id: paneRight
        height: parent.height
        width: parent.width - paneLeft.width - paneLeft.x
        z: 1
        y:0
        anchors.margins: marginCommon
        anchors.left: paneLeft.right

        Rectangle {
            anchors.fill: parent
            color:"yellow"
        }

        Loader {
            id: contentLoader
            anchors.fill: parent
        }
    }

    onWidthChanged: console.log(width)
}
