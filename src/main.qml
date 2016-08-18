import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {

    title: qsTr("Harrix-QMLComponents - Demo")

    navigationDrawer.drawer: LeftPanel{}

    head.logo.source: "qrc:/images/logo-harrix.svg"

    head.centerMobileElement: Image {
        source: "qrc:/images/logo-harrix.svg"
        id: logoMobile
        height: 40
        fillMode: Image.PreserveAspectFit
    }

    content: SwipeView {
        id: swipeViewContent
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        PageBasicComponents {}

        Page {
            Rectangle {
                anchors.fill: parent
                color: "red"
            }
        }
    }
}
