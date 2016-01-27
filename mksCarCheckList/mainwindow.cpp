#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flowlayout.h"
#include "wdgtvehicle.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FlowLayout *fl = new FlowLayout(ui->centralWidget);

    WdgtVehicle *wdg = new WdgtVehicle(ui->centralWidget);

    fl->addWidget(wdg);
fl->addWidget(new WdgtVehicle(ui->centralWidget));

    ui->centralWidget->setLayout(fl);
}

MainWindow::~MainWindow()
{
    delete ui;
}
