#pragma once

#include <sstream>
#include <stack>

class Command
{
public:
    Command()=default;
    virtual ~Command()=default;

    virtual void DoCommand(std::stack<int> &,
            std::stringstream &, std::string &) = 0;
};
