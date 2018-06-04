import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
  id: hamburger

  //Properties that it is necessary to set
  property color colorHamburger: SettingsHarrixQML.colorDarkElement
  property color colorHamburgerHover: SettingsHarrixQML.colorTeal

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
    y: 12
    height: 2
    antialiasing: true
  }

  Rectangle {
    id: bottomBar
    color: colorHamburger
    height: 2
    antialiasing: true
  }

  states: [
    State {
      name: "menu"
      PropertyChanges {
        target: hamburger
        rotation: 0
      }
      PropertyChanges {
        target: topBar
        rotation: 0
        width: 18
        x: 2
        y: 6
      }
      PropertyChanges {
        target: bottomBar
        rotation: 0
        width: 18
        x: 2
        y: 18
      }
      PropertyChanges {
        target: centerBar
        width: 18
        x: 2
      }
    },
    State {
      name: "back"
      PropertyChanges {
        target: hamburger
        rotation: 180
      }
      PropertyChanges {
        target: topBar
        rotation: 45
        width: 13
        x: 11
        y: 8
      }
      PropertyChanges {
        target: bottomBar
        rotation: -45
        width: 13
        x: 11
        y: 16
      }
      PropertyChanges {
        target: centerBar
        width: 17
        x: 5
      }
    }
  ]

  MouseArea {
    id: mouseAreaHamburger
    anchors.fill: parent
    hoverEnabled: true
    cursorShape: cursorShapeHamburger
    onEntered: colorAnimarionHover.running = true
    onExited: colorAnimarion.running = true
  }

  ParallelAnimation {
    id: colorAnimarionHover
    running: false
    ColorAnimation {
      target: topBar
      properties: "color"
      to: colorHamburgerHover
      duration: durationAnimation
    }
    ColorAnimation {
      target: centerBar
      properties: "color"
      to: colorHamburgerHover
      duration: durationAnimation
    }
    ColorAnimation {
      target: bottomBar
      properties: "color"
      to: colorHamburgerHover
      duration: durationAnimation
    }
  }

  ParallelAnimation {
    id: colorAnimarion
    running: false
    ColorAnimation {
      target: topBar
      properties: "color"
      to: colorHamburger
      duration: durationAnimation
    }
    ColorAnimation {
      target: centerBar
      properties: "color"
      to: colorHamburger
      duration: durationAnimation
    }
    ColorAnimation {
      target: bottomBar
      properties: "color"
      to: colorHamburger
      duration: durationAnimation
    }
  }

  transitions: [
    Transition {
      RotationAnimation {
        target: hamburger
        direction: RotationAnimation.Clockwise
        duration: durationAnimation
        easing.type: Easing.InOutQuad
      }
      NumberAnimation {
        target: topBar
        properties: "x, y, width, rotation"
        duration: durationAnimation
        easing.type: Easing.InOutQuad
      }
      NumberAnimation {
        target: centerBar
        properties: "x, y, width, rotation"
        duration: durationAnimation
        easing.type: Easing.InOutQuad
      }
      NumberAnimation {
        target: bottomBar
        properties: "x, y, width, rotation"
        duration: durationAnimation
        easing.type: Easing.InOutQuad
      }
    }
  ]
}
