#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QVector>
#include <QJsonObject>
#include "user.h"
#include "dbmanager.h"

class UserManager : public QObject
{
    Q_OBJECT
public:
    ///
    /// \brief UserManager
    /// \param dbManager
    /// \param parent
    ///
    explicit UserManager(DBManager *dbManager,
                         QObject *parent = nullptr);

    ///
    /// \brief registerUser
    /// \param username
    /// \param password
    /// \param firstname
    /// \param lastname
    /// \param birthdate
    /// \return
    ///
  Q_INVOKABLE bool registerUser(QString username,
                                QString password,
                                QString firstname,
                                QString lastname,
                                QString birthdate);

    ///
    /// \brief loginUser
    /// \param userName
    /// \param password
    /// \return
    ///
    Q_INVOKABLE bool loginUser(QString userName,
                                QString password);

    ///
    /// \brief logOut
    /// \return
    ///
    Q_INVOKABLE bool logOut();

    ///
    /// \brief getCurrentUser
    /// \return
    ///
    User* getCurrentUser();

signals:
private:
    DBManager* _db_manager;
    User* _current_user;
};

#endif // USERMANAGER_H
