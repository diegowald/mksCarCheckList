#ifndef VEHICLEEVENTLISTWIDGET_H
#define VEHICLEEVENTLISTWIDGET_H

#include <QListWidgetItem>
#include "vehicleeventcontroller.h"

class VehicleEventListWidget : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit VehicleEventListWidget(VehicleEventController* vehicleEvent, QListWidget *view = 0);

    void edit();
signals:

public slots:

private:
    VehicleEventController* _controller;
};

#endif // VEHICLEEVENTLISTWIDGET_H
