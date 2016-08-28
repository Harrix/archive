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
    property alias mainMenu: mainMenu

    //Properties that it is to set if necessary
    property bool colorMobileMode: false

    //Properties, through which you can access the elements
    property alias centerMobileElementItem: centerMobileElement.item

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBackgroundMobile: SettingsHarrixQML.colorRed
    property color colorRippleNormal: SettingsHarrixQML.colorLightElement
    property color colorRippleInWhite: SettingsHarrixQML.colorRippleInWhite
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int marginIcons: SettingsHarrixQML.marginIcons
    property int sizeIcons: SettingsHarrixQML.sizeIcons
    property int cursorShapeIcon: SettingsHarrixQML.cursorHover
    property int easingTypeHight: Easing.Linear
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
        property bool normalLastWasScroll: false
    }

    //Signals
    signal sendWidthForMainMenu(real widthForMenu, bool colorMobileModeHead, bool mobileModeHead);

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon
    state: "normal"

    Hamburger {
        id: leftIcon
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: marginIcons
        visible: false
    }

    MouseAreaRippleWithoutMask {
        id: leftIconMouseArea
        target: leftIcon
        onClicked: toogleNavigationDrawer()
    }

    Image {
        id: logo
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter

        Behavior on height {
            NumberAnimation {
                duration: durationAnimation
                easing.type: easingTypeHight
            }
        }
    }

    Loader {
        id: centerMobileElement
        sourceComponent: Component {
            Label {
                property string textLabel: mainWindow.title
                text: textLabel
                fontSize: 20
                verticalAlignment: Text.AlignVCenter
                font.weight: Font.Medium
                elide: Text.ElideRight
            }
        }
        anchors.centerIn: parent
        visible: false
    }

    MainMenu {
        id: mainMenu
        signalSender: head
        colorMobileMode: head.colorMobileMode
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    Behavior on height {
        NumberAnimation {
            duration: durationAnimation
            easing.type: easingTypeHight
        }
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
                colorHamburger: SettingsHarrixQML.colorDarkElement
                colorHamburgerHover: SettingsHarrixQML.colorBlue
                state: "menu"
            }
            PropertyChanges {
                target: leftIconMouseArea
                colorRipple: colorRippleInWhite
                visible: false
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
                colorHamburger: SettingsHarrixQML.colorDarkElement
                colorHamburgerHover: SettingsHarrixQML.colorBlue
                state: "menu"
            }
            PropertyChanges {
                target: leftIconMouseArea
                colorRipple:colorRippleInWhite
                visible: false
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
                height: heightLogoScroll
            }
            PropertyChanges {
                target: centerMobileElement
                visible: true
            }
            PropertyChanges {
                target: leftIcon
                visible: true
                colorHamburger: SettingsHarrixQML.colorDarkElement
                colorHamburgerHover: SettingsHarrixQML.colorBlue
                state: "menu"
            }
            PropertyChanges {
                target: leftIconMouseArea
                colorRipple: colorRippleInWhite
                visible: true
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
                height: heightLogoScroll
            }
            PropertyChanges {
                target: centerMobileElement
                visible: true
            }
            PropertyChanges {
                target: leftIcon
                visible: true
                colorHamburger: "white"
                colorHamburgerHover: SettingsHarrixQML.colorLightElementHover
                state: "menu"
            }
            PropertyChanges {
                target: leftIconMouseArea
                colorRipple: colorRippleNormal
                visible: true
            }
        }
    ]

    Connections {
        id: listenerSignals

        onSendMobileMode: {
            if ((!privateVar.firstOnSendMobileMode)
                    || (mobileMode !== privateVar.mobileModeHead)) {
                if (mobileMode) {
                    if (colorMobileMode)
                        head.state = "mobileColor";
                    else
                        head.state = "mobile";
                }
                else {
                    if (privateVar.normalLastWasScroll)
                        head.state = "normalScroll";
                    else
                        head.state = "normal";
                }
                sendWidthForMainMenu(calculateWidthForMainMenu(),
                                     colorMobileMode, privateVar.mobileModeHead);
                privateVar.firstOnSendMobileMode = true;
            }
        }

        onToogleHeightHead: {
            if (!mobileMode) {
                if (normal)
                    head.state = "normal";
                else
                    head.state = "normalScroll";
            }
            else {
                if (!normal)
                    privateVar.normalLastWasScroll = true;
                else
                    privateVar.normalLastWasScroll = false;
            }
        }
    }

    onWidthChanged: {
        sendWidthForMainMenu(calculateWidthForMainMenu(),
                             colorMobileMode, privateVar.mobileModeHead);
    }

    onStateChanged: {
        if (state == "normal")
            privateVar.normalLastWasScroll = false;
        if (state == "normalScroll")
            privateVar.normalLastWasScroll = true;
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
