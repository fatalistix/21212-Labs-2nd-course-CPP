cmake_minimum_required(VERSION 3.23)
project(job2_Forth)

set(CMAKE_CXX_STANDARD 20)

add_executable(job2_Forth main.cpp ForthFactory.h ArithmeticOperators.h InBuildOperators.h
        LogicOperators.h ConditionalOperators.h PrintString.h Loop.h Command.h)
