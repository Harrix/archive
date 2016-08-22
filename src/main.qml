import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {
    title: qsTr("Harrix-QMLComponents - Demo")

    navigationDrawer.drawer: LeftPanel{}

    head.logo.source: "qrc:/images/logo-harrix.svg"

    head.centerMobileElement: CenterMobileElement {id:centerMobileElementApp;}

    head.colorMobileMode: false

    head.mainMenu: ListModel {
        ListElement { name: "Главная";}
        ListElement { name: "Проекты"; }
        ListElement { name: "Harrix.org";}
        ListElement { name: "Контакты";}
    }

    content: Content {}

    Component.onCompleted: {
        if (head.colorMobileMode) {
            head.logo.source = "qrc:/images/logo-harrix-white.svg";
            head.centerMobileElementItem.source = "qrc:/images/logo-harrix-white.svg";
            console.log("head.colorMobileMode = " + head.colorMobileMode);
        }
        else {
            head.logo.source = "qrc:/images/logo-harrix.svg"
            head.centerMobileElementItem.source = "qrc:/images/logo-harrix.svg";
            console.log("head.colorMobileMode = " + head.colorMobileMode);
        }
    }
}
