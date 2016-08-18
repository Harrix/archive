import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias drawer: navigationDrawer.drawer
    //property alias content: contentLoader.sourceComponent
    //property alias head: headLoader.sourceComponent

    property alias navigationDrawer: navigationDrawer
    //property alias headLoader: headLoader

    property int marginCommon: SettingsApp.marginCommon
    property int startDragDistance: SettingsApp.startDragDistance
    property int zHeadPanel: SettingsApp.zHeadPanel
    property int zContentPanel: SettingsApp.zContentPanel
    property int heightHeadPanel: 84

    id: mainWindow
    objectName: "mainWindow"

    signal changeSizeWindow()

    visibility: "Maximized"

    NavigationDrawer {
        id: navigationDrawer
        drawer: drawer
        window: mainWindow
    }



    onWidthChanged: changeSizeWindow()
    onHeightChanged: changeSizeWindow()

    function widthPaneRight () {
        if (navigationDrawer.fixNavigationDrawer === true)
            return mainWindow.width - navigationDrawer.width
        else
            return mainWindow.width - startDragDistance / 2
    }
}
