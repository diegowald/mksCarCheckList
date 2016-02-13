#ifndef MONGOCLIENTAPI_H
#define MONGOCLIENTAPI_H

#include <QObject>
#include "httprequestworker.h"
#include "entities/jsonable.h"
#include <QJsonObject>



class MongoClientAPI : public QObject
{
    Q_OBJECT
public:
    enum Status
    {
        OK,
        ERROR
    };

    explicit MongoClientAPI(QObject *parent = 0);

    void example();

    void add(JsonAblePtr element);
    void update(JsonAblePtr element);
    void del(JsonAblePtr element);

signals:
    void added(QJsonDocument &json, Status status);
    void updated(QJsonDocument &json, Status status);
    void deleted(QJsonDocument &json, Status status);

public slots:

private slots:
    void handle_example(HttpRequestWorker* worker);

    void handle_add(HttpRequestWorker *worker);
    void handle_update(HttpRequestWorker *worker);
    void handle_delete(HttpRequestWorker *worker);
private:
    QString _apiKey;
    QString _baseURL;
    QString _database;
};

typedef QSharedPointer<MongoClientAPI> MongoClientAPIPtr;

#endif // MONGOCLIENTAPI_H
