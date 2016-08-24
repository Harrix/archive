import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    id: mainWindow
    objectName: "mainWindow"

    //Properties that it is necessary to set
    property alias content: contentLoader.sourceComponent
    property alias head: head
    property alias navigationDrawer: navigationDrawer

    //Properties that it is to set if necessary
    property bool mobileMode: false

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property int spacingCommon: SettingsHarrixQML.spacingCommon
    property int widthTransitionInMobileMode: 640

    //Signals
    signal toogleNavigationDrawer();
    signal sendMobileMode(bool mobileMode);
    signal clickItemMainMenu (string name);

    visibility: "Maximized"
    font.family: fontName
    font.pixelSize: fontSize

    NavigationDrawer {
        id: navigationDrawer
        drawer: drawer
        signalSender: mainWindow
    }

    Column {
        id: mainColumn
        height: parent.height
        width: widthPaneRight()
        y: 0
        z: navigationDrawer.zNavigationDrawer-1
        anchors.margins: 0
        anchors.left: navigationDrawer.right
        spacing: 0

        Head {
            id: head
            signalSender: mainWindow
            z: navigationDrawer.zNavigationDrawer-2
        }

        Rectangle {
            id: contentPanel
            height: parent.height - head.height
            width: parent.width
            y: 0
            z: navigationDrawer.zNavigationDrawer-3
            anchors.margins: 0

            Loader {
                id: contentLoader
                anchors.fill: parent
                anchors.margins: 0
                clip: true
            }
        }
    }

    Fonts {}

    Connections {
        id: listenerSignalsFromMainMenu
        target: head.mainMenuHead

        onClickItemMainMenu: clickItemMainMenu (name)
    }

    onWidthChanged:        checkMobileMode();
    onHeightChanged:       checkMobileMode();
    Component.onCompleted: checkMobileMode();

    function checkMobileMode() {
        var check = ((mainWindow.width <= widthTransitionInMobileMode)
                     ||(mainWindow.width < mainWindow.height));
        mobileMode = check ? true : false;
        sendMobileMode(mobileMode);
    }

    function widthPaneRight() {
        if (mobileMode)
            return mainWindow.width;
        else
            return mainWindow.width - navigationDrawer.width;
    }
}
