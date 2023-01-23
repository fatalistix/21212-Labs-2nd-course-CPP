#include "ArithmeticOperators.h"

#include "Base/Function__ClearStack.h"

std::string Add::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }

    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop + top);
    return "";
}

std::string Mul::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop * top);
    return "";
}

std::string Sub::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop - top);
    return "";
}

std::string Div::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int a = stack.top();
    if (!a)
    {
        stack.pop();
        stack.pop();
//        status = F_EXCEPTION;
        throw std::runtime_error("Division By Zero");
    }
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop / top);
    return "";
}

std::string Mod::DoCommand(std::stack<int> & stack, std::stringstream &, flag & status)
{
    if (stack.size() < 2)
    {
        ClearStack(stack);
//        status = F_EXCEPTION;
        throw std::invalid_argument("Stack Underflow");
    }
    int top = stack.top();
    if (!top)
    {
        stack.pop();
        stack.pop();
//        status = F_EXCEPTION;
        throw std::runtime_error("Division By Zero");
    }
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop / top);
    return "";
}