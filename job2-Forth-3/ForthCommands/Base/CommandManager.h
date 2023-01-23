#pragma once

#include <map>
#include <memory>
#include <sstream>
#include <stack>
#include <string>

//#include "Containers/SingletonHolder__Heap.h"
#include "Singleton__CommandFactory.h"
#include "Command.h"

class Command;

class CommandManager
{
public:
    CommandManager()=default;
    ~CommandManager()=default;

    CommandManager(const CommandManager &)=delete;
    CommandManager & operator=(const CommandManager &)=delete;

    void Debug(const std::string & keyword, std::stringstream & buffer,
               std::istream & in);

    void Execute(const std::string & keyword, std::stringstream & buffer, std::stack<int> & forthStack,
                 std::ostream & out);

    void Pass(const std::string & keyword, std::stringstream & buffer);

private:
//    friend SingletonHolder<CommandManager>;

//    std::map<std::string, Command *> createdCommands_;  //unique_ptr
    std::map<std::string, std::unique_ptr<Command>> createdCommands_;
    Command * command_ = nullptr;
    std::stack<std::string> keywords_;
};

//typedef SingletonHolder<CommandManager> ForthCommandManager;