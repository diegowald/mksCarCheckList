#include "factory.h"
#include "entities/user.h"
#include "entities/vehicle.h"

JsonAblePtr Factory::create(QJsonObject &obj)
{
    JsonAbleType type = static_cast<JsonAbleType>(obj["type"].toInt());
    JsonAblePtr entity;
    bool created = false;
    switch (type)
    {
    case JsonAbleType::User:
        entity = UserPtr::create(obj);
        created = true;
        break;
    case JsonAbleType::Vehicle:
        entity = VehiclePtr::create(obj);
        created = true;
        break;
    case JsonAbleType::VehicleEvent:
        break;
    default:
        break;
    }
    if (!created)
       entity = JsonAblePtr();
    return entity;
}
