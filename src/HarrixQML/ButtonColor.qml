import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

Button {
    property int type: ButtonRed
    colorButton: setColor()
    colorButtonHover: setColorHover()

    function setColor() {
        switch (type) {
        case ButtonRed:
            colorButton = Settings.colorRed;
            colorButtonHover = Settings.colorRedLight;
            break;
        case ButtonBlue:
            colorButton = Settings.colorBlue;
            colorButtonHover = Settings.colorBlueLight;
            break;
        case ButtonGreen:
            colorButton = Settings.colorGreen;
            colorButtonHover = Settings.colorGreenLight;
            break;
        default:
            colorButton = Settings.colorRed;
            colorButtonHover = Settings.colorRedLight;
        }
    }
}
