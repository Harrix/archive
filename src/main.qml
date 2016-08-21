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

    content: Content {}

    Component.onCompleted: {
        if (head.colorMobileMode) {
            head.logo.source = "qrc:/images/logo-harrix-white.svg";
            head.centerMobileElementLoader.item.source = "qrc:/images/logo-harrix-white.svg";
            console.log("head.colorMobileMode = " + head.colorMobileMode);
        }
        else {
            head.logo.source = "qrc:/images/logo-harrix.svg"
            head.centerMobileElementLoader.item.source = "qrc:/images/logo-harrix.svg";
            console.log("head.colorMobileMode = " + head.colorMobileMode);
        }
    }
}
