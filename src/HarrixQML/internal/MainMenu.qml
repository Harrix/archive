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
    property int heightIcons: SettingsHarrixQML.sizeIcons
    property color colorFontMenuHover: SettingsHarrixQML.colorBlue
    property color colorFontMenu: SettingsHarrixQML.colorFontDark
    property int cursorShapeMenu: SettingsHarrixQML.cursorHover
    property int topPaddingMenu: 5
    property int bottomPaddingMenu: 5
    property int leftPaddingMenu: 8
    property int rightPaddingMenu: 8

    //Signals
    signal clickItemMainMenu (string name);

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
                text: caption
                fontSize: fontSize
                color: colorFontMenu
                topPadding: topPaddingMenu
                bottomPadding: bottomPaddingMenu
                leftPadding: leftPaddingMenu
                rightPadding: rightPaddingMenu

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = colorFontMenuHover
                    onExited: parent.color = colorFontMenu
                    cursorShape: cursorShapeMenu
                    onClicked: clickItemMainMenu (name)
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
            name: "collapsedWhite"
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

        onSendWidthForMainMenu: {
            var widthMainMenu = rowMainMenu.width;
            if (widthForMenu > widthMainMenu)
                state = "expanded";
            else {
                if (mobileModeHead) {
                    if (colorMobileMode)
                        state = "collapsedWhite";
                    else
                        state = "collapsed";
                }
                else
                    state = "collapsed";
            }
        }
    }
}
