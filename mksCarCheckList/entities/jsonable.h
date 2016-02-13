#ifndef JSONABLE_H
#define JSONABLE_H

#include <QObject>
#include <QSharedPointer>
#include "QJsonObject"

enum class JsonAbleType
{
    User,
    Vehicle,
    VehicleEvent
};

class JsonAble : public QObject
{
    Q_OBJECT
public:
    explicit JsonAble(JsonAbleType type, const QString &collection, const QString objectVersion, QObject *parent = 0);
    explicit JsonAble(QJsonObject json, JsonAbleType type, const QString &collection, const QString objectVersion, QObject *parent = 0);

    virtual QJsonObject toJson(bool includeId); // to export the complete object
    virtual QJsonObject toJsonID(); // to export only the id (to use as a reference on another object)

    QString collection() const;
    virtual QString id() const;
    JsonAbleType type() const;
    QString objectVersion() const;

    bool isNew() const;
protected:
    virtual void buildJson(QJsonObject &jsonObj) = 0;
    virtual void buildJsonID(QJsonObject &jsonObj) = 0;

signals:

public slots:
private:
    QString _collection;
    JsonAbleType _type;
    QString _id;
    QString _objectVersion;
    bool _isNew;
};

typedef QSharedPointer<JsonAble> JsonAblePtr;

#endif // JSONABLE_H
