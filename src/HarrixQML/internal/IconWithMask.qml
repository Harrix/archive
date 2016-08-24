import QtQuick 2.7
import QtGraphicalEffects 1.0
import ".."

Rectangle {
    id: iconWithMask

    //Properties that it is necessary to set
    property alias source: mask.source
    property color colorIcon: SettingsHarrixQML.colorFontDark
    property color colorIconHover: SettingsHarrixQML.colorBlue

    //Common properties which can be changed if necessary
    property int sizeIcons: SettingsHarrixQML.sizeIcons
    property int cursorShapeIcon: SettingsHarrixQML.cursorHover
    property int durationAnimation: SettingsHarrixQML.durationAnimation

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

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: cursorShapeIcon
        onEntered: rectangleColor.color = colorIconHover
        onExited: rectangleColor.color = colorIcon
    }

    Behavior on color {
        ColorAnimation {
            duration: durationAnimation
        }
    }
}
