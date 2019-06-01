add_library( lib3cpp
    serial_.hpp serial_.cpp 
    std_.hpp std_.cpp 
    tbb_.hpp tbb_.cpp )
target_include_directories(lib3cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library( lib3cppmpi 
    tbb_.hpp tbb_.cpp
    mpi_.hpp mpi_.cpp )
target_include_directories(lib3cppmpi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})