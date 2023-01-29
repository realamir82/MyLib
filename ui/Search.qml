import QtQuick 2.14
import QtQuick.Controls 2.15


Item
{
    id:  SearchPage

    anchors.fill: parent
    Rectangle
    {    ColumnLayout
        {
            RadioButton {
                checked: true
                text: qsTr("By Title")
            }
            RadioButton {
                text: qsTr("By Author")
            }
            RadioButton {
                text: qsTr("By Publisher")
            }
            RadioButton
            {
                text: qsTr("By PublishYear")
            }
        }


    }







}

