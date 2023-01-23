#include "player.h"
#include "preferences.h"

#include <iostream>

Player::Player()
    : GameUnit(PLAYER_ID, PLAYER_START_POS_X_LT, PLAYER_START_POS_Y_LT,
               PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT,
               PLAYER_DEFAULT_VERTICAL_VELOCITY, PLAYER_DEFAULT_HORIZONTAL_VELOCITY,
               PLAYER_DEFAULT_VERTICAL_ACCELERATION, 0)
{}

Player::~Player() {}

void Player::moveLeft(size_t fieldWidth)
{
    x_LT -= horizontalVelocity;
    if (x_LT < -double(width))
    {
        x_LT = fieldWidth;
    }
}

void Player::moveRight(size_t fieldWidth)
{
    x_LT += horizontalVelocity;
    if (x_LT > fieldWidth)
    {
        x_LT = -double(width);
    }
}

void Player::changePos()
{
    y_LT += verticalVelocity + verticalAcceleration / 2;
    verticalVelocity += verticalAcceleration;
//    if (verticalVelocity >= std::abs(PLAYER_DEFAULT_VERTICAL_VELOCITY))
//    {
//        verticalVelocity *= -1;
//    }
}

void Player::stepped()
{
    verticalVelocity = PLAYER_DEFAULT_VERTICAL_VELOCITY;
}

double Player::getVerticalVelocity()
{
    return verticalVelocity;
}
