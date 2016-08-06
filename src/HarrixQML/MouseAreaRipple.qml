import QtQuick 2.7
import QtGraphicalEffects 1.0

MouseArea {
    id: mouseArea
    anchors.fill: parent

    QtObject {
        id: d
        property int mouseX: 0
        property int mouseY: 0
        property int radiusEnd: 0
        property int radiusBegin: 0
        property int xEnd: 0
        property int yEnd: 0
    }

    Rectangle {
        id: container
        color: "transparent"
        anchors.fill: parent
        visible: false

        Rectangle {
            id: ripple
            color: "#fff"
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
            NumberAnimation { target: ripple; property: "x"; to: d.xEnd; duration: 300; }
            NumberAnimation { target: ripple; property: "y"; to: d.yEnd; duration: 300; }
            NumberAnimation { target: ripple; property: "width"; from: 0; to: 2*d.radiusEnd; duration: 300; }
            NumberAnimation { target: ripple; property: "height"; from: 0; to: 2*d.radiusEnd; duration: 300; }
            NumberAnimation { target: ripple; property: "radius"; from: 0; to: d.radiusEnd; duration: 300; }
        }

        NumberAnimation { target: ripple; property: "opacity"; to: 0; duration: 100 }
        NumberAnimation { target: ripple; property: "width"; to: 0; duration: 1 }
        NumberAnimation { target: ripple; property: "height"; to: 0; duration: 1 }
    }

    onPressed: {
        d.mouseX = mouseArea.mouseX;
        d.mouseY = mouseArea.mouseY;
        d.radiusEnd = 1.5*maximumRadius (d.mouseX, d.mouseY,
                                         mouseArea.width, mouseArea.height);

        d.radiusBegin = 10;
        d.xEnd = d.mouseX - d.radiusEnd * 0.85090352453;
        d.yEnd = d.mouseY - d.radiusEnd * 0.85090352453;

        ripple.x = d.mouseX - d.radiusBegin * 0.85090352453;
        ripple.y = d.mouseY - d.radiusBegin * 0.85090352453;

        ripple.opacity = 0.3;
        animation.running = true;
    }

    function distanceTwoPoints(x1, y1, x2, y2) {
        var s = Math.sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        return s;
    }

    function maximumRadius(x, y, width, height) {
        var s1 = distanceTwoPoints(x, y, 0, 0);
        var s2 = distanceTwoPoints(x, y, width, 0);
        var s3 = distanceTwoPoints(x, y, 0, height);
        var s4 = distanceTwoPoints(x, y, width, height);
        var maxR = Math.max(s1, s2, s3, s4);
        return maxR;
    }
}
