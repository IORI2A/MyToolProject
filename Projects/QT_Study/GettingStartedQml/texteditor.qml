import QtQuick 2.0


Rectangle {
    id: screen
    width: 1000
    height: 1000

    // The screen is partitioned into the MenuBar and TextArea.
    // One-third of the screen is assigned to the MenuBar
    property int partition: height / 3

    MenuBar {
        id: menuBar
        height: partition
        width: parent.width
        z: 1
    }

    TextArea {
        id: textArea
        anchors.bottom: parent.bottom
        y: partition
        color: "white"
        width: parent.width
        height: partition * 2
    }
}
