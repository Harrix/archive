import QtQuick 2.0

import "HarrixQML"

Column {
    spacing: 5

    Image {
        source:"qrc:/images/HarrixQML/images/FullScreenHover.png"
    }

    //Кнопка
    HarrixButton {
        id: button //Имя кнопки

        //Действие мыши
        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            hoverEnabled: true;
            onClicked: _provider.buttonClicked("Worke522d?")
        }
    }

    //Строка ввода первого числа
    Rectangle {
        id: textinputRect1 //Имя строки ввода

        //Размеры строки ввода
        width: 100
        height: 18

        //цвет строки ввода
        color: "#ffffff"

        TextInput {
            id: textinput1
            objectName: "textinput1"
            color: "#0066ff";
            selectionColor: "blue"
            font.pixelSize: 12;
            width: parent.width-4
            anchors.centerIn: parent
            focus: true
            text:"1"
        }
    }

    //Строка ввода второго числа
    Rectangle {
        id: textinputRect2 //Имя строки ввода

        //Размеры строки ввода
        width: 100
        height: 18

        //цвет строки ввода
        color: "#ffffff"

        TextInput {
            id: textinput2
            objectName: "textinput2"
            color: "#0066ff";
            selectionColor: "blue"
            font.pixelSize: HarrixSettings.fontSize;
            width: parent.width-4
            anchors.centerIn: parent
            focus: true
            text:"1"
        }
    }

    //Поле вывода
    Rectangle {
        id: memoRect //Имя поля вывода

        //Размеры поле вывода
        width: 100
        height: 35

        //Цвет поля вывода
        color: "#ffffff"

        TextEdit{
            id: memo
            color: "#0066ff"
            objectName: "memo"
            wrapMode: TextEdit.Wrap
            width:parent.width;
            readOnly:true
        }
    }
}
