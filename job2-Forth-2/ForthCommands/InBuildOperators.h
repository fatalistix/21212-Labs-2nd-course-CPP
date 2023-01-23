#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "Base/CommandFactoryRegistration.h"

class Dup : public Command
{
public:
    Dup()=default;
    ~Dup() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Drop : public Command
{
public:
    Drop()=default;
    ~Drop() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Swap : public Command
{
public:
    Swap()=default;
    ~Swap() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Over : public Command
{
public:
    Over()=default;
    ~Over() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Rot : public Command
{
public:
    Rot()=default;
    ~Rot() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

namespace
{
    CommandFactoryRegistration<Dup> Duplicate_("dup");
    CommandFactoryRegistration<Drop> Drop_("drop");
    CommandFactoryRegistration<Swap> Swap_("swap");
    CommandFactoryRegistration<Over> Over_("over");
    CommandFactoryRegistration<Rot> Rotate_("rot");
}