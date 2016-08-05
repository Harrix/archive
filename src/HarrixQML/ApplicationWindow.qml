import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    property alias fonts: fonts

    visible: true
    width: 640
    height: 480
    title: qsTr("Harrix Window")
    color: Settings.colorBackground
    font.family: Settings.fontName
    font.pixelSize: Settings.fontSize

    ServiceFonts {
        id: fonts
    }
}
