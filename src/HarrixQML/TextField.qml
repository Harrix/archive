import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    id: textField

    //Common properties which can be changed if necessary
    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property string colorSelection: SettingsHarrixQML.colorRed
    property string colorFontSelection: SettingsHarrixQML.colorLightElement
    property string colorFont: SettingsHarrixQML.colorFont
    property string colorNotEnabled: SettingsHarrixQML.colorNotEnabled

    property string colorTextField: "blue"
    property string colorTextFieldHover: "yellow"
    property string colorFontTextField: "green"

    renderType: fontRenderType
    font.pixelSize: fontSize
    font.family: fontName
    selectionColor: colorSelection
    selectedTextColor: colorFontSelection
    selectByMouse: true
    color: enabled ? colorFont : colorNotEnabled
    placeholderText: ""

    padding: 6
    leftPadding: padding + 4

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.IBeamCursor
        acceptedButtons: Qt.NoButton
    }

    property alias textPlaceholder: placeholder2.text

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                                         placeholder2.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                                          placeholder2.implicitHeight + topPadding + bottomPadding)

    Text {
        id: placeholder2
        x: textField.leftPadding
        y: textField.topPadding
        width: textField.width - (textField.leftPadding + textField.rightPadding)
        height: textField.height - (textField.topPadding + textField.bottomPadding)

        //text: textField.placeholderText
        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        color: "red"
        horizontalAlignment: textField.horizontalAlignment
        verticalAlignment: textField.verticalAlignment
        visible: !textField.length && !textField.preeditText && (!textField.activeFocus || textField.horizontalAlignment !== Qt.AlignHCenter)
        //elide: Text.ElideRight
    }

    background: Rectangle {
        y: textField.height - height - textField.bottomPadding / 2
        implicitWidth: 120
        height: textField.activeFocus ? 2 : 1
        color: textField.activeFocus ? colorTextFieldHover : colorTextField

        Behavior on color {
            ColorAnimation { duration: durationAnimation }
        }
    }
}
