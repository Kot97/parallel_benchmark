cmake_minimum_required(VERSION 3.0.0)
project(parallel_benchmark VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

link_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
include_directories(src)
add_subdirectory(test)
# add_subdirectory(benchmark)
include_directories(test)

find_package(GoogleBenchmark REQUIRED)