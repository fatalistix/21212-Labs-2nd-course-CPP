#pragma once

#include <sstream>
#include <stack>
#include <string>

#include "CommandFactoryRegistrations.h"

class If : public Command
{
public:
    If()=default;
    ~If() override=default;

    void DoCommand(std::stack<int> &,
                   std::stringstream &, std::string &) override;
};

//class Else : public Command
//{
//public:
//    Else()=default;
//    ~Else() override=default;
//
//    void DoCommand(std::stack<int> &,
//                   std::stringstream &, std::string &) override;
//};
//
//class Then : public Command
//{
//public:
//    Then() = default;
//
//    ~Then() override = default;
//
//    void DoCommand(std::stack<int> &,
//                   std::stringstream &, std::string &) override;
//};

namespace
{
    CommandFactoryRegistration<If> If_("if");
//    CommandFactoryRegistration<Else> Else_("else");
//    CommandFactoryRegistration<Then> Then_("then");
}