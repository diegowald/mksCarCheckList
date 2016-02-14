#include "countkmsanalyzer.h"
#include "entities/VehicleEvents/countkms.h"

CountKmsAnalyzer::CountKmsAnalyzer(QObject *parent) : VehicleEventAnalyzer(parent)
{
}


void CountKmsAnalyzer::process(int currentKms, QList<VehicleEventPtr> vehicleEvents)
{
    int kms = currentKms;
    foreach (VehicleEventPtr ve, vehicleEvents)
    {
        CountKmsPtr ckms = qSharedPointerDynamicCast<CountKms>(ve);
        if (!ckms.isNull())
        {
            int value = ckms->kms();
            if (kms < value)
            {
                kms =  value;
                _element = ckms;
            }
        }
    }
}


QVariant CountKmsAnalyzer::result()
{
    return _element.isNull() ? -1 : _element->kms();
}
