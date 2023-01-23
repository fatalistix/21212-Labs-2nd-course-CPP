#include "ArithmeticOperators.h"

#include "Base/Function__CheckStack.h"

void Add::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop + top);
}

void Mul::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop * top);
}

void Sub::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop - top);
}

void Div::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    if (!top)
    {
        throw std::runtime_error("Division By Zero");
    }
    stack.push(subTop / top);
}

void Mod::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    if (!top)
    {
        throw std::runtime_error("Division By Zero");
    }
    stack.push(subTop % top);
}