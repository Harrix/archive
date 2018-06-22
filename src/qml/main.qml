import QtQuick 2.11
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "../HarrixQML"
import "../HarrixQML/internal"

MainWindow {
  title: qsTr("Harrix-QML - Demo")

  navigationDrawer.drawer: LeftPanel {
  }

  head.logo.source: "qrc:/images/logo-harrix.svg"

  //head.titleMobileElement: TitleMobileElement {}
  head.colorMobileMode: true

  head.mainMenu.mainMenuModel: MainMenuModel {
  }

  onClickActiveItemMenu: {
    console.log(name)
    if (name === "Exit")
      Qt.quit()
  }

  content: Content {
  }

  Component.onCompleted: {
    head.titleMobileElementItem.textLabel = qsTr(
          "Mind games for the company of people")
    /*if (head.colorMobileMode)
            head.titleMobileElementItem.source = "qrc:/images/logo-harrix-white.svg";
        else
            head.titleMobileElementItem.source = "qrc:/images/logo-harrix.svg";*/
  }
}
