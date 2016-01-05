/*
  HarrixQML 1.0 - Компоненты QML в Flat стиле.
  https://github.com/Harrix/HarrixQML
  Лицензия: MIT

  HarrixFonts - Подзагрузка шрифтов.
*/

import QtQuick 2.5

/*
Два способа загрузки:
font.family: fonts.fontConsolas.name
font.family: "Consolas"
*/

Item {
    property alias fontArimoRegular: fontArimo // name = Arimo
    property alias fontConsolas: fontConsolas // name = Consolas
    property alias fontRaleway: fontRaleway // name = Raleway
    property alias fontOpenSans: fontOpenSans // name = Open Sans
    property alias fontRobotoMono: fontRobotoMono // name = Roboto Mono
    property alias fontPTMono: fontPTMono // name = PT Mono

    FontLoader { id: fontArimo; source: "qrc:/fonts/HarrixQML/fonts/Arimo.ttf";}
    FontLoader { id: fontConsolas; source: "qrc:/fonts/HarrixQML/fonts/Consolas.ttf";}
    FontLoader { id: fontRaleway; source: "qrc:/fonts/HarrixQML/fonts/Raleway.ttf" }
    FontLoader { id: fontOpenSans; source: "qrc:/fonts/HarrixQML/fonts/OpenSans.ttf" }
    FontLoader { id: fontRobotoMono; source: "qrc:/fonts/HarrixQML/fonts/RobotoMono.ttf" }
    FontLoader { id: fontPTMono; source: "qrc:/fonts/HarrixQML/fonts/PTMono.ttf" }
}
