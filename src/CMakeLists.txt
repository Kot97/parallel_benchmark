##### 1 #####

add_library( lib1serial 1/serial_.h 1/serial_.c )

add_library( lib1
    1/c/openmp_.h 1/c/openmp_.c 
    1/c/pthread_.h 1/c/pthread_.c 
    1/cpp/std_.hpp 1/cpp/std_.cpp 
    1/cpp/tbb_.hpp 1/cpp/tbb_.cpp )
target_include_directories(lib1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib1 lib1serial -lpthread -fopenmp -ltbb)

add_library( lib1mpi 
    1/c/openmp_.h 1/c/openmp_.c 
    1/c/mpi_.h 1/c/mpi_.c )
target_include_directories(lib1mpi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib1mpi lib1serial -fopenmp)


add_library( lib1bmpi 
    1/cpp/tbb_.hpp 1/cpp/tbb_.cpp
    1/cpp/mpi_.hpp 1/cpp/mpi_.cpp )
target_include_directories(lib1bmpi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib1bmpi lib1serial -lpthread -ltbb -lboost_mpi)

##### 2 #####

add_library( lib2c 
    2/c/serial_.h 2/c/serial_.c
    2/c/openmp_.h 2/c/openmp_.c )
target_include_directories(lib2c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib2c -fopenmp)

add_library( lib2cppserial  )

add_library( lib2cpp 
    2/cpp/serial_.hpp 2/cpp/serial_.cpp
    2/cpp/std_.hpp 2/cpp/std_.cpp 
    2/cpp/tbb_.hpp 2/cpp/tbb_.cpp )
target_include_directories(lib2cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib2cpp -lpthread -ltbb)