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

# Add the GoogleTest library subdirectory
add_subdirectory(thirdparty/googletest)

# configure tests to run with ctest
include(CTest)

# Add the testing executable and add them to ctest
set(testsuites generator;geo;convert)

foreach(testsuite IN LISTS testsuites)
    message(STATUS "configuring test suite: ${testsuite}")
    add_executable(test_${testsuite} test/test_${testsuite}.cpp include/${testsuite}.h src/${testsuite}.cpp)
    target_link_libraries(test_${testsuite} gtest_main)
    add_test(NAME tests_${testsuite} COMMAND test_${testsuite})
endforeach()
