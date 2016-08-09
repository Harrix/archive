import QtQuick 2.7

pragma Singleton

Item {
    property alias buttons: buttons

    QtObject {
        id: buttons
        readonly property int red: 0
        readonly property int blue: 1
        readonly property int green: 2
    }
}
