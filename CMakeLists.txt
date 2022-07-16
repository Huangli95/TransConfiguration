cmake_minimum_required(VERSION 3.19)
project(transConfiguration VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/runtime)

set(CMAKE_CXX_FLAGS '-DRUNTIME_LOG_DIR="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/log/"')

option(ADD_G3LOG_BENCH_PERFORMANCE ON)

add_subdirectory(src/modules/g3log)
add_executable(test src/main.cpp)
target_include_directories(test
    PUBLIC
    )
target_link_libraries(test
    PRIVATE
    g3log
)
