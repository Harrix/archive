import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "../HarrixQML"
import "../HarrixQML/internal"

MainWindow {
    title: qsTr("Harrix-QMLComponents - Demo")

    navigationDrawer.drawer: LeftPanel {}

    head.logo.source: "qrc:/images/logo-harrix.svg"

    //head.centerMobileElement: CenterMobileElement { }

    head.colorMobileMode: true

    head.mainMenu.mainMenuModel: MainMenuModel {}

    onClickActiveItemMenu: {
        console.log(name);
        if (name === "Exit") Qt.quit();
    }

    content: Content {}

    Component.onCompleted: {
        head.centerMobileElementItem.textLabel = qsTr("Mind games for the company of people")
        /*if (head.colorMobileMode)
            head.centerMobileElementItem.source = "qrc:/images/logo-harrix-white.svg";
        else
            head.centerMobileElementItem.source = "qrc:/images/logo-harrix.svg";*/
    }
}
