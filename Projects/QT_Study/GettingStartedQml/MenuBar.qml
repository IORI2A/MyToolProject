import QtQuick 2.0
// 调测报错： ObjectModel is not a type
import QtQml.Models 2.1

// 补充：全部定义显示到一个矩形范围中。
// 相当于一个窗口。
Rectangle {

    // 补充：其他代码要用到的内容。在此处参照示例补充
    id: menuBar
    width: 1000; height: 300
    property color fileColor: "plum"
    property color editColor: "powderblue"

    property real partition: 1 / 10

    Rectangle {
        id: labelList
        //...
        z: 1

        // 补充：定义大小范围。否则全缩到左上角。
        height: menuBar.height * partition
        width: menuBar.width

        Row {
            anchors.centerIn: parent
            spacing: 40

            // 补充：此处指定大小范围。无法正常显示子元素，全部缩到一起了。
//            width: parent.width
//            height: parent.height

            Button {
                label: "File"
                id: fileButton
                //...

                // 通过元素的 index 操作元素。 index 就是元素在 model 中的声明顺序。
                onButtonClick: menuListView.currentIndex = 0

                // 补充：此处指定大小范围。避免全部缩到一起。
                width: 50; height: 20
            }

            Button {
                id: editButton
                label: "Edit"
                //...
                onButtonClick: menuListView.currentIndex = 1

                width: 50; height: 20
            }
        }
    }

    ListView {
        id: menuListView

        // Anchors are set to react to window anchors
        anchors.fill: parent
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height

        // The model contains the data
        model: menuListModel

        // Control the movement of the menu switching
        snapMode: ListView.SnapOneItem
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds
        flickDeceleration: 5000
        highlightFollowsCurrentItem: true
        highlightMoveDuration: 240
        highlightRangeMode: ListView.StrictlyEnforceRange
    }

    ObjectModel {
        id: menuListModel

        // 元素在 model 中的声明顺序就是 index 。
        FileMenu {
            width: menuListView.width
            height: menuBar.height
            color: fileColor
        }

        EditMenu {
            color: editColor
            width: menuListView.width
            height: menuBar.height
        }
    }
}
