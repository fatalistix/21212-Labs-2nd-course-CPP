#pragma once

#include <string>

#include "SingletonHolder.h"
#include "Factory.h"
#include "gameunit.h"

typedef SingletonHolder<Factory<GameUnit, std::string>> UnitFactory;

template<class T>
class UnitsFactoryRegistration
{
public:
    explicit UnitsFactoryRegistration(const std::string & id)
    {
        UnitFactory::Instance().Register(id,
                                            []() { return static_cast<GameUnit *>(new T); });
    }
};
