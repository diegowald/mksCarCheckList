#ifndef WDGTVEHICLE_H
#define WDGTVEHICLE_H

#include <QWidget>
#include "mongoclientapi.h"
#include "globalcontainer.h"
#include "entities/vehicle.h"

namespace Ui {
class WdgtVehicle;
}

class WdgtVehicle : public QWidget
{
    Q_OBJECT

public:
    explicit WdgtVehicle(GlobalContainerPtr container, VehiclePtr vehicle, QWidget *parent = 0);
    ~WdgtVehicle();

private slots:
    void on_toolButton_clicked();

private:
    void refreshUI();
private:
    Ui::WdgtVehicle *ui;
    QMovie* _spinnerMovie;
    VehiclePtr _vehicle;
    MongoClientAPIPtr _api;
    GlobalContainerPtr _container;
};

#endif // WDGTVEHICLE_H
