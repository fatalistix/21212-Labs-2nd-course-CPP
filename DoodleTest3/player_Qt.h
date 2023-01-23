#pragma once

#include "drawingitem.h"

class Player_Qt : public DrawingItem
{
public:
    Player_Qt();
};






//class Player_Qt : public QGraphicsPixmapItem
//{
//public:
//    Player_Qt();

//private:
//    QPixmap p;
//    const double HITBOX_RATIO = 0.48;
//    const double HITBOX_X_LT_OFFSET_RATIO = 0.2;
//    const double HITBOX_Y_LT_OFFSET_RATIO = 0.11;
//};


//constexpr size_t PLAYER_HITBOX_X_LT_OFFSET = size_t(double(PLAYER_MODEL_WIDTH)  * 0.18);
//constexpr size_t PLAYER_HITBOX_Y_LT_OFFSET = size_t(double(PLAYER_MODEL_HEIGHT) * 0.23);
