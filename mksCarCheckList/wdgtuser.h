#ifndef WDGTUSER_H
#define WDGTUSER_H

#include <QWidget>
#include "entities/user.h"
#include "mongoclientapi.h"
#include <QJsonDocument>
#include "globalcontainer.h"



namespace Ui {
class WdgtUser;
}

class WdgtUser : public QWidget
{
    Q_OBJECT

public:
    explicit WdgtUser(GlobalContainerPtr container, QWidget *parent = 0);
    ~WdgtUser();
    void refresh();
private slots:
    void on_toolButton_clicked();
    void on_added(QJsonDocument &json, MongoClientAPI::Status status);
    void on_updated(QJsonDocument &json, MongoClientAPI::Status status);
    void on_deleted(QJsonDocument &json, MongoClientAPI::Status status);

private:
    void checkIfNotRegistered();
    void startSpinner();
    void stopSpinner();


private:
    Ui::WdgtUser *ui;
    MongoClientAPIPtr _api;
    GlobalContainerPtr _container;
    QMovie *_spinnerMovie;
};

#endif // WDGTUSER_H
