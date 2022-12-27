#include "ArithmeticOperators.h"

#include "FunctionClearStack.h"

void Add::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }

    int top = fStack_.top();
    fStack_.pop();
    int subTop = fStack_.top();
    fStack_.pop();
    fStack_.push(subTop + top);
}

void Mul::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();
    int subTop = fStack_.top();
    fStack_.pop();
    fStack_.push(subTop * top);
}

void Sub::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();
    int subTop = fStack_.top();
    fStack_.pop();
    fStack_.push(subTop - top);
}

void Div::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int a = fStack_.top();
    if (!a)
    {
        fStack_.pop();
        fStack_.pop();
        throw std::invalid_argument("Division By Zero");
    }
    int top = fStack_.top();
    fStack_.pop();
    int subTop = fStack_.top();
    fStack_.pop();
    fStack_.push(subTop / top);
}

void Mod::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top = fStack_.top();
    if (!top)
    {
        fStack_.pop();
        fStack_.pop();
        throw std::invalid_argument("Division By Zero");
    }
    fStack_.pop();
    int subTop = fStack_.top();
    fStack_.pop();
    fStack_.push(subTop / top);
}
