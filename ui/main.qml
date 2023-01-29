import QtQuick 2.15
import QtQuick.Controls 2.15

import "./Component" as Controls


Window {
    id: mainApp
    width: 1
    height: 1
    minimumWidth: 1
    minimumHeight: 1
    title: qsTr("Amirhossein Farahmand Library")
    visible: true

    function init()
    {
        mainApp.width = default_width;
        mainApp.height = default_height;
        mainApp.minimumWidth = min_width;
        mainApp.minimumHeight = min_height;
        console.log("qml init!");
    }
    function loadPage(pageName)
    {
        console.log("loading page: " + pageName + " by loadPage function in main.qml");
        console.log(default_width + " , " + default_height + " , " + default_gap);
        loaderItem.source = pageName + ".qml";
        loaderItem.enabled = true;
        loaderItem.active =  true;
        return true;
    }

    Loader {
        id:  loaderItem
        onSourceChanged: gc()
    }

    Controls.MessageBox {
        id: msgBox
        visible: false
    }
}
