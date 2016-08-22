import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    id: applicationWindow

    property string fontName: SettingsHarrixQML.fontName
    property int fontSize: SettingsHarrixQML.fontSize
    property string colorFont: SettingsHarrixQML.colorFont
    property string colorBackground: SettingsHarrixQML.colorBackground
    property int widthWindow: 640
    property int heightWindow: 480

    visible: true
    width: widthWindow
    height: heightWindow
    title: qsTr("Harrix Window")
    color: colorBackground
    font.family: fontName
    font.pixelSize: fontSize

    Fonts {}
}
