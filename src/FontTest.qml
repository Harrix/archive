import QtQuick 2.5

import "HarrixQML"

Item {
    Flickable {
        anchors.fill: parent
        contentHeight: gridlayout.height
        contentWidth: gridlayout.width

        Grid {
            id: gridlayout

            columns: 3
            spacing: 2

            TextExample { fontName: "MS Shell Dlg 2" }

            TextExample { fontName: "Arimo" }
            TextExample { fontName: "Consolas" }
            TextExample { fontName: "Raleway" }
            TextExample { fontName: "Open Sans" }
            TextExample { fontName: "MS Shell Dlg 2" }
            TextExample { fontName: "Roboto Mono" }
        }
    }
}
