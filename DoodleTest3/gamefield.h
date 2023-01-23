#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#pragma once

#include <memory>
#include <vector>

#include <QObject>

#include "player.h"
#include "defaultstep.h"

class GameField : public QObject
{
    Q_OBJECT
public:
    GameField(QObject *parent = nullptr);
    ~GameField();

public slots:
    void changePositions();
    void movePlayerLeft();
    void movePlayerRight();
//    void start(); //!!!!!!

signals:
    void returnPos(std::vector <std::pair <QPoint, size_t>>);
    void endgame();


private:
    Player player;
    // список с указателями на абстрактный класс платформ
    // платформы хранят свое имя или номер (поле типа)
    std::vector <std::unique_ptr<DefaultStep>> steps;

    void verticalShift(size_t);
    void reset();
};

#endif // GAMEFIELD_H
