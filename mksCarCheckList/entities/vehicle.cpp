#include "vehicle.h"
#include <QJsonArray>


Vehicle::Vehicle(UserPtr owner, QObject *parent) : JsonAble(JsonAbleType::Vehicle, "vehicles", "1", parent)
{
    _name = "";
    _plate = "";
    _brand = "";
    _model = "";
    _year = -1;
    _owner = owner;
}

Vehicle::Vehicle(QJsonObject &json, QObject *parent) : JsonAble(JsonAbleType::Vehicle, "vehicles", "1", parent)
{
    _name = json["name"].toString();
    _plate = json["plate"].toString();
    _brand = json["brand"].toString();
    _model = json["model"].toString();
    _year = json["year"].toInt();

    QJsonObject obj = json["owner"].toObject();
    _owner = UserPtr::create(obj);


    QJsonArray array = json["others"].toArray();
    foreach (QJsonValue value, array)
    {
        QJsonObject obj = value.toObject();
        UserPtr user = UserPtr::create(obj);
        _others.append(user);
    }
}

QString Vehicle::name() const
{
    return _name;
}

QString Vehicle::plate() const
{
    return _plate;
}

QString Vehicle::brand() const
{
    return _brand;
}

QString Vehicle::model() const
{
    return _model;
}

int Vehicle::year() const
{
    return _year;
}

void Vehicle::setName(const QString &value)
{
    _name = value;
}

void Vehicle::setPlate(const QString &value)
{
    _plate = value;
}

void Vehicle::setBrand(const QString &value)
{
    _brand = value;
}

void Vehicle::setModel(const QString &value)
{
    _model = value;
}

void Vehicle::setYear(int value)
{
    _year = value;
}


void Vehicle::buildJson(QJsonObject &jsonObj)
{
    jsonObj["name"] = _name;
    jsonObj["plate"] = _plate;
    jsonObj["brand"] = _brand;
    jsonObj["model"] = _model;
    jsonObj["year"] = _year;

    jsonObj["owner"] = _owner->toJsonID();
    QJsonArray array;
    foreach (UserPtr user, _others)
    {
        array.append(user->toJsonID());
    }
    jsonObj["others"] = array;
}

void Vehicle::buildJsonID(QJsonObject &jsonObj)
{
}
