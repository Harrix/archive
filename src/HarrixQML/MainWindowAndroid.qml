import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {


    id: mainWindow
    objectName: "mainWindow"

    visibility: "Maximized"

    property var content: content
    property string testlabel: testlabel

    title: qsTr("Harrix-QMLComponents - Demo")

    Component {
        id: redSquare

        Label {
            text: "Text"
            anchors.centerIn: parent
        }
    }


    Component {
        id: blueSquare



        SwipeView {
            id: swipeViewContent

            anchors.fill: parent
            //currentIndex: tabBar.currentIndex

            Page {
                Label {
                    text: "testlabel"
                    anchors.centerIn: parent
                }
            }

            Page {
                Label {
                    text: testlabel
                    anchors.centerIn: parent
                }
            }
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

    onWidthChanged: console.log(width)

}
