#pragma once

#include <iostream>
#include <sstream>
#include <stack>
//#include <vector>

#include "CommandManager.h"

class CommandManager;

class Command
{
public:
    Command()=default;
    virtual ~Command()=default;

    virtual void Debug(CommandManager & manager, std::stringstream & buffer, std::istream & in,
                         std::stack<std::string> & keywords) = 0;

    virtual void Execute(CommandManager & manager, std::stack<int> & stack, std::stringstream & buffer,
                         std::ostream & out) = 0;

    virtual void Pass(CommandManager & manager, std::stringstream & buffer) = 0;
};