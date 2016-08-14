import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

Column {
    id: leftPanel
    objectName: "leftPanel"

    spacing: 10
    anchors.fill: parent

    TextField {
        id: field10
        objectName: "field10"
        placeholderText: qsTr("123 first 10313")
    }

    TextField {
        id: field101
        objectName: "field101"
        placeholderText: qsTr("test")
    }

    Button {
        text: qsTr("Download")

    }
}
