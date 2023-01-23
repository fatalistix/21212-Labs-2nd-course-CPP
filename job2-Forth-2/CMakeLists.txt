cmake_minimum_required(VERSION 3.23)
project(job2_Forth_2)

set(CMAKE_CXX_STANDARD 20)

add_compile_options("-fsanitize=address")
add_link_options("-fsanitize=address")

add_compile_options("-Wall")
add_link_options("-Wall")

add_executable(job2_Forth_2
        main.cpp
        Containers/SingletonHolder__Static.h
        Containers/SingletonHolder__Heap.h
        Containers/Factory.h
        ForthCommands/Base/Singleton__CommandFactory.h
        ForthCommands/Base/Command.h
        ForthCommands/Base/CommandFactoryRegistration.h
        CommandManager.h
        Forth.h
        Forth.cpp
        CommandManager.cpp
        ForthCommands/ArithmeticOperators.cpp ForthCommands/ArithmeticOperators.h ForthCommands/Base/Function__ClearStack.h ForthCommands/InBuildOperators.cpp ForthCommands/InBuildOperators.h ForthCommands/OutputOperators.cpp ForthCommands/OutputOperators.h)
