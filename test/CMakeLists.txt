find_package(MPI REQUIRED)

add_executable( all.test test_all.cpp )
target_link_libraries( all.test 
                1 2c 2cpp 3 
                -lgtest -lgtest_main -ltbb)

add_executable( mpi.test mpi_test.cpp )
target_link_libraries( mpi.test 
                    1mpi 3mpi 
                    -lgtest -lgtest_main ${MPI_C_LIBRARIES} )