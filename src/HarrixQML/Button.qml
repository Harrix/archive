import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property alias icon: loaderIcon.sourceComponent

    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property string colorButton: SettingsHarrixQML.colorRed
    property string colorButtonHover: SettingsHarrixQML.colorRedLight
    property string colorButtonNotEnabled: SettingsHarrixQML.colorNotEnabled
    property string colorFontButton: SettingsHarrixQML.colorFontInColorRectangle
    property int fontRenderType: SettingsHarrixQML.fontRenderType
    property int durationAnimation: SettingsHarrixQML.durationAnimation
    property int paddingButton: 8
    property int leftPaddingButton: 24
    property int rightPaddingButton: 24
    property int spacingIconText: 10
    property int fontWeightButton: Font.Bold
    property int fontCapitalizationButton:Font.AllUppercase

    id: control

    padding: paddingButton
    leftPadding: leftPaddingButton
    rightPadding: rightPaddingButton

    contentItem: Row {
        id: contentItem
        spacing: spacingIconText
        anchors.centerIn: parent

        Loader {
            id: loaderIcon
            width: loaderIcon.status ? text.height : 0
            height: text.height
        }

        Text {
            id: text
            text: control.text
            font.family: fontName
            font.pixelSize: fontSize
            font.weight: fontWeightButton
            font.capitalization: fontCapitalizationButton
            color: colorFontButton
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            renderType: fontRenderType
        }
    }

    background: Rectangle {
        color: defineColor()
        border.width: 0
        radius: 0

        MouseAreaRipple {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = colorButtonHover
            onExited: parent.color = colorButton
            onClicked: control.clicked()
        }

        Behavior on color {
            ColorAnimation {
                duration: durationAnimation
            }
        }
    }

    function defineColor() {
        if (enabled === false)
            return colorButtonNotEnabled;
        if (control.down)
            return colorButtonHover;
        else
            return colorButton;
    }
}
