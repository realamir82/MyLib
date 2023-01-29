#include "../include/usermanager.h"

UserManager::UserManager(DBManager* dbManager,
                         QObject *parent)
    : QObject{parent},
      _db_manager(dbManager),
      _current_user(nullptr)
{}

bool UserManager::registerUser(QString username,
                               QString password,
                               QString firstname,
                               QString lastname,
                               QString birthdate)
{
    if (_db_manager != nullptr &&
            _current_user == nullptr &&
            username != "" &&
            password != "" &&
            firstname != "" &&
            lastname != "" &&
            birthdate != "")
    {
        auto users = _db_manager->getDataCollectionByPropertyValue("users",
                                                                   "username",
                                                                   username);
        if (users.count() == 0)
        {
            QJsonObject newUserJson;
            newUserJson["username"] = username;
            newUserJson["password"] = password;
            newUserJson["firstname"] = firstname;
            newUserJson["lastname"] = lastname;
            newUserJson["birthdate"] = birthdate;
            newUserJson["admin"] = false;
            newUserJson["superadmin"] = false;

            if (_db_manager->insertNewDataForce("users",newUserJson) == true)
            {
                _current_user = new User(newUserJson,this);
                qDebug()<<"@@@@@@@@@ " << newUserJson["id"].toInt() << " " << _current_user->getUserId();
                return true;
            }
        }

    }
    return false;
}

bool UserManager::loginUser(QString userName,
                            QString password)
{
    if (_db_manager != nullptr && _current_user == nullptr)
    {
        auto users = _db_manager->getDataCollectionByPropertyValue("users",
                                                                   "username",
                                                                   userName);
        if (users.count() == 1)
        {
            if (_current_user != nullptr)
            {
                _current_user->deleteLater();
            }
            if (users[0].value("password").toString() == password)
            {
                _current_user=new User(users[0],this);
                return true;
            }
        }
    }
    return false;
}

bool UserManager::logOut()
{
    if (_db_manager != nullptr && _current_user != nullptr)
    {
        _current_user->deleteLater();
        _current_user = nullptr;
        return true;
    }
    return false;
}

User *UserManager::getCurrentUser()
{
    return _current_user;
}
