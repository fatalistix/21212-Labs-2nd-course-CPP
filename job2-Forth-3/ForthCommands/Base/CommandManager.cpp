#include "CommandManager.h"

#include <algorithm>

typedef char commandType;

enum COMMAND_TYPE
{
    CT_UNKNOWN = -1,
    CT_PUSH_INT = 0,
    CT_COMMAND = 1,
};

bool IsNumber(const std::string & s)
{
    if (s == "-")
    {
        return false;
    }
    if (std::ranges::any_of(s.begin() + (s[0] == '-'), s.end(),
                            [](char c) {return !std::isdigit(c);}))
    {
        return false;
    }
    return true;
}

commandType GetCommandType(const std::string & s)
{
    if (IsNumber(s))
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

void CommandManager::Debug(const std::string & keyword, std::stringstream & buffer,
                           std::istream & in)
{
    switch (GetCommandType(keyword))
    {
        case CT_PUSH_INT:
            return;
        case CT_COMMAND:
        {
            auto it = createdCommands_.find(keyword);
            if (it == createdCommands_.end())
            {
                command_ = CommandFactory::Instance().CreateObject(keyword);
                createdCommands_.insert(std::make_pair(keyword, command_));
            }
            else
            {
                command_ = it->second.get();
            }
            command_->Debug(buffer, in, keywords_);
            return;
        }
        default:
        {
            throw std::invalid_argument(keyword + " ?");
        }
    }
}

void CommandManager::Execute(const std::string & keyword, std::stringstream & buffer, std::stack<int> & forthStack,
                             std::ostream & out)
{
    switch (GetCommandType(keyword))
    {
        case CT_PUSH_INT:
        {
            forthStack.emplace(std::stoi(keyword));
            return;
        }
        case CT_COMMAND:
        {
            command_ = createdCommands_.find(keyword)->second.get();
            command_->Execute(forthStack, buffer, out);
        }
    }
}

void CommandManager::Pass(const std::string & keyword, std::stringstream & buffer)
{
    switch (GetCommandType(keyword))
    {
        case CT_PUSH_INT:
        {
            return;
        }
        case CT_COMMAND:
        {
            command_ = createdCommands_.find(keyword)->second.get();
            command_->Pass(buffer);
        }
    }
}