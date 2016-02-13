#ifndef VEHICLEEVENT_H
#define VEHICLEEVENT_H

#include <entities/jsonable.h>
#include <QDateTime>


enum class VehicleEventType
{
};

class VehicleEvent : public JsonAble
{
    Q_OBJECT
public:
    explicit VehicleEvent(VehicleEventType type, QObject *parent = 0);

signals:

public slots:

private:
    QDateTime _moment;
    int _kms;
    QString _name;
    QString _description;
    VehicleEventType _type;
};

typedef QSharedPointer<VehicleEvent> VehicleEventPtr;

#endif // VEHICLEEVENT_H
