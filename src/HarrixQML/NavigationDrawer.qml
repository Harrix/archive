import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

Rectangle {
    property alias drawer: contentLoader.sourceComponent

    property int widthNavigationDrawer: SettingsApp.widthNavigationDrawer
    property int startDragDistance: SettingsApp.startDragDistance
    property int marginCommon: SettingsApp.marginCommon
    property string colorBackground: SettingsApp.colorBackground
    property string colorNavigationDrawerDark: SettingsApp.colorNavigationDrawerDark
    property real opacityNavigationDrawerDark: SettingsApp.opacityNavigationDrawerDark
    property int easingTypeNavigationDrawer: SettingsApp.easingTypeNavigationDrawer
    property int zNavigationDrawer: 20
    property string type: "fix"
    property string position: "open"

    id: navigationDrawer
    objectName: "navigationDrawer"

    height: parent.height
    width: widthNavigationDrawer
    anchors.margins: 0
    y: 0
    x: 0
    z: zNavigationDrawer

    QtObject {
        id: privateVar
        property int startX: 0
        property bool startDrag: false
        property int minimumX: -navigationDrawer.width + startDragDistance / 2
    }

    MouseArea {
        id: mouseAreaDrag
        enabled: false        
        anchors.fill: parent
        drag.target: navigationDrawer
        drag.minimumX: privateVar.minimumX
        drag.maximumX: 0
        drag.axis: Qt.Horizontal
        drag.filterChildren: true

        onReleased: releasedDrag(mouseAreaDrag)

        Rectangle {
            id: dark
            parent: navigationDrawer.parent
            height: parent.height
            width: parent.width * 1.5
            x: navigationDrawer.width + navigationDrawer.x
            y: 0
            color: colorNavigationDrawerDark
            z: zNavigationDrawer - 1
            opacity: 0

            NumberAnimation on opacity  {
                id: animationDarkOn
                duration: SettingsApp.durationAnimation
                easing.type: Easing.Linear
                running: false
                to: opacityNavigationDrawerDark
            }

            NumberAnimation on opacity  {
                id: animationDarkOff
                duration: SettingsApp.durationAnimation
                easing.type: Easing.Linear
                running: false
                to: 0
            }

            MouseArea {
                id: mouseAreaDark
                enabled: false
                visible: false
                anchors.fill: parent
                onClicked: {
                    enabled = false;
                    hideNavigationDrawer();
                }
            }

            onOpacityChanged: {
                if (opacity === opacityNavigationDrawerDark) {
                    mouseAreaDark.enabled = true;
                    mouseAreaDark.visible = true;
                }
            }

        }

        Loader {
            id: contentLoader
            anchors.fill: parent
            anchors.margins: marginCommon
            clip: true
        }

        Rectangle {
            x: parent.width - startDragDistance
            width: startDragDistance
            height: parent.height
            color: "transparent"
        }

        Rectangle {
            x: parent.width - startDragDistance
            width: 2 * startDragDistance
            height: parent.height
            color: "transparent"

            MouseArea {
                id: mouseAreaStartDrag
                enabled: false
                anchors.fill: parent
                hoverEnabled: true
                //cursorShape: Qt.PointingHandCursor
                onClicked: toogleNavigationDrawer ()

                drag.target: navigationDrawer
                drag.minimumX: privateVar.minimumX
                drag.maximumX: 0
                drag.axis: Qt.Horizontal
                onReleased: releasedDrag(mouseAreaStartDrag)
            }
        }

    }

    Behavior on x {
        NumberAnimation {
            duration: SettingsApp.durationAnimation
            easing.type: easingTypeNavigationDrawer
        }
    }

    function releasedDrag(mouseArea) {
        if (mouseArea.drag.active) {

            if ((navigationDrawer.x > -(1-0.05)*navigationDrawer.width)&&(navigationDrawer.x <= 0)) {
                if (navigationDrawer.x > privateVar.startX) {
                    showNavigationDrawer();
                    privateVar.startDrag = false;
                }
            }

            if (privateVar.startDrag === true) {
                if ((navigationDrawer.x > -0.05*navigationDrawer.width)&&(navigationDrawer.x <= 0)) {
                    if (navigationDrawer.x < privateVar.startX) {
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
                privateVar.startX = x;
            }
            dark.opacity = lineTwoPoint(x,
                                        privateVar.minimumX, 0,
                                        0, opacityNavigationDrawerDark);
        }
    }

    onTypeChanged: {
        if (type === "fix") {
            position = "open";
            mouseAreaDrag.enabled = false;
            mouseAreaStartDrag.enabled = false;
            animationDarkOff.running = true;
        }
        if (type === "drawer") {
            position = "close";
            mouseAreaDrag.enabled = true;
            mouseAreaStartDrag.enabled = true;
            animationDarkOff.running = true;
        }
    }

    onPositionChanged: {
        if (position === "open")
            showNavigationDrawer ();
        if (position === "close")
            hideNavigationDrawer ();
    }

    function showNavigationDrawer () {
        position = "open";
        navigationDrawer.x = 0;
        if (type === "drawer")
            animationDarkOn.running = true;
        else
            animationDarkOff.running = true;

    }

    function hideNavigationDrawer () {
        position = "close";
        navigationDrawer.x = privateVar.minimumX;
        animationDarkOff.running = true;
    }

    function toogleNavigationDrawer () {
        if (type === "drawer")
            if (position === "close")
                position = "open";
            else
                position = "close";
    }

    function defineTypeNavigationDrawer (width, height) {
        if ((width <= 640)||(width < height))
            type = "drawer";
        else
            type = "fix";
    }

    function defineTypeNavigationDrawerSelf () {
        if ((mainWindow.width <= 640)||(mainWindow.width < mainWindow.height))
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
