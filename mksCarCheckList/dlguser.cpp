#include "dlguser.h"
#include "ui_dlguser.h"

DlgUser::DlgUser(UserPtr user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgUser)
{
    ui->setupUi(this);
    _user = user;
    ui->txtName->setText(user->name());
    ui->txtEmail->setText(user->email());

    ui->lblSpinner->clear();
    _spinnerMovie = new QMovie(":/img/spinner");
    ui->lblSpinner->setMovie(_spinnerMovie);
    QString s = "QLabel { background-color : transparent; color : darkred; }";
    ui->lblSpinner->setStyleSheet(s);
    ui->lblSpinner->setVisible(false);
}

DlgUser::~DlgUser()
{
    delete ui;
}

void DlgUser::on_buttonBox_accepted()
{
    _user->setName(ui->txtName->text());
    _user->setEmail(ui->txtEmail->text());
    close();
}


void DlgUser::startSpinner()
{
    ui->lblSpinner->setVisible(true);
    _spinnerMovie->start();
}

void DlgUser::stopSpinner()
{
    _spinnerMovie->stop();
    ui->lblSpinner->setVisible(false);
}
