#pragma once

#include <string>

#include "Singleton__CommandFactory.h"

template<class T>
class CommandFactoryRegistration
{
public:
    explicit CommandFactoryRegistration(const std::string & id)
    {
        CommandFactory::Instance().Register(id,
                                            []() { return static_cast<Command *>(new T); });
    }
};