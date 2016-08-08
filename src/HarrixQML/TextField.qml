import QtQuick 2.7
import QtQuick.Controls 2.0
import "."

TextField {
    id: control

    background: Rectangle {
        y: control.height - height - control.bottomPadding / 2
        implicitWidth: 120
        height: control.activeFocus ? 2 : 1
        color: control.activeFocus ? "#f54d4c" : "#de2b26"
    }
}
