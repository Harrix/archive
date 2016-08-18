import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {

    title: qsTr("Harrix-QMLComponents - Demo")

    navigationDrawer.drawer: LeftPanel{}

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
