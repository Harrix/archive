import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

Rectangle {
    property alias drawer: contentLoader.sourceComponent

    property int minimumWidth: SettingsApp.widthMinimumNavigationDrawer
    property var percentWidthOfParent: "none"
    property int startDragDistance: SettingsApp.startDragDistance
    property int marginCommon: SettingsApp.marginCommon
    property string colorBackground: SettingsApp.colorBackground
    property int easingTypeNavigationDrawer: SettingsApp.easingTypeNavigationDrawer
    property int zNavigationDrawer: 20
    property string type: "fix"
    property string position: "open"

    id: navigationDrawer
    objectName: "navigationDrawer"

    height: parent.height
    width: widthNavigationDrawer ()
    anchors.margins: 0
    y: 0
    x: 0
    z: zNavigationDrawer
    clip: true

    QtObject {
        id: privateVar
        property int previousX: 0
        property bool startDrag: false
    }

    MouseArea {
        id: mouseAreaDrag
        enabled: false

        Rectangle {
            id: dark
            parent: navigationDrawer.parent
            height: parent.height
            width: parent.width
            y: 0
            x: navigationDrawer.width + navigationDrawer.x
            color: "#000"
            z: 19
            opacity: 0
            /*Behavior on opacity {
                NumberAnimation {
                    duration: SettingsApp.durationAnimation
                    easing.type: Easing.Linear
                }
            }*/
        }

        Loader {
            id: contentLoader
            anchors.fill: parent
            anchors.margins: marginCommon
            clip: true
        }

        Rectangle {
            x: parent.width - 2 * startDragDistance
            width: 2 * startDragDistance
            height: parent.height
            color: "#21be2b"

            MouseArea {
                id: mouseAreaStartDrag
                enabled: false
                anchors.fill: parent
                hoverEnabled: true
                //cursorShape: Qt.PointingHandCursor
                onClicked: toogleNavigationDrawer ()

                drag.target: navigationDrawer
                drag.minimumX: -navigationDrawer.width + startDragDistance
                drag.maximumX: 0
                drag.axis: Qt.Horizontal
                onReleased: releasedDrag(mouseAreaStartDrag)
            }
        }

        anchors.fill: parent
        drag.target: navigationDrawer
        drag.minimumX: -navigationDrawer.width + startDragDistance
        drag.maximumX: 0
        drag.axis: Qt.Horizontal
        drag.filterChildren: true
        onReleased: releasedDrag(mouseAreaDrag)
    }

    Behavior on x {
        NumberAnimation {
            duration: SettingsApp.durationAnimation
            easing.type: easingTypeNavigationDrawer
        }
    }

    function releasedDrag(mouseArea) {
        if (mouseArea.drag.active) {
            console.log("p = " + privateVar.previousX)
            console.log("x = " + navigationDrawer.x)

            if ((navigationDrawer.x > -(1-0.05)*navigationDrawer.width)&&(navigationDrawer.x <= 0)) {
                if (navigationDrawer.x > privateVar.previousX) {
                    showNavigationDrawer();
                    privateVar.startDrag = false;
                }
            }

            if (privateVar.startDrag === true) {
                if ((navigationDrawer.x > -0.05*navigationDrawer.width)&&(navigationDrawer.x <= 0)) {
                    if (navigationDrawer.x < privateVar.previousX) {
                        showNavigationDrawer();
                        privateVar.startDrag = false;
                    }
                }
            }

            if (privateVar.startDrag === true)
                hideNavigationDrawer();

            Qt.inputMethod.hide();
            privateVar.startDrag = false;
        }
    }

    onXChanged: {
        if ((mouseAreaDrag.drag.active)||(mouseAreaStartDrag.drag.active)) {
            if (privateVar.startDrag === false) {
                privateVar.startDrag = true;
                privateVar.previousX = x;
            }
            dark.opacity = lineTwoPoint(x, -navigationDrawer.width + startDragDistance, 0, 0, 0.9);
        }
    }

    onTypeChanged: {
        if (type === "fix") {
            position = "open";
            mouseAreaDrag.enabled = false;
            mouseAreaStartDrag.enabled = false;
            dark.opacity = 0;
        }
        if (type === "drawer") {
            position = "close";
            mouseAreaDrag.enabled = true;
            mouseAreaStartDrag.enabled = true;
            dark.opacity = 0;
        }
    }

    onPositionChanged: {
        if (position === "open")
            showNavigationDrawer ()
        if (position === "close")
            hideNavigationDrawer ()
    }

    function showNavigationDrawer () {
        position = "open";
        navigationDrawer.x = 0;
        if (type === "drawer")
            dark.opacity = 0.9;
        else
            dark.opacity = 0;
    }

    function hideNavigationDrawer () {
        position = "close";
        navigationDrawer.x = -navigationDrawer.width + startDragDistance;
        dark.opacity = 0;
    }

    function toogleNavigationDrawer () {
        if (type === "drawer")
            if (position === "close")
                position = "open";
            else
                position = "close";
    }

    function widthNavigationDrawer () {
        if (percentWidthOfParent === "none")
            width = minimumWidth;
        else
            width = Math.max( parseFloat(percentWidthOfParent) * parent.width, minimumWidth);
    }

    function defineTypeNavigationDrawer (width, height) {
        if ((width <= 640)||(width < height))
            type = "drawer";
        else
            type = "fix";
    }

    function lineTwoPoint(x, x1, y1, x2, y2) {
        var y=0;

        if ((x1 === x2)&&(y1 === y2))
            y = y1;
        else
            if (y1 === y2)
                y = y1;
            else
                if (x1 === x2)
                    if (x === x1)
                        y = y1;
                    else
                        y = 0;
                else
                    y = (x-x1)*(y2-y1)/(x2-x1)+y1;

        return y;
    }
}
