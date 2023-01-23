#pragma once

#define DEBUG

#include <iostream>
#include <stack>
#include <string>

#include "ForthCommands/Base/CommandManager.h"


class Forth
{
public:
    Forth()=default;
    ~Forth()=default;

    Forth(const Forth &) = delete;
    Forth & operator=(const Forth &) = delete;

    bool ReadAndExecute(std::istream &, std::ostream &);

#ifdef DEBUG
    std::stack<int> & getStack() { return forthStack_; }
#undef DEBUG
#endif

private:
    //xf: CommandManager???
    CommandManager forthCommandManager_;

    std::stack<int> forthStack_;
    std::stringstream buffer_;
};