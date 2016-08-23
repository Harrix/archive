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
    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property int marginIcons: SettingsHarrixQML.marginIcons
    property int heightIcons: SettingsHarrixQML.heightIcons
    property color colorFontMenuHover: SettingsHarrixQML.colorBlue
    property color colorFontMenu: SettingsHarrixQML.colorFont

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
                fontSize: fontSize
                color: colorFontMenu
                padding: 5
                leftPadding: 8
                rightPadding: 8

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = colorFontMenuHover
                    onExited: parent.color = colorFontMenu
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
            PropertyChanges { target: mainMenuHead; width: rowMainMenu.width; }
            PropertyChanges { target: rightIcon; visible: false; }
            PropertyChanges { target: rowMainMenu; visible: true; }
        },
        State {
            name: "collapsed"
            PropertyChanges { target: mainMenuHead; width: rowMainMenu.width; }
            PropertyChanges {
                target: rightIcon
                visible: true
                source: "qrc:/HarrixQML/images/menu.svg"
            }
            PropertyChanges { target: rowMainMenu; visible: false; }
        },
        State {
            name: "collapsedColor"
            PropertyChanges { target: mainMenuHead; width: rowMainMenu.width; }
            PropertyChanges {
                target: rightIcon
                visible: true
                source: "qrc:/HarrixQML/images/menu-white.svg"
            }
            PropertyChanges { target: rowMainMenu; visible: false; }
        }
    ]

    Connections {
        id: listenerSignals

        onSendWidthForMenu: {
            var wM = rowMainMenu.width;
            if (w > wM)
                state = "expanded";
            else
                if (colorMobileMode)
                    state = "collapsedColor";
                else
                    state = "collapsed";
        }
    }
}
