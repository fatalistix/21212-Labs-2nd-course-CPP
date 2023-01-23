#ifndef DOODLEVIEW_H
#define DOODLEVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QMap>
#include <QPixmap>

#include <memory>

class DoodleView : public QGraphicsView
{
public:
    explicit DoodleView(QWidget * parent = nullptr);
    ~DoodleView();

public slots:
    void show(std::vector <std::pair<QPoint, size_t>>);


private:
    struct data
    {
        size_t id;
        std::shared_ptr<QGraphicsPixmapItem> item;
        QPointF offset;

        explicit data(size_t a, std::shared_ptr<QGraphicsPixmapItem> & b,
                      const QPointF & c) : id(a), item(b), offset(c)
        {}
    };
    QGraphicsScene scene;

    /// GraphicPixmapItems
    QList <data> items;
    // что-то типа очереди/списка
//    std::map <size_t, QList <std::shared_ptr <QGraphicsPixmapItem>>> m;
};

#endif // DOODLEVIEW_H
