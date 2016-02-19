#include "wdgtvehicle.h"
#include "ui_wdgtvehicle.h"
#include "dlgvehicleeditor.h"
#include "dlgupdatekms.h"
#include "dlgoildetails.h"
#include "qtaplistwidget.h"
#include "entities/vehicleevent.h"
#include "vehicleeventlistwidget.h"

WdgtVehicle::WdgtVehicle(GlobalContainerPtr container,
                         VehiclePtr vehicle, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgtVehicle)
{
    ui->setupUi(this);
    _vehicle = vehicle;
    _api = MongoClientAPIPtr::create();
    _container = container;


    //VehicleEventListWidget *item = new VehicleEventListWidget()
    //if (vehicle->handleGasCharge())
    if (vehicle->handleOilChange())
    {
        _oilChangeCtrller = new OilChangeController(_vehicle, this);
        VehicleEventListWidget *item = new VehicleEventListWidget(_oilChangeCtrller);
        ui->listWidget->insertItem(0, item);
    }

/*    QListWidgetItem *item = new QListWidgetItem("hola");
    item->setData(Qt::UserRole, QVariant(static_cast<int>(VehicleEventType::BendChange)));
    ui->listWidget->insertItem(0, "Hola\nMundo");
    ui->listWidget->insertItem(1, "Hola\nMundo 2");
    ui->listWidget->insertItem(2, item);*/

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
    ui->listWidget->update();
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

