import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"
//import "HarrixQML" as Harrix

ApplicationWindow {

    title: qsTr("Harrix-QMLComponents - Demo")

    visibility: "Maximized"

    Row {
        spacing: 10
        anchors.fill: parent

        Column {
            spacing: 10
            anchors.left: parent.left
            width: parent.width/3
            height: parent.height

            TextField {
                id: field10
                objectName: "field10"
                placeholderText: qsTr("Input first number")
                width: 250
            }
        }

        SwipeView {
            id: swipeView
            anchors.right: parent.right
            width: 2*parent.width/3
            height: parent.height
            //currentIndex: tabBar.currentIndex

            PageBasicComponents {

            }


            Page {
                Label {
                    text: qsTr("Second page")
                    anchors.centerIn: parent
                }
            }
        }
    }
}
