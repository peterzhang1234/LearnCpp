cmake_minimum_required(VERSION 3.28.0)
project(testcase CXX)

link_directories (${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(GLOB TESTSRCS *.cpp *.h)

add_executable(ltest ${TESTSRCS})

target_link_libraries(ltest func gtest_main gtest pthread)