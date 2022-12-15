#include "InBuildOperators.h"

#include "Base/Function__CheckStack.h"

void Dup::Execute(std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    if (stack.empty())
    {
        throw std::runtime_error("Stack Underflow");
    }
    stack.push(stack.top());
}

void Drop::Execute(std::stack<int> & stack, std::stringstream &,
                     std::ostream &)
{
    if (stack.empty())
    {
        throw std::runtime_error("Stack Underflow");
    }
    stack.pop();
}

void Swap::Execute(std::stack<int> & stack, std::stringstream &,
                     std::ostream &)
{
    CheckStack(stack, 2);
    int top, subTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();
    stack.pop();

    stack.push(top);
    stack.push(subTop);
}

void Over::Execute(std::stack<int> & stack, std::stringstream &,
                     std::ostream &)
{
    CheckStack(stack, 2);
    int top, subTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();

    stack.push(top);
    stack.push(subTop);
}

void Rot::Execute(std::stack<int> & stack, std::stringstream &,
                    std::ostream &)
{
    CheckStack(stack, 3);
    int top, subTop, subSubTop;
    top = stack.top();
    stack.pop();
    subTop = stack.top();
    stack.pop();
    subSubTop = stack.top();
    stack.pop();

    stack.push(subTop);
    stack.push(top);
    stack.push(subSubTop);
}