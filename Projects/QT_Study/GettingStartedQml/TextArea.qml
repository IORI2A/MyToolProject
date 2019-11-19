import QtQuick 2.0

// 补充：全部定义显示到一个矩形范围中。
// 相当于一个窗口。
Rectangle {
    id: textArea
    width: 1000; height: 400

    // 使用 Flickable 来包含文本元素。使用有一些 Flickable 特性。
    Flickable {
        id: flickArea
        width: parent.width
        height: parent.height
        anchors.fill: parent

        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.HorizontalFlick
        interactive: true

        // Javascript 语法。 定义函数。
        function ensureVisible(r) {
             if (contentX >= r.x)
                 contentX = r.x;
             else if (contentX + width <= r.x + r.width)
                 contentX = r.x + r.width - width;
             if (contentY >= r.y)
                 contentY = r.y;
             else if (contentY + height <= r.y + r.height)
                 contentY = r.y + r.height - height;
         }

        // 文本编辑区域。
        TextEdit {
            id: textEditor
            anchors.fill: parent
            width: parent.width
            height: parent.height
            color: "midnightblue"
            focus: true

            wrapMode: TextEdit.Wrap

            onCursorRectangleChanged: flickArea.ensureVisible(cursorRectangle)
        }
    }
}
