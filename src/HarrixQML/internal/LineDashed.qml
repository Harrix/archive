import QtQuick 2.11
import QtQuick.Controls 2.0
import ".."

Rectangle {
  id: lineDashed

  //Common properties which can be changed if necessary
  property color colorLineDashed: SettingsHarrixQML.colorBorder
  property int widthDash: 1
  property int spacingDash: 1

  implicitWidth: 50
  implicitHeight: 1
  clip: true
  color: "transparent"

  Row {
    spacing: spacingDash

    Repeater {
      model: lineDashed.width / (widthDash + spacingDash)
      Rectangle {
        width: widthDash
        height: lineDashed.height
        color: colorLineDashed
      }
    }
  }
}
