#include "wdgtvehicle.h"
#include "ui_wdgtvehicle.h"
#include "dlgvehicleeditor.h"
#include "dlgupdatekms.h"
#include "dlgoildetails.h"

WdgtVehicle::WdgtVehicle(GlobalContainerPtr container,
                         VehiclePtr vehicle, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgtVehicle)
{
    ui->setupUi(this);
    _vehicle = vehicle;
    _api = MongoClientAPIPtr::create();
    _container = container;
    refreshUI();
}

WdgtVehicle::~WdgtVehicle()
{
    delete ui;
}

void WdgtVehicle::refreshUI()
{
    ui->lblBrand->setText(_vehicle->brand());
    ui->lblModel->setText(_vehicle->model());
    ui->lblNombre->setText(_vehicle->name());
    ui->lblPlate->setText(_vehicle->plate());
    ui->lblYear->setText(QString::number(_vehicle->year()));

    QString s = "%1 km";
    ui->lblCurrentKms->setText(s.arg(_vehicle->currentKms()));
    s = "%1 km\n(%2)";
    ui->lblLastOilChange->setText(s.arg(_vehicle->lastOilChange())
                                  .arg(_vehicle->lastOilChangeDate().toString()));
    s = "%1 km";
    ui->lblNextOilChange->setText(s.arg(_vehicle->nextOilChange()));
}

void WdgtVehicle::on_toolButton_clicked()
{
    DlgVehicleEditor dlg(_vehicle);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (_vehicle->isNew())
        {
            _api->add(_vehicle);
        }
        else
        {
            _api->update(_vehicle);
        }
    }
    refreshUI();
}

void WdgtVehicle::on_btnUpdateKms_clicked()
{
    DlgUpdateKms dlg(_vehicle);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (_vehicle->isNew())
        {
            _api->add(_vehicle);
        }
        else
        {
            _api->update(_vehicle);
        }
    }
    refreshUI();
}

void WdgtVehicle::on_btnOilDetails_clicked()
{
    DlgOilDetails dlg(_vehicle);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (_vehicle->isNew())
        {
            _api->add(_vehicle);
        }
        else
        {
            _api->update(_vehicle);
        }
    }
    refreshUI();
}
