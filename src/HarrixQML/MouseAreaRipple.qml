import QtQuick 2.7
import QtGraphicalEffects 1.0

MouseArea {
    id: mouseArea
    anchors.fill: parent

    Rectangle {
        id: container
        color: "transparent"
        anchors.fill: parent
        visible: false

        Rectangle {
            id: ripple
            color: "yellow"
            opacity: 0
        }
    }

    Rectangle {
        id: mask
        anchors.fill: parent
        color: "#fff"
        visible: false
    }

    OpacityMask {
        anchors.fill: parent
        source: container
        maskSource: mask
    }

    SequentialAnimation {
        id: animation
        running: false

        ParallelAnimation {
            NumberAnimation { target: ripple; property: "width"; from: 0; to: 100; duration: 300; }
            NumberAnimation { target: ripple; property: "height"; from: 0; to: 100; duration: 300; }
            NumberAnimation { target: ripple; property: "radius"; from: 0; to: 50; duration: 300; }
        }

        NumberAnimation { target: ripple; property: "opacity"; to: 0; duration: 100 }
        NumberAnimation { target: ripple; property: "width"; to: 0; duration: 1 }
        NumberAnimation { target: ripple; property: "height"; to: 0; duration: 1 }
    }

    onPressed: {
        ripple.x = mouseArea.mouseX;
        ripple.y = mouseArea.mouseY;
        ripple.opacity = 0.3;
        animation.running = true;
    }
}
