#ifndef FACOTRY_H
#define FACOTRY_H

#include "entities/jsonable.h"

class Factory
{
public:
    static JsonAblePtr create(QJsonObject &obj);

};

#endif // FACOTRY_H
