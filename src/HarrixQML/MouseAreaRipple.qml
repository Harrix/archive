import QtQuick 2.7

MouseArea {
    id: mouseArea
    anchors.fill: parent

    Rectangle {
        id: rip
        anchors.fill: parent
        color: "yellow"
        opacity: 0.3
    }

    onClicked:  {
        rip.opacity = 0;
        console.log("222");
    }
}
