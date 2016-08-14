import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {
    drawer: LeftPanel{}

    content: PageBasicComponents {}
        /*SwipeView {
        id: swipeViewContent

        anchors.fill: parent
        //anchors.margins: 10
        //currentIndex: tabBar.currentIndex

        PageBasicComponents {}

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }*/
}
