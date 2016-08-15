import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "HarrixQML"

Page{
    id: pageBasicComponents
    objectName: "pageBasicComponents"
    signal qmlSignal(string msg)
    Flickable {
        focus: true

        width: parent.width
        height: parent.height
        contentWidth: parent.width
        contentHeight: column22.height

        ScrollBar.vertical: ScrollBar { id: vbar; }

        Column {
            id: column22
            spacing: SettingsApp.spacingCommon
            width: parent.width

            TextField {
                id: field1
                objectName: "field1"
                placeholderText: qsTr("Input first number")
            }

            TextField {
                id: field2
                objectName: "field2"
                placeholderText: qsTr("Input second number")
            }

            Button {
                id: button
                text: qsTr("Download")
                onClicked: qmlSignal( qsTr("apples") )
            }

            ButtonGreen {
                id: button2
                text: qsTr("Download")
                onClicked: qmlSignal( qsTr("tables") )
                icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
            }

            ButtonBlue {
                id: button22
                text: qsTr("Console")
                //onClicked: testSignal("send signal")
                icon:  IconFontAwesome { symbol: FontAwesome.fa_vk }
            }

            Button {
                id: button3
                text: qsTr("Download")
                enabled: false
                onClicked: qmlSignal( qsTr("images") )
                icon:  IconFontAwesome { symbol: FontAwesome.fa_download }
            }

            Label {
                text: "Answer:"
                font.pixelSize: textArea.font.pixelSize
            }

            TextArea {
                id: textArea
                objectName: "textArea"
                wrapMode: TextArea.Wrap
                readOnly: true
                width: 250
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

            Label {
                text: "The hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
                wrapMode: Text.WrapAnywhere
                anchors.margins: SettingsApp.marginCommon
            }

            Label {
                text: "The hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
                wrapMode: Text.Wrap
                anchors.margins: SettingsApp.marginCommon
            }

            Label {
                text: "The hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
                wrapMode: Text.Wrap
                anchors.margins: SettingsApp.marginCommon
            }

            Label {
                text: "The hedgehog was engaged in a fight with another hedgehog, which seemed to Alice an excellent opportunity for croqueting one of them with the other: the only difficulty was, that her flamingo was gone across to the other side of the garden, where Alice could see it trying in a helpless sort of way to fly up into a tree. By the time she had caught the flamingo and brought it back, the fight was over, and both the hedgehogs were out of sight: 'but it doesn't matter much,' thought Alice, 'as all the arches are gone from this side of the ground.' So she tucked it away under her arm, that it might not escape again, and went back for a little more conversation with her friend. When she got back to the Cheshire Cat, she was surprised to find quite a large crowd collected round it: there was a dispute going on between the executioner, the King, and the Queen, who were all talking at once, while all the rest were quite silent, and looked very uncomfortable."
                width: parent.width
                wrapMode: Text.Wrap
                anchors.margins: SettingsApp.marginCommon
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
    }
}
