#pragma once

#include <stack>
#include <sstream>
#include <string>

#include "CommandFactoryRegistrations.h"

class Dup : public Command
{
public:
    Dup()=default;
    ~Dup() override=default;

    void DoCommand(std::stack<int> &,
            std::stringstream &, std::string &) override;
};

class Drop : public Command
{
public:
    Drop()=default;
    ~Drop() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Swap : public Command
{
public:
    Swap()=default;
    ~Swap() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Over : public Command
{
public:
    Over()=default;
    ~Over() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Rot : public Command
{
public:
    Rot()=default;
    ~Rot() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

namespace
{
    CommandFactoryRegistration<Dup> Duplicate_("dup");
    CommandFactoryRegistration<Drop> Drop_("drop");
    CommandFactoryRegistration<Swap> Swap_("swap");
    CommandFactoryRegistration<Over> Over_("over");
    CommandFactoryRegistration<Rot> Rotate_("rot");
}
