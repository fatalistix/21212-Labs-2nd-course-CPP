#pragma once

#include <stack>

inline void ClearStack(std::stack<int> & fStack_)
{
    while (!fStack_.empty())
    {
        fStack_.pop();
    }
}
