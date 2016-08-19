import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {
    title: qsTr("Harrix-QMLComponents - Demo")

    navigationDrawer.drawer: LeftPanel{}

    head.logo.source: "qrc:/images/logo-harrix.svg"

    head.centerMobileElement: CenterMobileElement {}

    content: Content {}
}
