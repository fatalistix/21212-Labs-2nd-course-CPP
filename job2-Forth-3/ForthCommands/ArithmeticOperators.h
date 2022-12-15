#pragma once

#include <stack>

#include "Base/Command.h"
#include "Base/CommandFactoryRegistration.h"

class Add : public Command
{
public:
    Add()=default;
    ~Add() override=default;

    void Debug(std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Mul : public Command
{
public:
    Mul()=default;
    ~Mul() override=default;

    void Debug  (std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Sub : public Command
{
public:
    Sub()=default;
    ~Sub() override=default;

    void Debug  (std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Div : public Command
{
public:
    Div()=default;
    ~Div() override=default;

    void Debug  (std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};

class Mod : public Command
{
public:
    Mod()=default;
    ~Mod() override=default;

    void Debug  (std::stringstream &, std::istream &, std::stack<std::string> &) override {};
    void Execute(std::stack<int> &, std::stringstream &, std::ostream &) override;
    void Pass(std::stringstream &) override {};
};


namespace
{
    CommandFactoryRegistration<Add> Add_("+");
    CommandFactoryRegistration<Mul> Mul_("*");
    CommandFactoryRegistration<Sub> Sub_("-");
    CommandFactoryRegistration<Div> Div_("/");
    CommandFactoryRegistration<Mod> Mod_("mod");
}