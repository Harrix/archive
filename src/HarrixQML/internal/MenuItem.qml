import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

MenuItem {
    id: menuItem

    //Common properties which can be changed if necessary
    property int marginCommon: SettingsHarrixQML.marginCommon
    property string fontName: SettingsHarrixQML.fontName
    property color colorMenu: SettingsHarrixQML.colorDarkElement
    property color colorMenuHover: SettingsHarrixQML.colorDarkElementHover
    property color colorNotEnabled: SettingsHarrixQML.colorNotEnabled
    property int fontSize: SettingsHarrixQML.fontSize
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property color colorRippleInWhite: SettingsHarrixQML.colorRippleInWhite

    contentItem: Text {
        anchors.fill: parent
        leftPadding: marginCommon
        rightPadding: marginCommon
        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        text: menuItem.text
        color: defineColorTextMenu()
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter

        MouseAreaRipple {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            colorRipple: colorRippleInWhite
            //onEntered: parent.color = colorMenuHover
            //onExited: parent.color = colorMenu
            onClicked: menuItem.clicked()
        }

        Behavior on color {
            ColorAnimation {
                duration: durationAnimation
            }
        }
    }

    background: Rectangle {
        id: backgroundMenuItem
        color: "transparent"
        implicitHeight: 30
    }

    function defineColorTextMenu() {
        if (!menuItem.enabled)
            return colorNotEnabled;
        if (mouseArea.containsMouse)
            return colorMenuHover;
        return colorMenu;
    }

}
