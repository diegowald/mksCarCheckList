#ifndef WDGTVEHICLE_H
#define WDGTVEHICLE_H

#include <QWidget>
#include "mongoclientapi.h"
#include "globalcontainer.h"
#include "entities/vehicle.h"
#include <QListWidgetItem>
#include "oilchangecontroller.h"

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

    void on_btnUpdateKms_clicked();

    void on_btnOilDetails_clicked();

private:
    void refreshUI();
private:
    Ui::WdgtVehicle *ui;
    QMovie* _spinnerMovie;
    VehiclePtr _vehicle;
    MongoClientAPIPtr _api;
    GlobalContainerPtr _container;

    //bool _handleGasCharge;
    OilChangeController* _oilChangeCtrller;
    //bool _handleSparkChange;
    //bool _handleBendChange;
    //bool _handleGasFilter;
    //bool _handleWheelAlign;
    //bool _handleWheelPressure;

};

#endif // WDGTVEHICLE_H
