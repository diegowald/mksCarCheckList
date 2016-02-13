#include "wdgtuser.h"
#include "ui_wdgtuser.h"
#include "dlguser.h"
#include <QJsonObject>


WdgtUser::WdgtUser(GlobalContainerPtr container, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgtUser)
{
    ui->setupUi(this);

    ui->lblSpinner->clear();
    _spinnerMovie = new QMovie(":/img/spinner");
    ui->lblSpinner->setMovie(_spinnerMovie);
    QString s = "QLabel { background-color : transparent; color : darkred; }";
    ui->lblSpinner->setStyleSheet(s);
    ui->lblSpinner->setVisible(false);

    _api = MongoClientAPIPtr::create();
    _container = container;
    connect(_api.data(), &MongoClientAPI::added, this, &WdgtUser::on_added);
    connect(_api.data(), &MongoClientAPI::updated, this, &WdgtUser::on_updated);
    connect(_api.data(), &MongoClientAPI::deleted, this, &WdgtUser::on_deleted);

    checkIfNotRegistered();
    refresh();
}

WdgtUser::~WdgtUser()
{
    delete ui;
}

void WdgtUser::refresh()
{
    UserPtr user = _container->owner();
    if (user.isNull())
    {
        ui->lblUserName->setText(tr("Unregistered"));
    }
    else
    {
        ui->lblUserName->setText(user->name());
    }
}

void WdgtUser::on_toolButton_clicked()
{
    UserPtr user = _container->owner();
    DlgUser dlg(user);
    if (dlg.exec() == QDialog::Accepted)
    {
        if (user->isNew())
        {
            _api->add(user);
        }
        else
        {
            _api->update(user);
        }
    }
    refresh();
}

void WdgtUser::checkIfNotRegistered()
{
    if (!_container->isRegistered())
    {
        UserPtr user = UserPtr::create();
        DlgUser dlg(user);
        dlg.exec();
        startSpinner();
        _api->add(user);
    }
}


void WdgtUser::on_added(QJsonDocument &json, MongoClientAPI::Status status)
{
    if (status == MongoClientAPI::Status::OK)
    {
        QJsonObject obj = json.object();
        _container->addEntity(obj);
        refresh();
    }
    stopSpinner();
}

void WdgtUser::on_updated(QJsonDocument &json, MongoClientAPI::Status status)
{
    if (status == MongoClientAPI::Status::OK)
    {
        QJsonObject obj = json.object();
        _container->addEntity(obj);
        refresh();
    }
    stopSpinner();
}

void WdgtUser::on_deleted(QJsonDocument &json, MongoClientAPI::Status status)
{
    stopSpinner();
}

void WdgtUser::startSpinner()
{
    ui->lblSpinner->setVisible(true);
    _spinnerMovie->start();
}

void WdgtUser::stopSpinner()
{
    _spinnerMovie->stop();
    ui->lblSpinner->setVisible(false);
}
