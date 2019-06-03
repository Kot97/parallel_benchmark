##### 1 #####

add_library( 1
    1/c/serial_.c 1/c/openmp_.c 1/c/pthread_.c 
    1/cpp/serial_.cpp 1/cpp/std_.cpp 1/cpp/tbb_.cpp )
target_include_directories(1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(1 -lpthread -fopenmp -ltbb)

add_library( 1mpi 
    1/c/serial_.c 1/c/openmp_.c 1/c/mpi_.c )
target_include_directories(1mpi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(1mpi -fopenmp)

##### 2 #####

add_library( 2c 
    2/c/serial_.c 2/c/openmp_.c )
target_include_directories(2c PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(2c -fopenmp)

add_library( 2cpp 
    2/cpp/serial_.cpp 2/cpp/std_.cpp 2/cpp/tbb_.cpp )
target_include_directories(2cpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(2cpp -lpthread)

##### 3 #####

add_library( 3 
    3/c/serial_.c 3/c/openmp_.c )
target_include_directories(3 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(3 -lpthread -fopenmp)

add_library( 3mpi 
    3/c/serial_.c 3/c/openmp_.c 3/c/mpi_.c )
target_include_directories(3mpi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(3mpi -fopenmp)