#include "oilchangecontroller.h"
#include "dlgnewoilchange.h"

OilChangeController::OilChangeController(VehiclePtr vehicle, QObject *parent) : VehicleEventController(vehicle, ":/img/oil", parent)
{

}


QString OilChangeController::text()
{
    QString s =
    "Oil Change\n"
    "Kms: %1, Date: %2\n"
    "Next Change: \n"
    "Kms: %3, Estimated Date:%4";

    return s.arg(vehicle()->lastOilChange())
            .arg(vehicle()->lastOilChangeDate().toString("dd/MM/yyyy"))
            .arg(vehicle()->nextOilChange())
            .arg(vehicle()->nextOilChangeDate().toString("dd/MM/yyyy"));
}

bool OilChangeController::edit()
{
    OilChangePtr oil = OilChangePtr::create();
    DlgNewOilChange dlg(vehicle(), oil);
    if (dlg.exec() == QDialog::Accepted)
    {
        vehicle()->addVehicleEvent(oil);
        return true;
    }
    return false;
}
