#include "vehicle.h"
#include <QJsonArray>
#include "factory.h"
#include "analyzer/countkmsanalyzer.h"
#include "analyzer/oilchangeanalyzer.h"

Vehicle::Vehicle(UserPtr owner, QObject *parent) : JsonAble(JsonAbleType::Vehicle, "vehicles", "1", parent)
{
    _name = "";
    _plate = "";
    _brand = "";
    _model = "";
    _year = -1;
    _owner = owner;

    _handleGasCharge = true;
    _handleOilChange = true;
    _handleSparkChange = true;
    _handleBendChange = true;
    _handleGasFilter = true;
    _handleWheelAlign = true;
    _handleWheelPressure = true;
}

Vehicle::Vehicle(QJsonObject &json, QObject *parent) : JsonAble(json, JsonAbleType::Vehicle, "vehicles", "1", parent)
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

    QJsonArray arrayEvts = json["vehicleEvents"].toArray();
    foreach (QJsonValue value, arrayEvts)
    {
        QJsonObject obj = value.toObject();
        VehicleEventPtr ve = qSharedPointerDynamicCast<VehicleEvent>(Factory::create(obj));
        if (!ve.isNull())
            _vehicleEvents[ve->moment()] = ve;
    }

    _handleGasCharge = json["handleGasCharge"].toBool();
    _handleOilChange = json["handleOilChange"].toBool();
    _handleSparkChange = json["handleSparkChange"].toBool();
    _handleBendChange = json["handleBendChange"].toBool();
    _handleGasFilter = json["handleGasFilter"].toBool();
    _handleWheelAlign = json["handleWheelAlign"].toBool();
    _handleWheelPressure = json["handleWheelPressure"].toBool();
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

    QJsonArray arrayEvts;
    foreach (VehicleEventPtr ve, _vehicleEvents.values())
    {
        arrayEvts.append(ve->toJson(true));
    }
    jsonObj["vehicleEvents"] = arrayEvts;

    jsonObj["handleGasCharge"] = _handleGasCharge;
    jsonObj["handleOilChange"] = _handleOilChange;
    jsonObj["handleSparkChange"] = _handleSparkChange;
    jsonObj["handleBendChange"] = _handleBendChange;
    jsonObj["handleGasFilter"] = _handleGasFilter;
    jsonObj["handleWheelAlign"] = _handleWheelAlign;
    jsonObj["handleWheelPressure"] = _handleWheelPressure;
}

void Vehicle::buildJsonID(QJsonObject &jsonObj)
{
}

int Vehicle::currentKms()
{
    CountKmsAnalyzer counter;
    counter.process(0, _vehicleEvents.values());
    return counter.result().toInt();
}

int Vehicle::lastOilChange()
{
    OilChangeAnalyzer analyzer;
    analyzer.process(currentKms(), _vehicleEvents.values());
    return analyzer.lastOilChange();
}

QDateTime Vehicle::lastOilChangeDate()
{
    OilChangeAnalyzer analyzer;
    analyzer.process(currentKms(), _vehicleEvents.values());
    return analyzer.lastOilChangeDate();
}

int Vehicle::nextOilChange()
{
    OilChangeAnalyzer analyzer;
    analyzer.process(currentKms(), _vehicleEvents.values());
    return analyzer.nextOilChange();
}

QDateTime Vehicle::nextOilChangeDate()
{
    OilChangeAnalyzer analyzer;
    analyzer.process(currentKms(), _vehicleEvents.values());
    return analyzer.nextOilChangeDate();
}


void Vehicle::addVehicleEvent(VehicleEventPtr evt)
{
    _vehicleEvents[evt->moment()] = evt;
}

VehicleEventPtr Vehicle::lastOilChangeEvent()
{
    OilChangeAnalyzer analyzer;
    analyzer.process(currentKms(), _vehicleEvents.values());
    return analyzer.lastChangeEvent();
}


bool Vehicle::handleGasCharge() const
{
    return _handleGasCharge;
}

bool Vehicle::handleOilChange() const
{
    return _handleOilChange;
}

bool Vehicle::handleSparkChange() const
{
    return _handleSparkChange;
}

bool Vehicle::handleBendChange() const
{
    return _handleBendChange;
}

bool Vehicle::handleGasFilter() const
{
    return _handleGasFilter;
}

bool Vehicle::handleWheelAlign() const
{
    return _handleWheelAlign;
}

bool Vehicle::handleWheelPressure() const
{
    return _handleWheelPressure;
}

void Vehicle::setHandleGasCharge(bool value)
{
    _handleGasCharge = value;
}

void Vehicle::setHandleOilChange(bool value)
{
    _handleOilChange = value;
}

void Vehicle::setHandleSparkChange(bool value)
{
    _handleSparkChange = value;
}

void Vehicle::setHandleBendChange(bool value)
{
    _handleBendChange = value;
}

void Vehicle::setHandleGasFilter(bool value)
{
    _handleGasFilter = value;
}

void Vehicle::setHandleWheelAlign(bool value)
{
    _handleWheelAlign = value;
}

void Vehicle::setHandleWheelPressure(bool value)
{
    _handleWheelPressure = value;
}
