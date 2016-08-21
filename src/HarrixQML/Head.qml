import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    property alias logo: logo
    property alias centerMobileElement: centerMobileElement.sourceComponent
    property alias window: connectionsChangeSizeWindow.target

    property bool colorMobileMode: false

    property int marginCommon: SettingsHarrixQML.marginCommon
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBackgroundMobile: SettingsHarrixQML.colorRed
    property int heightHead: 84
    property int heightLogo: 60
    property int heightIcons: 22

    id:head
    objectName: "head"

    width: parent.width
    height: heightHead
    anchors.margins: marginCommon

    QtObject {
        id: privateVar
        property bool mobileModeHead: true
    }

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

        /*ListView {
            id: listView
            currentIndex: -1
            anchors.fill: parent
            orientation: ListView.Horizontal

            delegate: ItemDelegate {
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    if (listView.currentIndex != index) {
                        listView.currentIndex = index
                        //titleLabel.text = model.title
                        //stackView.replace(model.source)
                    }
                    //drawer.close()
                }
            }

            model: ListModel {
                ListElement { title: "BusyIndicator"; source: "qrc:/pages/BusyIndicatorPage.qml" }
                ListElement { title: "Button"; source: "qrc:/pages/ButtonPage.qml" }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }*/




        Image {
            id: rightIcon
            source: "qrc:/HarrixQML/images/menu-white.svg"
            height: heightIcons
            fillMode: Image.PreserveAspectFit
            visible: false
        }
    }

    Connections {
        id: connectionsChangeSizeWindow

        onMobileModeChanged: {
            if (mobileMode) {
                privateVar.mobileModeHead = true;
                if (colorMobileMode) {
                    color = colorBackgroundMobile;
                }
                else {
                    color = colorBackgroundMobile;
                }

                anchors.margins = 0;
                height = 48;
                logo.visible = false;
                centerMobileElement.visible = true;
                leftIcon.visible = true;
            }
            else {
                privateVar.mobileModeHead = false;
                anchors.margins = marginCommon;
                color = colorBackground;
                height = heightHead;
                logo.visible = true;
                centerMobileElement.visible = false;
                leftIcon.visible = false;
            }
        }
    }
}
