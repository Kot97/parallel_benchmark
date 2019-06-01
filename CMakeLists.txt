cmake_minimum_required(VERSION 3.0.0)
project(parallel_benchmark VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(test)
add_subdirectory(benchmark)
add_subdirectory(src)

find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)
find_package(TBB REQUIRED)
find_package(Boost COMPONENTS mpi REQUIRED)
find_package(MPI REQUIRED)
find_package(GTest REQUIRED)
find_package(GoogleBenchmark REQUIRED)

add_executable( test_all.test test/test_all.cpp )
target_link_libraries( test_all.test
                lib1c lib1cpp lib2c lib2cpp lib3c lib3cpp -lgtest )

add_executable( mpi_c.test test/mpi_c_test.cpp )
target_link_libraries( mpi_c.test
                    lib1cmpi lib3cmpi -lgtest ${MPI_INCLUDE_PATH} )
add_executable( mpi_cpp.test test/mpi_cpp_test.cpp )
target_link_libraries( mpi_cpp.test
                    lib1cppmpi lib3cppmpi -lgtest ${MPI_INCLUDE_PATH} )

add_executable( benchmark1.out benchmark/benchmark1.cpp )
target_link_libraries( benchmark1.out
                    lib1c lib1cpp -lbenchmark -lbenchmark_main )

add_executable( benchmark2c.out benchmark/benchmark2c.cpp )
add_executable( benchmark2cpp.out benchmark/benchmark2cpp.cpp )
target_link_libraries( benchmark2c.out 
                    lib2c -lbenchmark -lbenchmark_main)
target_link_libraries( benchmark2cpp.out 
                    lib2cpp -lbenchmark -lbenchmark_main)

add_executable( benchmark3.out benchmark/benchmark3.cpp )
target_link_libraries( benchmark3.out
                    lib3c lib3cpp -lbenchmark -lbenchmark_main)