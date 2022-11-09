#pragma once

#include <stack>
#include <sstream>
#include <string>

#include "CommandFactoryRegistrations.h"

class PrintTopNumber : public Command
{
public:
    PrintTopNumber()=default;
    ~PrintTopNumber() override=default;

    void DoCommand(std::stack<int> &,
            std::stringstream &, std::string &) override;
};

class Emit : public Command
{
public:
    Emit()=default;
    ~Emit() override=default;

    void DoCommand(std::stack<int> &,
            std::stringstream &, std::string &) override;
};

namespace
{
    CommandFactoryRegistration<PrintTopNumber> PrintTopNumber_(".");
    CommandFactoryRegistration<Emit> Emit_("emit");
}