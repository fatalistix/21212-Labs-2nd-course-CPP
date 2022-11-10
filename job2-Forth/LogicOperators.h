#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "CommandFactoryRegistrations.h"

class More : public Command
{
public:
    More()=default;
    ~More() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Less : public Command
{
public:
    Less()=default;
    ~Less() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Equal : public Command
{
public:
    Equal()=default;
    ~Equal() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class And : public Command
{
public:
    And()=default;
    ~And() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Or : public Command
{
public:
    Or()=default;
    ~Or() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Invert : public Command
{
public:
    Invert()=default;
    ~Invert() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
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
