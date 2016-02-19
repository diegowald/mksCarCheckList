#ifndef OILCHANGECONTROLLER_H
#define OILCHANGECONTROLLER_H

#include "vehicleeventcontroller.h"

class OilChangeController : public VehicleEventController
{
    Q_OBJECT
public:
    explicit OilChangeController(VehiclePtr vehicle, QObject *parent = 0);

signals:

public slots:

    // VehicleEventController interface
public:
    virtual QString text();
    virtual bool edit();
};

#endif // OILCHANGECONTROLLER_H
