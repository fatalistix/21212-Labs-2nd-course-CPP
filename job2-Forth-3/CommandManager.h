#pragma once

#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "Containers/SingletonHolder__Heap.h"
#include "ForthCommands/Base/Singleton__CommandFactory.h"
#include "ForthCommands/Base/Command.h"

class CommandManager
{
public:
    CommandManager(const CommandManager &)=delete;
    CommandManager & operator=(const CommandManager &)=delete;

    void Debug(const std::string & keyword, std::stringstream & buffer,
               std::istream & in);

    void Execute(const std::string & keyword, std::stringstream & buffer, std::stack<int> & forthStack,
                 std::ostream & out);

    void Pass(const std::string & keyword, std::stringstream & buffer);

private:
    friend SingletonHolder<CommandManager>;

    CommandManager()=default;
    ~CommandManager()
    {
        for (auto & c : createdCommands_)
        {
            delete c.second;
        }
    };

    std::map<std::string, Command *> createdCommands_;
    Command * command_ = nullptr;
    std::stack<std::string> keywords_;
};

typedef SingletonHolder<CommandManager> ForthCommandManager;