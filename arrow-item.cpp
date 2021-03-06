#include "arrow-item.h"
#include "globals.h"

#include <QPainter>
#include <QApplication>

ArrowItem::ArrowItem(QGraphicsItem* parent) : QGraphicsItem (parent)
{
}

QRectF ArrowItem::boundingRect() const
{
     QPointF ptPosition(0 - globals::penWidth, -10 - globals::penWidth);
     QSizeF size(80 + globals::penWidth, 20 + globals::penWidth);
     return { ptPosition, size };
}

void ArrowItem::paint(QPainter* painter,
                   const QStyleOptionGraphicsItem*,
                   QWidget*)
{
    painter->save();
    painter->setPen(QPen(Qt::black, globals::penWidth));
    painter->drawLine(0, 0, 80, 0);
    painter->drawLine(80, 0, 70, 10);
    painter->drawLine(80, 0, 70, -10);
    painter->restore();
}
