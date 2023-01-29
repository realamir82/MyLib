import QtQuick 2.15
import QtQuick.Controls 2.15

import "./Component" as Controls


Item {
    id:  registerPage

    anchors.fill: parent

    Rectangle {
        id: registerArea
        color: "gray"
        width: mainApp.width * 0.8
        height: mainApp.height * 0.8
        x: (mainApp.width - registerArea.width)/2
        y: (mainApp.height - registerArea.height)/2
        radius: 15

        Text {
            id: title
            text: qsTr("Register Page")
            color: "white"
            font.pixelSize: 30
            font.bold: true
            x: (registerArea.width -  title.width)/2
            y: default_gap
        }

        Controls.HiInputText {
            id: usernameInput
            placeholder: "User Name";
            passwordMode: false;
            width: registerArea.width/2 - 2 * default_gap;
            height: 50
            x: (registerArea.width -  usernameInput.width)/2
            y: title.y + title.height + default_gap
        }

        Controls.HiInputText {
            id: passwordInput
            placeholder: "Password";
            passwordMode: true;
            width: registerArea.width/2 - 2 * default_gap;
            height: 50
            x: (registerArea.width -  passwordInput.width)/2
            y:  usernameInput.y + usernameInput.height + default_gap
        }

        Controls.HiInputText {
            id: firstnameInput
            placeholder: "First Name";
            passwordMode: false;
            width: registerArea.width/2 - 2 * default_gap;
            height: 50
            x: (registerArea.width -  firstnameInput.width)/2
            y: passwordInput.y + passwordInput.height + default_gap
        }

        Controls.HiInputText {
            id: lastNameInput
            placeholder: "Last Name";
            passwordMode: false;
            width: registerArea.width/2 - 2 * default_gap;
            height: 50
            x: (registerArea.width -  lastNameInput.width)/2
            y: firstnameInput.y + firstnameInput.height + default_gap
        }

        Controls.HiInputText {
            id: birthdayInput
            placeholder: "Birthday {Day/Month/Year}";
            passwordMode: false;
            width: registerArea.width/2 - 2 * default_gap;
            height: 50
            x: (registerArea.width -  birthdayInput.width)/2
            y: lastNameInput.y + lastNameInput.height + default_gap
            inputText.validator:
                RegularExpressionValidator {
                    regularExpression:
                        /^(?:0[1-9]|[12]\d|3[01])([\/.-])(?:0[1-9]|1[012])\1(?:19|20)\d\d$/
                }
        }


        Button {
            id: loginBtn
            text: "Back To Login"
            width: 140
            height: 50
            x: (registerArea.width - default_gap)/2 - loginBtn.width
            y: quitBtn.y - signUpBtn.height - default_gap
            onClicked: {
                loadPage("LoginPage");
            }
        }

        Button {
            id: signUpBtn
            text: "Sign Up"
            width: 140
            height: 50
            x: (registerArea.width + default_gap)/2
            y: quitBtn.y - signUpBtn.height - default_gap
            onClicked: {
                if (usernameInput.text != "" &&
                        passwordInput.text != "" &&
                        firstnameInput.text != "" &&
                        lastNameInput.text != "" &&
                        birthdayInput.text != "")
                {
                    if (user_manager.registerUser(usernameInput.text,
                                                  passwordInput.text,
                                                  firstnameInput.text,
                                                  lastNameInput.text,
                                                  birthdayInput.text) == true)
                    {
                        loadPage("MainMenu");
                    }
                    else
                    {
                        msgBox.title = qsTr("Error!")
                        msgBox.text = qsTr("User Exists, please select another username!")
                        msgBox.visible = true
                    }
                }
                else
                {
                    msgBox.title = qsTr("Error!")
                    msgBox.text = qsTr("Please Enter Your Information Correctly!")
                    msgBox.visible = true
                }
            }
        }


        Button {
            id: quitBtn
            text: "Quit"
            background: Rectangle {
                color: "#ff0000"
            }
            x: (registerArea.width - quitBtn.width)/2
            y: registerArea.height - default_gap - quitBtn.height
            width: 300
            height: 50
            onClicked: Qt.quit();
        }
    }

     Component.onCompleted: console.log(registerPage.width + " " +mainApp.width);
}
