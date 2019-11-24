import QtQuick 2.0


Rectangle {
    id: screen
    width: 1000
    height: 600
    color: "lightblue"

    // 设定分3个等高区的高度。
    // The screen is partitioned into the MenuBar and TextArea.
    // One-third of the screen is assigned to the MenuBar
    property int partition: height / 3

    Rectangle {
        id: menuBar
        // 占一个分区。 起始坐标原点是父元素的(0,0)，即以父元素的(0,0)为锚点。
        height: partition
        width: parent.width
        // z 坐标值。对应显示层级。
        //z: 1
        color: "#8C8F8C"
    }

    // 增加一个中间分隔栏
    Rectangle {
        // 以父元素的(0,0)为锚点。

        id: drawer
        height:15; width: parent.width
        border.color : "red"
        border.width: 1

        // 同一 z 坐标值（相同显示层级），创建在后的显示在前面。
        //z: 1
    }

    Rectangle {
        id: textArea
        // 以父元素的底边为锚。
        //anchors.bottom: parent.bottom
        // y 坐标值，y起始值。
        y: drawer.height
        //y: partition
        color: "#6A6D6A"
        width: parent.width
        height: partition * 2
        //height: partition
        // 以父元素的底边为锚。则高度增加是反向向上增长。
        //height: partition * 3

        z:100
    }
}
