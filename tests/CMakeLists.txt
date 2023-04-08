cmake_minimum_required(VERSION 3.23)

add_executable(GTests test.cpp)

target_link_libraries(GTests gtest_main)

include(GoogleTest)

gtest_discover_tests(GTests)