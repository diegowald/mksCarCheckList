#include "vehicleevent.h"

VehicleEvent::VehicleEvent(VehicleEventType type, QObject *parent) : JsonAble(JsonAbleType::VehicleEvent, "", "1", parent)
{
    _evtType = type;
    _moment = QDateTime::currentDateTime();
    _kms = 0;
    _name = "";
    _description = "";
}

VehicleEvent::VehicleEvent(QJsonObject &json, QObject *parent) : JsonAble(json, JsonAbleType::VehicleEvent, "", "1", parent)
{
    _moment = QDateTime::fromMSecsSinceEpoch(json["datetime"].toInt());
    _kms = json["kms"].toInt();
    _name = json["name"].toString();
    _description = json["description"].toString();
    _evtType = static_cast<VehicleEventType>(json["eventType"].toInt());
}


void VehicleEvent::buildJson(QJsonObject &jsonObj)
{
    jsonObj["datetime"] = _moment.toMSecsSinceEpoch();
    jsonObj["kms"] = _kms;
    jsonObj["name"] = _name;
    jsonObj["description"] = _description;
    jsonObj["eventType"] = static_cast<int>(_evtType);
}

void VehicleEvent::buildJsonID(QJsonObject &jsonObj)
{
}


QDateTime VehicleEvent::moment() const
{
    return _moment;
}

int VehicleEvent::kms() const
{
    return _kms;
}

QString VehicleEvent::name() const
{
    return _name;
}

QString VehicleEvent::description() const
{
    return _description;
}

VehicleEventType VehicleEvent::evtType() const
{
    return _evtType;
}

void VehicleEvent::setMoment(QDateTime &value)
{
    _moment = value;
}

void VehicleEvent::setKms(int value)
{
    _kms = value;
}

void VehicleEvent::setName(const QString &value)
{
    _name = value;
}

void VehicleEvent::setDescription(const QString &value)
{
    _description = value;
}

void VehicleEvent::setEventType(VehicleEventType value)
{
    _evtType = value;
}
