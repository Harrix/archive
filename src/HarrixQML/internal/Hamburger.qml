import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id: hamburger

    //Properties that it is necessary to set
    property color colorHamburger: SettingsHarrixQML.colorDarkElement
    property color colorHamburgerHover: SettingsHarrixQML.colorBlue

    //Common properties which can be changed if necessary
    property int sizeHamburger: SettingsHarrixQML.sizeIcons
    property int cursorShapeHamburger: SettingsHarrixQML.cursorHover
    property int durationAnimation: SettingsHarrixQML.durationAnimation

    width: sizeHamburger
    height: sizeHamburger
    color: "transparent"
    state: "menu"

    Rectangle {
        id: topBar
        color: colorHamburger
        height: 2
        antialiasing: true
    }

    Rectangle {
        id: centerBar
        color: colorHamburger
        x: 2
        y: 12
        width: 22
        height: 2
        antialiasing: true
    }

    Rectangle {
        id: bottomBar
        color: colorHamburger

        width: 22
        height: 2
        antialiasing: true
    }

    states: [
        State {
            name: "menu"
            PropertyChanges { target: hamburger; rotation: 0; }
            PropertyChanges {
                target: topBar
                rotation: 0
                width: 22
                x: 2
                y: 6
            }
            PropertyChanges {
                target: bottomBar
                rotation: 0
                width: 22
                x: 2
                y: 18
            }
        },
        State {
            name: "back"
            PropertyChanges { target: hamburger; rotation: 180; }
            PropertyChanges {
                target: topBar
                rotation: 45
                width: 13
                x: 13
                y: 8
            }
            PropertyChanges {
                target: bottomBar
                rotation: -45
                width: 13
                x: 13
                y: 16
            }
        }
    ]

    ParallelAnimation {
        id: colorAnimationHover
        ColorAnimation {
            target: centerBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
        ColorAnimation {
            target: topBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
        ColorAnimation {
            target: bottomBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
    }

    ParallelAnimation {
        id: colorAnimation
        ColorAnimation {
            target: centerBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburger
        }
        ColorAnimation {
            target: topBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburger
        }
        ColorAnimation {
            target: bottomBar
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburger
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: cursorShapeHamburger
        onEntered: colorAnimationHover.running = true
        onExited: colorAnimation.running = true
    }

    transitions: [
        Transition {
            RotationAnimation {
                target: hamburger;
                direction: RotationAnimation.Clockwise;
                duration: durationAnimation;
                easing.type: Easing.InOutQuad
            }
        }
    ]
}
