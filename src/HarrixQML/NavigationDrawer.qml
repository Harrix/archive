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
    property int zNavigationDrawer: 2

    signal toogleNav()

    id: navigationDrawer
    objectName: "navigationDrawer"

    height: parent.height
    width: widthNavigationDrawer ()
    anchors.margins: 0
    y: 0
    x: 0
    z: zNavigationDrawer
    clip: true

    MouseArea {
        id: mouseAreaDrag
        enabled: false

        /*Rectangle {
            anchors.fill: parent
            color:"blue"
        }*/

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
            //color: "#21be2b"

            MouseArea {
                id: mouseAreaStartDrag
                enabled: false
                anchors.fill: parent
                hoverEnabled: true
                //cursorShape: Qt.PointingHandCursor
                onClicked: toogleNavigationDrawer ()

                drag.target: navigationDrawer
                drag.minimumX: -navigationDrawer.width
                drag.maximumX: 0
                drag.axis: Qt.Horizontal
                onPressed: {
                    console.log ("drag x = ");
                }
            }
        }

        anchors.fill: parent
        drag.target: navigationDrawer
        drag.minimumX: -navigationDrawer.width
        drag.maximumX: 0
        drag.axis: Qt.Horizontal
        drag.filterChildren: true
        onPressed: focus = true
    }



    Behavior on x {
        NumberAnimation {
            duration: SettingsApp.durationAnimation
            easing.type: easingTypeNavigationDrawer
        }
    }

    onXChanged: {
        //if (x)
    }

    function setTypeNavigationDrawer (type) {
        if (type === "fix") {
            showNavigationDrawer ();
            mouseAreaDrag.enabled = false;
            mouseAreaStartDrag.enabled = false;
        }
        if (type === "drawer") {
            hideNavigationDrawer ();
            mouseAreaDrag.enabled = true;
            mouseAreaStartDrag.enabled = true;
        }
    }

    function toogleNavigationDrawer () {
        if (navigationDrawer.x < 0)
            showNavigationDrawer ();
        else
            hideNavigationDrawer ();
    }

    function showNavigationDrawer () {
        navigationDrawer.x = 0;
    }

    function hideNavigationDrawer () {
        navigationDrawer.x = -navigationDrawer.width + startDragDistance;
    }

    function widthNavigationDrawer () {
        if (percentWidthOfParent === "none")
            width = minimumWidth;
        else
            width = Math.max( parseFloat(percentWidthOfParent) * parent.width, minimumWidth);
    }
}
