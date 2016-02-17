#include "oilchange.h"

OilChange::OilChange(QObject *parent) :  VehicleEvent(VehicleEventType::ChangeOil, parent)
{
    _brand = "";
    _where = "";
    _quantity = 0;
}

QString OilChange::brand() const
{
    return _brand;
}

QString OilChange::where() const
{
    return _where;
}

int OilChange::quantity() const
{
    return _quantity;
}

void OilChange::setBrand(const QString &value)
{
    _brand = value;
}

void OilChange::setWhere(const QString &value)
{
    _where = value;
}

void OilChange::setQuantity(int value)
{
    _quantity = value;
}
