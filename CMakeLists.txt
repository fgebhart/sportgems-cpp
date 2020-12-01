cmake_minimum_required(VERSION 3.7)
project(sportgems)

include_directories(src)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} -std=c++17")
# Add the GoogleTest library subdirectory
add_subdirectory(thirdparty/googletest)

file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_executable(sportgems ${SOURCES})

# Add the testing executable
add_executable(test test/cpp_sorter_test.cpp include/cpp_sorter.h)

target_link_libraries(test 
    gtest_main 
)
