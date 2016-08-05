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

        Button {
            id: button2
            text: qsTr("Скачать")

            onClicked: qmlSignal("яблок")

            icon:  Text {
                font.pointSize: Settings.fontSize
                color: Settings.colorFontButton
                font.family: "FontAwesome"
                text: "\uf019"
            }
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
    }
}
