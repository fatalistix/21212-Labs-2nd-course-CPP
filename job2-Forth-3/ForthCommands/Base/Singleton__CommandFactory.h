#pragma once

#include <string>

#include "../../Containers/SingletonHolder__Heap.h"
#include "../../Containers/Factory.h"
#include "Command.h"

typedef SingletonHolder<Factory<Command, std::string>> CommandFactory;