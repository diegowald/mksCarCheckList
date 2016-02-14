#include "oilchangeanalyzer.h"

OilChangeAnalyzer::OilChangeAnalyzer(QObject *parent) : VehicleEventAnalyzer(parent)
{
    _oilLifeSpan = 5000;
}

int OilChangeAnalyzer::lastOilChange()
{
    return (_lastChangeEvent.isNull()) ? 0 : _lastChangeEvent->kms();
}

QDateTime OilChangeAnalyzer::lastOilChangeDate()
{
    return (_lastChangeEvent.isNull()) ? QDateTime(QDate(0, 0, 0), QTime(0, 0, 0)) : _lastChangeEvent->moment();
}

int OilChangeAnalyzer::nextOilChange()
{
    return (lastOilChange() == 0) ? _currentKms : lastOilChange() + _oilLifeSpan;
}


void OilChangeAnalyzer::process(int currentKms, QList<VehicleEventPtr> vehicleEvents)
{
    int kms = 0;
    foreach (VehicleEventPtr evt, vehicleEvents)
    {
        if (evt->evtType() == VehicleEventType::ChangeOil)
        {
            int value = evt->kms();
            if (kms < value)
            {
                kms = value;
                _lastChangeEvent = evt;
            }
        }
    }
}

QVariant OilChangeAnalyzer::result()
{
    return _lastChangeEvent->kms();
}
