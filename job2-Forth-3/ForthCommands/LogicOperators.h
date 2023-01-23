#pragma once

#include <sstream>
#include <stack>

#include "Base/Command.h"
#include "Base/CommandFactoryRegistration.h"

class More : public Command
{
public:
    More()=default;
    ~More() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class Less : public Command
{
public:
    Less()=default;
    ~Less() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class Equal : public Command
{
public:
    Equal()=default;
    ~Equal() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class And : public Command
{
public:
    And()=default;
    ~And() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class Or : public Command
{
public:
    Or()=default;
    ~Or() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

class Invert : public Command
{
public:
    Invert()=default;
    ~Invert() override=default;

    void Debug(CommandManager &, std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(CommandManager &, std::stringstream &) override {};
};

namespace
{
    CommandFactoryRegistration<More> More_(">");
    CommandFactoryRegistration<Less> Less_("<");
    CommandFactoryRegistration<Equal> Equal_("=");
    CommandFactoryRegistration<And> And_("and");
    CommandFactoryRegistration<Or> Or_("or");
    CommandFactoryRegistration<Invert> Invert_("invert");
}