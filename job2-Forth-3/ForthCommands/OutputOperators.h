#pragma once

#include <stack>

#include "Base/CommandFactoryRegistration.h"

class PrintTopNumber : public Command
{
public:
    PrintTopNumber()=default;
    ~PrintTopNumber() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Emit : public Command
{
public:
    Emit()=default;
    ~Emit() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Carriage : public Command
{
public:
    Carriage()=default;
    ~Carriage() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class PrintString : public Command
{
public:
    PrintString()=default;
    ~PrintString() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

namespace
{
    CommandFactoryRegistration<PrintTopNumber> PrintTopNumber_(".");
    CommandFactoryRegistration<Emit> Emit_("emit");
    CommandFactoryRegistration<Carriage> Carriage_("cr");
    CommandFactoryRegistration<PrintString> PrintString_(".\"");
}