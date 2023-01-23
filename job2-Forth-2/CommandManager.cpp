#include "CommandManager.h"

#include <algorithm>

typedef char commandType;

enum COMMAND_TYPE
{
    CT_EMPTY = -2,
    CT_UNKNOWN = -1,
    CT_PUSH_INT = 0,
    CT_COMMAND = 1,
};

bool IsNumber(std::string & s)
{
    if (std::ranges::any_of(s.begin(), s.end(),
                            [](char c) {return !std::isdigit(c);}))
    {
        return false;
    }
    return true;
}

commandType GetCommandType(std::string & s)
{
    if (s.empty())
    {
        std::cerr << "Used command \"EMPTY\"" << std::endl;
        return CT_EMPTY;
    }
    else if (IsNumber(s))
    {
        return CT_PUSH_INT;
    }
    else if (CommandFactory::Instance().IsRegistered(s))
    {
        return CT_COMMAND;
    }
    else
    {
        return CT_UNKNOWN;
    }
}

std::string CommandManager::DoCommand(std::string & input, std::stack<int> & stack, flag & status)
{
    switch (GetCommandType(input))
    {
        case CT_EMPTY:
        {
            return "";
        }
        case CT_PUSH_INT:
        {
            stack.push(std::stoi(input));
            return "";
        }
        case CT_COMMAND:
        {
            auto it = createdCommands_.find(input);
            if (it == createdCommands_.end())
            {
                command_ = CommandFactory::Instance().CreateObject(input);
                createdCommands_.insert(std::make_pair(input, command_));
            }
            else
            {
                command_ = it->second;
            }

            try
            {
                std::string forRet = command_->DoCommand(stack, currentCommands, status);
                if (status != F_OK)
                {
                    customFlags_.insert(std::make_pair(status, command_));
                }
                return forRet;
            }
            catch (std::invalid_argument& e)
            {
                status = F_EXCEPTION;
                return e.what();
            }
            catch (std::runtime_error& e)
            {
                status = F_EXCEPTION;
                return e.what();
            }
        }
        default:
        {
            if (status == F_OK)
            {
                status = F_UNKNOWN;
                return " " + input;
            }
            else
            {

            }
        }
    }
    return "";
}