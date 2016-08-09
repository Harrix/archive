import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    property string fontName: Settings.fontName
    property int fontSize: Settings.fontSize
    property string colorTextField: Settings.colorRed
    property string colorTextFieldHover: Settings.colorRedLight
    property string colorFontTextField: Settings.colorFontButton
    property int fontRenderType: Settings.fontRenderType
    property int durationAnimation: Settings.durationAnimation
    property int opacityNotEnabled: Settings.opacityNotEnabled

    id: control

    background: Rectangle {
        y: control.height - height - control.bottomPadding / 2
        implicitWidth: 120
        height: control.activeFocus ? 2 : 1
        color: control.activeFocus ? colorTextFieldHover : colorTextField
    }
}
