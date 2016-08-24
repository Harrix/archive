import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id: head
    objectName: "head"

    //Properties that it is necessary to set
    property alias logo: logo
    property alias centerMobileElement: centerMobileElement.sourceComponent
    property alias signalSender: listenerSignals.target
    property alias mainMenu: mainMenuHead.mainMenu

    //Properties that it is to set if necessary
    property bool colorMobileMode: false

    //Properties, through which you can access the elements
    property alias centerMobileElementItem: centerMobileElement.item
    property alias mainMenuHead: mainMenuHead

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBackgroundMobile: SettingsHarrixQML.colorRed
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int marginIcons: SettingsHarrixQML.marginIcons
    property int sizeIcons: SettingsHarrixQML.sizeIcons
    property int cursorShapeIcon: SettingsHarrixQML.cursorHover
    property int heightHead: 84
    property int heightHeadScroll: 48
    property int heightHeadMobile: 56
    property int heightLogo: 60
    property int heightLogoScroll: 40

    //Private properties
    QtObject {
        id: privateVar
        property bool mobileModeHead: false
        property bool firstOnSendMobileMode: false
    }

    //Signals
    signal sendWidthForMainMenu(real widthForMenu, bool colorMobileModeHead, bool mobileModeHead);

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon
    state: "normal"

    IconWithMask {
        id: leftIcon
        source: "qrc:/HarrixQML/images/drawer.svg"
        colorIcon: SettingsHarrixQML.colorFontDark
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: marginIcons
        visible: false
        MouseArea {
            anchors.fill: parent
            cursorShape: cursorShapeIcon
            onClicked: toogleNavigationDrawer()
        }
    }

    Image {
        id: logo
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Loader {
        id: centerMobileElement
        anchors.centerIn: parent
        visible: false
    }

    MainMenu {
        id: mainMenuHead
        signalSender: head
        colorMobileMode: head.colorMobileMode
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    states: [
        State {
            name: "normal"
            PropertyChanges {
                target: privateVar
                mobileModeHead: false
            }
            PropertyChanges {
                target: head
                anchors.margins: marginCommon
                height: heightHead
                color: colorBackground
            }
            PropertyChanges {
                target: logo
                visible: true
                height: heightLogo
            }
            PropertyChanges {
                target: centerMobileElement
                visible: false
            }
            PropertyChanges {
                target: leftIcon
                visible: false
                colorIcon: SettingsHarrixQML.colorFontDark
                colorIconHover: SettingsHarrixQML.colorBlue
            }
        },
        State {
            name: "normalScroll"
            PropertyChanges {
                target: privateVar
                mobileModeHead: false
            }
            PropertyChanges {
                target: head
                anchors.margins: marginCommon
                height: heightHeadScroll
                color: colorBackground
            }
            PropertyChanges {
                target: logo
                visible: true
                height: heightLogoScroll
            }
            PropertyChanges {
                target: centerMobileElement
                visible: false
            }
            PropertyChanges {
                target: leftIcon
                visible: false
                colorIcon: SettingsHarrixQML.colorFontDark
                colorIconHover: SettingsHarrixQML.colorBlue
            }
        },
        State {
            name: "mobile"
            PropertyChanges {
                target: privateVar
                mobileModeHead: true
            }
            PropertyChanges {
                target: head
                anchors.margins: 0
                height: heightHeadMobile
                color: colorBackground
            }
            PropertyChanges {
                target: logo
                visible: false
            }
            PropertyChanges {
                target: centerMobileElement
                visible: true
            }
            PropertyChanges {
                target: leftIcon
                visible: true
                colorIcon: SettingsHarrixQML.colorFontDark
                colorIconHover: SettingsHarrixQML.colorBlue
            }
        },
        State {
            name: "mobileColor"
            PropertyChanges {
                target: privateVar
                mobileModeHead: true
            }
            PropertyChanges {
                target: head
                anchors.margins: 0
                height: heightHeadMobile
                color: colorBackgroundMobile
            }
            PropertyChanges {
                target: logo
                visible: false
            }
            PropertyChanges {
                target: centerMobileElement
                visible: true
            }
            PropertyChanges {
                target: leftIcon
                visible: true
                colorIcon: "white"
                colorIconHover: SettingsHarrixQML.colorFontHoverInColorRectangle
            }
        }
    ]

    Connections {
        id: listenerSignals

        onSendMobileMode: {
            if ((privateVar.firstOnSendMobileMode === false)
                    || (mobileMode !== privateVar.mobileModeHead)) {
                if (mobileMode) {
                    if (colorMobileMode)
                        head.state = "mobileColor";
                    else
                        head.state = "mobile";
                }
                else
                    head.state = "normal";
                sendWidthForMainMenu(calculateWidthForMainMenu(),
                                     colorMobileMode, privateVar.mobileModeHead);
                privateVar.firstOnSendMobileMode = true;
            }
        }
    }

    onWidthChanged: {
        sendWidthForMainMenu(calculateWidthForMainMenu(),
                             colorMobileMode, privateVar.mobileModeHead);
    }

    function calculateWidthForMainMenu() {
        var widthForMenu = head.width;
        if (!privateVar.mobileModeHead)
            widthForMenu -= logo.x + logo.width + 2 * marginIcons;
        else
            widthForMenu -= centerMobileElement.x + centerMobileElement.width + 2 * marginIcons;
        return widthForMenu;
    }
}
