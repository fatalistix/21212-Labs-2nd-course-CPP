#include "OutputOperators.h"

void PrintTopNumber::Execute(CommandManager &, std::stack<int> & fStack_, std::stringstream &,
                               std::ostream & out)
{
    if (fStack_.empty())
    {
        throw std::runtime_error("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();

    out << std::to_string(top) << ' ';
}

void Emit::Execute(CommandManager &, std::stack<int> & fStack_, std::stringstream &,
                     std::ostream & out)
{
    if (fStack_.empty())
    {
        throw std::runtime_error("Stack Underflow");
    }
    int top = fStack_.top();
    fStack_.pop();

    out << char(top);
}

void Carriage::Execute(CommandManager &, std::stack<int> &, std::stringstream &,
                         std::ostream & out)
{
    out << '\n';
}

void PrintString::Debug(CommandManager &, std::stringstream & buffer, std::istream &, std::stack<std::string> &)
{
    if (buffer.get() == EOF)
    {
        throw std::runtime_error(".\" ?");
    }

    while (buffer.peek() != EOF && buffer.peek() != '\"')
    {
        buffer.get();
    }
    buffer.get();
}

void PrintString::Execute(CommandManager &, std::stack<int> &, std::stringstream & buffer,
                            std::ostream & out)
{
    if (buffer.get() == EOF)
    {
        throw std::runtime_error(".\" ?");
    }

    while (buffer.peek() != EOF && buffer.peek() != '\n' && buffer.peek() != '\"')
    {
        out << char(buffer.get());
    }
    buffer.get();
}