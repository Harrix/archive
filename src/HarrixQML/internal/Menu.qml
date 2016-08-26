import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Menu {
    id: menu

    //Common properties which can be changed if necessary
    property color colorBackground: SettingsHarrixQML.colorBackground
    property color colorBorder: SettingsHarrixQML.colorBorder
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int easingTypeScale: Easing.OutQuint
    property int easingTypeOpacity: Easing.OutCubic
    property int implicitWidthMenu: 200
    property int implicitHeightMenu: 20
    property int borderWidth: 1

    enter: Transition {
        NumberAnimation {
            property: "scale"
            from: 0.9
            to: 1.0
            easing.type: easingTypeScale
            duration: durationAnimation
        }
        NumberAnimation {
            property: "opacity"
            from: 0.0
            to: 1.0
            easing.type: Easing.OutCubic
            duration: durationAnimation
        }
    }

    background: Rectangle {
        implicitWidth: implicitWidthMenu
        implicitHeight: implicitHeightMenu
        color: colorBackground
        border.width: borderWidth
        border.color: colorBorder
    }
}
