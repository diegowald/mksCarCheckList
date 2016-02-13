#include "user.h"

User::User(QObject *parent) : JsonAble(JsonAbleType::User, "users", "1", parent)
{
    _name = "";
    _email = "";
}

User::User(QJsonObject &json, QObject *parent) : JsonAble(json, JsonAbleType::User, "users", "1", parent)
{
    _name = json["name"].toString();
    _email = json["email"].toString();
}

void User::setName(const QString &name)
{
    _name = name;
}

QString User::name() const
{
    return _name;
}

void User::setEmail(const QString &email)
{
    _email = email;
}

QString User::email() const
{
    return _email;
}

void User::buildJson(QJsonObject &jsonObj)
{
    jsonObj["name"] = _name;
    jsonObj["email"] = _email;
}

void User::buildJsonID(QJsonObject &jsonObj)
{
}
