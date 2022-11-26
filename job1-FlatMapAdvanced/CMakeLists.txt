cmake_minimum_required(VERSION 3.23)
project(job1_FlatMapAdvanced)

project(FlatMapTest)

#find_package( googletest-git REQUIRED )


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(job1_FlatMapAdvanced
        FlatMap.h main.cpp)
