#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

class Command
{
public:
    Command()=default;
    virtual ~Command()=default;

    virtual void Debug(std::stringstream & buffer, std::istream & in,
                         std::stack<std::string> & keywords) = 0;

    virtual void Execute(std::stack<int> & stack, std::stringstream & buffer,
                         std::ostream & out) = 0;

    virtual void Pass(std::stringstream & buffer) = 0;
};