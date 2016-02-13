#ifndef USER_H
#define USER_H

#include "entities/jsonable.h"

class User : public JsonAble
{
    Q_OBJECT
public:
    explicit User(QObject *parent = 0);
    explicit User(QJsonObject &json, QObject *parent = 0);

    void setName(const QString &name);
    QString name() const;

    void setEmail(const QString &email);
    QString email() const;

signals:

public slots:

private:
    QString _name;
    QString _email;

    // JsonAble interface
protected:
    virtual void buildJson(QJsonObject &jsonObj); // to serialize everything
    virtual void buildJsonID(QJsonObject &jsonObj); // to add some relevant data to id
};

typedef QSharedPointer<User> UserPtr;

#endif // USER_H
