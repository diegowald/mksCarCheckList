#include "dlgvehicleeditor.h"
#include "ui_dlgvehicleeditor.h"
#include <QDate>

DlgVehicleEditor::DlgVehicleEditor(VehiclePtr vehicle, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgVehicleEditor)
{
    ui->setupUi(this);
    ui->spinYear->setMinimum(1950);
    ui->spinYear->setMaximum(QDate::currentDate().year());

    _vehicle = vehicle;
    ui->txtName->setText(vehicle->name());
    ui->txtBrand->setText(vehicle->brand());
    ui->txtModel->setText(vehicle->model());
    ui->txtPlate->setText(vehicle->plate());
    ui->spinYear->setValue(vehicle->year());

    ui->lblSpinner->clear();
    _spinnerMovie = new QMovie(":/img/spinner");
    ui->lblSpinner->setMovie(_spinnerMovie);
    QString s = "QLabel { background-color : transparent; color : darkred; }";
    ui->lblSpinner->setStyleSheet(s);
    ui->lblSpinner->setVisible(false);

}

DlgVehicleEditor::~DlgVehicleEditor()
{
    delete ui;
}

void DlgVehicleEditor::on_buttonBox_accepted()
{
    _vehicle->setName(ui->txtName->text());
    _vehicle->setBrand(ui->txtBrand->text());
    _vehicle->setModel(ui->txtModel->text());
    _vehicle->setPlate(ui->txtPlate->text());
    _vehicle->setYear(ui->spinYear->value());
    close();
}
