#pragma once

#include <sstream>
#include <stack>

#include "Base/Command.h"
#include "Base/CommandFactoryRegistration.h"

class Do : public Command
{
public:
    Do()=default;
    ~Do() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override;
};

class Loop : public Command
{
public:
    Loop()=default;
    ~Loop() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {}
};

class I : public Command
{
public:
    I()=default;
    ~I() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override {}
    void Pass(CommandManager &, std::stringstream &) override {}
};

namespace
{
    CommandFactoryRegistration<Do> Do_("do");
    CommandFactoryRegistration<Loop> Loop_("loop");
    CommandFactoryRegistration<I> I_("i");
}