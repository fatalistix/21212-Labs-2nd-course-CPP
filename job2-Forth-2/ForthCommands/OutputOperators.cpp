#include "OutputOperators.h"

std::string PrintTopNumber::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    int top = stack.top();
    stack.pop();

    return std::to_string(top) + " ";
}

std::string Emit::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    int top = stack.top();
    stack.pop();

    std::string forRet;
    return forRet + char(top);
}

std::string Carriage::DoCommand(std::stack<int> &, std::stringstream &, flag &)
{
    return "\n";
}

std::string PrintString::DoCommand(std::stack<int> &, std::stringstream & current, flag & status)
{
    if (status == F_OK)
    {
        status = F_PRINT_STRING_WAITING_FOR_STRING;

    }
}