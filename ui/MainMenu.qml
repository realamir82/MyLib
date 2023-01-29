import QtQuick 2.15
import QtQuick.Controls 2.15

import "./Component" as Controls


Item {
    id:  mainPage

    anchors.fill: parent

    Rectangle {
        id: mainArea
        color: "gray"
        width: mainApp.width * 0.8
        height: mainApp.height * 0.8
        x: (mainApp.width - mainArea.width)/2
        y: (mainApp.height - mainArea.height)/2
        radius: 15

        Text {
            id: title
            text: qsTr("Main Page")
            color: "white"
            font.pixelSize: 30
            font.bold: true
            x: (mainArea.width -  title.width)/2
            y: default_gap
        }

        Button {
            id: myBorrowedBooks
            text: "My Borrowed Books"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  myBorrowedBooks.width)/2
            y: title.y + title.height + default_gap
        }

        Button {
            id: searchAndBorrowBook
            text: "Search & Borrow Book"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  searchAndBorrowBook.width)/2
            y:  myBorrowedBooks.y + myBorrowedBooks.height + default_gap
        }

        Button {
            id: addEditRemoveBook
            text: "Add-Edit-Remove Book"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  addEditRemoveBook.width)/2
            y: searchAndBorrowBook.y + searchAndBorrowBook.height + default_gap
        }

        Button {
            id: manageAdminUsers
            text: "Manage Admin Users"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  manageAdminUsers.width)/2
            y: addEditRemoveBook.y + addEditRemoveBook.height + default_gap
        }

        Button {
            id: logOutBtn
            text: "Log Out"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  logOutBtn.width)/2
            y: manageAdminUsers.y + manageAdminUsers.height + default_gap
            onClicked: {
                user_manager.logOut();
                loadPage("LoginPage");
            }
        }

        Button {
            id: quitBtn
            text: "Quit"
            width: mainArea.width/2 - 2 * default_gap;
            height: 50
            x: (mainArea.width -  quitBtn.width)/2
            y: logOutBtn.y + logOutBtn.height + default_gap
            background: Rectangle {
                color: "#ff0000"
            }
            onClicked: Qt.quit();
        }
    }
}
