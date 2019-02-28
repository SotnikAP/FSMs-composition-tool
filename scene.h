#ifndef SCENE_H
#define SCENE_H

#include "fsm-item.h"
#include "link-item.h"
#include "composition-item.h"

#include <QGraphicsScene>

using fsmVector = std::vector<fsmItem*>;
using linkVector = std::vector<linkItem*>;
using compositionVector = std::vector<compositionItem*>;

class Scene : public QGraphicsScene
{
public:
     Scene(QObject* parent = nullptr);
     Scene(const QRectF &sceneRect, QObject *parent = nullptr);


     ///@brief Добавляет на сцену автомат и запоминает в fsms_
     void addFsm();

     ///@brief Добавляет на сцену связь и запоминает в links_
     void addLink();

     ///@brief Добавляет на сцену композицию и запоминает в compositions_
     void addComposition();

private:



private:
     fsmVector fsms_;
     linkVector links_;
     compositionVector compositions_;
};

#endif // SCENE_H