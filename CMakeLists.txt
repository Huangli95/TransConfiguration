cmake_minimum_required(VERSION 3.19)
project(transConfiguration VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/runtime)

add_executable(test src/main.cpp)
target_include_directories(test
    PUBLIC
    src/include
    src/thirdPart
    )
