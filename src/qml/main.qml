import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Window {
  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  Column {
    id: leftPanel
    objectName: "leftPanel"

    spacing: 10
    anchors.fill: parent
    anchors.bottomMargin: 0

    TextField {
      objectName: "field10"
    }

    TextField {
      objectName: "field101"
    }

    Button {
      text: qsTr("Download")
    }
  }
}
