import QtQuick 2.11
import QtGraphicalEffects 1.0
import ".."

MouseArea {
  id: mouseArea

  //Common properties which can be changed if necessary
  property int durationAnimation: SettingsHarrixQML.durationAnimation
  property int cursorShapeRipple: SettingsHarrixQML.cursorHover
  property real opacityRipple: 0.3
  property color colorRipple: "#fff"
  property int easingTypeRipple: Easing.Linear

  //Private properties
  QtObject {
    id: privateVar
    property int radiusEnd: 0
    property int xEnd: 0
    property int yEnd: 0
  }

  anchors.fill: parent
  cursorShape: cursorShapeRipple

  Rectangle {
    id: container
    color: "transparent"
    anchors.fill: parent
    visible: false

    Rectangle {
      id: ripple
      color: colorRipple
      opacity: 0
    }
  }

  Rectangle {
    id: mask
    anchors.fill: parent
    color: "#fff"
    visible: false
  }

  OpacityMask {
    anchors.fill: parent
    source: container
    maskSource: mask
  }

  SequentialAnimation {
    id: animation
    running: false

    ParallelAnimation {
      NumberAnimation {
        target: ripple
        property: "x"
        to: privateVar.xEnd
        duration: durationAnimation
        easing.type: easingTypeRipple
      }
      NumberAnimation {
        target: ripple
        property: "y"
        to: privateVar.yEnd
        duration: durationAnimation
        easing.type: easingTypeRipple
      }
      NumberAnimation {
        target: ripple
        property: "width"
        from: 0
        to: 2 * privateVar.radiusEnd
        duration: durationAnimation
        easing.type: easingTypeRipple
      }
      NumberAnimation {
        target: ripple
        property: "height"
        from: 0
        to: 2 * privateVar.radiusEnd
        duration: durationAnimation
        easing.type: easingTypeRipple
      }
      NumberAnimation {
        target: ripple
        property: "radius"
        from: 0
        to: privateVar.radiusEnd
        duration: durationAnimation
        easing.type: easingTypeRipple
      }
    }

    NumberAnimation {
      target: ripple
      property: "opacity"
      to: 0
      duration: durationAnimation / 3
    }
  }

  onPressed: rippleEffect()

  function rippleEffect() {
    if (!animation.running) {
      var mouseX = mouseArea.mouseX
      var mouseY = mouseArea.mouseY

      ripple.x = mouseX
      ripple.y = mouseY
      ripple.opacity = opacityRipple

      privateVar.radiusEnd = maximumRadius(mouseX, mouseY, mouseArea.width,
                                           mouseArea.height)

      privateVar.xEnd = mouseX - privateVar.radiusEnd
      privateVar.yEnd = mouseY - privateVar.radiusEnd

      animation.running = true
    }
  }

  function distanceTwoPoints(x1, y1, x2, y2) {
    var s = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
    return s
  }

  function maximumRadius(x, y, width, height) {
    var s1 = distanceTwoPoints(x, y, 0, 0)
    var s2 = distanceTwoPoints(x, y, width, 0)
    var s3 = distanceTwoPoints(x, y, 0, height)
    var s4 = distanceTwoPoints(x, y, width, height)
    var maxR = Math.max(s1, s2, s3, s4)
    return maxR
  }
}
