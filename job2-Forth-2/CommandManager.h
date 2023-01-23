#pragma once

#include <map>
#include <sstream>
#include <stack>
#include <string>

#include "Containers/SingletonHolder__Heap.h"
#include "ForthCommands/Base/Singleton__CommandFactory.h"
#include "ForthCommands/Base/Command.h"

class CommandManager
{
public:
    CommandManager(const CommandManager &)=delete;
    CommandManager & operator=(const CommandManager &)=delete;

    std::string DoCommand(std::string & input, std::stack<int> & stack, flag & status);

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

    // #TODO: Think about idea of containing loops and ifs in currentCommand
    // В случае с условным loop можно в парсинге попытаться сделать
    // рекурсивный вызов CommandManager::DoCommand()
    // в теории оно и запишется правильно, и сразу распарсится
    // Подумать над форматом приема комманд коммандным мэнеджером
    // либо коммандный мэнеджер принимает сразу stringstream со
    // всеми текущими коммандами
    // Либо принимает по строке, но тогда как реализовать loop,
    // вывод строк и условный оператор
    std::stringstream currentCommands;
    std::map<std::string, Command *> createdCommands_;
    std::map<flag, Command *> customFlags_;
    Command * command_ = nullptr;
};

typedef SingletonHolder<CommandManager> ForthCommandManager;