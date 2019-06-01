find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)
find_package(TBB REQUIRED)
find_package(Boost COMPONENTS mpi REQUIRED)
find_package(GTest REQUIRED)
find_package(MPI REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(../src)

add_executable( test_all test_all.cpp 
            test_c_fibonacci.hpp test_c_search.hpp test_c_vector_mult.hpp
            test_cpp_fibonacci.hpp test_cpp_search.hpp test_cpp_vector_mult.hpp )
target_link_libraries( test_all
                lib1 lib2c lib2cpp lib3c lib3cpp 
                -lgtest -lgtest_main )

add_executable( mpi_c mpi_c_test.cpp mpi_environment.hpp
                mpi_test_c_search.hpp mpi_test_c_vector_mult.hpp )
target_link_libraries( mpi_c
                    lib1mpi lib3cmpi 
                    -lgtest -lgtest_main ${MPI_C_LIBRARIES} )
add_executable( mpi_cpp mpi_cpp_test.cpp mpi_environment.hpp 
                mpi_test_cpp_search.hpp mpi_test_cpp_vector_mult.hpp)
target_link_libraries( mpi_cpp
                    lib1bmpi lib3bmpi 
                    -lgtest -lgtest_main ${MPI_C_LIBRARIES})