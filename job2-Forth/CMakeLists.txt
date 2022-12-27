cmake_minimum_required(VERSION 3.23)
project(job2_Forth)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_compile_options(-Wall)
add_link_options(-Wall)

add_executable(job2_Forth
        main.cpp
        Factory.h
        Singleton.h
        ArithmeticOperators.h
        InBuildOperators.h
        LogicOperators.h
        ConditionalOperator.h
        OutputOperators.h
        Loop.h
        Command.h
        ArithmeticOperators.cpp
        CommandFactory.h
        CommandFactoryRegistrations.h
        Functions.h
        Functions.cpp
        InBuildOperators.cpp
        FunctionClearStack.h
        OutputOperators.cpp
        Forth.cpp
        Forth.h
        LogicOperators.cpp ConditionalOperator.cpp CommandManager.h Loop.cpp CommandManager.cpp FunctionGetCommandType.h)
