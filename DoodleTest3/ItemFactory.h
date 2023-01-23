#pragma once

#include <map>

#include <QPair>
#include <QGraphicsPixmapItem>
#include <QPoint>

#include "Factory.h"
#include "SingletonHolder.h"


typedef SingletonHolder <Factory <QGraphicsPixmapItem, size_t>> ItemFactory;

template <class T>
class ItemFactoryRegistration
{
public:
    explicit ItemFactoryRegistration(const size_t id)
    {
        ItemFactory::Instance().Register(
                    id, []() { return static_cast <QGraphicsPixmapItem *> (new T); });
    }
};

