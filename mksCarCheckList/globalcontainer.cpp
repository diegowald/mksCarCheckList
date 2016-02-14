#include "globalcontainer.h"
#include <QDebug>
#include "entities/user.h"
#include "entities/vehicle.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include "factory.h"

GlobalContainer::GlobalContainer(QObject *parent) : QObject(parent)
{
    _idOwner = "";
}

void GlobalContainer::initialize(const QString &filename)
{
    /*_fileDataLocation = QString("%1/%2")
            .arg(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation))
            .arg("data.json");
    if (!_fileDataLocation.isEmpty())*/
    _filename = filename;
    if (!filename.isEmpty())
    {
        QFile jsonFile(filename);
        if (jsonFile.exists())
        {
            jsonFile.open(QFile::ReadOnly);
            QJsonDocument jsonDoc = QJsonDocument().fromJson(jsonFile.readAll());
            foreach (QJsonValue value, jsonDoc.array())
            {
                QJsonObject json = value.toObject();
                addEntity(json);
            }
        }
    }
}

void GlobalContainer::finalize()
{
    QFile jsonFile(_filename);
    jsonFile.open(QFile::WriteOnly);

    QJsonDocument json2Write;
    QJsonArray array;
    foreach (JsonAblePtr element, _entities.values())
    {
        array.append(element->toJson(true));
    }
    json2Write.setArray(array);

    //jsonFile.write(jsonDoc.toJson());
    jsonFile.write(json2Write.toJson());
    jsonFile.close();
}

void GlobalContainer::addEntity(QJsonObject &obj)
{
    JsonAblePtr entity = Factory::create(obj);
    if (!entity.isNull())
        addEntity(entity);
}

void GlobalContainer::addEntity(JsonAblePtr entity)
{
    _entities[entity->id()] = entity;
    switch (entity->type())
    {
    case JsonAbleType::User:
        _idOwner = entity->id();
        break;
    case JsonAbleType::Vehicle:
        break;
    case JsonAbleType::VehicleEvent:
        break;
    default:
        break;
    }
}

bool GlobalContainer::isRegistered() const
{
    return !_idOwner.isEmpty();
}

UserPtr GlobalContainer::owner()
{
    UserPtr user;
    if (!_idOwner.isEmpty())
        user = qSharedPointerDynamicCast<User>(_entities[_idOwner]);
    return user;
}

QList<JsonAblePtr> GlobalContainer::vehicles()
{
    QList<JsonAblePtr> result;
    foreach (JsonAblePtr entity, _entities.values())
    {
        if (entity->type() == JsonAbleType::Vehicle)
        {
            result.append(entity);
        }
    }
    return result;
}
