#ifndef DEFAULTSTEP_H
#define DEFAULTSTEP_H

#include "gameunit.h"

constexpr size_t DEFAULT_STEP_ID = 1;

class DefaultStep : public GameUnit
{
public:
    explicit DefaultStep(size_t x_LT, size_t y_LT);

    ~DefaultStep() override = default;

    void changePos() override;

    void reset(int);
};

#endif // DEFAULTSTEP_H
