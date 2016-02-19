#include "qtaplistwidget.h"
#include <QGestureEvent>
#include <QTapAndHoldGesture>
#include <QDebug>
#include "vehicleeventitemdelegate.h"
#include "vehicleeventlistwidget.h"

QTapListWidget::QTapListWidget(QWidget *parent) : QListWidget(parent)
{
    grabGesture(Qt::TapAndHoldGesture);
    //setItemDelegate(new VehicleEventItemDelegate(this));
}


bool QTapListWidget::event(QEvent *evt)
{
    if (evt->type() == QEvent::Gesture)
    {
        QGestureEvent * gesture = static_cast<QGestureEvent*>(evt);
        QGesture* tAh = gesture->gesture(Qt::TapAndHoldGesture);
        if (tAh)
        {
            QTapAndHoldGesture *tap = static_cast<QTapAndHoldGesture*>(tAh);
            qDebug() << "tapAndHold";
            QPoint pt;
            pt.setX(tap->position().toPoint().x() - x());
            pt.setY(tap->position().toPoint().y() - y());

            if (selectedItems().count() > 0)
            {
                QListWidgetItem *item = selectedItems().at(0);
                if (item)
                {
                    VehicleEventListWidget *w = static_cast<VehicleEventListWidget*>(item);
                    w->edit();
                }
            }
            return true;
        }
    }
    return QWidget::event(evt);
}
