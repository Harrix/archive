import QtQuick 2.7
import QtGraphicalEffects 1.0
import ".."

Rectangle {
    id: iconWithMask

    //Properties that it is necessary to set
    property alias source: mask.source
    property color colorIcon: mask.source

    //Common properties which can be changed if necessary
    property int sizeIcons: SettingsHarrixQML.sizeIcons

    width: sizeIcons
    height: sizeIcons
    color: "transparent"
    clip: true

    Rectangle {        
        id: rectangleColor
        anchors.fill: parent
        color: colorIcon
        visible: false
        x: 0
        y: 0
    }

    Image {
        id: mask
        height: sizeIcons
        fillMode: Image.PreserveAspectFit
        visible: false
        x: 0
        y: 0
    }

    OpacityMask {
        anchors.fill: iconWithMask
        source: rectangleColor
        maskSource: mask
    }
}
