#include "composition-item.h"
#include "fsm-item.h"
#include "link-item.h"
#include "globals.h"

#include <iostream>

#ifdef QT_DEBUG
#include <QDebug>
#endif //QT_DEBUG

CompositionItem::CompositionItem(QGraphicsItem* parent)
     : CommonItem(parent)
{

}

void CompositionItem::formComposition()
{
     fsmVector fsms;
     linkVector links;

     auto getFsmsAndLinks = [&fsms, &links](QList<QGraphicsItem*> allItems)
     {
          for( const auto& item : allItems )
          {
               if( globals::customTypes::fsm == item->type() )
               {
                    // Автомат уже сформирован
                    fsms.push_back( dynamic_cast<FsmItem*>(item)->getFsm() );
               }
               else if ( globals::customTypes::link == item->type() )
               {
                    // Связь нужно сначала сформировать
                    LinkItem* link = dynamic_cast<LinkItem*>(item);
                    link->formLink();
                    links.push_back( link->getLink() );
               }
          }
     };

     getFsmsAndLinks(collidingItems());

     composition_ = Composition(fsms, links);
}

Composition CompositionItem::getComposition() const
{
     return composition_;
}


void CompositionItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
     QMenu menu;
     QAction* removeAction = menu.addAction(QIcon(":/context/icons/delete.svg"), "&Delete");
     removeAction->setShortcut(QKeySequence::Delete);
     QAction* formAction = menu.addAction("&Form");
     QAction* currAct = menu.exec(event->screenPos());
     if (currAct == removeAction)
     {
          removeItem();
     }
     else if (currAct == formAction)
     {
          formComposition();
          //composition_.formXmlFile();
          composition_.formBalm2Script();
          int result = system("sh script.sh");
          //popen("sh script.sh", "r");
#ifdef QT_DEBUG
          std::cout << "Result: " << result << std::endl;
          printFsmsAndLinks();
#endif
     }
}

#ifdef QT_DEBUG
void CompositionItem::printFsmsAndLinks()
{
     for(const auto& fsm : composition_.getFsms())
     {
          qDebug() << "FSM: " << fsm.getName();
     }
     for(const auto& link : composition_.getLinks())
     {
          qDebug() << "Link: " << link.getId() << "\n Input FSM: " << link.getInputFsm().getName() << "   Output FSM: " << link.getOutputFsm().getName();
     }
}
#endif //QT_DEBUG

int CompositionItem::type() const
{
     return globals::customTypes::composition;
}

QRectF CompositionItem::boundingRect() const
{
     QPointF ptPosition(0 - globals::penWidth, 0 - globals::penWidth);
     QSizeF size(400 + globals::penWidth, 180 + globals::penWidth);
     return { ptPosition, size };
}

void CompositionItem::paint(QPainter* painter,
                            const QStyleOptionGraphicsItem*,
                            QWidget*)
{
     painter->save();
     painter->setPen(QPen(Qt::black, globals::penWidth, Qt::DashLine));
     painter->drawRect(0, 0, 400, 180);
     painter->restore();
}
