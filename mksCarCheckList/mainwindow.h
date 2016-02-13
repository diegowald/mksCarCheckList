#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "globalcontainer.h"
#include "mongoclientapi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void refreshUI();
private slots:
    void on_added(QJsonDocument &json, MongoClientAPI::Status status);
    void on_updated(QJsonDocument &json, MongoClientAPI::Status status);
    void on_deleted(QJsonDocument &json, MongoClientAPI::Status status);
    void on_vehicleAdded();

private:
    Ui::MainWindow *ui;
    MongoClientAPIPtr _api;
    GlobalContainerPtr _container;
    QMovie* _spinnerMovie;
};

#endif // MAINWINDOW_H
