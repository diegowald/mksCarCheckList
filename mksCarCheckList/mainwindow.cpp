#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flowlayout.h"
#include "wdgtvehicle.h"
#include <QVBoxLayout>
#include "entities/user.h"
#include <QJsonDocument>
#include "dlguser.h"
#include "wdgtuser.h"
#include "wdgcontroller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _api = MongoClientAPIPtr::create();
    _container = GlobalContainerPtr::create();
    _container->initialize("./settings.json");
    FlowLayout *fl = new FlowLayout(ui->centralWidget);

    WdgController *controller = new WdgController(_container, ui->centralWidget);
    controller->setStyleSheet("background-color: rgb(219, 246, 242); gridline-color: rgb(225, 9, 187);");
    connect(controller, &WdgController::vehicleAdded, this, &MainWindow::on_vehicleAdded);
    fl->addWidget(controller);

    WdgtUser *wdUser = new WdgtUser(_container, ui->centralWidget);
    wdUser->setStyleSheet("background-color: rgb(219, 246, 242); gridline-color: rgb(225, 9, 187);");
    fl->addWidget(wdUser);

    foreach (JsonAblePtr entity, _container->vehicles())
    {
        VehiclePtr vehicle = qSharedPointerDynamicCast<Vehicle>(entity);
        WdgtVehicle *wdg = new WdgtVehicle(_container, vehicle, ui->centralWidget);
        fl->addWidget(wdg);
    }

    //fl->addWidget(new WdgtVehicle(ui->centralWidget));

    ui->centralWidget->setLayout(fl);

    connect(_api.data(), &MongoClientAPI::added, this, &MainWindow::on_added);
    connect(_api.data(), &MongoClientAPI::updated, this, &MainWindow::on_updated);
    connect(_api.data(), &MongoClientAPI::deleted, this, &MainWindow::on_deleted);

    /*ui->lblSpinner->clear();
    _spinnerMovie = new QMovie(":/img/spinner");
    ui->lblSpinner->setMovie(_spinnerMovie);
    s = "QLabel { background-color : transparent; color : darkred; }";
    ui->lblSpinner->setStyleSheet(s);
    ui->lblSpinner->setVisible(false);*/
}

MainWindow::~MainWindow()
{
    _container->finalize();
    delete ui;
}


void MainWindow::on_added(QJsonDocument &json, MongoClientAPI::Status status)
{
    QJsonObject obj = json.object();
    //_container->addEntity(obj);
    refreshUI();
}

void MainWindow::on_updated(QJsonDocument &json, MongoClientAPI::Status status)
{
}

void MainWindow::on_deleted(QJsonDocument &json, MongoClientAPI::Status status)
{
}



/*void MainWindow::startSpinner()
{
    ui->lblSpinner->setVisible(true);
    _spinnerMovie->start();
}

void MainWindow::stopSpinner()
{
    _spinnerMovie->stop();
    ui->lblSpinner->setVisible(false);
}*/


void MainWindow::refreshUI()
{
    FlowLayout *fl = dynamic_cast<FlowLayout*>(ui->centralWidget->layout());

    foreach (JsonAblePtr entity, _container->vehicles())
    {
        VehiclePtr vehicle = qSharedPointerDynamicCast<Vehicle>(entity);
        WdgtVehicle *wdg = new WdgtVehicle(_container, vehicle, ui->centralWidget);
        fl->addWidget(wdg);
    }
}

void MainWindow::on_vehicleAdded()
{
    refreshUI();
}
