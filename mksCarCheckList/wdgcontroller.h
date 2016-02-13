#ifndef WDGCONTROLLER_H
#define WDGCONTROLLER_H

#include <QWidget>
#include <QMovie>
#include "mongoclientapi.h"
#include "globalcontainer.h"

namespace Ui {
class WdgController;
}

class WdgController : public QWidget
{
    Q_OBJECT

public:
    explicit WdgController(GlobalContainerPtr container, QWidget *parent = 0);
    ~WdgController();

signals:
    void vehicleAdded();

private:
    void startSpinner();
    void stopSpinner();
private slots:
    void on_toolButton_clicked();
    void on_added(QJsonDocument &json, MongoClientAPI::Status status);
    void on_updated(QJsonDocument &json, MongoClientAPI::Status status);
    void on_deleted(QJsonDocument &json, MongoClientAPI::Status status);

private:
    Ui::WdgController *ui;
    MongoClientAPIPtr _api;
    GlobalContainerPtr _container;
    QMovie *_spinnerMovie;
};

#endif // WDGCONTROLLER_H
