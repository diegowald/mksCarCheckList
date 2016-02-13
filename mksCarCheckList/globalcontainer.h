#ifndef GLOBALCONTAINER_H
#define GLOBALCONTAINER_H

#include <QObject>
#include "entities/jsonable.h"
#include <QMap>
#include "entities/user.h"

class GlobalContainer : public QObject
{
    Q_OBJECT
public:
    explicit GlobalContainer(QObject *parent = 0);

    void initialize(const QString &filename);
    void finalize();

    void addEntity(QJsonObject &obj);
    void addEntity(JsonAblePtr entity);

    bool isRegistered() const;

    UserPtr owner();

    QList<JsonAblePtr> vehicles();
signals:

public slots:
private:
    QString _filename;
    QMap<QString, JsonAblePtr> _entities;
    QString _idOwner;
};

typedef QSharedPointer<GlobalContainer> GlobalContainerPtr;

#endif // GLOBALCONTAINER_H
