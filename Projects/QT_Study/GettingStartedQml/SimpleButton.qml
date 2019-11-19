// import QtQuick 2.0 示例使用的是 2.3
import QtQuick 2.3

Rectangle {
    id: simpleButton

    // 设定颜色、高、宽。
    color: "grey"
    width: 150; height: 75

    // 描述文本显示。
    Text {
        id: buttonLabel
        anchors.centerIn: parent

        // 文本内容超出指定大小范围，丢失，截取范围内的显示。
        text: "button label123456789012345678901234567890"
    }

    // 描述鼠标交互区域。
    MouseArea {
        id: buttonMouseArea

        // 锚定父元素(Rectangle id: simpleButton)的所有边包围的区域。
        // Anchor all sides of the mouse area to the rectangle's anchors
        anchors.fill: parent

        // 处理鼠标点击事件。
        // onClicked handles valid mouse button clicks
        onClicked: console.log(buttonLabel.text + " clicked")
        // buttonLabel.text 通过ID(Text id: buttonLabel)引用元素对象及其属性。
    }
}
