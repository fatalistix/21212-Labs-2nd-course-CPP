#pragma once

#include <string>

#include "../../Containers/SingletonHolder__Heap.h"
#include "../../Containers/Factory.h"
#include "Command.h"

class Command;

typedef SingletonHolder<Factory<Command, std::string>> CommandFactory;
