#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QFont>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <memory>

#include "controller.h"
#include "doodleview.h"

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void startGameButtonPressed();
    void gameEnded();
    void restartGame();

signals:
    void startGame();

private:
//    Ui::MainWindow *ui;

    /// Application base
//    QWidget centralWidget;
    std::unique_ptr <QWidget> gameWidget;
    std::unique_ptr <QWidget> mainMenuWidget;
    std::unique_ptr <QWidget> endGameWidget;
//    QWidget mainMenuWidget;
//    QWidget endGameWidget;
    std::unique_ptr <QPushButton> startGameButton;
    std::unique_ptr <QPushButton> restartGameButton;
    std::unique_ptr <QLabel> doodleGameLabel;
    std::unique_ptr <QLabel> endGameLabel;

//    QVBoxLayout layout;
    std::unique_ptr <QVBoxLayout> mainMenuLayout;
    std::unique_ptr <QVBoxLayout> gameLayout;
    std::unique_ptr <QVBoxLayout> endGameLayout;
//    QVBoxLayout centralWidgetLayout;

    /// App logic
    Controller controller;

    /// Graphics
    DoodleView view;

    QFont font;
};
#endif // MAINWINDOW_H
