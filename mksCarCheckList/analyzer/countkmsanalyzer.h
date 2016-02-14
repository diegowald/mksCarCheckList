#ifndef COUNTKMSANALYZER_H
#define COUNTKMSANALYZER_H

#include "analyzer/vehicleeventanalyzer.h"

class CountKmsAnalyzer : public VehicleEventAnalyzer
{
    Q_OBJECT
public:
    explicit CountKmsAnalyzer(QObject *parent = 0);

signals:

public slots:

    // VehicleEventAnalyzer interface
public:
    virtual void process(int currentKms, QList<VehicleEventPtr> vehicleEvents);
    virtual QVariant result();

private:
    VehicleEventPtr _element;
};

#endif // COUNTKMSANALYZER_H
