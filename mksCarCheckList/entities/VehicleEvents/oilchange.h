#ifndef OILCHANGE_H
#define OILCHANGE_H

#include <QObject>
#include "entities/vehicleevent.h"


class OilChange : public VehicleEvent
{
    Q_OBJECT
public:
    explicit OilChange(QObject *parent = 0);

    QString brand() const;
    QString where() const;
    int quantity() const;

    void setBrand(const QString &value);
    void setWhere(const QString &value);
    void setQuantity(int value);

signals:

public slots:

private:
    QString _brand;
    QString _where;
    int _quantity;
};

typedef QSharedPointer<OilChange> OilChangePtr;

#endif // OILCHANGE_H
