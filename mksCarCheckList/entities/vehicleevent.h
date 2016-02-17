#ifndef VEHICLEEVENT_H
#define VEHICLEEVENT_H

#include <entities/jsonable.h>
#include <QDateTime>


enum class VehicleEventType
{
    CountKms,
    ChangeOil
};

class VehicleEvent : public JsonAble
{
    Q_OBJECT
public:
    explicit VehicleEvent(VehicleEventType type, QObject *parent = 0);
    explicit VehicleEvent(QJsonObject &json, QObject *parent = 0);

    QDateTime moment() const;
    int kms() const;
    QString name() const;
    QString description() const;
    VehicleEventType evtType() const;

    void setMoment(const QDateTime &value);
    void setKms(int value);
    void setName(const QString &value);
    void setDescription(const QString &value);
    void setEventType(VehicleEventType value);

signals:

public slots:

private:
    QDateTime _moment;
    int _kms;
    QString _name;
    QString _description;
    VehicleEventType _evtType;

    // JsonAble interface
protected:
    virtual void buildJson(QJsonObject &jsonObj);
    virtual void buildJsonID(QJsonObject &jsonObj);
};

typedef QSharedPointer<VehicleEvent> VehicleEventPtr;

#endif // VEHICLEEVENT_H
