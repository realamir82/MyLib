#include "../include/dbmanager.h"

DBManager::DBManager(QObject *parent):
    QObject(parent),
    _inited(false)

{

}

bool DBManager::init()
{
    if (!this->isInited())
    {
        _inited =  true;
        this->loadData();
        return true;
    }
    return false;
}

bool DBManager::isInited()
{
    return _inited;
}

bool DBManager::loadData()
{
    if (this->isInited())
    {
        QFile file(QDir().absoluteFilePath(QString(PROJECT_ASSETS_DIR) + QString(PROJECT_DATA_FILE_NAME)));
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = file.readAll();
        file.close();

        QJsonParseError errorPtr;
        _db = QJsonDocument::fromJson(data,&errorPtr);

        if (errorPtr.error == 0)
        {
           return true;
        }
        qDebug()<<"please fix data.json file!";
        return false;
    }

    qDebug()<<"please init this db manager object!";
    return false;
}

bool DBManager::saveDate()
{
    if (!this->isInited() || _db.isEmpty() || _db.isNull())
    {
        qDebug()<<"please init this db manager object!";
    }
    else
    {
        QFile file(QDir().absoluteFilePath(QString(PROJECT_ASSETS_DIR) + QString(PROJECT_DATA_FILE_NAME)));
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        file.write(_db.toJson());
        return true;
    }
    return false;
}

QJsonObject DBManager::getDataById(QString category,
                                   uint id)
{
    QJsonObject output;
    int counter = 0;
    if (!this->isInited())
    {
        qDebug()<<"please init this db manager object!";
    }
    else
    {
        QJsonObject root_obj = _db.object();
        if (category.trimmed() != "" && id > 0)
        {
            auto infoObject = root_obj.value(category); //users , books , borrowedbooks
            if (infoObject.isNull() || infoObject.isUndefined())
            {
                return output;
            }
            else
            {
                QJsonArray dataArray = infoObject.toArray();
                foreach(const QJsonValue & item, dataArray)
                {
                    if (QString::number(id) == item.toObject().value("id").toString().trimmed())
                    {
                       output = (_db.object().value(category).toArray())[counter].toObject();
                       return output;
                    }
                    counter++;
                }
            }
        }
    }
    return output;
}

QVector<QJsonObject> DBManager::getDataCollectionByPropertyValue(QString category,
                                                                 QString property ,
                                                                 QVariant value)
{
    QVector<QJsonObject> output;
    if (!this->isInited())
    {
        qDebug()<<"please init this db manager object!";
        return output;
    }
    else
    {
        if (category.trimmed() != "" &&
                property.trimmed() != "" &&
                value != NULL)
        {
            QString strVal = value.toString();
            QJsonObject root_obj = _db.object();
            auto infoObject = root_obj.value(category); //users , books , borrowedbooks

            if (!infoObject.isNull() && !infoObject.isUndefined())
            {
                QJsonArray dataArray = infoObject.toArray();
                foreach(const QJsonValue & item, dataArray)
                {
                    auto property_value = item.toObject().value(property);
                    if (!property_value.isNull() && !property_value.isUndefined())
                    {
                        if (property_value.toString() == strVal)
                        {
                            output.push_back(item.toObject());
                        }
                    }
                }
            }
        }
    }
    return output;
}

QVector<QJsonObject> DBManager::getDataCollectionContainsStrPropertyValue(QString category,
                                                                          QString property,
                                                                          QString value)
{
    QVector<QJsonObject> output;
    if (!this->isInited())
    {
        qDebug()<<"please init this db manager object!";
        return output;
    }
    else
    {
        if (category.trimmed() != "" &&
                property.trimmed() != "" &&
                value != "")
        {
            QJsonObject root_obj = _db.object();
            auto infoObject = root_obj.value(category); //users , books , borrowedbooks

            if (!infoObject.isNull() && !infoObject.isUndefined())
            {
                QJsonArray dataArray = infoObject.toArray();
                foreach(const QJsonValue & item, dataArray)
                {
                    auto property_value = item.toObject().value(property);
                    if (!property_value.isNull() && !property_value.isUndefined())
                    {
                        if (property_value.toString().contains(value))
                        {

                            output.push_back(item.toObject());
                        }
                    }
                }
            }
        }
    }
    return output;
}

bool DBManager::insertNewDataForce(QString category,
                              QJsonObject& data)
{
    if (!this->isInited())
    {
        qDebug()<<"please init this db manager object!";
    }
    else
    {
        if (category.trimmed() != "" &&
                !data.isEmpty())
        {
            QJsonObject root_obj = _db.object();
            auto cat_array = root_obj[category]; //users , books , borrowedbooks

            if (!cat_array.isNull() && !cat_array.isUndefined())
            {
                QJsonArray dataArray = cat_array.toArray();
                int last_id = dataArray[dataArray.count()-1].toObject().value("id").toInt();
                data["id"] = last_id + 1;
                dataArray.append(data);
                root_obj[category] = dataArray;
                _db.setObject(root_obj);

                return saveDate();
            }
        }
    }
    return false;
}

void DBManager::setData(QString category,
                        QString property,
                        QVariant value)
{

}

