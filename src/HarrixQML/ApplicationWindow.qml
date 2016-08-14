import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property string fontName: SettingsApp.fontName
    property int fontSize: SettingsApp.fontSize
    property string colorFont: SettingsApp.colorFont
    property string colorBackground: SettingsApp.colorBackground
    property int widthWindow: SettingsApp.widthWindow
    property int heightWindow: SettingsApp.heightWindow

    visible: true
    width: widthWindow
    height: heightWindow
    title: qsTr("Harrix Window")
    color: colorBackground
    font.family: fontName
    font.pixelSize: fontSize

    Fonts {}
}
