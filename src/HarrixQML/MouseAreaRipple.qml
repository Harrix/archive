import QtQuick 2.7
import QtGraphicalEffects 1.0

MouseArea {
    property real rippleOpacity: 0.3
    property int rippleDuration: 300
    property var rippleEasingType: Easing.Linear

    id: mouseArea
    anchors.fill: parent

    QtObject {
        id: d
        property int radiusEnd: 0
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
            NumberAnimation {
                target: ripple
                property: "x"
                to: d.xEnd
                duration: rippleDuration
                easing.type: rippleEasingType
            }
            NumberAnimation {
                target: ripple
                property: "y"
                to: d.yEnd
                duration: rippleDuration
                easing.type: rippleEasingType
            }
            NumberAnimation {
                target: ripple
                property: "width"
                from: 0
                to: 2*d.radiusEnd
                duration: rippleDuration
                easing.type: rippleEasingType
            }
            NumberAnimation {
                target: ripple;
                property: "height"
                from: 0
                to: 2*d.radiusEnd
                duration: rippleDuration
                easing.type: rippleEasingType
            }
            NumberAnimation {
                target: ripple
                property: "radius"
                from: 0
                to: d.radiusEnd
                duration: rippleDuration
                easing.type: rippleEasingType
            }
        }

        NumberAnimation {
            target: ripple
            property: "opacity"
            to: 0
            duration: 100
        }
    }

    onPressed: rippleEffect()

    function rippleEffect() {
        if (!animation.running) {
            var mouseX = mouseArea.mouseX;
            var mouseY = mouseArea.mouseY;

            ripple.x = mouseX;
            ripple.y = mouseY;
            ripple.opacity = rippleOpacity;

            d.radiusEnd = maximumRadius (mouseX, mouseY,
                                         mouseArea.width, mouseArea.height);

            d.xEnd = mouseX - d.radiusEnd
            d.yEnd = mouseY - d.radiusEnd

            animation.running = true;
        }
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
