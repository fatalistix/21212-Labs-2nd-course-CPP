#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>

#include "CommandFactory.h"


class Forth
{
public:
    Forth(const Forth &)=delete;
    Forth & operator=(const Forth &)=delete;

    friend std::string & operator>>(std::string &, Forth &);
    friend std::string & operator<<(std::string &, Forth &);
private:
    friend SingletonHolder<Forth>;

    Forth()=default;
    ~Forth();

    void DoCommands();

    std::stringstream inputData_;
    std::stack<int> forthStack_;
    std::map<std::string, Command *> createdCommands_;
    Command * command_ = nullptr;
    std::string output;

    enum FLAGS
    {
        OK = 0,
        EXCEPTION = 1,
        WAITING = 2
    };
    typedef char flag;
    flag forthStatus_ = OK;
};