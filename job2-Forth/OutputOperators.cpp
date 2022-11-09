#include "OutputOperators.h"

void PrintTopNumber::DoCommand(std::stack<int> & fStack_,
                               std::stringstream &, std::string & output)
{
    if (fStack_.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();

    output += std::to_string(top) + " ";
}

void Emit::DoCommand(std::stack<int> & fStack_,
                     std::stringstream &, std::string & output)
{
    if (fStack_.empty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();

    output += char(top);
}
