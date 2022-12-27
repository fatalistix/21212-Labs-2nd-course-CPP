#pragma once

#include <algorithm>
#include <string>

#include "CommandFactory.h"

typedef char commandType;

bool IsNumber(std::string & s)
{
    if (std::ranges::any_of(s.begin(), s.end(),
                            [](char c) {return !std::isdigit(c);}))
    {
        return false;
    }
    return true;
}

enum COMMAND_TYPE
{
    EMPTY = -2,
    UNKNOWN = -1,
    PUSH_INT = 0,
    COMMAND = 1,

};

commandType GetCommandType(std::string & s)
{
    if (s.empty())
    {
        return EMPTY;
    }
    else if (IsNumber(s))
    {
        return PUSH_INT;
    }
    else if (CommandFactory::Instance().IsRegistered(s))
    {
        return COMMAND;
    }
    else
    {
        return UNKNOWN;
    }
}
