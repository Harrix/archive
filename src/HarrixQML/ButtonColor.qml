import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property int type: Enums.buttons.red

    colorButton: setColor()
    colorButtonHover: setColorHover()

    function setColor() {
        switch (type) {
        case Enums.buttons.red:
            colorButton = Settings.colorRed;
            colorButtonHover = Settings.colorRedLight;
            break;
        case Enums.buttons.blue:
            colorButton = Settings.colorBlue;
            colorButtonHover = Settings.colorBlueLight;
            break;
        case Enums.buttons.green:
            colorButton = Settings.colorGreen;
            colorButtonHover = Settings.colorGreenLight;
            break;
        default:
            colorButton = Settings.colorRed;
            colorButtonHover = Settings.colorRedLight;
        }
    }
}
