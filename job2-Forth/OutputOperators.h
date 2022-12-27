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

class Carriage : public Command
{
public:
    Carriage()=default;
    ~Carriage() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class PrintString : public Command
{
public:
    PrintString()=default;
    ~PrintString() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

namespace
{
    CommandFactoryRegistration<PrintTopNumber> PrintTopNumber_(".");
    CommandFactoryRegistration<Emit> Emit_("emit");
    CommandFactoryRegistration<Carriage> Carriage_("cr");
    CommandFactoryRegistration<PrintString> PrintString_(".\"");
}