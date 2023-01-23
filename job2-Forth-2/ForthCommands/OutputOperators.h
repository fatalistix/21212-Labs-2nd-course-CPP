#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "Base/CommandFactoryRegistration.h"

class PrintTopNumber : public Command
{
public:
    PrintTopNumber()=default;
    ~PrintTopNumber() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Emit : public Command
{
public:
    Emit()=default;
    ~Emit() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Carriage : public Command
{
public:
    Carriage()=default;
    ~Carriage() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class PrintString : public Command
{
public:
    PrintString()=default;
    ~PrintString() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

namespace
{
    CommandFactoryRegistration<PrintTopNumber> PrintTopNumber_(".");
    CommandFactoryRegistration<Emit> Emit_("emit");
    CommandFactoryRegistration<Carriage> Carriage_("cr");
    CommandFactoryRegistration<PrintString> PrintString_(".\"");
}