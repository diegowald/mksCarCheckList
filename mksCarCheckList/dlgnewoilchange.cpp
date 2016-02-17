#include "dlgnewoilchange.h"
#include "ui_dlgnewoilchange.h"

DlgNewOilChange::DlgNewOilChange(VehiclePtr vehicle, OilChangePtr oilChange, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewOilChange)
{
    ui->setupUi(this);
    _vehicle = vehicle;
    _oilChange = oilChange;

    ui->date->setDateTime(_oilChange->moment());
    ui->spinKms->setMinimum(_vehicle->lastOilChange());
    ui->spinKms->setMaximum(_vehicle->currentKms() + 30000);
    ui->spinKms->setValue(_vehicle->currentKms());
    ui->txtBrand->setText(_oilChange->brand());
    ui->txtQuantity->setText(QString::number(_oilChange->quantity()));
    ui->txtWhere->setText(_oilChange->where());
}

DlgNewOilChange::~DlgNewOilChange()
{
    delete ui;
}

void DlgNewOilChange::on_buttonBox_accepted()
{
    _oilChange->setMoment(ui->date->dateTime());
    _oilChange->setKms(ui->spinKms->value());
    _oilChange->setBrand(ui->txtBrand->text());
    _oilChange->setQuantity(ui->txtQuantity->text().toInt());
    _oilChange->setWhere(ui->txtWhere->text());

    close();
}
