add_library( lib3c 
    serial_.h serial_.c 
    openmp_.h openmp_.c )
target_include_directories(lib3c PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library( lib3cmpi 
    openmp_.h openmp_.c 
    mpi_.h mpi_.c )
target_include_directories(lib3cmpi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})