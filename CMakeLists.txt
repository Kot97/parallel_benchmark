cmake_minimum_required(VERSION 3.0.0)
project(parallel_benchmark VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)
find_package(TBB REQUIRED)
find_package(Boost COMPONENTS mpi REQUIRED)
find_package(GTest REQUIRED)
find_package(GoogleBenchmark REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(benchmark)