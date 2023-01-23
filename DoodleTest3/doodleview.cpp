#include "doodleview.h"
#include "preferences.h"
#include "ItemFactory.h"

#include <QDebug>
#include <QPixmap>
#include <QScrollBar>

DoodleView::DoodleView(QWidget * parent)
    : QGraphicsView(parent)
    , scene(this)
{
    this->setFixedWidth(WIDTH);
    this->setFixedHeight(HEIGHT);
    this->setSceneRect(QRect(0, 0, WIDTH, HEIGHT));
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(&scene);
    this->verticalScrollBar()->blockSignals(true);
    this->horizontalScrollBar()->blockSignals(true);
}

DoodleView::~DoodleView() {}

void DoodleView::show(std::vector <std::pair<QPoint, size_t>> coords)
{
    for (size_t i = 0; i < coords.size(); i++)
    {
        if (items.size() == int(i))
        {
            std::shared_ptr<QGraphicsPixmapItem> buf;
            buf.reset(ItemFactory::Instance().CreateObject(coords[i].second));
            items.push_back(data(coords[i].second, buf, buf->pos()));
            buf->setPos(coords[i].first - items.last().offset);
            scene.addItem(buf.get());
        }
        else
        {
            if (coords[i].second == items[i].id)
            {
                items[i].item->setPos(coords[i].first - items[i].offset);
            }
            else
            {
                scene.removeItem(items[i].item.get());
                items[i].item.reset(ItemFactory::Instance().CreateObject(coords[i].second));
                items[i].item->setPos(coords[i].first - items[i].offset);
                scene.addItem(items[i].item.get());
                items[i].id = coords[i].second;
            }
        }
    }
}
