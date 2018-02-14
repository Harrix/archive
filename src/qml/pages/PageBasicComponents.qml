import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml 2.2
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Material.impl 2.1

import "../../HarrixQML"

Page{
    id: pageBasicComponents
    objectName: "pageBasicComponents"

    property alias flickable: flickable

    signal qmlSignal(string msg)

    ListModel {
        id: modelTest
        ListElement {
            name: "Options";
            caption: qsTr("Options");
        }
        ListElement {
            name: "File";
            caption: qsTr("File");
        }
        ListElement {
            name: "Edit";
            caption: qsTr("Edit");
        }
    }

    ListModel {
        id: modelTest2
        ListElement {
            name: "About";
            caption: qsTr("About");
        }
        ListElement {
            name: "Terminator";
            caption: qsTr("Terminator");
        }
        ListElement {
            name: "Matrix";
            caption: qsTr("Matrix");
        }

        ListElement {
            name: "Harry Potter";
            caption: qsTr("Harry Potter");
        }
    }

    Menu {
        id: menuTest
        property alias model: instantiatormenuTest.model

        Instantiator {
            id: instantiatormenuTest
            model: ListModel {
                ListElement {
                    name: "Text";
                    caption: qsTr("Text");
                }
            }
            onObjectAdded: menuTest.insertItem( index, object )
            onObjectRemoved: menuTest.removeItem( object )
            delegate: MenuItem {
                text: caption
                onTriggered: {
                    //menuModel.executeCommand( role_command, role_user );
                }
            }
        }
    }

    Flickable {
        id: flickable
        focus: true
        width: parent.width
        height: parent.height
        contentWidth: parent.width
        contentHeight: column22.height

        ScrollBar.vertical: ScrollBar { id: vbar; }

        Column {
            id: column22
            spacing: spacingCommon
            width: parent.width - 2*marginCommon
            x: marginCommon

            Hamburger {
                id: menuBackIcon
                MouseArea {
                    anchors.fill: parent
                    onClicked: menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
                }
            }

            TextFieldGreen {
                id: field1
                objectName: "field1"
                textPlaceholder: qsTr("Input first number")
                inputMethodHints: Qt.ImhDigitsOnly
            }

            TextFieldBlue {
                id: field2
                objectName: "field2"
                textPlaceholder: qsTr("Input second number")
                inputMethodHints: Qt.ImhDigitsOnly
            }

            Button {
                id: button
                text: qsTr("Sum")
                onClicked: qmlSignal( qsTr("apples") )
            }

            TextArea {
                id: textArea
                objectName: "textArea"
                wrapMode: TextArea.Wrap
                readOnly: true
                width: 250
            }

            LineDashed {}


            TextField {
                textPlaceholder: qsTr("Input first number")
                enabled: false
            }

            TextField {
                textPlaceholder: qsTr("Qt.ImhDate")
                inputMethodHints: Qt.ImhDate
            }

            TextField {
                textPlaceholder: qsTr("Qt.ImhPreferNumbers")
                inputMethodHints: Qt.ImhPreferNumbers
            }

            TextField {
                textPlaceholder: qsTr("Qt.ImhTime")
                inputMethodHints: Qt.ImhTime
            }

            TextField {
                textPlaceholder: qsTr("Qt.ImhEmailCharactersOnly")
                inputMethodHints: Qt.ImhEmailCharactersOnly
            }

            TextField {
                textPlaceholder: qsTr("Qt.ImhUrlCharactersOnly")
                inputMethodHints: Qt.ImhUrlCharactersOnly
            }

            ButtonBlue{
                text: qsTr("enabled: false")
                onClicked:  toogleNavigationDrawer()
                enabled: false
            }

            ButtonBlue{
                text: qsTr("Open Drawer")
                onClicked:  toogleNavigationDrawer()
            }

            ButtonBlue{
                text: qsTr("Head Scroll")
                onClicked:  toogleHeightHead(false)
            }

            ButtonBlue{
                text: qsTr("Head Normall")
                onClicked:  toogleHeightHead(true)
            }

            ButtonGreen {
                id: button2
                text: qsTr("Download")
                onClicked: qmlSignal( qsTr("tables") )
                //icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
            }

            ButtonBlue {
                id: button22
                text: qsTr("Open menu")
                //icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
                onClicked:  {
                    menuTest.model = modelTest
                    menuTest.open()
                }
            }

            ButtonBlue {
                id: button22996
                text: qsTr("Open menu 2")
                //icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
                onClicked:  {
                    menuTest.model = modelTest2
                    menuTest.open()
                }
            }

            Button {
                id: button3
                text: qsTr("Download")
                enabled: false
                //icon:  IconFontAwesome { symbol: FontAwesome.fa_apple }
            }

            Label {
                text: "Answer:"
            }

            Image {
                source: "qrc:/images/harrix_photo.png"
                width: 300
                height: 300
                smooth: true

                MouseAreaRipple {
                    id: mouseAreaImage
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        console.log("image")
                    }
                }
            }

            Image {
                source: "qrc:/images/harrix_photo.png"
                width: 300
                height: 300
                smooth: true

                Ripple {
                    clipRadius: 2
                    width: parent.width
                    height: parent.height
                    pressed: control.pressed
                    anchor: control
                    active: control.down || control.visualFocus || control.hovered
                    color: "black"
                }
            }

            Label {
                text: "The <b>hedgehog</b> was <a href='http://harrix.org'>engaged</a> in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
            }

            Label {
                text: "<p>The hedgehog was engaged in a fight with another hedgehog.</p>
<p><img src='qrc:/images/logo-harrix.svg'></p>
<p>By the time she had caught the flamingo and brought it back.</p>"
                width: parent.width
            }

            Label {
                text: "T!he hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
                font.weight: Font.Black
            }

            Label {
                text: "The hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
            }

            Image {
                source: "qrc:/images/harrix_photo.png"
                width: 300
                height: 300
                smooth: true

                MouseAreaRipple {
                    id: mouseAreaImage2
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        console.log("image")
                    }
                }
            }
        }

        onContentYChanged: {
            if (contentApp.currentIndex == 0) {
                if (contentY > 0)
                    toogleHeightHead(false);
                else
                    toogleHeightHead(true);
            }
        }
    }
}
