import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    property string fontName: SettingsApp.fontName
    property int fontSize: SettingsApp.fontSize
    property string colorTextField: SettingsApp.colorRed
    property string colorTextFieldHover: SettingsApp.colorRedLight
    property string colorFontTextField: SettingsApp.colorFontButton
    property int fontRenderType: SettingsApp.fontRenderType
    property int durationAnimation: SettingsApp.durationAnimation

    selectionColor: SettingsApp.colorRed
    selectedTextColor: "#fff"

    selectByMouse: true
    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.IBeamCursor
        acceptedButtons: Qt.NoButton
    }

    id: control

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
