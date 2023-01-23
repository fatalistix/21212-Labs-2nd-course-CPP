#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "gameunit.h"

constexpr size_t PLAYER_ID = 0;

class GameField;

class Player : public GameUnit
{
public:
    Player();

    ~Player() override;

    void changePos() override;
    double getVerticalVelocity();

private: //в public
    void moveLeft (size_t fieldWidth);
    void moveRight(size_t fieldWidth);

    void stepped();
    void reset(double x, double y)
    {
        x_LT = x;
        y_LT = y;
    }

    friend GameField;
};

#endif // PLAYER_H
