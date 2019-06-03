find_package(MPI REQUIRED)

include(GoogleTest)

add_executable( all.test test_all.cpp )
target_link_libraries( all.test 
                1 2c 2cpp 3 
                -lgtest -ltbb)

add_test(NAME all COMMAND all.test)

add_executable( mpi.test mpi_test.cpp )
target_link_libraries( mpi.test 
                    1mpi 3mpi 
                    -lgtest -lpthread ${MPI_LIBRARIES} )