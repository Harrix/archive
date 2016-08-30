import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Rectangle {
    id: control

    //Properties that it is necessary to set
    property alias textPlaceholder: placeholderReplace.text
    property alias text: textField.text

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
    property int extraHeight: 10
    property int implicitHeightTextField: 31

    width: textField.width
    height: textField.height + extraHeight
    color: "transparent"

    TextField {
        id: textField

        y: extraHeight
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
        implicitHeight: implicitHeightTextField

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.IBeamCursor
            acceptedButtons: Qt.NoButton
        }

        Text {
            id: placeholderReplace
            x: 0
            y: normalPlaceholder() ? textField.topPadding : -(extraHeight + textField.bottomPadding)
            width: textField.width
            height: textField.height - (textField.topPadding + textField.bottomPadding)
            renderType: fontRenderType
            font.pixelSize: normalPlaceholder() ? fontSize : fontSize - 1
            font.family: fontName
            color: defineColorFontPlaceholder()
            horizontalAlignment: textField.horizontalAlignment
            verticalAlignment: textField.verticalAlignment
            elide: Text.ElideRight
            Behavior on y {
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

    function defineColorFontPlaceholder() {
        if (normalPlaceholder())
            return colorFontPlaceholder;
        if (textField.activeFocus)
            return colorTextFieldBorderHover;
        else
            return  colorFontPlaceholder;
    }

    function normalPlaceholder() {
        var result = !textField.length;
        result = result && !textField.preeditText;
        result = result && !textField.activeFocus;
        return result;
    }
}
