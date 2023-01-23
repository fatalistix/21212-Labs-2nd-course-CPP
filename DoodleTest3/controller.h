#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QPixmap>
#include <QTimer>
#include <QTimerEvent>
#include <QWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>


#include <vector>

#include "gamefield.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

    ~Controller();

private slots:
    void onCurrentPressedKeys();
    void returnedPos(std::vector <std::pair <QPoint, size_t>>);

public slots:
    void start(); // !!!!!!
    void endgame(); // !!!!!!

signals:
    void moveLeft();
    void moveRight();

    void resetModel(); // !!!!!!!
    void updatePositions();
    void draw(std::vector <std::pair <QPoint, size_t>>);

    void gameOver(); // !!!!!!!

private:
    QTimer timer;

    GameField fieldModel;
};

#endif // CONTROLLER_H
