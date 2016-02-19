#ifndef VEHICLEEVENTITEMDELEGATE_H
#define VEHICLEEVENTITEMDELEGATE_H

#include <QStyledItemDelegate>

class VehicleEventItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit VehicleEventItemDelegate(QObject *parent = 0);



signals:

public slots:

    // QAbstractItemDelegate interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    void details(QString text, const QFont font, const QStyleOptionViewItem &option, int *lineCount, int *widthUsed) const;

    QString resourceName(QVariant value) const;

};

#endif // VEHICLEEVENTITEMDELEGATE_H
