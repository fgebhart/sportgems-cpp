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
