cmake_minimum_required(VERSION 3.23)
project(job1_FlatMapAdvanced VERSION 2.2)
project(FlatMapTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(job1_FlatMapAdvanced FlatMap.h main.cpp)
add_executable(FlatMapTest FlatMap.h FlatMapTests.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
SET(WARN_FLAGS "-Wall -Wpedantic -Wextra")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS}")

enable_testing()
target_link_libraries(
        FlatMapTest
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(FlatMapTest)

