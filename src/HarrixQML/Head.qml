import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    id:headerApp
    objectName: "headerApp"

    anchors.fill: parent
    height:84

    Row {
        spacing: 10
        anchors.fill: parent

        Image {
            source: "qrc:/images/logo-harrix.svg"
            height: 60
            fillMode: Image.PreserveAspectFit
            smooth: true
        }

        ButtonBlue{
            text: qsTr("Open Drawer")
            onClicked:  navigationDrawer.toogleNavigationDrawer()
        }

        ButtonBlue{
            text: qsTr("Open Drawer")
            onClicked:  testSignal("send signal from Head")
        }
    }
}
