import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

MainWindow {
    id: mainWindow
    objectName: "mainWindow"

    headLoader.source: "HeadAndroid.qml"
    headLoader.anchors.margins: 0
}
