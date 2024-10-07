cmake_minimum_required(VERSION 3.28.0)
project(func CXX)

link_directories (${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(func SHARED ${SOURCE_FILES})

target_include_directories(func PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
