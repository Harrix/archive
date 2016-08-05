import QtQuick 2.5

import "HarrixQML"

HarrixMainWindow {
    id:window;
    objectName:"MainWindow"
    title: qsTr("Flat Example Demo Привет! Вася пошёл домой! World")
    width: 960
    height: 540
    visible:true

    contentLoader.anchors.margins: 20
    content: FontTest {}
}

