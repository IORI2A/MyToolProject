
import QtQuick 2.0

Rectangle {
     id: button

     //...

     // 自定义属性(custom property)
     // 语法：property type name 。指定属性的类型，名称。
     property color buttonColor: "lightblue"
     property color onHoverColor: "gold"
     property color borderColor: "white"

     // 自定义信号。 signal keyword in front of the signal name.
     // 可视作为搭接内外部通信的中间信号。
     signal buttonClick()

     // 定义自定义信号会自动生成相应的信号处理，以on开头，on_<signal name>。
     // 元素内部定义的信号处理操作始终会执行。而且是先于外部调用者指定的操作。
     // 暴露给外部（增补）设定各种操作。
     onButtonClick: {
         // 报错： buttonLabel is not defined
         console.log(buttonLabel.text + " clicked")
         //console.log(" clicked")
     }

     MouseArea{
         id: buttonMouseArea
         onClicked: buttonClick()
         // ture 时，使用该交互区域除检测点击事件外，也检测移动事件。
         hoverEnabled: true
         // 信号处理。 使用自定义属性 onHoverColor、borderColor 在不同状态下变更父元素边框颜色。
         onEntered: parent.border.color = onHoverColor
         onExited:  parent.border.color = borderColor

         // 填充父元素整个空间，检测鼠标事件。
         anchors.fill: parent
     }

     // 根据条件判定，使用自定义属性 buttonColor 来绑定 color 属性。
     // Determines the color of the button by using the conditional operator
     color: buttonMouseArea.pressed ? Qt.darker(buttonColor, 1.5) : buttonColor


     /////////////////////////////////////////////////////////
     // 报错： buttonLabel is not defined
     // 再增加一个 (Text id: buttonLabel) 描述文本显示。
     Text {
         id: buttonLabel
         anchors.centerIn: parent

         // text 属性关联到父元素(Rectangle id: button)的 label 属性。 使得外部访问修改 label 属性就联动修改了 text 属性。
         // text: "button label"
         text: label
     }

     // 补充一个 label 属性，外部 FileMenu.qml 有使用。
     property string label: "button label"
 }
