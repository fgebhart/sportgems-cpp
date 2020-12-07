cmake_minimum_required(VERSION 3.7)
project(sportgems)

include_directories(src)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} -std=c++17")

file(GLOB SOURCES
    include/*.h
    src/*.cpp
)
add_executable(sportgems ${SOURCES})

## Add the GoogleTest library subdirectory
add_subdirectory(thirdparty/googletest)

# configure tests to run with ctest
include(CTest)

# configure test_geo
message(STATUS "configuring test suite: test_geo")
add_executable(test_geo test/test_geo.cpp src/geo.cpp)
target_link_libraries(test_geo gtest_main)
add_test(NAME tests_geo COMMAND test_geo)

# configure test_parser
message(STATUS "configuring test suite: test_parser")
add_executable(test_parser test/test_parser.cpp src/parser.cpp src/types.cpp)
target_link_libraries(test_parser gtest_main)
add_test(NAME tests_parser COMMAND test_parser)

# configure test_generator
message(STATUS "configuring test suite: test_generator")
add_executable(test_generator test/test_generator.cpp src/generator.cpp src/types.cpp)
target_link_libraries(test_generator gtest_main)
add_test(NAME tests_generator COMMAND test_generator)

# configure test_gem_finder
message(STATUS "configuring test suite: test_gem_finder")
add_executable(test_gem_finder test/test_gem_finder.cpp src/gem_finder.cpp src/types.cpp src/geo.cpp src/generator.cpp src/parser.cpp)
target_link_libraries(test_gem_finder gtest_main)
add_test(NAME test_gem_finder COMMAND test_gem_finder)

