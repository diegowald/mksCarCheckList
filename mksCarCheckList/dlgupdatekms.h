#ifndef DLGUPDATEKMS_H
#define DLGUPDATEKMS_H

#include <QDialog>
#include "entities/vehicle.h"
#include "entities/VehicleEvents/countkms.h"

namespace Ui {
class DlgUpdateKms;
}

class DlgUpdateKms : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUpdateKms(VehiclePtr vehicle, QWidget *parent = 0);
    ~DlgUpdateKms();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgUpdateKms *ui;

    VehiclePtr _vehicle;
    CountKmsPtr _counter;
};

#endif // DLGUPDATEKMS_H
