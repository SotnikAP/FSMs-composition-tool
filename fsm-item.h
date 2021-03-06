#ifndef FSMITEM_H
#define FSMITEM_H

#include "common-item.h"
#include "fsm.h"
#include "globals.h"

#include <QtWidgets/QGraphicsItem>
#include <QPainter>
#include <QFile>
#include <QApplication>
#include <QMenu>

/// @brief Класс автомата как графического итема
///        Содержит в себе логический элемент автомата
///        И отвечает за его формирование
class FsmItem : public CommonItem
{
private:
     // Используется для нумерации автоматов
     // Увеличивается в конструкторе
     static int fsmNumber;

     /// @brief Используется для задания начального идентификатора автомата
     int number_;

     /// @brief Текстовый итем - отвечает за отображение id_ автомата
     QGraphicsTextItem* nameItem_;

     /// @brief Файл прикреплённый к автомату черещ onAtachFile()
     QFile file_;

     /// @brief Соответствующий логический элемент автомата
     Fsm fsm_;
private:
     /// @brief Вызывает диалоговое окно выбора файла и прекрепляет файл к итему (копирует рядом к exe)
     void onAttachFile();

protected:
     /// @brief Определяет невидимые элементы и неприкрытые области, которые должны быть отрисованы стр. 324
     virtual QRectF boundingRect() const;

     /// @brief Отвечает за отображение элемента
     virtual void paint(QPainter* painter,
                        const QStyleOptionGraphicsItem*,
                        QWidget*);

     /// @brief Конекстное меню для автомата содержит также прикрепление файла
     virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

public:
     FsmItem(QGraphicsItem* parent = nullptr, QString name = "");
     ~FsmItem();

     int       type()  const;
     QString   getName() const;

     /// @brief Возвращает логический элемент-автомат
     Fsm getFsm() const;

     /// @brief Формирует fsm_ поле
     ///        Вызывается в соответствующей связи
     void formFsm();
};

#endif // FSMITEM_H
