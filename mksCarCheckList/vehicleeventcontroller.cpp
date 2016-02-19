#include "vehicleeventcontroller.h"

VehicleEventController::VehicleEventController(VehiclePtr vehicle, QString resourceName, QObject *parent) : QObject(parent)
{
    _resourceName = resourceName;
    _vehicle = vehicle;
}


QString VehicleEventController::resourceName() const
{
    return _resourceName;
}

VehiclePtr VehicleEventController::vehicle() const
{
    return _vehicle;
}
