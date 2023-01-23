#include "mainwindow.h"
#include "preferences.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//    , centralWidget(this)
    , gameWidget(new QWidget)
    , mainMenuWidget(new QWidget)
    , endGameWidget(new QWidget)
    , startGameButton(new QPushButton)
    , restartGameButton(new QPushButton)
    , doodleGameLabel(new QLabel("Ready for game?", mainMenuWidget.get()))
    , endGameLabel(new QLabel("End Game\nRestart?", endGameWidget.get()))
//    , layout(&centralWidget)
    , mainMenuLayout(new QVBoxLayout(mainMenuWidget.get()))
    , gameLayout(new QVBoxLayout(gameWidget.get()))
    , endGameLayout(new QVBoxLayout(endGameWidget.get()))
    , controller(this)
    , view()
    , font("Helvetica", 50)
{
//    ui->setupUi(this);
//    ui->verticalLayout->setGeometry(QRect(0, 0, 600, 800));


//    centralWidget.setGeometry(QRect(0, 0, WIDTH, HEIGHT));
//    startGameButton->setGeometry(QRect(0, 0, WIDTH, HEIGHT / 4));

//    this->setCentralWidget(&centralWidget);
//    centralWidget.setLayout(&layout);
//    layout.addWidget(&view);  // !!!!!!!


    mainMenuWidget->setGeometry(QRect(0, 0, WIDTH, HEIGHT));
    gameWidget    ->setGeometry(QRect(0, 0, WIDTH, HEIGHT));
    endGameWidget ->setGeometry(QRect(0, 0, WIDTH, HEIGHT));

    mainMenuWidget->setLayout(mainMenuLayout.get());
    gameWidget    ->setLayout(gameLayout.get());
    endGameWidget ->setLayout(endGameLayout.get());

    doodleGameLabel->setGeometry(QRect(0, 0, WIDTH, HEIGHT / 4));
    doodleGameLabel->setFont(font);
    doodleGameLabel->setAlignment(Qt::AlignHCenter);

    endGameLabel->setGeometry(QRect(0, 0, WIDTH, HEIGHT / 4));
    endGameLabel->setFont(font);
    endGameLabel->setAlignment(Qt::AlignHCenter);

    startGameButton->setText("START");

    restartGameButton->setText("RESTART");

    endGameLayout->addWidget(endGameLabel.get());
    endGameLayout->addWidget(restartGameButton.get());

    gameLayout->addWidget(&view);

    mainMenuLayout->addWidget(doodleGameLabel.get());
    mainMenuLayout->addWidget(startGameButton.get());

    this->setWindowTitle("Doodle");
    this->setFixedSize(WIDTH + 15, HEIGHT + 15);

    this->setCentralWidget(mainMenuWidget.get());




    connect(&controller, &Controller::draw, &view, &DoodleView::show);

    connect(startGameButton.get(), &QPushButton::clicked, this, &MainWindow::startGameButtonPressed);
    connect(this, &MainWindow::startGame, &controller, &Controller::start);
    connect(&controller, &Controller::gameOver, this, &MainWindow::gameEnded);
    connect(restartGameButton.get(), &QPushButton::clicked, this, &MainWindow::restartGame);
}

MainWindow::~MainWindow()
{
//    delete ui;
}

void MainWindow::startGameButtonPressed()
{
//    mainMenuWidget.reset(takeCentralWidget());
    mainMenuWidget->setParent(0);
    this->setCentralWidget(gameWidget.get());
    emit startGame();
}

void MainWindow::gameEnded()
{
//    gameWidget.reset(takeCentralWidget());
    gameWidget->setParent(0);
    this->setCentralWidget(endGameWidget.get());
}

void MainWindow::restartGame()
{
    endGameWidget->setParent(0);
    this->setCentralWidget(endGameWidget.get());
    emit startGame();
}
