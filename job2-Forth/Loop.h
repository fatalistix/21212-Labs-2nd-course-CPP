#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "CommandFactoryRegistrations.h"

class Do : public Command
{
public:
    Do()=default;
    ~Do() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

namespace
{
    CommandFactoryRegistration<Do> Do_("do");
}