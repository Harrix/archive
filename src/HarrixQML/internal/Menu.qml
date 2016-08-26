import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Menu {
    id: menu

    //Common properties which can be changed if necessary
    property color colorBackground: SettingsHarrixQML.colorBackground
    property int durationAnimation: SettingsHarrixQML.durationAnimation

    enter: Transition {
        NumberAnimation {
            property: "scale"
            from: 0.9
            to: 1.0
            easing.type: Easing.OutQuint
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

    exit: Transition {
        NumberAnimation {
            property: "scale"
            from: 1.0
            to: 0.9
            easing.type: Easing.OutQuint
            duration: durationAnimation
        }
        NumberAnimation {
            property: "opacity"
            from: 1.0
            to: 0.0
            easing.type: Easing.OutCubic
            duration: durationAnimation
        }
    }

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 48
        color: colorBackground
    }
}
