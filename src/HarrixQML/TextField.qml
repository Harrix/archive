import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    id: control

    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property string colorTextField: SettingsHarrixQML.colorRed
    property string colorTextFieldHover: SettingsHarrixQML.colorRedLight
    property string colorFontTextField: SettingsHarrixQML.colorFontInColorRectangle
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property int durationAnimation: SettingsHarrixQML.durationAnimation

    selectionColor: SettingsHarrixQML.colorRed
    selectedTextColor: "#fff"

    selectByMouse: true
    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.IBeamCursor
        acceptedButtons: Qt.NoButton
    }

    background: Rectangle {
        y: control.height - height - control.bottomPadding / 2
        implicitWidth: 120
        height: control.activeFocus ? 2 : 1
        color: control.activeFocus ? colorTextFieldHover : colorTextField

        Behavior on color {
            ColorAnimation { duration: durationAnimation }
        }

    }
}
