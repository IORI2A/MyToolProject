// import QtQuick 2.0 示例使用的是 2.3
import QtQuick 2.3

Rectangle {
    id: simpleButton

    // 设定颜色、高、宽。
    // 如果同时使用 color 和 gradient 属性。color 内容覆盖 gradient 。
    //color: "grey"
    width: 150; height: 75

    // This is because the children property of Item has been set as the type's default property to enable this more convenient syntax.
    // 默认有 children 属性，为了语法方便简洁，声明子对象时，不用写出来。
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

    /////////////////////////
    // 使用渐变色。
    // 渐变色比纯色或使用图片更耗性能。
    //  position: 值范围 [0.0, 1.0] 。每个点位之间形成渐变色。
    gradient: Gradient {
        GradientStop { position: 0.0; color: "yellow" }
        GradientStop { position: 1.0; color: "green" }
    }
}
