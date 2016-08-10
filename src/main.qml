import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

ApplicationWindow {

    title: qsTr("Harrix-QMLComponents - Demo")

    visibility: "Maximized"

    onWidthChanged: console.log(width)
    Component.onCompleted: console.log(width)

    Drawer {
            id: drawer
            width: 0.66 * window.width
            height: window.height

            Label {
                text: qsTr("1111 page")
                anchors.centerIn: parent
            }
        }

    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: SettingsApp.marginCommon

        Rectangle {
            Layout.fillWidth: true
            Layout.minimumWidth: 300
            Layout.preferredWidth: parent.width/4
            Layout.minimumHeight: parent.height
            Layout.leftMargin: SettingsApp.marginCommon

            LeftPanel {}
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredWidth: 3*parent.width/4
            Layout.preferredHeight: parent.height
            Layout.rightMargin: SettingsApp.marginCommon

            SwipeView {
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
    }
}
