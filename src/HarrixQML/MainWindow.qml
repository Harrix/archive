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
        id: layout
        anchors.fill: parent
        spacing: SettingsApp.marginCommon

        Container {
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            Layout.preferredWidth: parent.width/4
            Layout.minimumHeight: parent.height
            z: 2
            anchors.margins: marginCommon

            Loader {
                id: leftPanelLoader
                anchors.fill: parent
            }
        }

        Container {
            Layout.fillWidth: true
            Layout.preferredWidth: 3*parent.width/4
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
