#include "gamefield.h"
#include "preferences.h"

#include <iostream>
#include <QRandomGenerator>

GameField::GameField(QObject * parent)
    : QObject{parent}
    , player()
    , steps(DEFAULT_NUMBER_OF_STEPS)
{
//    steps[0].reset(new DefaultStep((WIDTH - DEFAULT_STEP_HITBOX_WIDTH) / 2, DANGER_HEIGHT));
//    for (size_t i = 1; i < DEFAULT_NUMBER_OF_STEPS; i++)
//    {
//        steps[i].reset(new DefaultStep(
//                           QRandomGenerator::global()->bounded(int(STEPS_MIN_X_LT),
//                                                               int(STEPS_MAX_X_LT)),
//                           double(DANGER_HEIGHT) * (DEFAULT_NUMBER_OF_STEPS - i) / DEFAULT_NUMBER_OF_STEPS -
//                           QRandomGenerator::global()->bounded(1.) * DANGER_HEIGHT / DEFAULT_NUMBER_OF_STEPS));
//    }

    this->reset();
}

GameField::~GameField() {}

void GameField::changePositions()
{
    std::vector <std::pair <QPoint, size_t>> coords;
    player.changePos();
    if (player.getCurrentPos_LT().y() < PLAYER_MAX_HEIGHT)
    {
        verticalShift(PLAYER_MAX_HEIGHT - player.getCurrentPos_LT().y());
    }
    if (player.getCurrentPos_LT().y() > DANGER_HEIGHT)
    {
//        exit(0);
        emit endgame();
    }
    coords.emplace_back(std::make_pair(player.getCurrentPos_LT(), player.ID));
    for (size_t i = 0; i < DEFAULT_NUMBER_OF_STEPS; i++)
    {
        steps[i]->changePos();
        if (player.getVerticalVelocity() > 0 &&
                steps[i]->getCurrentPos_LT().y() + EPS >= player.getCurrentPos_LT().y() + player.getHitboxHeight() &&
                steps[i]->getCurrentPos_LT().y() <= player.getCurrentPos_LT().y() + player.getHitboxHeight() &&
                steps[i]->getCurrentPos_LT().x() - player.getHitboxWidth() <= player.getCurrentPos_LT().x() &&
                player.getCurrentPos_LT().x() <= steps[i]->getCurrentPos_LT().x() + steps[i]->getHitboxWidth())
        {
            player.stepped();
        }
        coords.emplace_back(std::make_pair(steps[i]->getCurrentPos_LT(), steps[i]->ID));
    }
    emit returnPos(std::move(coords));
}

void GameField::verticalShift(size_t shift)
{
    player.verticalShift(shift);
    for (size_t i = 0; i < steps.size(); i++)
    {
        steps[i]->verticalShift(shift);
        if (steps[i]->getCurrentPos_LT().y() > DANGER_HEIGHT)
        {
            steps[i]->reset(QRandomGenerator::global()->bounded(int(STEPS_MIN_X_LT),
                                                                int(STEPS_MAX_X_LT)));
        }
    }
}

void GameField::movePlayerLeft()
{
    player.moveLeft(WIDTH);
}

void GameField::movePlayerRight()
{
    player.moveRight(WIDTH);
}

void GameField::reset()
{
    player.reset(PLAYER_START_POS_X_LT, PLAYER_START_POS_Y_LT);

    steps.resize(DEFAULT_NUMBER_OF_STEPS);

    steps[0].reset(new DefaultStep((WIDTH - DEFAULT_STEP_HITBOX_WIDTH) / 2, DANGER_HEIGHT));
    for (size_t i = 1; i < DEFAULT_NUMBER_OF_STEPS; i++)
    {
        steps[i].reset(new DefaultStep(
                           QRandomGenerator::global()->bounded(int(STEPS_MIN_X_LT),
                                                               int(STEPS_MAX_X_LT)),
                           double(DANGER_HEIGHT) * (DEFAULT_NUMBER_OF_STEPS - i) / DEFAULT_NUMBER_OF_STEPS -
                           QRandomGenerator::global()->bounded(1.) * DANGER_HEIGHT / DEFAULT_NUMBER_OF_STEPS));
    }
}
