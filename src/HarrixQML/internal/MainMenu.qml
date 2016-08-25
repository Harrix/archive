import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id: mainMenu
    objectName: "mainMenu"

    //Properties that it is necessary to set
    property alias mainMenuModel: mainMenuRepeater.model
    property alias signalSender: listenerSignals.target

    //Properties that it is to set if necessary
    property bool colorMobileMode: false

    //Properties, through which you can access the elements
    property alias head: mainMenu.parent

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
    property int bottomPaddingMenuVertical: 13
    property int leftPaddingMenu: 8
    property int leftPaddingSubmenu: 30
    property int rightPaddingMenu: 8
    property int maximumHeightVerticalMainMenu: 318

    //Signals
    signal clickActiveItemMenu (string name);

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
                    onEntered: {
                        parent.color = colorMenuHover;
                        showSubmenuHorizontalMainMenu(this.parent, name, submenu);
                    }
                    onExited: {
                        parent.color = colorMenu;
                        submenuHorizontalMainMenu.visible = false;
                    }
                    cursorShape: cursorShapeMenu
                    //onClicked: clickItemMenu (name, submenu)
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
        id: submenuHorizontalMainMenu

        property alias text: label.text

        //parent: mainMenu.parent
        color: "red"//colorBackgroundColumn
        width: 100
        height: 100
        visible: false

        Label {
            id: label
            text: "Text"
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

                Component.onCompleted: buildModelVerticalMenu()

                Repeater {
                    id: columnMainMenuRepeater

                    //model: mainMenuModel

                    Label {
                        text: caption
                        fontSize: fontSize
                        color: colorMenu
                        topPadding: topPaddingMenuVertical
                        bottomPadding: bottomPaddingMenuVertical
                        leftPadding: sub ? leftPaddingSubmenu : leftPaddingMenu
                        rightPadding: rightPaddingMenu
                        width: rectangleColumnMainMenu.width

                        Rectangle {
                            height: 1
                            width: rectangleColumnMainMenu.width
                            y: parent.height - 1
                            color: SettingsHarrixQML.colorBorder
                        }

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: parent.color = colorMenuHover
                            onExited: parent.color = colorMenu
                            cursorShape: cursorShapeMenu
                            onClicked: clickActiveItemMenu (name)
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
            PropertyChanges { target: mainMenu; width: rowMainMenu.width; }
            PropertyChanges { target: rightIcon; visible: false; }
            PropertyChanges { target: rowMainMenu; visible: true; }
            PropertyChanges { target: rectangleColumnMainMenu; visible: false; }
        },
        State {
            name: "collapsed"
            PropertyChanges { target: mainMenu; width: rowMainMenu.width; }
            PropertyChanges {
                target: rightIcon
                visible: true
                colorIcon: colorMenu
                colorIconHover: colorMenuHover
            }
            PropertyChanges { target: rowMainMenu; visible: false; }
            PropertyChanges { target: rectangleColumnMainMenu; visible: true; }
        },
        State {
            name: "collapsedWhite"
            PropertyChanges { target: mainMenu; width: rowMainMenu.width; }
            PropertyChanges {
                target: rightIcon
                visible: true
                colorIcon: colorMenuLight
                colorIconHover: colorMenuLightHover
            }
            PropertyChanges { target: rowMainMenu; visible: false; }
            PropertyChanges { target: rectangleColumnMainMenu; visible: true; }
        }
    ]

    Component {
        id: сomponentListModel
        ListModel {
        }
    }

    Connections {
        id: listenerSignals

        onSendWidthForMainMenu: {
            var widthMainMenu = rowMainMenu.width;
            if (widthForMenu > widthMainMenu) {
                if ((colorMobileMode) && (mobileModeHead))
                    state = "collapsedWhite";
                else
                    state = "expanded";
            }
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

    function createListModel(parent) {
        var newModel = сomponentListModel.createObject(parent);
        return newModel;
    }

    function showSubmenuHorizontalMainMenu(label, name, submenu) {
        if (submenu !== undefined) {
        submenuHorizontalMainMenu.x = label.x//mainMenu.x;
        submenuHorizontalMainMenu.y = 0;
        submenuHorizontalMainMenu.visible = true;
        submenuHorizontalMainMenu.text = name;
        }
    }

    function buildModelVerticalMenu() {
        var model = createListModel(mainMenu);

        for (var i = 0; i < mainMenuModel.count; i++) {
            model.append({"caption": mainMenuModel.get(i).caption,
                             "name": mainMenuModel.get(i).name,
                             "sub": false});

            var submenuArray = mainMenuModel.get(i).submenu;
            if (submenuArray !== undefined) {
                for (var j = 0; j < submenuArray.count; j++) {
                    model.append({"caption": submenuArray.get(j).caption,
                                     "name": submenuArray.get(j).name,
                                     "sub": true});
                }
            }
        }

        columnMainMenuRepeater.model = model;
    }

    function toogleVecticalMainMenu() {
        if (rectangleColumnMainMenu.height === 0)
            rectangleColumnMainMenu.height = Math.min(columnMainMenu.height,
                                                      mainWindow.heightWindow - head.height);//TODO
        else
            rectangleColumnMainMenu.height = 0;
    }
}
