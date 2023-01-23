#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "Base/CommandFactoryRegistration.h"

class Add : public Command
{
public:
    Add()=default;
    ~Add() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Mul : public Command
{
public:
    Mul()=default;
    ~Mul() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Sub : public Command
{
public:
    Sub()=default;
    ~Sub() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Div : public Command
{
public:
    Div()=default;
    ~Div() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};

class Mod : public Command
{
public:
    Mod()=default;
    ~Mod() override=default;

    std::string DoCommand(std::stack<int> &, std::stringstream &, flag &) override;
};


namespace
{
    CommandFactoryRegistration<Add> Add_("+");
    CommandFactoryRegistration<Mul> Mul_("*");
    CommandFactoryRegistration<Sub> Sub_("-");
    CommandFactoryRegistration<Div> Div_("/");
    CommandFactoryRegistration<Mod> Mod_("mod");
}