add_library( lib2c 
    ${PROJECT_SOURCE_DIR}/src/2/c/serial_.h ${PROJECT_SOURCE_DIR}/src/2/c/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/2/c/openmp_.h ${PROJECT_SOURCE_DIR}/src/2/c/openmp_.c )

target_link_libraries(lib2c -fopenmp)