#ifndef QTAPLISTWIDGET_H
#define QTAPLISTWIDGET_H

#include <QListWidget>


class QTapListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit QTapListWidget(QWidget *parent = 0);
    virtual bool event(QEvent *evt);

signals:

public slots:
};

#endif // QTAPLISTWIDGET_H
