import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"
import "pages"

SwipeView {
    id: contentApp
    objectName: "contentApp"

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
