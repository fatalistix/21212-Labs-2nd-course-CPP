#include "controller.h"
#include "pressedkeys.h"

#include <iostream>

Controller::Controller(QObject *parent)
    : QObject{parent}
    , fieldModel(this)
{
//    timer.start(2); //!!!!
    connect(&timer, &QTimer::timeout, &fieldModel, &GameField ::changePositions);
    connect(&timer, &QTimer::timeout, this,        &Controller::onCurrentPressedKeys);


    connect(this, &Controller::moveLeft,  &fieldModel, &GameField::movePlayerLeft);
    connect(this, &Controller::moveRight, &fieldModel, &GameField::movePlayerRight);


    connect(&fieldModel, &GameField::returnPos, this, &Controller::returnedPos);


    connect(&fieldModel, &GameField::endgame, this, &Controller::endgame);
}

Controller::~Controller() {}

void Controller::start()
{
    timer.start(2);
}


void Controller::onCurrentPressedKeys()
{
    if (KeysServer::Instance().LeftPressed())
    {
        emit moveLeft();
    }
    else
    {
        if (KeysServer::Instance().RightPressed())
        {
            emit moveRight();
        }
    }
}

void Controller::returnedPos(std::vector <std::pair <QPoint, size_t>> coords)
{
    emit draw(std::move(coords));
}

void Controller::endgame()
{
    timer.stop();
    emit gameOver();
}
