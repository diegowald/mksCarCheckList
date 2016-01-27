#-------------------------------------------------
#
# Project created by QtCreator 2016-01-27T07:56:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mksCarCheckList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    httprequestworker.cpp \
    flowlayout.cpp \
    wdgtvehicle.cpp

HEADERS  += mainwindow.h \
    httprequestworker.h\
    flowlayout.h \
    wdgtvehicle.h


FORMS    += mainwindow.ui \
    wdgtvehicle.ui

CONFIG += mobility
MOBILITY =

