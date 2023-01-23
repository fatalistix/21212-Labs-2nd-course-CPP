#include "InBuildOperators.h"

#include "Base/Function__ClearStack.h"

std::string Dup::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.empty())
    {
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    stack.push(stack.top());
    return "";
}

std::string Drop::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.empty())
    {
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    stack.pop();
    return "";
}

std::string Swap::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();
    stack.pop();

    stack.push(top);
    stack.push(subTop);
    return "";
}

std::string Over::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();

    stack.push(top);
    stack.push(subTop);
    return "";
}

std::string Rot::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 3)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop, subSubTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();
    stack.pop();
    subSubTop = stack.top();
    stack.pop();

    stack.push(subTop);
    stack.push(top);
    stack.push(subSubTop);
    return "";
}