import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    id: textField

    //Properties that it is necessary to set
    property alias textPlaceholder: placeholderReplace.text

    //Common properties which can be changed if necessary
    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property string colorSelection: SettingsHarrixQML.colorRed
    property string colorFontSelection: SettingsHarrixQML.colorLightElement
    property string colorFont: SettingsHarrixQML.colorFont
    property string colorNotEnabled: SettingsHarrixQML.colorNotEnabled

    property string colorFontPlaceholder: SettingsHarrixQML.colorNotEnabled

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

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.IBeamCursor
        acceptedButtons: Qt.NoButton
    }

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                                         placeholderReplace.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                                          placeholderReplace.implicitHeight + topPadding + bottomPadding)

    Text {
        id: placeholderReplace
        x: textField.leftPadding
        y: textField.topPadding
        width: textField.width - (textField.leftPadding + textField.rightPadding)
        height: textField.height - (textField.topPadding + textField.bottomPadding)

        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        color: colorFontPlaceholder
        horizontalAlignment: textField.horizontalAlignment
        verticalAlignment: textField.verticalAlignment
        visible: !textField.length && !textField.preeditText && (!textField.activeFocus || textField.horizontalAlignment !== Qt.AlignHCenter)
        elide: Text.ElideRight
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
