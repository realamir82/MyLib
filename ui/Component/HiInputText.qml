import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle {
    id: hiInputTextRect
    radius: 15
    color: "white"
    border.color: "gray"
    property string placeholder: "Enter";
    property bool passwordMode: false;
    property string text: hiInputText.text;
    property alias inputText: hiInputText

    TextInput {
        id: hiInputText
        anchors.fill : parent
        font.pixelSize: 25
        horizontalAlignment : "AlignHCenter"
        verticalAlignment: "AlignVCenter"
        width: parent.width
        smooth: true
        maximumLength: 20
        echoMode: (passwordMode)?TextInput.Password:TextInput.Normal;

        Text {
            font.pixelSize: hiInputText.font.pixelSize
            horizontalAlignment : "AlignHCenter"
            verticalAlignment: "AlignVCenter"
            text: placeholder
            color: "#aaa"
            visible: !hiInputText.text
            anchors.fill : parent
        }
    }
}
