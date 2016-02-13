#include "wdgtvehicle.h"
#include "ui_wdgtvehicle.h"
#include "dlgvehicleeditor.h"

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
