add_library( lib3cpp
    ${PROJECT_SOURCE_DIR}/src/3/cpp/serial_.hpp ${PROJECT_SOURCE_DIR}/src/3/cpp/serial_.cpp 
    ${PROJECT_SOURCE_DIR}/src/3/cpp/std_.hpp ${PROJECT_SOURCE_DIR}/src/3/cpp/std_.cpp 
    ${PROJECT_SOURCE_DIR}/src/3/cpp/tbb_.hpp ${PROJECT_SOURCE_DIR}/src/3/cpp/tbb_.cpp )
target_link_libraries(lib3cpp -ltbb -lpthread)

add_library( lib3cppmpi 
    ${PROJECT_SOURCE_DIR}/src/3/cpp/tbb_.hpp ${PROJECT_SOURCE_DIR}/src/3/cpp/tbb_.cpp
    ${PROJECT_SOURCE_DIR}/src/3/cpp/mpi_.hpp ${PROJECT_SOURCE_DIR}/src/3/cpp/mpi_.cpp )
target_link_libraries(lib3cppmpi -ltbb -lpthread -lboost_mpi)