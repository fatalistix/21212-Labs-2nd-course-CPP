#pragma once

#include <iostream>

/// IDs
//constexpr size_t PLAYER_ID = 0;
//constexpr size_t DEFAULT_STEP_ID = 10;

/// ZValue
constexpr size_t PLAYER_Z = 2;
constexpr size_t STEPS_Z  = 1;

/// Main window and field parameters
constexpr double SCREEN_RATIO = 0.75;

constexpr size_t HEIGHT = 800;
constexpr size_t WIDTH  = size_t(SCREEN_RATIO * HEIGHT);

constexpr double DANGER_HEIGHT_RATIO = 1./12;
constexpr int DANGER_HEIGHT = size_t(double(HEIGHT) * (1 - DANGER_HEIGHT_RATIO));

constexpr size_t DEFAULT_NUMBER_OF_STEPS = 4;
constexpr int EPS = HEIGHT / 500;

/// Units ratio
//constexpr double MOBS_RATIO  = 1./6;
//constexpr double STEPS_RATIO = 1./12;

/// Player parameters
//constexpr size_t PLAYER_MODEL_WIDTH  = size_t(double(WIDTH) * MOBS_RATIO);
//constexpr size_t PLAYER_MODEL_HEIGHT = size_t(double(WIDTH) * MOBS_RATIO);

//constexpr size_t PLAYER_HITBOX_X_LT_OFFSET = size_t(double(PLAYER_MODEL_WIDTH)  * 0.18);
//constexpr size_t PLAYER_HITBOX_Y_LT_OFFSET = size_t(double(PLAYER_MODEL_HEIGHT) * 0.23);

//constexpr size_t PLAYER_HITBOX_WIDTH  = size_t(double(PLAYER_MODEL_WIDTH)  * 0.51);
//constexpr size_t PLAYER_HITBOX_HEIGHT = size_t(double(PLAYER_MODEL_HEIGHT) * 0.46);

//constexpr size_t PLAYER_START_POS_X_LT = WIDTH / 2 - PLAYER_HITBOX_WIDTH / 2;
//constexpr size_t PLAYER_START_POS_Y_LT = DANGER_HEIGHT - PLAYER_HITBOX_HEIGHT ;

//constexpr double PLAYER_DEFAULT_VERTICAL_VELOCITY = -double(HEIGHT) / 400;          // 400
//constexpr double PLAYER_DEFAULT_HORIZONTAL_VELOCITY = double(WIDTH) / 1000;         // 1200
//constexpr double PLAYER_DEFAULT_VERTICAL_ACCELERATION = double(HEIGHT) / 130000;    // 200000

//constexpr int PLAYER_MAX_HEIGHT = int(double(DANGER_HEIGHT) - double(PLAYER_HITBOX_HEIGHT) -
//        (PLAYER_DEFAULT_VERTICAL_VELOCITY * PLAYER_DEFAULT_VERTICAL_VELOCITY) / PLAYER_DEFAULT_VERTICAL_ACCELERATION / 2);

///// Default step parameters
//constexpr size_t DEFAULT_STEP_MODEL_WIDTH  = size_t(double(WIDTH) * STEPS_RATIO);
//constexpr size_t DEFAULT_STEP_MODEL_HEIGHT = size_t(double(HEIGHT) * STEPS_RATIO);
//constexpt sixe_t DEFAULT_STEP_HITBOX_WIDTH = size_t(double(WIDTH))


//constexpr size_t DEFAULT_NUMBER_OF_STEPS = 4;
//constexpr size_t STEPS_MIN_X_LT = WIDTH / 60;
//constexpr size_t STEPS_MAX_X_LT = WIDTH - WIDTH / 60 - DEFAULT_STEP_MODEL_WIDTH;


///Player parameters
constexpr size_t PLAYER_HITBOX_WIDTH  = size_t(0.08   * WIDTH);
constexpr size_t PLAYER_HITBOX_HEIGHT = size_t(0.0975 * HEIGHT);



/// Default Step parameters
constexpr size_t DEFAULT_STEP_HITBOX_WIDTH  = PLAYER_HITBOX_WIDTH * 2;
constexpr size_t DEFAULT_STEP_HITBOX_HEIGHT = size_t(0.02875 * HEIGHT);


constexpr size_t PLAYER_START_POS_X_LT = WIDTH / 2 - PLAYER_HITBOX_WIDTH / 2;
constexpr size_t PLAYER_START_POS_Y_LT = DANGER_HEIGHT - PLAYER_HITBOX_HEIGHT ;

constexpr double PLAYER_DEFAULT_VERTICAL_VELOCITY = -double(HEIGHT) / 400;          // 400
constexpr double PLAYER_DEFAULT_HORIZONTAL_VELOCITY = double(WIDTH) / 1000;         // 1200
constexpr double PLAYER_DEFAULT_VERTICAL_ACCELERATION = double(HEIGHT) / 130000;    // 200000


constexpr size_t STEPS_MIN_X_LT = WIDTH / 60;
constexpr size_t STEPS_MAX_X_LT = WIDTH - WIDTH / 60 - DEFAULT_STEP_HITBOX_WIDTH;

constexpr int PLAYER_MAX_HEIGHT = int(double(DANGER_HEIGHT) - double(PLAYER_HITBOX_HEIGHT) -
        (PLAYER_DEFAULT_VERTICAL_VELOCITY * PLAYER_DEFAULT_VERTICAL_VELOCITY) / PLAYER_DEFAULT_VERTICAL_ACCELERATION / 2);
