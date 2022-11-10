#include "InBuildOperators.h"

#include "FunctionClearStack.h"

void Dup::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    fStack_.push(fStack_.top());
}

void Drop::DoCommand(std::stack<int> & fStack_,
                     std::stringstream &, std::string &)
{
    if (fStack_.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    fStack_.pop();
}

void Swap::DoCommand(std::stack<int> & fStack_,
                     std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop;
    top = fStack_.top();
    fStack_.pop();
    subTop = fStack_.top();
    fStack_.pop();

    fStack_.push(top);
    fStack_.push(subTop);
}

void Over::DoCommand(std::stack<int> & fStack_,
                     std::stringstream &, std::string &)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop;
    top = fStack_.top();
    fStack_.pop();
    subTop = fStack_.top();

    fStack_.push(top);
    fStack_.push(subTop);
}

void Rot::DoCommand(std::stack<int> & fStack_,
                    std::stringstream &, std::string &)
{
    if (fStack_.size() < 3)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }
    int top, subTop, subSubTop;
    top = fStack_.top();
    fStack_.pop();
    subTop = fStack_.top();
    fStack_.pop();
    subSubTop = fStack_.top();
    fStack_.pop();

    fStack_.push(subTop);
    fStack_.push(top);
    fStack_.push(subSubTop);
}