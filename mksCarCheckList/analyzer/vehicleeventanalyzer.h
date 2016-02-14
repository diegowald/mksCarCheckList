#ifndef VEHICLEEVENTANALYZER_H
#define VEHICLEEVENTANALYZER_H

#include <QObject>
#include <entities/vehicleevent.h>
#include <QVariant>


class VehicleEventAnalyzer : public QObject
{
    Q_OBJECT
public:
    explicit VehicleEventAnalyzer(QObject *parent = 0);
    virtual void process(int currentKms, QList<VehicleEventPtr> vehicleEvents) = 0;
    virtual QVariant result() = 0;
signals:

public slots:
};

#endif // VEHICLEEVENTANALYZER_H
