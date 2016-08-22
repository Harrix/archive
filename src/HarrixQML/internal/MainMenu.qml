import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id: mainMenuHead
    objectName: "mainMenuHead"

    //Properties that it is necessary to set
    property alias mainMenu: mainMenuRepeater.model
    property alias signalSender: listenerSignals.target

    //Properties that it is to set if necessary
    property bool colorMobileMode: false

    //Common properties which can be changed if necessary
    property int marginIcons: 25
    property int heightIcons: 22

    state: "expanded"

    Image {
        id: rightIcon
        height: heightIcons
        fillMode: Image.PreserveAspectFit
        visible: false
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: marginIcons
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            //onEntered: parent.color = SettingsHarrixQML.colorBlue
            //onExited: parent.color = "#25292c"
            cursorShape: Qt.PointingHandCursor
            //onClicked: toogleNavigationDrawer()
        }
    }

    Row {
        id: rowMainMenu
        spacing: 0
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: marginIcons

        Repeater {
            id: mainMenuRepeater

            Label {
                text: name
                font.pixelSize: SettingsHarrixQML.fontSize
                font.family: SettingsHarrixQML.fontName
                color: "#25292c"
                padding: 5
                leftPadding: 8
                rightPadding: 8

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = SettingsHarrixQML.colorBlue
                    onExited: parent.color = "#25292c"
                    cursorShape: Qt.PointingHandCursor
                    //onClicked:
                }

                Behavior on color {
                    ColorAnimation {
                        duration: durationAnimation
                    }
                }
            }
        }
    }

    states: [
        State {
            name: "expanded"
            PropertyChanges {
                target: mainMenuHead
                width: rowMainMenu.width
            }
            PropertyChanges {
                target: rightIcon
                visible: false
            }
            PropertyChanges {
                target: rowMainMenu
                visible: true
            }
        },
        State {
            name: "collapsed"
            PropertyChanges {
                target: mainMenuHead
                width: rowMainMenu.width
            }
            PropertyChanges {
                target: rightIcon
                visible: true
                source: "qrc:/HarrixQML/images/menu.svg"
            }
            PropertyChanges {
                target: rowMainMenu
                visible: false
            }
        }
    ]

    Connections {
        id: listenerSignals
    }
}
