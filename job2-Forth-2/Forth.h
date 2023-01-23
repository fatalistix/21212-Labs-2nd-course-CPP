#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

#include "Containers/SingletonHolder__Heap.h"
#include "ForthCommands/Base/Command.h"
#include "CommandManager.h"

class Forth
{
public:
    Forth(const Forth &)=delete;
    Forth & operator=(const Forth &)=delete;

    friend std::stringstream & operator>>(std::stringstream &, Forth &);
    friend std::string & operator<<(std::string &, Forth &);

private:
    friend SingletonHolder<Forth>;

    Forth()=default;
    ~Forth()=default;

    std::stack<int> forthStack_;
    std::string output_;
    flag forthStatus_ = F_OK;
};

typedef SingletonHolder<Forth> ForthInterpreter;
