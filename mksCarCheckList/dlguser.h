#ifndef DLGUSER_H
#define DLGUSER_H

#include <QDialog>
#include "entities/user.h"
#include <QMovie>


namespace Ui {
class DlgUser;
}

class DlgUser : public QDialog
{
    Q_OBJECT

public:
    explicit DlgUser(UserPtr user, QWidget *parent = 0);
    ~DlgUser();
private:
    void startSpinner();
    void stopSpinner();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DlgUser *ui;
    UserPtr _user;
    QMovie* _spinnerMovie;
};

#endif // DLGUSER_H
