import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

Column {
    id: pageBasicComponents
    objectName: "pageBasicComponents"

    spacing: Settings.marginCommon
    anchors.fill: parent

    signal qmlSignal(string msg)

    TextField {
        id: field1
        objectName: "field1"
        placeholderText: qsTr("Input first number")
    }

    TextField {
        id: field2
        objectName: "field2"
        placeholderText: qsTr("Input second number")
    }

    Button {
        id: button
        text: qsTr("Download")
        onClicked: qmlSignal( qsTr("apples") )
    }

    ButtonGreen {
        id: button2
        text: qsTr("Download")
        onClicked: qmlSignal( qsTr("tables") )
        icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
    }

    ButtonBlue {
        id: button22
        text: qsTr("Download")
        onClicked: qmlSignal( qsTr("tomato") )
        icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
    }

    Button {
        id: button3
        text: qsTr("Download")
        enabled: false
        onClicked: qmlSignal( qsTr("images") )
        icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
    }

    Text {
        text: "Answer:"
        font.pixelSize: textArea.font.pixelSize
    }

    TextArea {
        id: textArea
        objectName: "textArea"
        wrapMode: TextArea.Wrap
        readOnly: true
        width: 250
    }

    Image {
        source: "qrc:/images/harrix_photo.png"
        width: 300
        height: 300
        smooth: true

        MouseAreaRipple {
            id: mouseAreaImage
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                console.log("image")
            }
        }
    }
}
