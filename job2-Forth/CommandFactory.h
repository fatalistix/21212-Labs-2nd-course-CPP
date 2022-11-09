#pragma once

#include <string>

#include "Singleton.h"
#include "Factory.h"
#include "Command.h"

typedef SingletonHolder<Factory<Command, std::string>> CommandFactory;
