#pragma once

#include <sstream>
#include <string>
#include <stack>

typedef char flag;

enum FLAGS
{
    F_UNKNOWN = -1,
    F_OK = 0,
    F_EXCEPTION = 1,
    F_WAITING_FOR_STRING = 2,
};

class Command
{
public:
    Command()=default;
    virtual ~Command()=default;

    virtual std::string DoCommand(std::stack<int> & stack, std::stringstream & currentCommands, flag & status) = 0;
};
