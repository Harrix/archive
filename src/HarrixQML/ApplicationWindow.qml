import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias fonts: fonts
    property string fontName: Settings.fontName
    property int fontSize: Settings.fontSize
    property string colorFont: Settings.colorFont
    property string colorBackground: Settings.colorBackground

    visible: true
    width: 640
    height: 480
    title: qsTr("Harrix Window")
    color: colorBackground
    font.family: fontName
    font.pixelSize: fontSize

    Fonts {
        id: fonts
    }
}
