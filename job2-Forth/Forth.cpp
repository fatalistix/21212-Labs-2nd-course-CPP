#include "Forth.h"

#include <algorithm>

Forth::~Forth()
{
    for (auto & c : createdCommands_)
    {
        delete c.second;
    }
}


std::string & operator>>(std::string & in, Forth & f)
{
    if (!in.empty())
    {
        f.inputData_.str(in);
        f.DoCommands();
    }
    return in;
}

std::string & operator<<(std::string & out, Forth & f)
{
    out = f.output;
}


bool IsNumber(std::string & s)
{
    if (std::ranges::any_of(s.begin(), s.end(),
                            [](char c) {return !std::isdigit(c);}))
    {
        return false;
    }
    return true;
}

typedef char commandType;
enum COMMAND_TYPE
{
    UNKNOWN = -1,
    PUSH_INT = 0,
    COMMAND = 1,

};

commandType GetCommandType(std::string & s)
{
    if (IsNumber(s))
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

void Forth::DoCommands()
{
    output.clear();
    std::string stringCommand;
    while (!inputData_.eof())
    {
        inputData_ >> stringCommand;
        auto inputCommand = GetCommandType(stringCommand);

        if (inputCommand == PUSH_INT)
        {
            forthStack_.push(std::stoi(stringCommand));
            forthStatus_ = OK;
        }
        else if (inputCommand == COMMAND)
        {
            auto it = createdCommands_.find(stringCommand);
            if (it == createdCommands_.end())
            {
                command_ = CommandFactory::Instance().CreateObject(stringCommand);
                createdCommands_.insert(std::make_pair(stringCommand, command_));
            }
            else
            {
                command_ = it->second;
            }
            try {
                command_->DoCommand(forthStack_, inputData_, output);
            }
            catch(std::invalid_argument & e)
            {
                output += e.what();
                forthStatus_ = EXCEPTION;
                break;
            }
            forthStatus_ = OK;
        }
        else
        {
            output += " " + stringCommand;
            forthStatus_ = UNKNOWN;
            break;
        }
    }
    switch (forthStatus_)
    {
        case OK:
            output += " ok";
            break;
        case UNKNOWN:
            output += " ?";
            break;
        default: // Case WAITING
            // Later
            break;
    }
    inputData_.clear();
}


//        switch (GetCommandType(stringCommand))
//        {
//            case INT:
//            {
//                forthStack_.push(std::stoi(stringCommand));
//                forthStatus_ = OK;
//                break;
//            }
//            case COMMAND:
//            {
//                auto it = createdCommands_.find(stringCommand);
//                if (it == createdCommands_.end())
//                {
//                    command_ = CommandFactory::Instance().CreateObject(stringCommand);
//                    createdCommands_.insert(std::make_pair(stringCommand, command_));
//                }
//                else
//                {
//                    command_ = it->second;
//                }
//                try {
//                    command_->DoCommand(forthStack_, inputData_, output);
//                }
//                catch(std::invalid_argument & e)
//                {
//                    output += e.what();
//                    output += " ";
//                    forthStatus_ = EXCEPTION;
//                    break;
//                }
//                forthStatus_ = OK;
//                break;
//            }
//
//            default:
//            {
//                output += " " + stringCommand;
//                forthStatus_ = UNKNOWN;
//                break;
//            }
//        }