import QtQuick 2.5

import "HarrixQML"

Column {
    id: column

    property string fontName

    spacing: 5

    Text {
        id: testtext
        text: "Шрифт - "+fontName + " - QtRendering"
        renderType: Text.QtRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Light
    }

    Text {
        text: "Light. Hello World! При реализации алгоритма."
        renderType: Text.QtRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Light
    }

    Text {
        text: "Normal. Hello World! При реализации алгоритма следует."
        renderType: Text.QtRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Normal
    }

    Text {
        text: "Bold. Hello World! При реализации алгоритма следует."
        renderType: Text.QtRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Bold
    }

    //

    Text {
        text: "Шрифт - "+fontName + " - NativeRendering"
        renderType: Text.NativeRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Light
    }

    Text {
        text: "Light. Hello World! При реализации алгоритма."
        renderType: Text.NativeRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Light
    }

    Text {
        text: "Normal. Hello World! При реализации алгоритма следует."
        renderType: Text.NativeRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Normal
    }

    Text {
        text: "Bold. Hello World! При реализации алгоритма следует."
        renderType: Text.NativeRendering
        font.family: fontName
        font.pixelSize: HarrixSettings.fontSize
        font.weight: Font.Bold
    }

    HarrixLine { orientation: Qt.Horizontal; length: column.width; color:HarrixSettings.colorBorder; }
}

