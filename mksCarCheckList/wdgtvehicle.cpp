#include "wdgtvehicle.h"
#include "ui_wdgtvehicle.h"

WdgtVehicle::WdgtVehicle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgtVehicle)
{
    ui->setupUi(this);
}

WdgtVehicle::~WdgtVehicle()
{
    delete ui;
}
