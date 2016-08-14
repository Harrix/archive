import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

Rectangle {
    property alias drawer: leftPanelLoader.sourceComponent

    id: navigationDrawer
    objectName: "navigationDrawer"

    height: parent.height
    width: Math.max( 0.25*parent.width, 250)
    z: 2
    //padding: 0
    anchors.margins: 0
    anchors.rightMargin: 0
    y:0
    x:0
    MouseArea {

        Rectangle {
            anchors.fill: parent
            color:"blue"
        }

        Loader {
            id: leftPanelLoader
            anchors.fill: parent
            anchors.margins: SettingsApp.marginCommon
        }

        Rectangle {
            x: parent.width - 15
            width: 15
            height: parent.height
            color: "#21be2b"

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: toogleDrawer ()

                drag.target: navigationDrawer
                drag.minimumX: -navigationDrawer.width
                drag.maximumX: 0
                drag.axis: Qt.Horizontal
            }
        }


        anchors.fill: parent
        //hoverEnabled: true
        drag.target: navigationDrawer
        drag.minimumX: -navigationDrawer.width
        drag.maximumX: 0
        drag.axis: Qt.Horizontal
        //propagateComposedEvents:true
        //preventStealing: true
        drag.filterChildren: true
        //drag.active: true
        onPressed:  {
            focus = true
            console.log(Qt.styleHints.startDragDistance)
        }

    }

    onXChanged: {
        //if (x)
    }

    Behavior on x {
        NumberAnimation {
            duration: 500
            easing.type: Easing.OutBack
        }
    }

    function toogleDrawer () {
        if (navigationDrawer.x < 0)
            navigationDrawer.x = 0;
        else
            navigationDrawer.x = -navigationDrawer.width + 15;
    }
}
