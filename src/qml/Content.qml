import QtQuick 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "../HarrixQML"
import "pages"

SwipeView {
  id: contentApp
  objectName: "contentApp"

  anchors.fill: parent

  //currentIndex: tabBar.currentIndex
  PageBasicComponents {
    id: pageBasicComponents
  }

  Page {
    Rectangle {
      anchors.fill: parent
      color: "red"
    }
  }

  onCurrentIndexChanged: {
    if (currentIndex == 1)
      toogleHeightHead(true)

    if (currentIndex == 0) {
      if (pageBasicComponents.flickable.contentY > 0)
        toogleHeightHead(false)
      else
        toogleHeightHead(true)
    }
  }
}
