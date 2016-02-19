#include "vehicleeventlistwidget.h"

VehicleEventListWidget::VehicleEventListWidget(VehicleEventController *vehicleEvent, QListWidget *view) : QListWidgetItem(view)
{
    _controller = vehicleEvent;
    QPixmap px;
    px.load(_controller->resourceName());
    setIcon(QIcon(px));
    setText(_controller->text());
}


void VehicleEventListWidget::edit()
{
    if (_controller->edit())
        setText(_controller->text());
}
