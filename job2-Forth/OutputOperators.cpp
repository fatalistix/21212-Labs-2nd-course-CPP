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

void Carriage::DoCommand(std::stack<int> &,
        std::stringstream &, std::string & output)
{
    output += '\n';
}

void PrintString::DoCommand(std::stack<int> &,
        std::stringstream & input, std::string & output)
{
    int inputSymbol = input.get();
    if (inputSymbol == EOF)
    {
        throw std::invalid_argument(".\" ?");
    }
    while (input.peek() != EOF && input.peek() != '\"')
    {
        inputSymbol = input.get();
        output += char(inputSymbol);
    }
    input.get();
}
