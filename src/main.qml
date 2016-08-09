import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"
//import "HarrixQML" as Harrix

ApplicationWindow {

    title: qsTr("Сложение двух чисел")

    visibility: "Maximized"

    signal qmlSignal(string msg)

    Column {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            id: field1
            objectName: "field1"
            placeholderText: "Введите первое число!"
            width: 250
        }

        TextField {
            id: field2
            objectName: "field2"
            placeholderText: "Введите второе число"
            width: 250
        }

        Button {
            id: button
            text: qsTr("Скачать")
            onClicked: qmlSignal("яблок")
        }

        ButtonGreen {
            id: button2
            text: qsTr("Скачать")
            onClicked: qmlSignal("помидор")
            icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
        }

        ButtonBlue {
            id: button22
            text: qsTr("Скачать")
            onClicked: qmlSignal("помидор")
            icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
        }

        Button {
            id: button3
            text: qsTr("Скачать")
            enabled: false
            onClicked: qmlSignal("топинамбуров")
            icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
        }

        Text {
            text: "Ответ:"
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
}
