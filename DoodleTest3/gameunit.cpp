#include "gameunit.h"

GameUnit::GameUnit(size_t id,
                   double start_x_LT, double start_y_LT,
                   size_t start_width, size_t start_height,
                   double start_verticalVelocity, double start_horizontalVelocity,
                   double verticalAcceleration, double horizontalAcceleration)

    : ID(id)
    , x_LT(start_x_LT), y_LT(start_y_LT)
    , width(start_width), height(start_height)
    , verticalVelocity(start_verticalVelocity), horizontalVelocity(start_horizontalVelocity)
    , verticalAcceleration(verticalAcceleration), horizontalAcceleration(horizontalAcceleration)
{

}

GameUnit::~GameUnit() {}

QPoint GameUnit::getCurrentPos_LT()
{
    return QPoint(x_LT, y_LT);
}

int GameUnit::getHitboxHeight()
{
    return height;
}

int GameUnit::getHitboxWidth()
{
    return width;
}

void GameUnit::verticalShift(size_t shift)
{
    y_LT += shift;
}
