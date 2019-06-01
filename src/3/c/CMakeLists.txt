add_library( lib3c 
    ${PROJECT_SOURCE_DIR}/src/3/c/serial_.h ${PROJECT_SOURCE_DIR}/src/3/c/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/3/c/openmp_.h ${PROJECT_SOURCE_DIR}/src/3/c/openmp_.c )
target_link_libraries(lib3c -fopenmp -lpthread)

add_library( lib3cmpi 
    ${PROJECT_SOURCE_DIR}/src/3/c/openmp_.h ${PROJECT_SOURCE_DIR}/src/3/c/openmp_.c 
    ${PROJECT_SOURCE_DIR}/src/3/c/mpi_.h ${PROJECT_SOURCE_DIR}/src/3/c/mpi_.c )
target_link_libraries(lib3cmpi -fopenmp)