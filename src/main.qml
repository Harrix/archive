import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

MainWindow {
       property var content: content

    title: qsTr("Harrix-QMLComponents - Demo")

    Component {
           id: redSquare

           LeftPanel{}
       }


    Component {
           id: blueSquare

           Rectangle {
               color: "blue"
               width: 10
               height: 10
           }
       }


    Loader {
        id: content
        anchors.fill: parent
        anchors.margins: SettingsApp.marginCommon
    }


    Component.onCompleted: {
        var platform = Qt.platform.os;
        if (platform === "android") {
            /*var component = Qt.createComponent("AndroidContent.qml");
            if (component.status == Component.Ready)
                component.createObject(content);*/
            redSquare.createObject(content);
        }
        else {
            /*var component2 = Qt.createComponent("LeftPanel.qml");
            if (component2.status == Component.Ready)
                component2.createObject(content);*/
            blueSquare.createObject(content);

        }
    }
}
