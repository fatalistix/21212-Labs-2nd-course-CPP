#pragma once

#define DEBUG

#include <iostream>
#include <stack>
#include <string>

#include "Containers/SingletonHolder__Heap.h"
#include "CommandManager.h"


class Forth
{
public:
    Forth(const Forth &)=delete;
    Forth & operator=(const Forth &)=delete;

    bool ReadAndExecute(std::istream &, std::ostream &);

#ifdef DEBUG
    std::stack<int> & getStack() { return forthStack_; }
#undef DEBUG
#endif

private:
    friend SingletonHolder<Forth>;

    Forth()=default;
    ~Forth()=default;

    std::stack<int> forthStack_;
    std::stringstream buffer;
};

typedef SingletonHolder<Forth> ForthInterpreter;