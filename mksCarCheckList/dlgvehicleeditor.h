#ifndef DLGVEHICLEEDITOR_H
#define DLGVEHICLEEDITOR_H

#include <QDialog>
#include "entities/vehicle.h"
#include <QMovie>


namespace Ui {
class DlgVehicleEditor;
}

class DlgVehicleEditor : public QDialog
{
    Q_OBJECT

public:
    explicit DlgVehicleEditor(VehiclePtr vehicle, QWidget *parent = 0);
    ~DlgVehicleEditor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgVehicleEditor *ui;
    VehiclePtr _vehicle;
    QMovie* _spinnerMovie;
};

#endif // DLGVEHICLEEDITOR_H
