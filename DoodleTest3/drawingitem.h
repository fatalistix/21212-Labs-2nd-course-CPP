#pragma once

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>

class DrawingItem : public QGraphicsPixmapItem
{
public:
    explicit DrawingItem(size_t z_value,
                         size_t hitbox_width,
                         size_t hitbox_height,
                         double hitbox_width_ratio,
                         double hitbox_height_ratio,
                         double hitbox_x_lt_offset_ratio,
                         double hitbox_y_lt_offset_ratio,
                         const QString & path);

private:
    QPixmap p;
};
