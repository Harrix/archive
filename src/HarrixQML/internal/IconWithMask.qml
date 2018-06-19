import QtQuick 2.11
import QtGraphicalEffects 1.0
import ".."

Rectangle {
  id: iconWithMask

  //Properties that it is necessary to set
  property alias source: mask.source
  property color colorIcon: SettingsHarrixQML.colorDarkElement
  property color colorIconHover: SettingsHarrixQML.colorTeal

  //Common properties which can be changed if necessary
  property int sizeIcons: SettingsHarrixQML.sizeIcons
  property int cursorShapeIcon: SettingsHarrixQML.cursorHover
  property int durationAnimation: SettingsHarrixQML.durationAnimation

  width: sizeIcons
  height: sizeIcons
  color: "transparent"
  clip: true

  Rectangle {
    id: rectangleColor
    anchors.fill: parent
    color: colorIcon
    visible: false
    x: 0
    y: 0

    ColorAnimation on color {
      id: colorAnimation
      running: false
      duration: durationAnimation
    }
  }

  Image {
    id: mask
    height: sizeIcons
    fillMode: Image.PreserveAspectFit
    visible: false
    x: 0
    y: 0
  }

  OpacityMask {
    anchors.fill: iconWithMask
    source: rectangleColor
    maskSource: mask
  }

  MouseArea {
    anchors.fill: parent
    hoverEnabled: true
    cursorShape: cursorShapeIcon
    onEntered: {
      colorAnimation.to = colorIconHover
      colorAnimation.running = true
    }
    onExited: {
      colorAnimation.to = colorIcon
      colorAnimation.running = true
    }
  }

  onColorIconChanged: rectangleColor.color = colorIcon
}
