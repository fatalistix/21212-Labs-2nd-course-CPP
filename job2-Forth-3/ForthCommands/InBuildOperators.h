#pragma once

#include <stack>

#include "Base/Command.h"
#include "Base/CommandFactoryRegistration.h"

class Dup : public Command
{
public:
    Dup()=default;
    ~Dup() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Drop : public Command
{
public:
    Drop()=default;
    ~Drop() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Swap : public Command
{
public:
    Swap()=default;
    ~Swap() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Over : public Command
{
public:
    Over()=default;
    ~Over() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Rot : public Command
{
public:
    Rot()=default;
    ~Rot() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

namespace
{
    CommandFactoryRegistration<Dup> Duplicate_("dup");
    CommandFactoryRegistration<Drop> Drop_("drop");
    CommandFactoryRegistration<Swap> Swap_("swap");
    CommandFactoryRegistration<Over> Over_("over");
    CommandFactoryRegistration<Rot> Rotate_("rot");
}