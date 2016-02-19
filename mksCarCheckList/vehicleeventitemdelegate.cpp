#include "vehicleeventitemdelegate.h"
#include <QVariant>
#include <QTextLayout>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include "entities/vehicleevent.h"

VehicleEventItemDelegate::VehicleEventItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}


void VehicleEventItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
/*    int widthUsed, lineCount;

    //Try and word wrap strings
    if (index.data().canConvert(QMetaType::QString))
    {
        QVariant v = index.data(Qt::UserRole);
        QString resource = resourceName(v);
        painter->save();

        QPalette::ColorGroup group = option.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
        if (group == QPalette::Normal && !(option.state & QStyle::State_Active))
            group = QPalette::Inactive;

        //set pen color depending on behavior
        painter->setFont( QApplication::font() );

        if (option.state & QStyle::State_Selected)
            painter->setPen(option.palette.color(group, QPalette::HighlightedText));
        else
            painter->setPen(option.palette.color(group, QPalette::Text));

        //Text from item
        QString text = index.data(Qt::DisplayRole).toString();

        //Begin word-wrapping effect (use the provided rectangles width to determine when to wrap)
        details(text, QApplication::font(), option, &lineCount, &widthUsed);

        //Word wrap the text, 'elide' it if it goes past a pre-determined maximum
        QString newText = painter->fontMetrics().elidedText(text, Qt::ElideRight, widthUsed);
        /*if (option.state & QStyle::State_Selected)
        {
            //painter->setBackground(QBrush(Qt::red));
            QSize size = sizeHint(option, index);
            //painter->fillRect(painter->window(), Qt::red);
        }*-/

        QPixmap px;
        px.load(resource);
        QRect r;
        r.setLeft(0);
        r.setTop(0);
        r.setWidth(px.width());
        r.setHeight(px.height());
        painter->drawPixmap(r, px);

        painter->drawText( option.rect, (Qt::TextWrapAnywhere|Qt::TextWordWrap|Qt::AlignTop|Qt::AlignLeft), newText );
        painter->restore();
    }
    else*/
    {
        //Fall back on original
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize VehicleEventItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
/*    int lineCount = 1;
    int widthUsed = 0;
    //Try and word wrap strings
    if(index.data().canConvert(QMetaType::QString))
    {
        //Update the size based on the number of lines (original size of a single line multiplied
        //by the number of lines)
        QString text = index.data(Qt::DisplayRole).toString();
        details(text, QApplication::font(), option, &lineCount, &widthUsed);

        QSize size = QStyledItemDelegate::sizeHint(option, index);
        size.setHeight(lineCount *  size.height());

        return size;
    }
    else*/
    {
        //Fall back on original size hint of item
        return QStyledItemDelegate::sizeHint(option, index);
    }
}

void VehicleEventItemDelegate::details( QString text, const QFont font, const QStyleOptionViewItem &option, int *lineCount, int *widthUsed ) const
{
    //Use text layout to word-wrap and provide informmation about line counts and width's
    QTextLayout textLayout(text);

    *widthUsed = 0;
    *lineCount = 0;
    textLayout.setFont(font);
    textLayout.beginLayout();
    while (*lineCount < 2)
    {
        *lineCount = *lineCount + 1;
        QTextLine line = textLayout.createLine();
        if (!line.isValid())
            break;

        line.setLineWidth(option.rect.width());
        *widthUsed = (*widthUsed + line.naturalTextWidth());
    }
    textLayout.endLayout();
    *widthUsed = (*widthUsed + option.rect.width());
}

QString VehicleEventItemDelegate::resourceName(QVariant value) const
{
    QString resource = "";
    if (value.isValid())
    {
        VehicleEventType vehicleEvType = static_cast<VehicleEventType>(value.toInt());

        switch (vehicleEvType)
        {
        case VehicleEventType::CountKms:
            resource = ":/img/kms";
            break;
        case VehicleEventType::ChangeOil:
            resource = ":/img/oil";
            break;
        case VehicleEventType::GasCharge:
            resource = ":/img/fuel";
            break;
        case VehicleEventType::SparkChange:
            resource = ":/img/spark";
            break;
        case VehicleEventType::BendChange:
            resource = ":/img/bend";
            break;
        case VehicleEventType::GasFilter:
            resource = ":/img/gasFilter";
            break;
        case VehicleEventType::AlignWheels:
            resource = ":/img/wheelAlgin";
            break;
        case VehicleEventType::WheelPressure:
            resource = ":/img/wheelPressure";
            break;
        default:
            break;
        }
    }
    return resource;
}
