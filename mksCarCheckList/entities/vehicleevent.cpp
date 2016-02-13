#include "vehicleevent.h"

VehicleEvent::VehicleEvent(VehicleEventType type, QObject *parent) : JsonAble(JsonAbleType::VehicleEvent, "", "1", parent)
{
    _type = type;
}
