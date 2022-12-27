#include "LogicOperators.h"

#include "FunctionClearStack.h"

void More::DoCommand(std::stack<int> & fStack_,
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
    fStack_.push(subTop > top ? -1 : 0);
}

void Less::DoCommand(std::stack<int> & fStack_,
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
    fStack_.push(subTop < top ? -1 : 0);
}

void Equal::DoCommand(std::stack<int> & fStack_,
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
    fStack_.push(subTop == top ? -1 : 0);
}

void And::DoCommand(std::stack<int> & fStack_,
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
    fStack_.push(subTop & top ? -1 : 0);
}

void Or::DoCommand(std::stack<int> & fStack_,
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
    fStack_.push(subTop | top ? -1 : 0);
}

void Invert::DoCommand(std::stack<int> & fStack_,
                   std::stringstream &, std::string &)
{
    if (fStack_.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }

    int top = fStack_.top();
    fStack_.pop();
    fStack_.push((!top) - 1);
}
