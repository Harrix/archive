import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQml 2.2
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
    //property alias mainWindowApp: mainMenu.parent.parent
    //property alias mainWindow: mainMenu.parent.mainWindow

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
    property color colorRippleInWhite: SettingsHarrixQML.colorRippleInWhite
    property int cursorShapeMenu: SettingsHarrixQML.cursorHover
    property int easingTypeVerticalMenu: Easing.OutBack
    property int topPaddingMenu: 5
    property int bottomPaddingMenu: 5
    property int topPaddingMenuVertical: 16
    property int bottomPaddingMenuVertical: 13
    property int leftPaddingMenu: 16
    property int rightPaddingMenu: 16
    property int leftPaddingVerticalMenu: marginIcons
    property int leftPaddingVerticalSubmenu: marginIcons + 20
    property int fontSizeAngle: 10
    property int yAngle: 10

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
                color: mouseAreaLabel.containsMouse ? colorMenuHover : colorMenu
                topPadding: topPaddingMenu
                bottomPadding: bottomPaddingMenu
                leftPadding: leftPaddingMenu
                rightPadding: rightPaddingMenu

                MouseArea {
                    id: mouseAreaLabel
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: cursorShapeMenu
                    //onEntered: showSubmenuHorizontalMainMenu(this.parent, name, submenu)
                    onClicked: {
                        clickActiveItemMenu(name);
                        showSubmenuHorizontalMainMenu(this.parent, name, submenu)
                    }
                }

                IconFontAwesome {
                    id: angle
                    symbol: isThereSubmenuHorizontalMainMenu(submenu)
                    colorFont: mouseAreaLabel.containsMouse ? colorMenuHover : colorMenu
                    fontSize: fontSizeAngle
                    y: yAngle
                    anchors.right: parent.right

                    Behavior on color {
                        ColorAnimation {
                            duration: durationAnimation
                        }
                    }

                    Component.onCompleted: {
                        if (symbol === "") {
                            width = 0;
                            parent.rightPadding -= 10;
                            console.log ("0")
                        }
                    }
                }

                Behavior on color {
                    ColorAnimation {
                        duration: durationAnimation
                    }
                }
            }
        }
    }

    Menu {
        id: submenuHorizontalMainMenu
        property alias model: instantiatorSubmenuHorizontalMainMenu.model
        property string name: ""

        Instantiator {
            id: instantiatorSubmenuHorizontalMainMenu
            model: ListModel {
                ListElement {
                    name: "Text";
                    caption: qsTr("Text");
                }
            }
            onObjectAdded: submenuHorizontalMainMenu.insertItem( index, object )
            onObjectRemoved: submenuHorizontalMainMenu.removeItem( object )
            delegate: MenuItem {
                text: caption
                onTriggered: {
                    clickActiveItemMenu(name);
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
                easing.type: easingTypeVerticalMenu
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

                    Label {
                        text: caption
                        fontSize: fontSize
                        color: mouseAreaLabelColumn.containsMouse ? colorMenuHover : colorMenu
                        topPadding: topPaddingMenuVertical
                        bottomPadding: bottomPaddingMenuVertical
                        leftPadding: sub ? leftPaddingVerticalSubmenu : leftPaddingVerticalMenu
                        rightPadding: rightPaddingMenu
                        width: rectangleColumnMainMenu.width

                        Rectangle {
                            height: 1
                            width: rectangleColumnMainMenu.width
                            y: parent.height - 1
                            color: SettingsHarrixQML.colorBorder
                        }

                        MouseAreaRipple {
                            id: mouseAreaLabelColumn
                            colorRipple: colorRippleInWhite
                            anchors.fill: parent
                            hoverEnabled: true
                            cursorShape: cursorShapeMenu
                            onClicked: clickActiveItemMenu(name)
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

    onStateChanged: {
        submenuHorizontalMainMenu.close();
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

    function isThereSubmenuHorizontalMainMenu(submenu) {
        if (submenu !== undefined)
            return FontAwesome.fa_angle_down;
        else
            return "";
    }

    function showSubmenuHorizontalMainMenu(label, name, submenu) {
        if (submenu !== undefined) {
            submenuHorizontalMainMenu.x = label.x - marginCommon
            submenuHorizontalMainMenu.y = marginCommon;

            submenuHorizontalMainMenu.model.destroy();
            var model = createListModel(mainMenu);
            for (var i = 0; i < mainMenuModel.count; i++) {
                if (mainMenuModel.get(i).name === name) {
                    var submenuArray = mainMenuModel.get(i).submenu;
                    if (submenuArray !== undefined) {
                        for (var j = 0; j < submenuArray.count; j++) {
                            model.append({"caption": submenuArray.get(j).caption,
                                             "name": submenuArray.get(j).name});
                        }
                    }

                }
            }
            submenuHorizontalMainMenu.model = model;
            submenuHorizontalMainMenu.name = name;

            submenuHorizontalMainMenu.open();
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
        if (rectangleColumnMainMenu.height > 0)
            rectangleColumnMainMenu.height = 0;
        else {
            rectangleColumnMainMenu.height = Math.min(columnMainMenu.height,
                                                      mainWindow.height - head.height);//TODO
        }
    }
}
