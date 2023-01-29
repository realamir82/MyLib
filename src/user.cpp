#include "../include/user.h"

User::User(QObject *parent):
    User(0,
         "",
         "",
         "",
         "",
         "",
         false,
         false,
         parent)
{

}

User::User(int id,
           QString username,
           QString password,
           QString firstname,
           QString lastname,
           QString birthdate,
           bool isAdmin,
           bool isSuperAdmin,
           QObject *parent):
                QObject(parent),
                _is_admin(isAdmin),
                _is_super_admin(isSuperAdmin)
{
    _id = id;
    setUserName(username);
    setPassword(password);
    setFirstName(firstname);
    setLastName(lastname);
    setBirthDate(birthdate);
}

User::User(QJsonObject jsonObject, QObject *parent):
    User(jsonObject.value("id").toInt(),
         jsonObject.value("username").toString(),
         jsonObject.value("password").toString(),
         jsonObject.value("firstname").toString(),
         jsonObject.value("lastname").toString(),
         jsonObject.value("birthdate").toString(),
         jsonObject.value("admin").toBool(),
         jsonObject.value("superadmin").toBool(),
         parent)
{

}

int User::getUserId()
{
    return _id;
}

void User::setUserName(QString username)
{
    if(username != _user_name)
    {
        _user_name = username;
        emit userChanged_SI();
    }
}

QString User::getUserName()
{
    return _user_name;
}

void User::setPassword(QString password)
{
    if(password != _password)
    {
        _password = password;
        emit userChanged_SI();
    }
}

QString User::getPassword()
{
    return _password;
}

void User::setFirstName(QString firstname)
{
    if(_first_name != firstname)
    {
        _first_name = firstname;
        emit userChanged_SI();
    }
}

QString User::getFirstName()
{
    return _first_name;
}

void User::setLastName(QString lastname)
{
    if(_last_name != lastname)
    {
        _last_name = lastname;
        emit userChanged_SI();
    }
}

QString User::getLastName()
{
    return _last_name;
}

void User::setBirthDate(QString birthdate)
{
    if(_birth_date != birthdate)
    {
        _birth_date = birthdate;
        emit userChanged_SI();
    }
}

QString User::getBitrhDate()
{
    return _birth_date;
}

bool User::getAdminMode()
{
    return _is_admin;
}

bool User::getSuperAdminMode()
{
    return _is_super_admin;
}

QJsonObject User::getInfoJson()
{
    QJsonObject output;
    output.insert("id",this->getUserId());
    output.insert("username",this->getUserName());
    output.insert("password",this->getPassword());
    output.insert("firstname",this->getFirstName());
    output.insert("lastname",this->getLastName());
    output.insert("birthdate",this->getBitrhDate());
    output.insert("admin",this->getAdminMode());
    output.insert("superadmin",this->getSuperAdminMode());
    return output;
}

QString User::getInfoStr()
{
    QJsonObject info_json = getInfoJson();
    QJsonDocument doc(info_json);
    return doc.toJson(QJsonDocument::Compact);
}

void User::userChanged_SL()
{

}


