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

    RowLayout {
        id: layoutApp
        anchors.fill: parent
        spacing: SettingsApp.marginCommon

        Pane {
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            Layout.minimumHeight: parent.height
            Layout.preferredWidth: 2*Math.min(layoutApp.width, layoutApp.height)/3
            z: 2
            anchors.margins: marginCommon

            Loader {
                id: leftPanelLoader
                anchors.fill: parent
            }
        }

        Pane {
            Layout.fillWidth: true
            Layout.preferredWidth: layoutApp.width - 2*Math.min(layoutApp.width, layoutApp.height)/3
            Layout.preferredHeight: parent.height
            z: 1
            anchors.margins: marginCommon

            Loader {
                id: contentLoader
                anchors.fill: parent
            }
        }
    }

    onWidthChanged: console.log(width)
}
