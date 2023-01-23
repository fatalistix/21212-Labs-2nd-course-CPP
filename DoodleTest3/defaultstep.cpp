#include "defaultstep.h"
#include "preferences.h"

DefaultStep::DefaultStep(size_t x_LT, size_t y_LT)
    : GameUnit(DEFAULT_STEP_ID,
               x_LT, y_LT,
               DEFAULT_STEP_HITBOX_WIDTH, DEFAULT_STEP_HITBOX_HEIGHT,
               0, 0, 0, 0)
{}

void DefaultStep::changePos() {}

void DefaultStep::reset(int x)
{
    x_LT = x;
    y_LT = 0;
}
