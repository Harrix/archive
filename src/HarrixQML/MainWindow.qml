import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "."

ApplicationWindow {
    visibility: "Maximized"

    onWidthChanged: console.log(width)
    Component.onCompleted: console.log("onCompleted = "+width)
}
