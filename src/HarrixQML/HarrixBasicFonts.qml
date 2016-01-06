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
    property alias fontOpenSans: fontOpenSans // name = Open Sans
    property alias fontPTMono: fontPTMono // name = PT Mono

    FontLoader { id: fontOpenSans; source: "qrc:/fonts/HarrixQML/fonts/OpenSans.ttf" }
    FontLoader { id: fontPTMono; source: "qrc:/fonts/HarrixQML/fonts/PTMono.ttf" }
}
