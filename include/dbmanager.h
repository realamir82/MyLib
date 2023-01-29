#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QVector>

#include "config.h"

///
/// \brief The DBManager class
///
class DBManager: public QObject
{
    Q_OBJECT
public:
    ///
    /// \brief DBManager
    /// \param parent
    ///
    DBManager(QObject* parent = nullptr);

    ///
    /// \brief init
    /// \return
    ///
    bool init();

    ///
    /// \brief isInited
    /// \return
    ///
    bool isInited();

    ///
    /// \brief loadData
    /// \return
    ///
    bool loadData();

    ///
    /// \brief saveDate
    /// \return
    ///
    bool saveDate();

    ///
    /// \brief getDataById
    /// \param category
    /// \param id
    /// \return
    ///
    QJsonObject getDataById(QString category,uint id);

    ///
    /// \brief getDataCollectionByPropertyValue
    /// \param category
    /// \param property
    /// \param value
    /// \return
    ///
    QVector<QJsonObject> getDataCollectionByPropertyValue(QString category, QString property, QVariant value);

    ///
    /// \brief getDataCollectionContainsStrPropertyValue
    /// \param category
    /// \param property
    /// \param value
    /// \return
    ///
    QVector<QJsonObject> getDataCollectionContainsStrPropertyValue(QString category, QString property, QString value);

    ///
    /// \brief insertNewDataForce
    /// \param category
    /// \param data
    /// \return
    ///
    bool insertNewDataForce(QString category, QJsonObject& data);

    ///
    /// \brief setData
    /// \param category
    /// \param property
    /// \param value
    ///
    void setData(QString category, QString property, QVariant value);
private:
    ///
    /// \brief _inited
    ///
    bool _inited;

    ///
    /// \brief _db
    ///
    QJsonDocument _db;
};

#endif // DBMANAGER_H
