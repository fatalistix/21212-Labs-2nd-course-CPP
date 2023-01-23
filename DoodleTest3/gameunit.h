#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#pragma once

#include <QPoint>

class GameUnit
{
public:
    explicit GameUnit(size_t ID,
                      double start_x_LT, double start_y_LT,
                      size_t start_width, size_t start_height,
                      double start_verticalVelocity, double start_horizontalVelocity,
                      double verticalAcceleration,   double horizontalAcceleration);

    virtual ~GameUnit();

    int getHitboxHeight();
    int getHitboxWidth();
    QPoint getCurrentPos_LT();
    void verticalShift(size_t);
    virtual void changePos() = 0;

    const size_t ID;


protected:
    double x_LT;
    double y_LT;

    int width;
    int height;

    double verticalVelocity;
    double horizontalVelocity;

    const double verticalAcceleration;
    const double horizontalAcceleration;

};

#endif // GAMEUNIT_H
