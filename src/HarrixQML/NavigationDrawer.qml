import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

Rectangle {
    property alias drawer: contentLoader.sourceComponent
    property alias window: connectionsChangeSizeWindow.target

    property int marginCommon: SettingsApp.marginCommon
    property string colorBackground: SettingsApp.colorBackground
    property int durationAnimation: SettingsApp.durationAnimation
    property int widthTransitionInMobileMode: SettingsApp.widthTransitionInMobileMode
    property int widthNavigationDrawer: 320
    property int startDragDistance: 20
    property string colorNavigationDrawerDark: "#000"
    property real opacityDarkNavigationDrawer: 0.5
    property int easingTypeNavigationDrawer: Easing.OutBack
    property int easingDarkNavigationDrawer: Easing.Linear
    property real percentFailureSwipe: 0.05
    property int zNavigationDrawer: 100

    property bool openNavigationDrawer: true
    property bool fixNavigationDrawer: true

    id: navigationDrawer
    objectName: "navigationDrawer"

    height: parent.height
    width: widthNavigationDrawer
    anchors.margins: 0
    y: 0
    x: 0
    z: zNavigationDrawer
    color: colorBackground

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
                duration: durationAnimation
                easing.type: easingDarkNavigationDrawer
                running: false
                to: opacityDarkNavigationDrawer
            }

            NumberAnimation on opacity  {
                id: animationDarkOff
                duration: durationAnimation
                easing.type: easingDarkNavigationDrawer
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
                onReleased: {
                    enabled = false;
                    hideNavigationDrawer();
                }
            }

            onOpacityChanged: {
                if (opacity === opacityDarkNavigationDrawer) {
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
            id: startDragVisible
            x: parent.width - startDragDistance
            width: startDragDistance
            height: parent.height
            color: "transparent"
        }

        Rectangle {
            id: startDragInvisible
            x: parent.width - startDragDistance
            width: 2 * startDragDistance
            height: parent.height
            color: "transparent"

            MouseArea {
                id: mouseAreaStartDrag
                enabled: false
                anchors.fill: parent
                hoverEnabled: true
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
            duration: durationAnimation
            easing.type: easingTypeNavigationDrawer
        }
    }

    function releasedDrag(mouseArea) {
        if (mouseArea.drag.active) {
            if (betweenTwoNumbers(navigationDrawer.x,
                                  -(1-percentFailureSwipe)*navigationDrawer.width, 0)) {
                if (navigationDrawer.x > privateVar.startX)
                    showNavigationDrawer();
            }

            if (privateVar.startDrag === true) {
                if (betweenTwoNumbers(navigationDrawer.x,
                                      -percentFailureSwipe*navigationDrawer.width, 0)) {
                    if (navigationDrawer.x < privateVar.startX)
                        showNavigationDrawer();
                }
            }

            if (privateVar.startDrag === true)
                hideNavigationDrawer();

            Qt.inputMethod.hide();
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
                                        0, opacityDarkNavigationDrawer);
        }
    }

    onFixNavigationDrawerChanged: {
        if (fixNavigationDrawer === true) {
            openNavigationDrawer = true;
            mouseAreaDrag.enabled = false;
            mouseAreaStartDrag.enabled = false;
            mouseAreaDark.enabled = false;
            animationDarkOff.running = true;            
        }
        else {
            openNavigationDrawer = false;
            mouseAreaDrag.enabled = true;
            mouseAreaStartDrag.enabled = true;
            mouseAreaDark.enabled = true;
            animationDarkOff.running = true;
        }
    }

    onOpenNavigationDrawerChanged: {
        if (openNavigationDrawer === true)
            showNavigationDrawer ();
        if (openNavigationDrawer === false)
            hideNavigationDrawer ();
    }

    Connections {
        id: connectionsChangeSizeWindow

        onChangeSizeWindow: {
            if ((window.width <= widthTransitionInMobileMode)
                    ||(window.width < window.height))
                fixNavigationDrawer = false;
            else
                fixNavigationDrawer = true;
        }
    }

    function showNavigationDrawer () {
        openNavigationDrawer = true;
        navigationDrawer.x = 0;
        if (fixNavigationDrawer === false)
            animationDarkOn.running = true;
        else
            animationDarkOff.running = true;
        privateVar.startDrag = false;
    }

    function hideNavigationDrawer () {
        openNavigationDrawer = false;
        navigationDrawer.x = privateVar.minimumX;
        animationDarkOff.running = true;
        privateVar.startDrag = false;
    }

    function toogleNavigationDrawer () {
        if (fixNavigationDrawer === false)
            if (openNavigationDrawer === false)
                openNavigationDrawer = true;
            else
                openNavigationDrawer = false;
    }

    function lineTwoPoint(x, x1, y1, x2, y2) {
        var y = 0;
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

    function betweenTwoNumbers(x, a, b) {
        var result = false;
        if (a <= b) {
            if ((x >= a)&&(x <= b))
                result = true;
        }
        else {
            if ((x >= b)&&(x <= a))
                result = true;
        }
        return result;
    }
}
