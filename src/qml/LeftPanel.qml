import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "../HarrixQML"

Column {
    id: leftPanel
    objectName: "leftPanel"

    spacing: 10
    anchors.fill: parent
    anchors.margins: marginCommon
    anchors.bottomMargin: 0

    TextField {
        objectName: "field10"
        textPlaceholder: qsTr("123 first 10313")
    }

    TextField {
        objectName: "field101"
        textPlaceholder: qsTr("test")
    }

    Button {
        text: qsTr("Download")
    }

    ListView {
        width: 160
        height: 240

        model: Qt.fontFamilies()

        delegate: ItemDelegate {
            text: modelData
            width: parent.width
            onClicked: console.log("clicked:", modelData)
        }

        ScrollIndicator.vertical: ScrollIndicator {
        }
    }
}
