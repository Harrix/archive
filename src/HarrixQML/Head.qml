import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    id:head
    objectName: "head"

    //Properties that it is necessary to set
    property alias logo: logo
    property alias centerMobileElement: centerMobileElement.sourceComponent
    property alias signalSender: listenerSignals.target
    property alias mainMenu: mainMenu.model

    //Properties that it is to set if necessary
    property bool colorMobileMode: false

    //Properties, through which you can access the elements
    property alias centerMobileElementItem: centerMobileElement.item

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBackgroundMobile: SettingsHarrixQML.colorRed
    property int heightHead: 84
    property int heightHeadScroll: 48
    property int heightHeadMobile: 48
    property int heightLogo: 60
    property int heightLogoScroll: 40
    property int heightIcons: 22

    //Private properties
    QtObject {
        id: privateVar
        property bool mobileModeHead: true
    }

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon

    Image {
        id: leftIcon
        source: "qrc:/HarrixQML/images/drawer-white.svg"
        height: heightIcons
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20
        visible: false
    }

    Image {
        id: logo
        height: heightLogo
        fillMode: Image.PreserveAspectFit
        anchors.left: head.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Loader {
        id: centerMobileElement
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
    }

    Rectangle {
        anchors.right: parent.right
        height: 40
        width: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 20
        color: "transparent"

        Image {
            id: rightIcon
            source: "qrc:/HarrixQML/images/menu-white.svg"
            height: heightIcons
            fillMode: Image.PreserveAspectFit
            visible: false
        }

        Row {
            spacing: 2
            anchors.right: parent.right

            Repeater {
                id: mainMenu

                Text {
                    text: name
                }
            }
        }
    }

    states: [
        State {
            name: "normal"
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
            }
        },
        State {
            name: "normalScroll"
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
            }
        },
        State {
            name: "mobile"
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
            }
        },
        State {
            name: "mobileColor"
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
            }
        }
    ]

    Connections {
        id: listenerSignals

        onMobileModeChanged: {
            if (mobileMode) {
                privateVar.mobileModeHead = true;
                leftIcon.visible = true;
            }
            else {
                privateVar.mobileModeHead = false;

                leftIcon.visible = false;
            }
        }
    }
}
