import QtQuick 2.7
import QtGraphicalEffects 1.0
import ".."

Item {
    id: iconWithSVGMask

    //Properties that it is necessary to set
    property alias source: mask.source
    property color colorIcon: mask.source

    //Common properties which can be changed if necessary
    property int sizeIcons: SettingsHarrixQML.sizeIcons

    width: sizeIcons
    height: sizeIcons

    Rectangle {
        id: rectangleColor
        anchors.fill: parent
        color: colorIcon
        visible: false
    }

    Image {
        id: mask
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    OpacityMask {
        anchors.fill: iconWithSVGMask
        source: rectangleColor
        maskSource: mask
    }
}
