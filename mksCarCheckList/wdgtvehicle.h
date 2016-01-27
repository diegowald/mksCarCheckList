#ifndef WDGTVEHICLE_H
#define WDGTVEHICLE_H

#include <QWidget>

namespace Ui {
class WdgtVehicle;
}

class WdgtVehicle : public QWidget
{
    Q_OBJECT

public:
    explicit WdgtVehicle(QWidget *parent = 0);
    ~WdgtVehicle();

private:
    Ui::WdgtVehicle *ui;
};

#endif // WDGTVEHICLE_H
