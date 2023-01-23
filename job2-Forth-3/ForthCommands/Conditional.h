#pragma once

#include <sstream>
#include <stack>

#include "Base/Command.h"
#include "Base/CommandFactoryRegistration.h"

class If : public Command
{
public:
    If()=default;
    ~If() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override;
};

class Else : public Command
{
public:
    Else()=default;
    ~Else() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class Then : public Command
{
public:
    Then()=default;
    ~Then() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override;
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

namespace
{
    CommandFactoryRegistration<If> If_("if");
    CommandFactoryRegistration<Else> Else_("else");
    CommandFactoryRegistration<Then> Then_("then");
}