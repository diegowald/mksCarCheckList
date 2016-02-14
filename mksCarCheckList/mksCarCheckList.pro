#-------------------------------------------------
#
# Project created by QtCreator 2016-01-27T07:56:58
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mksCarCheckList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httprequestworker.cpp \
    flowlayout.cpp \
    wdgtvehicle.cpp \
    mongoclientapi.cpp \
    entities/user.cpp \
    entities/vehicle.cpp \
    entities/jsonable.cpp \
    entities/vehicleevent.cpp \
    globalcontainer.cpp \
    dlguser.cpp \
    wdgtuser.cpp \
    wdgcontroller.cpp \
    dlgvehicleeditor.cpp \
    factory.cpp \
    entities/VehicleEvents/countkms.cpp \
    analyzer/vehicleeventanalyzer.cpp \
    analyzer/countkmsanalyzer.cpp \
    analyzer/oilchangeanalyzer.cpp

HEADERS  += mainwindow.h \
    httprequestworker.h\
    flowlayout.h \
    wdgtvehicle.h \
    mongoclientapi.h \
    entities/user.h \
    entities/vehicle.h \
    entities/jsonable.h \
    entities/vehicleevent.h \
    globalcontainer.h \
    dlguser.h \
    wdgtuser.h \
    wdgcontroller.h \
    dlgvehicleeditor.h \
    factory.h \
    entities/VehicleEvents/countkms.h \
    analyzer/vehicleeventanalyzer.h \
    analyzer/countkmsanalyzer.h \
    analyzer/oilchangeanalyzer.h


FORMS    += mainwindow.ui \
    wdgtvehicle.ui \
    dlguser.ui \
    wdgtuser.ui \
    wdgcontroller.ui \
    dlgvehicleeditor.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    resources.qrc

