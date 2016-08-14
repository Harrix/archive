import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {

    head: Rectangle {
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
        }
    }

    drawer: LeftPanel{}

    content: SwipeView {
        id: swipeViewContent
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        PageBasicComponents {}

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }
}
