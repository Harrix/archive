import QtQuick 2.7
import QtQuick.Controls 2.0
import ".."

Rectangle {
    id: lineDashed

    //Common properties which can be changed if necessary
    property color colorLineDashed: SettingsHarrixQML.colorBorder
    property int widthDash: 2
    property int spacingDash: 2

    width: 50
    height: 2
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
