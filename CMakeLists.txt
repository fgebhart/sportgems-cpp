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

# configure tests to run with ctest
include(CTest)

# Add the testing executable and add them to ctest
add_executable(test_sort test/cpp_sorter_test.cpp include/cpp_sorter.h)
target_link_libraries(test_sort gtest_main)
add_test(NAME AllTestsInSorter COMMAND test_sort)

add_executable(test_generator test/test_generator.cpp include/generator.h src/generator.cpp)
target_link_libraries(test_generator gtest_main)
add_test(NAME AllTestsInGenerator COMMAND test_generator)

add_executable(test_geo test/test_geo.cpp include/geo.h src/geo.cpp)
target_link_libraries(test_geo gtest_main)
add_test(NAME AllTestsInGeo COMMAND test_geo)

