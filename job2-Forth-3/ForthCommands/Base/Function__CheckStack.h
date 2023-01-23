#pragma once

#include <iostream>
#include <stack>

inline void CheckStack(std::stack<int> & fStack_, size_t expectedSize)
{
    if (fStack_.size() < expectedSize)
    {
        while (!fStack_.empty())
        {
            fStack_.pop();
        }
        throw std::runtime_error("Stack underflow");
    }
}