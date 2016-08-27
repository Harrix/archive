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
    property int marginHamburger: 2

    width: sizeHamburger
    height: sizeHamburger
    color: "transparent"

    Rectangle {
        id: centerLine
        color: colorHamburger
        anchors.horizontalCenter: hamburger.horizontalCenter
        anchors.verticalCenter: hamburger.verticalCenter
        width: hamburger.width - 2 * marginHamburger
        height: 2
    }

    Rectangle {
        id: topLine
        color: colorHamburger
        anchors.horizontalCenter: hamburger.horizontalCenter
        anchors.bottom: centerLine.top
        anchors.bottomMargin: 4
        width: hamburger.width - 2 * marginHamburger
        height: 2
    }

    Rectangle {
        id: bottomLine
        color: colorHamburger
        anchors.horizontalCenter: hamburger.horizontalCenter
        anchors.top: centerLine.bottom
        anchors.topMargin: 4
        width: hamburger.width - 2 * marginHamburger
        height: 2
    }

    ParallelAnimation {
        id: colorAnimationHover
        ColorAnimation {
            target: centerLine
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
        ColorAnimation {
            target: topLine
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
        ColorAnimation {
            target: bottomLine
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburgerHover
        }
    }

    ParallelAnimation {
        id: colorAnimation
        ColorAnimation {
            target: centerLine
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburger
        }
        ColorAnimation {
            target: topLine
            property: "color"
            running: false
            duration: durationAnimation
            to: colorHamburger
        }
        ColorAnimation {
            target: bottomLine
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
}
