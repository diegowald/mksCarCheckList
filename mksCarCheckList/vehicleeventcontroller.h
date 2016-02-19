#ifndef VEHICLEEVENTCONTROLLER_H
#define VEHICLEEVENTCONTROLLER_H

#include <QObject>
#include "entities/vehicle.h"

class VehicleEventController : public QObject
{
    Q_OBJECT
public:
    explicit VehicleEventController(VehiclePtr vehicle, QString resourceName, QObject *parent = 0);

    QString resourceName() const;
    virtual QString text() = 0;
    virtual bool edit() = 0;

protected:
    VehiclePtr vehicle() const;

signals:

public slots:

private:
    QString _resourceName;
    VehiclePtr _vehicle;
};

#endif // VEHICLEEVENTCONTROLLER_H
