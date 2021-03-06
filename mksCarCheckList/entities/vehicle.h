#ifndef VECHICLE_H
#define VECHICLE_H

#include "entities/jsonable.h"
#include "entities/user.h"
#include "entities/vehicleevent.h"
#include <QMap>

class Vehicle : public JsonAble
{
    Q_OBJECT
public:
    explicit Vehicle(UserPtr owner, QObject *parent = 0);
    explicit Vehicle(QJsonObject &json, QObject *parent = 0);

    QString name() const;
    QString plate() const;
    QString brand() const;
    QString model() const;
    int year() const;

    void setName(const QString &value);
    void setPlate(const QString &value);
    void setBrand(const QString &value);
    void setModel(const QString &value);
    void setYear(const int value);

    bool handleGasCharge() const;
    bool handleOilChange() const;
    bool handleSparkChange() const;
    bool handleBendChange() const;
    bool handleGasFilter() const;
    bool handleWheelAlign() const;
    bool handleWheelPressure() const;

    void setHandleGasCharge(bool value);
    void setHandleOilChange(bool value);
    void setHandleSparkChange(bool value);
    void setHandleBendChange(bool value);
    void setHandleGasFilter(bool value);
    void setHandleWheelAlign(bool value);
    void setHandleWheelPressure(bool value);

    // VehicleEvents;
    void addVehicleEvent(VehicleEventPtr evt);
    VehicleEventPtr lastOilChangeEvent();

    // Calculable values
    int currentKms();
    int lastOilChange();
    QDateTime lastOilChangeDate();
    int nextOilChange();
    QDateTime nextOilChangeDate();


    // JsonAble interface
protected:
    virtual void buildJson(QJsonObject &jsonObj);
    virtual void buildJsonID(QJsonObject &jsonObj);

signals:

public slots:
private:
    // Users that can access this vehicle
    UserPtr _owner;
    QList<UserPtr> _others;

    QString _name;
    QString _plate;
    QString _brand;
    QString _model;
    int _year;

    bool _handleGasCharge;
    bool _handleOilChange;
    bool _handleSparkChange;
    bool _handleBendChange;
    bool _handleGasFilter;
    bool _handleWheelAlign;
    bool _handleWheelPressure;

    QMap<QDateTime, VehicleEventPtr> _vehicleEvents;
};

typedef QSharedPointer<Vehicle> VehiclePtr;
#endif // VECHICLE_H
