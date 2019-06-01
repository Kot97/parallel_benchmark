add_library( lib1c
    ${PROJECT_SOURCE_DIR}/src/1/serial_.h ${PROJECT_SOURCE_DIR}/src/1/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/1/c/openmp_.h ${PROJECT_SOURCE_DIR}/src/1/c/openmp_.c 
    ${PROJECT_SOURCE_DIR}/src/1/c/pthread_.h ${PROJECT_SOURCE_DIR}/src/1/c/pthread_.c )
target_link_libraries(lib1c -lpthread -fopenmp)

add_library( lib1cmpi 
    ${PROJECT_SOURCE_DIR}/src/1/serial_.h ${PROJECT_SOURCE_DIR}/src/1/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/1/c/openmp_.h ${PROJECT_SOURCE_DIR}/src/1/c/openmp_.c 
    ${PROJECT_SOURCE_DIR}/src/1/c/mpi_.h ${PROJECT_SOURCE_DIR}/src/1/c/mpi_.c )
target_link_libraries(lib1cmpi -fopenmp)