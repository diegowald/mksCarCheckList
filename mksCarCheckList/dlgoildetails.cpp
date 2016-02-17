#include "dlgoildetails.h"
#include "ui_dlgoildetails.h"
#include <QDateTime>
#include "dlgnewoilchange.h"

DlgOilDetails::DlgOilDetails(VehiclePtr vehicle, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgOilDetails)
{
    ui->setupUi(this);
    _vehicle = vehicle;
    _lastChange = qSharedPointerDynamicCast<OilChange>(vehicle->lastOilChangeEvent());

    if (_lastChange.isNull())
    {
        ui->lblDate->setText(tr("No oil change registered"));
        ui->lblDate->setText(tr("No oil change registered"));
        ui->lblKms->setText(tr("No oil change registered"));
        ui->lblOilBrand->setText(tr("No oil change registered"));
        ui->lblWhere->setText(tr("No oil change registered"));
        ui->lblNextChange->setText(tr("No oil change registered"));
        ui->lblDateNextChange->setText(_vehicle->nextOilChangeDate().toString());
    }
    else
    {
        ui->lblDate->setText(_lastChange->moment().toString());
        ui->lblKms->setText(QString::number(_lastChange->kms()));
        ui->lblOilBrand->setText(_lastChange->brand());
        ui->lblWhere->setText(_lastChange->where());
        ui->lblNextChange->setText(QString("%1 km").arg(_vehicle->nextOilChange()));
        ui->lblDateNextChange->setText(_vehicle->nextOilChangeDate().toString());
    }
}

DlgOilDetails::~DlgOilDetails()
{
    delete ui;
}

void DlgOilDetails::on_btnOilChange_clicked()
{
    OilChangePtr newChange = OilChangePtr::create();
    DlgNewOilChange dlg(_vehicle, newChange, this);
    if (dlg.exec() == QDialog::Accepted)
    {
        _vehicle->addVehicleEvent(newChange);
    }
}
