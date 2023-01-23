#include "LogicOperators.h"

#include "Base/Function__CheckStack.h"

void More::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                     std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop > top ? -1 : 0);
}

void Less::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                     std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop < top ? -1 : 0);
}

void Equal::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                      std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop == top ? -1 : 0);
}

void And::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop & top);
}

void Or::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                   std::ostream &)
{
    CheckStack(stack, 2);
    int top = stack.top();
    stack.pop();
    int subTop = stack.top();
    stack.pop();
    stack.push(subTop | top);
}

void Invert::Execute(CommandManager &, std::stack<int> & stack, std::stringstream &,
                       std::ostream &)
{
    if (stack.empty())
    {
        throw std::runtime_error("Stack Underflow");
    }
    int top = stack.top();
    stack.pop();
    stack.push(~top);
}