import QtQuick 2.7

ListModel {
    ListElement {
        name: "File";
        caption: qsTr("File");
        submenu: [
            ListElement { name: "New";    caption: qsTr("New"); },
            ListElement { name: "Open";   caption: qsTr("Open"); },
            ListElement { name: "Exit";   caption: qsTr("Exit"); }
        ]
    }
    ListElement {
        name: "Options";
        caption: qsTr("Options");
    }
    ListElement {
        name: "Harrix.org";
        caption: qsTr("Harrix.org");
    }
    ListElement {
        name: "About";
        caption: qsTr("About");
        submenu: [
            ListElement { name: "Help";            caption: qsTr("Help"); },
            ListElement { name: "AboutProgram";    caption: qsTr("About Program"); }
        ]
    }
}
