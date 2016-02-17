#ifndef DLGOILDETAILS_H
#define DLGOILDETAILS_H

#include <QDialog>
#include "entities/vehicle.h"
#include "entities/VehicleEvents/oilchange.h"

namespace Ui {
class DlgOilDetails;
}

class DlgOilDetails : public QDialog
{
    Q_OBJECT

public:
    explicit DlgOilDetails(VehiclePtr vehicle, QWidget *parent = 0);
    ~DlgOilDetails();

private slots:
    void on_btnOilChange_clicked();

private:
    Ui::DlgOilDetails *ui;
    VehiclePtr _vehicle;
    OilChangePtr _lastChange;
};

#endif // DLGOILDETAILS_H
