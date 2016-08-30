import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    id: control

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
    property string colorFontPlaceholder: SettingsHarrixQML.colorFontPlaceholder
    property string colorTextFieldBorder: SettingsHarrixQML.colorBorder
    property string colorTextFieldBorderHover: SettingsHarrixQML.colorRed

    width: textField.width
    height: textField.height + 10
    color: "transparent"

    TextField {
        id: textField

        y: 10
        renderType: fontRenderType
        font.pixelSize: fontSize
        font.family: fontName
        selectionColor: colorSelection
        selectedTextColor: colorFontSelection
        selectByMouse: true
        color: enabled ? colorFont : colorNotEnabled
        placeholderText: ""
        leftPadding: 0
        rightPadding: 0
        implicitWidth: Math.max(background ? background.implicitWidth : 0,
                                             placeholderReplace.implicitWidth
                                             + leftPadding + rightPadding)
        implicitHeight: Math.max(background ? background.implicitHeight : 0,
                                              placeholderReplace.implicitHeight
                                              + topPadding + bottomPadding)

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.IBeamCursor
            acceptedButtons: Qt.NoButton
        }

        Text {
            id: placeholderReplace
            x: 0
            y: textField.topPadding
            width: textField.width
            height: textField.height - (textField.topPadding + textField.bottomPadding)
            renderType: fontRenderType
            font.pixelSize: fontSize
            font.family: fontName
            color: colorFontPlaceholder
            horizontalAlignment: textField.horizontalAlignment
            verticalAlignment: textField.verticalAlignment
            visible: calculateNormalStatePlaceholder()
            elide: Text.ElideRight
        }

        background: Rectangle {
            y: textField.height - height - textField.bottomPadding / 2
            implicitWidth: 120
            height: 1
            color: colorTextFieldBorder

            Rectangle {
                y: 0
                width: textField.activeFocus ? parent.width : 0
                height: 2
                color: textField.activeFocus ? colorTextFieldBorderHover : colorTextFieldBorder
                anchors.horizontalCenter: parent.horizontalCenter

                Behavior on width {
                    NumberAnimation {
                        duration: durationAnimation
                        easing.type: Easing.InOutQuad
                    }
                }
                Behavior on color {
                    ColorAnimation {
                        duration: durationAnimation
                        easing.type: Easing.InOutQuad
                    }
                }
            }
        }
    }

    function calculateNormalStatePlaceholder() {
        var result = !textField.length;
        result = result && !textField.preeditText;
        result = result && !textField.activeFocus;
        return result;
    }
}
