import QtQuick 2.0


// 将 Row 置于一个 Rectangle 中
Rectangle {
    id: myFileMenu
    height: 480
    width: 1000

    // Row 将子元素按水平排列
    Row {
        anchors.centerIn: parent

        // 指定内部各元素的间隔距离。
        spacing: parent.width / 6

        Button {
            id: loadButton
            buttonColor: "lightgrey"
            label: "Load"

            // 需要指定元素尺寸大小，否则全部挤一起了。
            height: 50
            width: 50
        }
        Button {
            buttonColor: "grey"
            id: saveButton
            label: "Save"

            height: 50
            width: 50
        }
        Button {
            id: exitButton
            label: "Exit"
            buttonColor: "darkgrey"

            // 元素内部定义的信号处理操作会先执行，再执行此处的操作。
            // 增补该级层次的操作。
            onButtonClick: {
                console.log("xxxxxxxxxxxxxxxxx")
                Qt.quit()
            }

            height: 50
            width: 50
        }
    }
}

