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

    //Properties, through which you can access the elements
    property alias head: mainMenuHead.parent

    //Common properties which can be changed if necessary
    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property int marginIcons: SettingsHarrixQML.marginIcons
    property int sizeIcons: SettingsHarrixQML.sizeIcons
    property color colorMenu: SettingsHarrixQML.colorDarkElement
    property color colorMenuHover: SettingsHarrixQML.colorDarkElementHover
    property color colorMenuLight: SettingsHarrixQML.colorLightElement
    property color colorMenuLightHover: SettingsHarrixQML.colorLightElementHover
    property color colorBackgroundColumn: SettingsHarrixQML.colorBackground
    property color colorBorder: SettingsHarrixQML.colorBorder
    property int cursorShapeMenu: SettingsHarrixQML.cursorHover
    property int topPaddingMenu: 5
    property int bottomPaddingMenu: 5
    property int topPaddingMenuVertical: 16
    property int bottomPaddingMenuVertical: 12
    property int leftPaddingMenu: 8
    property int rightPaddingMenu: 8

    //Signals
    signal clickItemMainMenu (string name);

    state: "expanded"

    IconWithMask {
        id: rightIcon
        source: "qrc:/HarrixQML/images/menu.svg"
        colorIcon: colorMenu
        visible: false
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: marginIcons
        MouseArea {
            anchors.fill: parent
            cursorShape: cursorShapeMenu
            onClicked: toogleVecticalMainMenu()
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
                color: colorMenu
                topPadding: topPaddingMenu
                bottomPadding: bottomPaddingMenu
                leftPadding: leftPaddingMenu
                rightPadding: rightPaddingMenu


                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.color = colorMenuHover
                    onExited: parent.color = colorMenu
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

    Rectangle {
        id: rectangleColumnMainMenu
        parent: head
        x: 0
        y: head.height
        color: colorBackgroundColumn
        width: head.width
        height: 0

        Behavior on height {
            NumberAnimation {
                duration: durationAnimation
            }
        }

        Flickable {
            focus: true
            width: parent.width
            height: rectangleColumnMainMenu.height
            contentWidth: parent.width
            contentHeight: columnMainMenu.height
            clip: true

            ScrollBar.vertical: ScrollBar { id: vbar; }

            Column {
                id: columnMainMenu
                spacing: 0
                anchors.margins: marginIcons

                Repeater {
                    id: columnMainMenuRepeater

                    model: mainMenu

                    Label {
                        text: caption
                        fontSize: fontSize
                        color: colorMenu
                        topPadding: topPaddingMenuVertical
                        bottomPadding: bottomPaddingMenuVertical
                        leftPadding: leftPaddingMenu
                        rightPadding: rightPaddingMenu
                        width: rectangleColumnMainMenu.width

                        Rectangle {
                            height: 1
                            width: rectangleColumnMainMenu.width
                            y: parent.height
                            color: SettingsHarrixQML.colorBorder
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: parent.color = colorMenuHover
                            onExited: parent.color = colorMenu
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
                colorIcon: colorMenu
                colorIconHover: colorMenuHover
            }
            PropertyChanges { target: rowMainMenu; visible: false; }
        },
        State {
            name: "collapsedWhite"
            PropertyChanges { target: mainMenuHead; width: rowMainMenu.width; }
            PropertyChanges {
                target: rightIcon
                visible: true
                colorIcon: colorMenuLight
                colorIconHover: colorMenuLightHover
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

    function toogleVecticalMainMenu() {
        if (rectangleColumnMainMenu.height === 0)
            rectangleColumnMainMenu.height = Math.min(columnMainMenu.height, 300);
        else
            rectangleColumnMainMenu.height = 0;
    }
}
