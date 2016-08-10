import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property var content: content

    id: mainWindow
    objectName: "mainWindow"

    visibility: "Maximized"

    Loader {
        id: content
        anchors.fill: parent
        anchors.margins: SettingsApp.marginCommon
    }

    onWidthChanged: console.log(width)

}
