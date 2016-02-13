#include "jsonable.h"

JsonAble::JsonAble(JsonAbleType type, const QString &collection, const QString objectVersion, QObject *parent) : QObject(parent)
{
    _collection = collection;
    _type = type;
    _id = "";
    _objectVersion = objectVersion;
    _isNew = true;
}

JsonAble::JsonAble(QJsonObject json, JsonAbleType type, const QString &collection, const QString objectVersion, QObject *parent) : QObject(parent)
{
    _collection = collection;
    _id = json["_id"].toObject()["$oid"].toString();
    _type = type;
    _objectVersion = json["version"].toString();
    _isNew = false;
}

QString JsonAble::collection() const
{
    return _collection;
}

JsonAbleType JsonAble::type() const
{
    return _type;
}


QJsonObject JsonAble::toJson(bool includeId)
{
    QJsonObject json;
    if (includeId && !_id.isEmpty())
    {
        QJsonObject jsonId;
        jsonId["$oid"] = _id;
        json["_id"] = jsonId;
    }

    json["type"] = static_cast<int>(_type);
    json["version"] = _objectVersion;
    buildJson(json);
    return json;
}

QJsonObject JsonAble::toJsonID()
{
    QJsonObject json;
    if (!_id.isEmpty())
    {
        QJsonObject jsonId;
        jsonId["$oid"] = _id;
        json["_id"] = jsonId;
    }

    json["type"] = static_cast<int>(_type);
    buildJsonID(json);
    return json;
}

QString JsonAble::id() const
{
    return _id;
}

QString JsonAble::objectVersion() const
{
    return _objectVersion;
}

bool JsonAble::isNew() const
{
    return _isNew;
}
