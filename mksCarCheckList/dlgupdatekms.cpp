#include "dlgupdatekms.h"
#include "ui_dlgupdatekms.h"

DlgUpdateKms::DlgUpdateKms(VehiclePtr vehicle, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUpdateKms)
{
    ui->setupUi(this);

    _vehicle = vehicle;
    _counter = CountKmsPtr::create();
    _counter->setMoment(QDateTime::currentDateTime());
    _counter->setKms(_vehicle->currentKms());

    ui->date->setDateTime(_counter->moment());
    ui->spinKms->setMinimum(_counter->kms());
    ui->spinKms->setMaximum(_counter->kms() + 10000);
    ui->spinKms->setValue(_counter->kms());
}

DlgUpdateKms::~DlgUpdateKms()
{
    delete ui;
}

void DlgUpdateKms::on_buttonBox_accepted()
{
    QDateTime dt = ui->date->dateTime();

    _counter->setMoment(dt);
    _counter->setKms(ui->spinKms->value());

    _vehicle->addVehicleEvent(_counter);

    close();
}
