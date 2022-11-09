#include "ArithmeticOperators.h"

#include "ClearStackFunction.h"

void Add::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }

    int a = fStack_.top();
    fStack_.pop();
    int b = fStack_.top();
    fStack_.pop();
    fStack_.push( b + a);
}

void Mul::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int a = fStack_.top();
    fStack_.pop();
    int b = fStack_.top();
    fStack_.pop();
    fStack_.push(b * a);
}

void Sub::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int a = fStack_.top();
    fStack_.pop();
    int b = fStack_.top();
    fStack_.pop();
    fStack_.push(b - a);
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
    fStack_.pop();
    int b = fStack_.top();
    fStack_.pop();
    fStack_.push(b / a);
}

void Mod::DoCommand(std::stack<int> & fStack_,
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
    fStack_.pop();
    int b = fStack_.top();
    fStack_.pop();
    fStack_.push(b % a);
}
