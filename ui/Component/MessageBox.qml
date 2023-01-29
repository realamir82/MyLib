import QtQml 2.2

import QtQuick 2.9
import QtQuick.Controls 2.2

Dialog {
    parent: mainApp.overlay

    width:  400
    height:  100
    x: (mainApp.width - width) / 2
    y: (mainApp.height - height) / 2

    focus: true
    modal: true

    property alias text: messageText.text

    Label {
        id: messageText

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        anchors.fill: parent
    }

    standardButtons: Dialog.Ok
}
