#ifndef DLGNEWOILCHANGE_H
#define DLGNEWOILCHANGE_H

#include <QDialog>
#include "entities/vehicle.h"
#include "entities/VehicleEvents/oilchange.h"


namespace Ui {
class DlgNewOilChange;
}

class DlgNewOilChange : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewOilChange(VehiclePtr vehicle, OilChangePtr oilChange, QWidget *parent = 0);
    ~DlgNewOilChange();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgNewOilChange *ui;
    VehiclePtr _vehicle;
    OilChangePtr _oilChange;
};

#endif // DLGNEWOILCHANGE_H
