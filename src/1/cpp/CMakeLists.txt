add_library( lib1cpp 
    ${PROJECT_SOURCE_DIR}/src/1/serial_.h ${PROJECT_SOURCE_DIR}/src/1/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/1/cpp/std_.hpp ${PROJECT_SOURCE_DIR}/src/1/cpp/std_.cpp 
    ${PROJECT_SOURCE_DIR}/src/1/cpp/tbb_.hpp ${PROJECT_SOURCE_DIR}/src/1/cpp/tbb_.cpp )
target_link_libraries(lib1cpp -lpthread -ltbb)

add_library( lib1cppmpi 
    ${PROJECT_SOURCE_DIR}/src/1/serial_.h ${PROJECT_SOURCE_DIR}/src/1/serial_.c 
    ${PROJECT_SOURCE_DIR}/src/1/cpp/tbb_.hpp ${PROJECT_SOURCE_DIR}/src/1/cpp/tbb_.cpp
    ${PROJECT_SOURCE_DIR}/src/1/cpp/mpi_.hpp ${PROJECT_SOURCE_DIR}/src/1/cpp/mpi_.cpp )
target_link_libraries(lib1cppmpi -lpthread -ltbb)