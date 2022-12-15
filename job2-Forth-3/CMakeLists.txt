cmake_minimum_required(VERSION 3.23)
project(job2_Forth_3 VERSION 3.1)
project(ForthTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(job2_Forth_3
        main.cpp
        Streams/CurrentStreams.h
        Streams/CurrentStreams.cpp
        Containers/Factory.h
        Containers/SingletonHolder__Heap.h
        Containers/SingletonHolder__Static.h
        ForthCommands/Base/Command.h
        ForthCommands/Base/CommandFactoryRegistration.h
        ForthCommands/Base/Singleton__CommandFactory.h
        Forth.cpp
        Forth.h
        CommandManager.cpp
        CommandManager.h
        ForthCommands/ArithmeticOperators.cpp
        ForthCommands/ArithmeticOperators.h
        ForthCommands/Base/Function__CheckStack.h
        ForthCommands/InBuildOperators.cpp
        ForthCommands/InBuildOperators.h
        ForthCommands/OutputOperators.cpp
        ForthCommands/OutputOperators.h
        ForthCommands/LogicOperators.cpp
        ForthCommands/LogicOperators.h
        ForthCommands/Conditional.cpp
        ForthCommands/Conditional.h
        ForthCommands/Loop.cpp
        ForthCommands/Loop.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

add_executable(ForthTest
        UnitTests/Tests.cpp
        Streams/CurrentStreams.cpp
        Containers/Factory.h
        Containers/SingletonHolder__Heap.h
        Containers/SingletonHolder__Static.h
        ForthCommands/Base/Command.h
        ForthCommands/Base/CommandFactoryRegistration.h
        ForthCommands/Base/Singleton__CommandFactory.h
        Forth.cpp
        Forth.h
        CommandManager.cpp
        CommandManager.h
        ForthCommands/ArithmeticOperators.cpp
        ForthCommands/ArithmeticOperators.h
        ForthCommands/Base/Function__CheckStack.h
        ForthCommands/InBuildOperators.cpp
        ForthCommands/InBuildOperators.h
        ForthCommands/OutputOperators.cpp
        ForthCommands/OutputOperators.h
        ForthCommands/LogicOperators.cpp
        ForthCommands/LogicOperators.h
        ForthCommands/Conditional.cpp
        ForthCommands/Conditional.h
        ForthCommands/Loop.cpp
        ForthCommands/Loop.h
        )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS}")

enable_testing()
target_link_libraries(
        ForthTest
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(ForthTest)
