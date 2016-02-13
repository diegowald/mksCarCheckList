#include "wdgcontroller.h"
#include "ui_wdgcontroller.h"
#include "entities/vehicle.h"
#include "dlgvehicleeditor.h"
#include <QJsonDocument>

WdgController::WdgController(GlobalContainerPtr container, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgController)
{
    ui->setupUi(this);

    ui->lblSpinner->clear();
    _spinnerMovie = new QMovie(":/img/spinner");
    ui->lblSpinner->setMovie(_spinnerMovie);
    QString s = "QLabel { background-color : transparent; color : darkred; }";
    ui->lblSpinner->setStyleSheet(s);
    ui->lblSpinner->setVisible(false);
    _api = MongoClientAPIPtr::create();
    _container = container;

    connect(_api.data(), &MongoClientAPI::added, this, &WdgController::on_added);
    connect(_api.data(), &MongoClientAPI::updated, this, &WdgController::on_updated);
    connect(_api.data(), &MongoClientAPI::deleted, this, &WdgController::on_deleted);
}

WdgController::~WdgController()
{
    delete ui;
}

void WdgController::on_toolButton_clicked()
{
    VehiclePtr vehicle = VehiclePtr::create(_container->owner());
    DlgVehicleEditor dlg(vehicle);
    dlg.exec();
    startSpinner();
    _api->add(vehicle);
}

void WdgController::startSpinner()
{
    ui->lblSpinner->setVisible(true);
    _spinnerMovie->start();
}

void WdgController::stopSpinner()
{
    _spinnerMovie->stop();
    ui->lblSpinner->setVisible(false);
}

void WdgController::on_added(QJsonDocument &json, MongoClientAPI::Status status)
{
    stopSpinner();
    QJsonObject jsonObj = json.object();
    _container->addEntity(jsonObj);
    if (status == MongoClientAPI::Status::OK)
    {
        emit vehicleAdded();
    }
}

void WdgController::on_updated(QJsonDocument &json, MongoClientAPI::Status status)
{
    stopSpinner();
}

void WdgController::on_deleted(QJsonDocument &json, MongoClientAPI::Status status)
{
    stopSpinner();
}
