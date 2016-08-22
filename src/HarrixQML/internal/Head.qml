import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id:head
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

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBackgroundMobile: SettingsHarrixQML.colorRed
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int heightHead: 84
    property int heightHeadScroll: 48
    property int heightHeadMobile: 48
    property int heightLogo: 60
    property int heightLogoScroll: 40
    property int heightIcons: 22
    property int marginIcons: 25

    //Private properties
    QtObject {
        id: privateVar
        property bool mobileModeHead: false
        property bool firstOnSendMobileMode: false
    }

    //Signals
    signal sendWidthForMenu(real w);

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon
    state: "normal"

    Image {
        id: leftIcon
        height: heightIcons
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: marginIcons
        visible: false
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            //onEntered: parent.color = SettingsHarrixQML.colorBlue
            //onExited: parent.color = "#25292c"
            cursorShape: Qt.PointingHandCursor
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
                source: "qrc:/HarrixQML/images/drawer.svg"
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
                source: "qrc:/HarrixQML/images/drawer.svg"
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
                source: "qrc:/HarrixQML/images/drawer.svg"
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
                source: "qrc:/HarrixQML/images/drawer-white.svg"
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
                        state = "mobileColor";
                    else
                        state = "mobile";
                }
                else {
                    state = "normal";
                }
                privateVar.firstOnSendMobileMode = true;
            }
        }
    }

    onWidthChanged: {
        var w = width;
        if (logo.visible)
            w = w - logo.x - logo.width - marginIcons;
        else
            w = w - centerMobileElement.x - centerMobileElement.width - marginIcons;
        sendWidthForMenu(w)
    }
}
