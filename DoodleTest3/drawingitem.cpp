#include "drawingitem.h"

DrawingItem::DrawingItem(size_t z_value,
                         size_t hitbox_width,
                         size_t hitbox_height,
                         double hitbox_width_ratio,
                         double hitbox_height_ratio,
                         double hitbox_x_lt_offset_ratio,
                         double hitbox_y_lt_offset_ratio,
                         const QString & path)
    : p(path)
{
    this->setPixmap(p);
    double model_width  = double(hitbox_width)  / hitbox_width_ratio;
    double model_height = double(hitbox_height) / hitbox_height_ratio;
    this->setScale(model_width / p.width());
    this->setZValue(z_value);
    this->setPos(hitbox_x_lt_offset_ratio * model_width,
                 hitbox_y_lt_offset_ratio * model_height);
}
