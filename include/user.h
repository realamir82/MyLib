#ifndef USER_H
#define USER_H

#include<iostream>
using namespace::std;

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class User: public QObject
{
    Q_OBJECT
public:

    ///
    /// \brief User
    /// \param parent
    ///
    explicit User(QObject *parent = nullptr);

    ///
    /// \brief User
    /// \param id
    /// \param username
    /// \param password
    /// \param firstname
    /// \param lastname
    /// \param birthdate
    /// \param isAdmin
    /// \param isSuperAdmin
    /// \param parent
    ///
    explicit User(int id,
                  QString username,
                  QString password,
                  QString firstname,
                  QString lastname,
                  QString birthdate,
                  bool isAdmin,
                  bool isSuperAdmin,
                  QObject *parent = nullptr);

    ///
    /// \brief User
    /// \param jsonObject
    /// \param parent
    ///
    explicit User(QJsonObject jsonObject,
                  QObject *parent = nullptr);

    ///
    /// \brief getUserId
    /// \return
    ///
    int getUserId();

    ///
    /// \brief setUserName
    /// \param username
    ///
    void setUserName(QString username);
    ///
    /// \brief getUserName
    /// \return
    ///
    QString getUserName();

    ///
    /// \brief setPassword
    /// \param password
    ///
    void setPassword(QString password);
    ///
    /// \brief getPassword
    /// \return
    ///
    QString getPassword();

    ///
    /// \brief setFirstname
    /// \param firstname
    ///
    void setFirstName(QString firstname);
    ///
    /// \brief getFirstname
    /// \return
    ///
    QString getFirstName();

    ///
    /// \brief setLastName
    /// \param lastname
    ///
    void setLastName(QString lastname);
    ///
    /// \brief getLastName
    /// \return
    ///
    QString getLastName();
    ///
    /// \brief setBirthdate
    /// \param birthdate
    ///
    void setBirthDate(QString birthdate);
    ///
    /// \brief getBitrhDate
    /// \return
    ///
    QString getBitrhDate();

    ///
    /// \brief getAdminMode
    /// \return
    ///
    bool getAdminMode();

    ///
    /// \brief getSuperAdminMode
    /// \return
    ///
    bool getSuperAdminMode();

    ///
    /// \brief getInfo
    /// \return
    ///
    QString getInfoStr();

    QJsonObject getInfoJson();
Q_SIGNALS:
    ///
    /// \brief userChanged_SI
    ///
    void userChanged_SI ();
public Q_SLOTS:
    ///
    /// \brief userChanged_SL
    ///
    void userChanged_SL();
private:
    ///
    /// \brief _id
    ///
    int _id;
    ///
    /// \brief _user_name
    ///
    QString _user_name;
    ///
    /// \brief _password
    ///
    QString _password;
    ///
    /// \brief _first_name
    ///
    QString _first_name;
    ///
    /// \brief _last_name
    ///
    QString _last_name;
    ///
    /// \brief _birth_date
    ///
    QString _birth_date;

    ///
    /// \brief _is_admin
    ///
    bool _is_admin;

    ///
    /// \brief _is_super_admin
    ///
    bool _is_super_admin;

};

#endif // USER_H
