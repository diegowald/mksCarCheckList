#ifndef OILCHANGEANALYZER_H
#define OILCHANGEANALYZER_H

#include "analyzer/vehicleeventanalyzer.h"

class OilChangeAnalyzer : public VehicleEventAnalyzer
{
    Q_OBJECT
public:
    explicit OilChangeAnalyzer(QObject *parent = 0);

    int lastOilChange();
    QDateTime lastOilChangeDate();
    int nextOilChange();
    VehicleEventPtr lastChangeEvent();
    QDateTime nextOilChangeDate();
signals:

public slots:

    // VehicleEventAnalyzer interface
public:
    virtual void process(int currentKms, QList<VehicleEventPtr> vehicleEvents);
    virtual QVariant result();

    VehicleEventPtr _lastChangeEvent;
    int _currentKms;
    int _oilLifeSpan;
};

#endif // OILCHANGEANALYZER_H
