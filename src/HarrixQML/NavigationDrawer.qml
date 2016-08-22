import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

Rectangle {
    id: navigationDrawer
    objectName: "navigationDrawer"

    //Variables that it is necessary to set
    property alias drawer: contentLoader.sourceComponent
    property alias signalSender: listenerSignals.target

    //Common properties which can be changed if necessary
    property string colorBackground: SettingsHarrixQML.colorBackground
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int widthNavigationDrawer: 320
    property int startDragDistance: 20
    property string colorNavigationDrawerDark: "#000"
    property real opacityDarkNavigationDrawer: 0.5
    property int easingTypeNavigationDrawer: Easing.OutBack
    property int easingDarkNavigationDrawer: Easing.Linear
    property real percentFailureSwipe: 0.05
    property int zNavigationDrawer: 100

    //Private properties
    QtObject {
        id: privateVar
        property int startX: 0
        property bool startDrag: false
        property int minimumX: -navigationDrawer.width
        property bool openNavigationDrawer: true
        property bool mobileModeDrawer: true
        property bool firstOnSendMobileMode: false

        onOpenNavigationDrawerChanged: {
            if (openNavigationDrawer === true)
                showNavigationDrawer();
            if (openNavigationDrawer === false)
                hideNavigationDrawer();
        }
    }

    height: parent.height
    width: widthNavigationDrawer
    anchors.margins: 0
    y: 0
    x: 0
    z: zNavigationDrawer
    color: colorBackground

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
            anchors.margins: 0
            clip: true
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
                onClicked: toogle()

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

    Connections {
        id: listenerSignals

        onSendMobileMode: {
            if ((privateVar.firstOnSendMobileMode === false)
                    || (mobileMode !== privateVar.mobileModeDrawer)) {
                if (mobileMode) {
                    privateVar.mobileModeDrawer = true;
                    privateVar.openNavigationDrawer = false;
                    mouseAreaDrag.enabled = true;
                    mouseAreaStartDrag.enabled = true;
                    mouseAreaDark.enabled = true;
                    animationDarkOff.running = true;
                }
                else {
                    privateVar.mobileModeDrawer = false;
                    privateVar.openNavigationDrawer = true;
                    mouseAreaDrag.enabled = false;
                    mouseAreaStartDrag.enabled = false;
                    mouseAreaDark.enabled = false;
                    animationDarkOff.running = true;
                }
                privateVar.firstOnSendMobileMode = true;
            }
        }

        onToogleNavigationDrawer: toogle()
    }

    function toogle() {
        if (privateVar.mobileModeDrawer)
            if (privateVar.openNavigationDrawer === false)
                privateVar.openNavigationDrawer = true;
            else
                privateVar.openNavigationDrawer = false;
    }


    function showNavigationDrawer() {
        privateVar.openNavigationDrawer = true;
        navigationDrawer.x = 0;
        if (privateVar.mobileModeDrawer)
            animationDarkOn.running = true;
        else
            animationDarkOff.running = true;
        privateVar.startDrag = false;
    }

    function hideNavigationDrawer() {
        privateVar.openNavigationDrawer = false;
        navigationDrawer.x = privateVar.minimumX;
        animationDarkOff.running = true;
        privateVar.startDrag = false;
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
