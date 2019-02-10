#include "common-item.h"
#include "fsm-item.h"
#include "globals.h"

#include "QKeyEvent"
#include "QGraphicsScene"

commonItem::commonItem(QGraphicsItem* parent)
     : QGraphicsItem(parent)
{

}

void commonItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
     QApplication::setOverrideCursor(Qt::PointingHandCursor);
     setFocus();
     QGraphicsItem::mousePressEvent(event);
}

void commonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
     QApplication::restoreOverrideCursor();
     QGraphicsItem::mouseReleaseEvent(event);
}


