import QtQuick 2.15
import QtQuick.Controls 2.15

import "./Component" as Controls

Item {
    id:  loginPage

    anchors.fill: parent

    Rectangle {
        id: loginArea
        color: "gray"
        width: mainApp.width * 0.8
        height: mainApp.height * 0.8
        x: (mainApp.width - loginArea.width)/2
        y: (mainApp.height - loginArea.height)/2
        radius: 15


        Text {
            id: title
            text: qsTr("Login Page")
            color: "white"
            font.pixelSize: 30
            font.bold: true
            x: (loginArea.width -  title.width)/2
            y: default_gap
        }

        Controls.HiInputText {
            id: usernameInput
            placeholder: "Username";
            passwordMode: false;
            width: loginArea.width/2 - 2 * default_gap;
            height: 50
            x: (loginArea.width -  usernameInput.width)/2
            y: (loginArea.height - usernameInput.height)/2
        }

        Controls.HiInputText {
            id: passwordInput
            placeholder: "Password";
            passwordMode: true;
            width: loginArea.width/2 - 2 * default_gap;
            height: 50
            x: (loginArea.width - passwordInput.width)/2
            y: usernameInput.y + usernameInput.height + default_gap
        }

        Button {
            id: loginBtn
            text: "Login"
            width: 140
            height: 50
            x: (loginArea.width - default_gap)/2 - loginBtn.width
            y: quitBtn.y - signUpBtn.height - default_gap

            onClicked:
            {
                if (user_manager.loginUser(usernameInput.text,passwordInput.text) == true)
                {
                    loadPage("MainMenu");
                }
                else
                {
                    msgBox.title = qsTr("Error!")
                    msgBox.text = qsTr("Invalid Username or password!")
                    msgBox.visible = true
                }
            }

        }

        Button {
            id: signUpBtn
            text: "Sign Up"
            width: 140
            height: 50
            x: (loginArea.width + default_gap)/2
            y: quitBtn.y - signUpBtn.height - default_gap
            onClicked: {
                loadPage("RegisterPage");
            }
        }


        Button {
            id: quitBtn
            text: "Quit"
            background: Rectangle {
                color: "#ff0000"
            }
            x: (loginArea.width - quitBtn.width)/2
            y: loginArea.height - default_gap - quitBtn.height
            width: 300
            height: 50
            onClicked: Qt.quit();
        }
    }

     Component.onCompleted: console.log(loginPage.width + " " +mainApp.width);
}
