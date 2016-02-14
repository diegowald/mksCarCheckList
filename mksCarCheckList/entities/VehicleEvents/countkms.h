#ifndef COUNTKMS_H
#define COUNTKMS_H

#include <QObject>
#include "entities/vehicleevent.h"


class CountKms : public VehicleEvent
{
    Q_OBJECT
public:
    explicit CountKms(QObject *parent = 0);

signals:

public slots:
};

typedef QSharedPointer<CountKms> CountKmsPtr;

#endif // COUNTKMS_H
