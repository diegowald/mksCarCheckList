#include "mongoclientapi.h"
#include <QMessageBox>
#include <QJsonDocument>

MongoClientAPI::MongoClientAPI(QObject *parent) : QObject(parent)
{
    _apiKey = "3oUpZRiqZ_CiqIHFvv8YgwU5lfBMCCZg";
    _baseURL = "https://api.mongolab.com/api/1";
    _database = "carchecklist";
}

void MongoClientAPI::example()
{

    QString url_str = QString("%1/databases?apiKey=%2").arg(_baseURL).arg(_apiKey);

    HttpRequestInput input(url_str, "GET");

/*    input.add_var("dni", DNI);
    input.add_var("celular", "");
    input.add_var("nombre", "");
    input.add_var("fechaSolicitud", QDate::currentDate().toString("yyyy-MM-dd"));*/

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_example(HttpRequestWorker*)));
    worker->execute(&input);
}


void MongoClientAPI::handle_example(HttpRequestWorker *worker)
{
    if (worker->error_type == QNetworkReply::NoError)
    {
        // communication was successful
        QByteArray response = worker->response;

        qDebug() << response;
/*
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        loadJson(jsonDoc);

        QFile jsonFile(_fileDataLocation);
        jsonFile.open(QFile::WriteOnly);

        QJsonDocument json2Write;
        QJsonArray array;
        foreach (QJsonObject jsonObj, dominiosAsegurados.values())
        {
            array.append(jsonObj);
        }
        json2Write.setArray(array);

        //jsonFile.write(jsonDoc.toJson());
        jsonFile.write(json2Write.toJson());*/
    }
    else
    {
        // an error occurred
        QString msg = "Error: " + worker->error_str;
        //QMessageBox::information(this, "", msg);
        qDebug() << msg;
    }
}


void MongoClientAPI::add(JsonAblePtr element)
{
    QString url_str = QString("%1/databases/%4/collections/%2?apiKey=%3").arg(_baseURL)
            .arg(element->collection()).arg(_apiKey).arg(_database);

    qDebug() << url_str;
    HttpRequestInput input(url_str, "POST");
    input.var_layout = JSON;

    QJsonDocument doc(element->toJson(false));
    qDebug() << QString(doc.toJson(QJsonDocument::Compact));
    //input.add_var(element->name(), QString(doc.toJson(QJsonDocument::Compact)));
    input.add_data(doc.toJson(QJsonDocument::Compact));
    /*    input.add_var("dni", DNI);
    input.add_var("celular", "");
    input.add_var("nombre", "");
    input.add_var("fechaSolicitud", QDate::currentDate().toString("yyyy-MM-dd"));*/

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, &HttpRequestWorker::on_execution_finished, this, &MongoClientAPI::handle_add);
    worker->execute(&input);
}

void MongoClientAPI::handle_add(HttpRequestWorker *worker)
{
    if (worker->error_type == QNetworkReply::NoError)
    {
        // communication was successful
        QByteArray response = worker->response;

        qDebug() << response;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
/*        loadJson(jsonDoc);

        QFile jsonFile(_fileDataLocation);
        jsonFile.open(QFile::WriteOnly);

        QJsonDocument json2Write;
        QJsonArray array;
        foreach (QJsonObject jsonObj, dominiosAsegurados.values())
        {
            array.append(jsonObj);
        }
        json2Write.setArray(array);

        //jsonFile.write(jsonDoc.toJson());
        jsonFile.write(json2Write.toJson());*/
        emit added(jsonDoc, OK);
    }
    else
    {
        // an error occurred
        QString msg = "Error: " + worker->error_str;
        //QMessageBox::information(this, "", msg);
        qDebug() << msg;
        QJsonDocument jsonDoc;
        emit added(jsonDoc, ERROR);
    }
}

void MongoClientAPI::update(JsonAblePtr element)
{
    QString url_str = QString("%1/databases/%5/collections/%2/%4?apiKey=%3")
            .arg(_baseURL).arg(element->collection())
            .arg(_apiKey).arg(element->id()).arg(_database);
qDebug() << url_str;
    HttpRequestInput input(url_str, "PUT");
    input.var_layout = JSON;

    QJsonObject jsonObj;
    jsonObj["$set"] = element->toJson(false);
    QJsonDocument doc(jsonObj);
    qDebug() << QString(doc.toJson(QJsonDocument::Compact));
    input.add_data(doc.toJson(QJsonDocument::Compact));

    /*    input.add_var("dni", DNI);
    input.add_var("celular", "");
    input.add_var("nombre", "");
    input.add_var("fechaSolicitud", QDate::currentDate().toString("yyyy-MM-dd"));*/

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, &HttpRequestWorker::on_execution_finished, this, &MongoClientAPI::handle_update);
    worker->execute(&input);
}

void MongoClientAPI::handle_update(HttpRequestWorker *worker)
{
    if (worker->error_type == QNetworkReply::NoError)
    {
        // communication was successful
        QByteArray response = worker->response;

        qDebug() << response;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
/*        loadJson(jsonDoc);

        QFile jsonFile(_fileDataLocation);
        jsonFile.open(QFile::WriteOnly);

        QJsonDocument json2Write;
        QJsonArray array;
        foreach (QJsonObject jsonObj, dominiosAsegurados.values())
        {
            array.append(jsonObj);
        }
        json2Write.setArray(array);

        //jsonFile.write(jsonDoc.toJson());
        jsonFile.write(json2Write.toJson());*/
        emit updated(jsonDoc, OK);
    }
    else
    {
        // an error occurred
        QString msg = "Error: " + worker->error_str;
        //QMessageBox::information(this, "", msg);
        qDebug() << msg;
        QJsonDocument jsonDoc;
        emit updated(jsonDoc, ERROR);
    }
}

void MongoClientAPI::del(JsonAblePtr element)
{
    QString url_str = QString("%1/databases/%5/collections/%2/%4?apiKey=%3")
            .arg(_baseURL).arg(element->collection())
            .arg(_apiKey).arg(element->id()).arg(_database);

    HttpRequestInput input(url_str, "PUT");

    /*    input.add_var("dni", DNI);
    input.add_var("celular", "");
    input.add_var("nombre", "");
    input.add_var("fechaSolicitud", QDate::currentDate().toString("yyyy-MM-dd"));*/

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, &HttpRequestWorker::on_execution_finished, this, &MongoClientAPI::handle_delete);
    worker->execute(&input);
}

void MongoClientAPI::handle_delete(HttpRequestWorker *worker)
{
    if (worker->error_type == QNetworkReply::NoError)
    {
        // communication was successful
        QByteArray response = worker->response;

        qDebug() << response;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
/*        loadJson(jsonDoc);

        QFile jsonFile(_fileDataLocation);
        jsonFile.open(QFile::WriteOnly);

        QJsonDocument json2Write;
        QJsonArray array;
        foreach (QJsonObject jsonObj, dominiosAsegurados.values())
        {
            array.append(jsonObj);
        }
        json2Write.setArray(array);

        //jsonFile.write(jsonDoc.toJson());
        jsonFile.write(json2Write.toJson());*/
        emit deleted(jsonDoc, OK);
    }
    else
    {
        // an error occurred
        QString msg = "Error: " + worker->error_str;
        //QMessageBox::information(this, "", msg);
        qDebug() << msg;
        QJsonDocument jsonDoc;
        emit deleted(jsonDoc, ERROR);
    }
}
