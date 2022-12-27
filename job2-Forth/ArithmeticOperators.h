#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "CommandFactoryRegistrations.h"

class Add : public Command
{
public:
    Add()=default;
    ~Add() override=default;

    void DoCommand(std::stack<int> &,
            std::stringstream &, std::string &) override;
};

class Mul : public Command
{
public:
    Mul()=default;
    ~Mul() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Sub : public Command
{
public:
    Sub()=default;
    ~Sub() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Div : public Command
{
public:
    Div()=default;
    ~Div() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

class Mod : public Command
{
public:
    Mod()=default;
    ~Mod() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};


namespace
{
    CommandFactoryRegistration<Add> Add_("+");
    CommandFactoryRegistration<Mul> Mul_("*");
    CommandFactoryRegistration<Sub> Sub_("-");
    CommandFactoryRegistration<Div> Div_("/");
    CommandFactoryRegistration<Mod> Mod_("mod");
}
